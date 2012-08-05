<?php

/**
 * @file ontains helper classes for testing of OCR module
 */

/**
 *
 * Provides fake OCR response messages.
 * @author Bulat Yapparov
 *
 */
class sqs_fake {
  private $reference;
  /**
   *
   * Initiates the class
   * @param integer $reference reference of the object for OCR response message
   */
  public function __construct($reference) {
    $this->reference = $reference;
  }
  /**
   *
   * Gets fake OCR repsponse message from teplate of the JSON file
   * @param string $file_name name of the template file for the message
   */
  public function getFakeMessage($file_name) {
    $message = $this->GetMessageFromFakeFile($file_name);
    return $this->GetMessageWithExternalReference($message);
  }

  /**
   *
   * Gets text from the specified file
   * @param string $file_name name of the file that we want to read text from.
   */
  private function GetMessageFromFakeFile($file_name) {
    $testsPath = DRUPAL_ROOT . '/' . drupal_get_path('module', 'ocr') . '/tests/';
    return file_get_contents($testsPath . $file_name);
  }

  /**
   *
   * Replaces ExternalReference attribute in Json message with value provided.
   * @param string $message JSON message from OCR response
   * @param integer $reference New value for ExternalReference attribute
   */
  private function GetMessageWithExternalReference($message) {
    $messageJSON = json_decode($message);
    // Overwrite external reference with node id of the test node
    $messageJSON->ExternalReference = $this->reference;
    $message = json_encode($messageJSON);
    return $message;
  }
}

/**
 *
 * Creates and saves new Product node;
 * @author Bulat Yapparov
 *
 */
class product_node_creator {
  /**
   * Creates and saves instance of Product node.
   */
  public static function getNewProductNode($eventid = NULL) {
    // Create new event node to use for product node
    if (is_null($eventid)) {

      $event = new stdClass();
      $event->language = LANGUAGE_NONE;
      $event->field_pricing[$event->language]['0']['value'] = 5;
      $event->title = 'OCR Test Event';
      $event->type = 'event';
      $event->status = 1;
      node_object_prepare($event);
      $event = node_submit($event); // Prepare node for a submit
      node_save($event); // After this call we'll get a nid
      $eventid = $event->nid;
    }
   

    // We create a new Product Node
    $node = new stdClass();
    // content type
    $node->type = 'product';
    //node title
    $node->title = 'Test Product Node';
    //set language
    $node->language = LANGUAGE_NONE;
    //user id
    $node->status = 1;
    $node->comment = 1;
     
    // Create node that we want to update with numbers and OCR status.
    // $price = $event->field_pricing['und']['0']['value'];
    $node->field_event_reference[$node->language][]['nid'] = $eventid;
    $node->field_event_reference[$node->language][]['target_type'] = "node";

    node_object_prepare($node);
    $node = node_submit($node); // Prepare node for a submit
    node_save($node); // After this call we'll get a nid


    return $node;

  }
}


