<?php 
// @todo move account url to config or install file
define('AMAZON_SQS_PATH','https://' . variable_get('aws_sqs_region', '') . '.queue.amazonaws.com/'. variable_get('aws_account_id','') . '/');

/*
 *  Represents Amason SQS Queue
 */
class sqs_queue
{	
	private $queueName;
	protected $queueURL;
	protected $service;
	protected function __construct($queueName)
	{
		$this->queueName = $queueName;
		$this->queueURL = AMAZON_SQS_PATH . $this->queueName;
		
		// create Amason SQS client
		$this->service  = new Amazon_SQS_Client(variable_get('aws_access_key'. ''), variable_get('aws_secret_key',''));
	}
};

/*
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
	public function getMessage()
	{
		if(count($this->messages) == 0)
		{
			$this->getMessages(10);
		} 
		if(count($this->messages) == 0)
		{
			return NULL;
		}
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
		return $messages;
	}
	/*
	 *  Deletes messages from the SQS queue by receipt handle
	*
	* @param $message - message recieved with get Message command from SQS queue
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

/*
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
	 * @param $nid nodeid of uploaded image
	 * @param $fname name of uploaded image
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

?>
