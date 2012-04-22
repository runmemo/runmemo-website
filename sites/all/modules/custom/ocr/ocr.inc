<?php

/*
 * Represents SQS response queue and allows to get messages from that queue.
 */
class response_queue
{
	private $amazon_sqs_base_path ='https://eu-west-1.queue.amazonaws.com/374933304004/';
	
	private $queueName;
	function __construct($responseQueue)
	{
		$this->$queueName = $responseQueue;
	}
	
	public function getMessages($n=10) {
		if ($n>10)
		{
			throw new InvalidArgumentException('Can only receive upto 10 messages at a time. Input was: ' . $n);
		}
		require_once libraries_get_path('Amazon') . '/SQS/Model/ReceiveMessageRequest.php';
		require_once libraries_get_path('Amazon') . '/SQS/Model/DeleteMessageRequest.php';
		// get service credentials
		$service = amazonsqs_service();
		$request = new Amazon_SQS_Model_ReceiveMessageRequest();

		//setting response queue url
		$ocr = new ocr_model();
		$request->setQueueUrl($ocr->amazon_sqs_base_path() . $this->$queueName);
		$request->SetMaxNumberOfMessages($n);
		$request->SetVisibilityTimeout(15);
		$responsebody = "";


		$response = NULL;
		$messages=array();
		do { // Loop through SQS responses
			try {
				$response = $service->receiveMessage($request);
				if ($response->isSetReceiveMessageResult())
				{
					$receiveMessageResult = $response->getReceiveMessageResult();
					$messageList 		= $receiveMessageResult->getMessage();
					watchdog('OCR Debug', 'Got SQS Responses', array(), WATCHDOG_DEBUG);
					foreach ($messageList as $message) {
						if ($message->isSetMessageId()) {
							$messageid = $message->getMessageId() ;
						}
						if ($message->isSetBody()) {
							$responsebody = $message->getBody();
						}
						if ($message->isSetReceiptHandle())
						{
							$receipthandle = $message->getReceiptHandle();
						}
						try
						{
							if ($responsebody)
							{	// make array of messages from SQS response
								$messages[]= $responsebody;
							}
						}
						catch(Exception $e) {
							watchdog('OCR Exception',$e->getMessage(), array(), WATCHDOG_ERROR);
						}
						
					}
					// Delete messages from the queue after processing of results is complete;
					$this->deleteMessages($receiptHandle);
				}
			}
			catch(Exception $e) {
				watchdog('OCR Exception', $e->getMessage(), array(), WATCHDOG_ERROR);
			}
		}
		while($response != NULL);
		return $messages;
	}
	/*
	 *  Deletes messages from the SQS queue by receipt handle
	 * 
	 * @param $receiptHandle - value recieved when messages were received from the SQS queue
	 */
	private function deleteMessages($receiptHandle)
	{
		try {
			//deleting messages
			$delete_request = new Amazon_SQS_Model_DeleteMessageRequest();
			$delete_request->setQueueUrl($this->$amazon_sqs_base_path . $this->queueName);
			$delete_request->setReceiptHandle($receipthandle);
			if($service->deleteMessage($delete_request)) {
				watchdog('OCR Debug', 'Message deleted.', array(), WATCHDOG_DEBUG);
			}
			else{
				watchdog('OCR Error', 'Problem with deleting message'.$receipthandle, array(), WATCHDOG_ERROR);
			}
		}
		catch(Exception $e) {
			watchdog('OCR Exception',$e->getMessage(), array(), WATCHDOG_ERROR);
			throw $e;
		}
	}
}

/*
 * Represents queue with requests and allows to send messages to that queue
 */
class request_queue
{
	private $amazon_sqs_base_path ='https://eu-west-1.queue.amazonaws.com/374933304004/';
	
	private $queueName;
	
	function __construct($requestqueue)
	{
		$this->$queueName = $requestqueue;
	}
	
	/**
	 * The SendMessage action delivers a message to the specified queue.
	 *
	 * @param $nid nodeid of uploaded image
	 * @param $fname name of uploaded image
	 */
	private function send_message($message) {
		require_once libraries_get_path('Amazon') . '/SQS/Model/SendMessageRequest.php';
		// get service credentials
		$service = amazonsqs_service();
		$request = new Amazon_SQS_Model_SendMessageRequest();

		//setting message queue url
		$request->setQueueUrl($this->$amazon_sqs_base_path . $this->$queueName);
		$request->setMessageBody($message);
		$response = $service->sendMessage($request);

		return 1;

	}
	/*
	 * Submits S3 image to the job queue with Node id as ExternalReference
	*
	* @param $nid -  Node Id
	* @param $fname -  path to the file is S3
	* @param $responsequeue - name of the queue to which worker will put the responce
	*/
	public 	function send_image($nid, $fname, $responsequeue)
	{
		//create message
		$bucket = variable_get('amazons3_bucket', '');
		$message_arr = array('ExternalReference' => $nid,
				'ImageKey' => $fname,
				'ImageBucket' => $bucket,
				'OutQueue' => "http://eu-west-1.queue.amazonaws.com/" . $responsequeue,
		);

		$this->send_message(json_encode($message_arr));
	}
}

