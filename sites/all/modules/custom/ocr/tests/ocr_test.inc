<?php


class sqs_fake {
  /**
   * 
   * Gets fake OCR repsponse message
   * @param integer $nid ID of the node that message will be used for.
   */
  public static function getFakeResponseMessage($nid) {
    $testsPath = DRUPAL_ROOT . '/' . drupal_get_path('module', 'ocr') . '/tests/';
    $message = file_get_contents($testsPath . 'response_message_fake.json');

    $messageJSON = json_decode($message);
    // Overwrite external reference with node id of the test node
    $messageJSON->ExternalReference = $nid;
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
   * 
   * Creates and saves instance of Product node.
   * @param integer $uid ID of the user that will be set as creator of the node.
   */
  public static function getNewProductNode() {
     // Create new event node to use for product node
    // @todo create function that creates new Product node without image
    
     global $user;
     $uid = $user->uid;
     $event = new stdClass();
     $event->language = LANGUAGE_NONE;
     $event->field_pricing[$event->language]['0']['value'] = 5;
     $event->title = 'OCR Test Event';
     $event->uid = $uid;
     $event->type = 'event';
     $event->status = 1;
     $event = node_submit($event); // Prepare node for a submit
     node_save($event); // After this call we'll get a nid

     // We create a new Product Node
     $node = new stdClass();
     // content type
     $node->type = 'product';
     //node title
     $node->title = 'Test Product Node';
     //set language
     $node->language = LANGUAGE_NONE;
     //user id
     $node->uid = $uid;
     $node->status = 1;
     $node->comment = 1;
     
     
     
     // Create node that we want to update with numbers and OCR status.
    // $price = $event->field_pricing['und']['0']['value'];
     $node->field_event_reference[$node->language][]['nid'] = $event->nid;
     $node->field_event_reference[$node->language][]['target_type'] = "node";
  
     $node = node_submit($node); // Prepare node for a submit
     node_save($node); // After this call we'll get a nid

    
     return $node;
    
  }
}


