<?php
/**
 * @file contains classes for integration with Amazon SQS service.
 * @author Bulat Yapparov
 */

require_once libraries_get_path('Amazon') . '/SQS/Client.php';

/** @todo move account url to config or install file
 */
define('AMAZON_SQS_PATH', 'https://' . variable_get('aws_sqs_region') . '.queue.amazonaws.com/' . variable_get('aws_account_id') . '/');

interface SqsQueueInterface {
  public function __construct($queueName);
  public function getMessage();
  public function deleteMessage($message);
  public function sendMessage($message);
}


/**
 *  Represents Amason SQS Queue
 */
class SqsQueue implements SqsQueueInterface {
  protected $queueURL;
  protected $service;
  private $messages; // cached messages - upto 10
  /**
   * Creates new instance of SqsQueue object
   * @param String $queueName name of the queue in Amazon SQS
   *
   */
  public function __construct($QueueURL) {
    $this->queueURL = $QueueURL;
    $this->messages = array();
    // create Amason SQS client
    $this->service  = new Amazon_SQS_Client(variable_get('aws_access_key'), variable_get('aws_secret_key'));
  }
  public function GetURL() {
    return $this->queueURL;
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
      return FALSE;
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
};


class FakeSqsQueueMessage {
  private $body;
  private $id;
  public function __construct($message, $id) {
    $this->body = $message;
  }
  
  public function getBody() {
    return $this->body;
  }
  public function GetID() {
    return $this->id;
  }
}
/**
 * 
 * Class fakes SQS Queue by wrapping MemoryQueue to store and retrieve messages
 * @author Bulat Yapparov
 *
 */
class FakeSqsQueue implements SqsQueueInterface {
  private $queue;
  public function __construct($queueName) {
    $this->queue = new MemoryQueue($queueName);   
  }
  public function getMessage() {
    $item = $this->queue->claimItem(10);
    if (!$item) {
      return FALSE;
    }
    $message = new FakeSqsQueueMessage($item->data, $item->item_id);
    return $message;
  }
  public function sendMessage($message) {
    debug($message, 'Putting message to FakeSqsQueue');
    $this->queue->createItem($message);
  }
  public function deleteMessage($message) {
    $item = new stdClass();
    $item->item_id = $message->GetID();
    $this->queue->deleteItem($item);
  }
}