class ocr_model{

	/**
	 * Insert runner number from ocr response
	 */
	public function insert_runnernumber($nid = 0,$runner_num=0,$revision_id =0,$runner_count=0){

		db_insert('field_data_field_runner_number')->fields(
				array('entity_type' =>'node',
						'bundle' => 'product',
						'deleted' => 0,
						'revision_id' =>$revision_id,
						'language' => 'und',
						'delta' => $runner_count,
						'entity_id' =>$nid,
						'field_runner_number_value' => $runner_num
				))->execute();
	}
	/**
	 * retrieve revision_id for a node
	 */
	public function getnoderevision($nid = 0){
		$result = db_select('node_revision','vid')
		->condition('nid', $nid)
		->fields('vid')
		->execute();
		return $result;

	}
	/**
	 * insert response from OCR to ocr_response if response is success
	 */
	public function insert_response($responsebody="",$success=0){
		$responsebody = mysql_real_escape_string($responsebody);
		db_insert('ocr_response')->fields(
				array('ocr_response' => $responsebody,
						'ocr_status' => $success,
						'received' => REQUEST_TIME,
				))
				->execute();
	}

	/**
	 * insert response from OCR to ocr_response if response is success
	 */
	public function insert_ocr_status($entity_id=0,$success=0){
		if($success == 1){
			$status = "Success";
		}
		else{
			$status = "Failure";
		}
		db_update('field_data_field_ocr_response')->fields(
				array('field_ocr_response_value' =>$status,
				))->condition('entity_id', $entity_id)
				->execute();
	}
	public function getocr_status($nid =0){
		$result = db_select('field_data_field_ocr_response','field_ocr_response_value')
		->condition('entity_id', $nid)
		->fields('field_ocr_response_value')
		->execute();
		return $result;

	}
	public function check_node($nid=0) {
		$result = db_select('node','nid')
		->condition('nid', $nid)
		->fields('nid')
		->execute();
		return $result;
	}
}

/**
 * updating OCR response
 */
function update_drupal_with_responce ($message)
{
	if($message){
		$responsearr   = json_decode(trim($message));
		$nid         = $responsearr->ExternalReference;
		$imagekey    = $responsearr->ImageKey;
		$imagebucket = $responsearr->ImageBucket;
		$success = $responsearr->Success;
		$error       = $responsearr->ErrorMessage;
		$number[]    = $responsearr->Numbers;
		$response_object = new ocr_model();
		if ($success == true) {
			$check_node = $response_object->check_node($nid);
			foreach($check_node as $nodeid){
				$node_exists = $nodeid->nid;
			}
			if( $node_exists )
			{ //inserting runner number
				if ($nid) { //checking OCR status of the node
					$ocr_status = $response_object->getocr_status($nid);
					foreach($ocr_status as $ocr_response){
						$ocr_responce = $ocr_response->field_ocr_response_value;
					}

					$number_count = 0;
					if (!empty($responsearr->Numbers)) {
						foreach($responsearr->Numbers as $responsenumber){
							$revision   = $response_object->getnoderevision($nid);
							foreach($revision as $revision_id){
								$node_revid = $revision_id->vid;
							}
							if ($responsenumber->Number) {
								if($ocr_responce == "Pending" || $ocr_responce == ""){
									$result = $response_object->insert_runnernumber($nid,$responsenumber->Number,$node_revid,$number_count);
									$status_object   = new ocr_model();


									$insert_status   = $status_object->insert_ocr_status($nid,1);
								}
								else{
									watchdog('ocrinfo','Response received for already updated node');
								}

							}
							$number_count +=1;
						}

					}
					else { // numbers are empty
						$status_object   = new ocr_model();
						if($ocr_responce == "Pending" || $ocr_responce == "")
						{
							$insert_status   = $status_object->insert_ocr_status($nid,0);
							watchdog('OCR Info','Runner number not present in OCR response for node: ' . $nid);
						}
					}
				}
			}
			else{ // Node does not exist
				watchdog('OCR Error','Response received for a  node that does not exists',array(), WATCHDOG_ERROR);
			}
		}
	}
}

?>