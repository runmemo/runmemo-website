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
		$this->service  = new Amazon_SQS_Client(variable_get('aws_access_key'), variable_get('aws_secret_key'));
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

/**
 * Contains attributes of runner's number on the photo.
 */
class OcrResponceNumber
{
	// Id of the product node that contains image
	private $nid;
	// Number of the Runner
	public $number;
	private $probability;
	private $top;
	private $left;
	private $width;
	private $height;

	public function __construct($nid, $number)
	{
		$this->nid = $nid;
		$this->number 	= $number->Number;
		$this->left 	= $number->X;
		$this->top 		= $number->Y;
		$this->width 	= $number->Width;
		$this->height 	= $number->Height;
		$this->probability 	= $number->Probability;
	}

	/**
	 * Saves response from OCR to ocr_response
	 */
	public function Save()
	{
		// @todo write insert query that will add OCR results to DB table.
		db_insert('ocr_response_numbers')->fields(
				array(	'nid' 		=> $this->nid,
						'number'	=> $this->number,
						'left'		=> $this->left,
						'top'		=> $this->top,
						'width'		=> $this->width,
						'height'	=> $this->height,
						'probability' => $this->probability,
						'received' => REQUEST_TIME,
				))
				->execute();
	}
}

/**
 *  Represents Product Node in Drupal
 */
class ProductNode
{
	private $node = NULL;
	private $changed = false;

	public function __construct($nid)
	{
		$this->node = node_load($nid);
	}
	
	/**
	 * Shows whether Drupal Node with this ID exists.
	 * @return boolean
	 */
	private function Exists()
	{
		if($this->node)
		{
			return true;
		} else
		{
			return false;
		}
	}

	/**
	 * Saves runner's number from ocr response to Drupal
	 */
	private function AddRunnerNumber($number)
	{
		$this->node->body[LANGUAGE_NONE][0]['field_runner_number_value'][] = $number;
		
		$this->changed = true;
	}

	/**
	 * Update Product node with the OCR response status.
	 */
	public function SetOcrStatus($success)
	{
		if($success){
			$status = 'Success';
		}
		else{
			$status = 'Failure';
		}

		$this->node->body[LANGUAGE_NONE][0]['field_ocr_response_value'] = $status;
		$this->changed = true;
	}

	public function GetOcrStatus()
	{ 
		// @todo need to merge this function with the one that checks node existance
		return $this->node->body[LANGUAGE_NONE][0]['field_ocr_response_value'];
	}
	
	/**
	 * Saves changes done to the node.
	 */
	public function Save()
	{
		if($this->changed)
		{
			node_save($node);
			$this->changed = false;
		}
		
	}
}

/**
 * Saves Json response message to Drupal.
 */
class OcrResultsSaver
{
	private $nid; // id of the Node
	private $success; // Success flag from the responce
	private $numbers = array();
	private $error_message;
	private $product;

	public function __construct($message)
	{
		if (!$message)
		{
			throw new Exception('$message must be not be null.');

			$responsearr = json_decode(trim($message));
			$this->nid         = $responsearr->ExternalReference;

			$this->success = $responsearr->Success;
			if($this->success)
			{
				foreach ($responsearr->Numbers as $number)
				{
					$this->numbers[] = new OcrResponceNumber($this->nid, $number);
				}
			} else
			{
				$this->error_message 	= $responsearr->ErrorMessage;
			}
			//	$imagekey    = $responsearr->ImageKey;
			//	$imagebucket = $responsearr->ImageBucket;
		}
	}

	/**
	 * Saves all details from OCR response message to Drupal
	 */
	public function Save()
	{
		$ocr_object = new ocr_model();
		if ($success == true) {
				
			try {
				$this->product = new ProductNode($this->nid);

				// adding runner's numbers
				foreach($this->numbers as $number){
					$this->product->AddRunnerNumber($number->number);
					$number->Save();
				}
				$this->product->SetOcrStatus($this->success);
				$this->product->Save();
			} catch (Exception $e)
			{
				watchdog_exception('OCR Exception', $e);
			}
		}
		else { // OCR response: Success == False
			$this->SaveError();
		}
	}
	
	/**
	 * Saves error message from OCR responce to Product node.
	 */
	private function SaveError()
	{
	
		if($this->error_message)
		{
			// @todo - maybe need to save this on the Product Node.
			watchdog('OCR Result Error', 'OCR Message: ' . $this->error_message, array(), WATCHDOG_WARNING);
		}
	}
}

/**
 * updating OCR response
 */
function update_drupal_with_responce ($message)
{
	$results_saver = new OcrResultsSaver($message);
	$results_saver->Save();
}

?>