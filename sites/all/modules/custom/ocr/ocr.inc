<?php

/**
 * @file
 * Include file for OCR integration with classes for SQS queue and Node updates
 *
 * /

 /**
 * Saves OCR response message.
 */
class OcrResultsSaver {
  public $nid; // id of the Node
  public $success; // Success flag from the responce
  public $numbers = array();
  private $error_message;
  private $product;

  public function GetSuccess() {
    return $this->success;
  }

  public function __construct($message) {
    if (is_null($message)) {
      throw new IvalidArgumentException('$message must be not be null for OcrResultSaver construction.');
    }

    $response = json_decode(trim($message));
    $this->nid = $response->ExternalReference;
     
    // convert success to boolean
    $this->success = $response->Success;
    if ($this->success) {
      foreach ($response->Numbers as $number) {
        $this->numbers[] = new OcrResponceNumber($this->nid, $number);
      }
    }
    else {
      $this->error_message = $response->ErrorMessage;
    }
    //	$imagekey    = $response->ImageKey;
  }


  /**
   * Saves all details from OCR response message to Drupal
   */
  public function Save() {
    
    if ($this->success) {
      
      $this->product = new ProductNodeSaver($this->nid);

      // adding runner's numbers
      foreach ($this->numbers as $number) {
        $this->product->AddNumber($number->number);
        //    $number->Save();
      }
      $this->product->SetOcrStatus($this->success);
      $this->product->Save();

    }
    else { // OCR response: Success == False
      $this->SaveError();
    }
  }

  /**
   * Saves error message from OCR responce.
   */
  private function SaveError() {

    if ($this->error_message) {
      // @todo - maybe need to save this on the Product Node.
      watchdog('OCR Message Error', $this->error_message, array(), WATCHDOG_WARNING);
    }
  }
}


/**
 * Contains attributes of runner's number on the photo.
 */
class OcrResponceNumber {
  // Id of the product node that contains image
  private $nid;
  // Number of the Runner
  public $number;
  private $probability;
  private $top;
  private $left;
  private $width;
  private $height;

  public function __construct($nid, $number) {
    $this->nid    = $nid;
    $this->number = $number->Number;
    $this->left   = $number->X;
    $this->top    = $number->Y;
    $this->width  = $number->Width;
    $this->height = $number->Height;
    $this->probability = $number->Probability;
  }

  /**
   * Saves response from OCR to ocr_response
   */
  public function Save() {
    // @todo write insert query that will add OCR results to DB table.
    db_insert('ocr_numbers')->fields(
    array(  'nid'    => $this->nid,
            'number' => $this->number,
            'position_left'   => $this->left,
            'position_top'    => $this->top,
            'width'  => $this->width,
            'height' => $this->height,
            'probability' => $this->probability,
            'received' => REQUEST_TIME,
    ))
    ->execute();
  }
}