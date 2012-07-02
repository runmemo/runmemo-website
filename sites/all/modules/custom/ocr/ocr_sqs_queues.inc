<?php
/**
 * @file contains classes for integration with Amazon SQS service.
 * @author Bulat Yapparov
 */

require_once libraries_get_path('Amazon') . '/SQS/Client.php';

/** @todo move account url to config or install file
 */
define('AMAZON_SQS_PATH', 'https://' . variable_get('aws_sqs_region') . '.queue.amazonaws.com/' . variable_get('aws_account_id') . '/');

/**
 *  Represents Amason SQS Queue
 */
class sqs_queue {
  protected $queueURL;
  protected $service;
  /**
   * Creates new instance of sqs_queue object
   * @param String $queueName name of the queue in Amazon SQS
   *
   */
  protected function __construct($QueueURL) {
    $this->queueURL = $QueueURL;

    // create Amason SQS client
    $this->service  = new Amazon_SQS_Client(variable_get('aws_access_key'), variable_get('aws_secret_key'));
  }
  public function GetURL() {
    return $this->queueURL;
  }

};

/**
 * Represents SQS response queue and allows to get messages from that queue.
 */
class response_queue extends sqs_queue {
  private $messages;
  public function __construct($queueName) {
    parent::__construct($queueName);
    $this->messages = array();
  }
  /**
   * Gets a message from the SQS queue
   */
  public function getMessage() {
    if (count($this->messages) == 0) {
      // array with messages is empty
      // so we get messages from SQS to array
      $this->getMessages();
    }
    if (count($this->messages) == 0) { // SQS queue is empty
      return NULL;
    }
    // get message from array
    $message = array_shift($this->messages);
    return $message;
  }
  /**
   * Gets specified number of messages from the SQS queue
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

    $response = $this->service->receiveMessage($request);
    if ($response->isSetReceiveMessageResult()) {
      $receiveMessageResult = $response->getReceiveMessageResult();
      $messageList = $receiveMessageResult->getMessage();
      foreach ($messageList as $message) {
        // loop through messages in the list within SQS responce
        $this->messages[] = $message;
      }
    }
  }

  /**  Deletes message from the SQS queue by receipt handle
   *
   * @param object $message -message recieved with getMessage command from SQS queue
   */
  public function deleteMessage($message) {
    require_once libraries_get_path('Amazon') . '/SQS/Model/DeleteMessageRequest.php';

    //deleting messages
    $delete_request = new Amazon_SQS_Model_DeleteMessageRequest();
    $delete_request->setQueueUrl($this->queueURL);
    $delete_request->setReceiptHandle($message->receiptHandle);
    // @todo find out what response has if unsuccessful and throw exception if needed.
    $response = $this->service->deleteMessage($delete_request);
    if (!$response) {
      watchdog('OCR Error', 'Problem with deleting message: ' . $message->receiptHandle, array(), WATCHDOG_ERROR);
    }
  }
}

/**
 * Represents queue with requests and allows to send messages to that queue
 */
class request_queue extends sqs_queue {
  public function __construct($queueName) {
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
  }
}
