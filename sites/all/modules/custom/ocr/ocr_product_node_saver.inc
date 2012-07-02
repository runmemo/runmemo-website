<?php

/**
 * @file contains ProductNodeSaver class.
 * @author Bulat Yapparov
 */


/**
 *  Saves values for OCR fields to Product node
 */
class ProductNodeSaver {
  private $node = NULL;
  private $changed = FALSE;

  public function __construct($nid) {
    $this->node = node_load($nid);
  }

  /**
   * Shows whether Drupal Node with this ID exists.
   * @return boolean
   */
  private function Exists() {
    if ($this->node) {
      return TRUE;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Saves runner's number from ocr response to Drupal
   */
  public function AddNumber($number) {
    $this->node->ocr_numbers[$this->node->language][]['value'] = $number;
    $this->changed = TRUE;
  }

  /**
   * Update Product node with the OCR response status.
   */
  public function SetOcrStatus($success) {
    if ($success == TRUE) {
      $status = 1;
    }
    else {
      $status = 0;
    }
    $this->node->ocr_success[$this->node->language][0]['value'] = $status;
    $this->changed = TRUE;
  }

  /**
   * Saves changes done to the node.
   */
  public function Save() {
    if ($this->changed) {
      node_save($this->node);
      $this->changed = FALSE;
    }
  }
}