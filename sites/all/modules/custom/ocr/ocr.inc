<?php 
// @todo move account url to config or install file
define('AMAZON_SQS_PATH','https://' . variable_get('aws_sqs_region', '') . '.queue.amazonaws.com/'. variable_get('aws_account_id','') . '/');

/**
 *  Represents Amason SQS Queue
 */
class sqs_queue
{	
	private $queueName;
	protected $queueURL;
	protected $service;
	/**
	 * Creates new instance of sqs_queue object
	 * @param String $queueName name of the queue in Amazon SQS
	 * 
	 */
	protected function __construct($queueName)
	{
		$this->queueName = $queueName;
		$this->queueURL = AMAZON_SQS_PATH . $this->queueName;
		
		// create Amason SQS client
		$this->service  = new Amazon_SQS_Client(variable_get('aws_access_key'. ''), variable_get('aws_secret_key',''));
	}
};

/**
 * Represents SQS response queue and allows to get messages from that queue.
*/
class response_queue extends sqs_queue 
{
	private $messages;
	public function __construct($queueName)
	{
		parent::__construct($queueName);
		$this->messages = array();
	}
	/**
	 * Gets a message from the SQS queue
	 */
	public function getMessage()
	{
		if(count($this->messages) == 0)
		{ 	// array with messages is empty
			// so we get messages from SQS to array
			$this->getMessages();
		} 
		if(count($this->messages) == 0)
		{ // SQS queue is empty
			return NULL;
		}
		// get message from array
		$message = array_shift($this->messages);
		return $message;
	}
	/*
	 * Gets specified number of messages from
	*/
	private function getMessages($maxMessages=10) {

		require_once libraries_get_path('Amazon') . '/SQS/Model/ReceiveMessageRequest.php';
		$request = new Amazon_SQS_Model_ReceiveMessageRequest();

		//setting response queue url
		$request->setQueueUrl($this->queueURL);
		$request->SetMaxNumberOfMessages($maxMessages);
		$request->SetVisibilityTimeout(15);
		$responsebody = "";
		$response = NULL;
		$this->receiptHandle = NULL;
		$messages=array();
		
		try { // fetch messages from SQS queue
			$response = $this->service->receiveMessage($request);
			if ($response->isSetReceiveMessageResult())
			{
				$receiveMessageResult = $response->getReceiveMessageResult();
				$messageList 		= $receiveMessageResult->getMessage();
				watchdog('OCR Debug', 'Got SQS Responses', array(), WATCHDOG_DEBUG);
				foreach ($messageList as $message) 
				{ // loop through messages in the list within SQS responce
					$this->messages[] = $message;
				}
			}
		}
		catch(Exception $e) {
			watchdog('OCR Exception', $e->getMessage(), array(), WATCHDOG_ERROR);
		}
	}
	
	/**  Deletes message from the SQS queue by receipt handle
	*
	* @param object $message -message recieved with getMessage command from SQS queue
	*/
	public function deleteMessage($message)
	{
		require_once libraries_get_path('Amazon') . '/SQS/Model/DeleteMessageRequest.php';
		
		try 
		{	//deleting messages
			$delete_request = new Amazon_SQS_Model_DeleteMessageRequest();
			$delete_request->setQueueUrl($this->queueURL);
			$delete_request->setReceiptHandle($message->receiptHandle);
			// @todo find out what response has if unsucessful and throw exception if needed.
			$response = $this->service->deleteMessage($delete_request);
			if($response) {
				watchdog('OCR Debug', 'Message deleted for handler: ' . $message->receiptHandle, array(), WATCHDOG_DEBUG);	
			}
			else {
				watchdog('OCR Error', 'Problem with deleting message: '. $message->receiptHandle, array(), WATCHDOG_ERROR);
			}
		}
		catch(Exception $e) {
			watchdog('OCR Exception', $e->getMessage(), array(), WATCHDOG_ERROR);
		}
	}
}

/**
 * Represents queue with requests and allows to send messages to that queue
 */
class request_queue extends sqs_queue
{
	public function __construct($queueName)
	{
		parent::__construct($queueName);
	}

	/**
	 * The SendMessage action delivers a message to the specified queue.
	 *
	 * @param String $message message that will be added to SQS queue
	 */
	public function sendMessage($message) {
		require_once libraries_get_path('Amazon') . '/SQS/Model/SendMessageRequest.php';
		
		$request = new Amazon_SQS_Model_SendMessageRequest();

		//setting message queue url
		$request->setQueueUrl($this->queueURL);
		$request->setMessageBody($message);
		$response = $this->service->sendMessage($request);
		// @todo find out what the response status are and implement exception throw for bad statuses.
		//watchdog('SQS Responce', $response->getSendMessageResult(),array(), WATCHDOG_DEBUG);
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
	public function getnoderevision($nid){
		$result = db_select('node_revision','vid')
		->condition('nid', $nid)
		->fields('vid')
		->execute();
		return $result;

	}
	/**
	 * insert response from OCR to ocr_response if response is success
	 */
	public function insert_response($responsebody, $success){
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
	public function insert_ocr_status($entity_id, $success){
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
	public function getocr_status($nid){
		$result = db_select('field_data_field_ocr_response','field_ocr_response_value')
		->condition('entity_id', $nid)
		->fields('field_ocr_response_value')
		->execute();
		return $result;

	}
	public function check_node($nid) {
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
		$responsearr = json_decode(trim($message));
		$nid         = $responsearr->ExternalReference;
		$imagekey    = $responsearr->ImageKey;
		$imagebucket = $responsearr->ImageBucket;
		$success = $responsearr->Success;
		$error       = $responsearr->ErrorMessage;
		$numbers[]    = $responsearr->Numbers;
		$ocr_object = new ocr_model();
		if ($success == true) {
			$check_node = $ocr_object->check_node($nid);
			foreach($check_node as $nodeid){
				$node_exists = $nodeid->nid;
			}
			if($node_exists)
			{ //inserting runner number
				//checking OCR status of the node
				$ocr_status = $ocr_object->getocr_status($nid);
				foreach($ocr_status as $ocr_response){
					$ocr_responce = $ocr_response->field_ocr_response_value;
				}
				if (!empty($responsearr->Numbers)) {
					foreach($responsearr->Numbers as $responsenumber){
						$revision   = $ocr_object->getnoderevision($nid);
						foreach($revision as $revision_id){
							$node_revid = $revision_id->vid;
						}
						if ($responsenumber->Number) 
						{
							$result = $ocr_object->insert_runnernumber($nid, $responsenumber->Number,$node_revid);
							$insert_status   = $ocr_object->insert_ocr_status($nid,1);
						}
					}
				}
				else { // numbers are empty
					
					if($ocr_responce == "Pending" || $ocr_responce == "")
					{
						$insert_status   = $ocr_object->insert_ocr_status($nid,0);
						watchdog('OCR Info','Runner number not present in OCR response for node: ' . $nid);
					}
				}
			}
			else{ // Node does not exist
				watchdog('OCR Error','Response received for a node that does not exists', array(), WATCHDOG_ERROR);
			}
		}
		else { // OCR response: Success == False
			// @todo
		}
	}
}

?>