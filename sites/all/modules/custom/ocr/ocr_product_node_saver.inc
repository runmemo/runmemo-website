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
   * 
   * Saves runner's number from ocr response to Drupal
   * @param array $number named array with attributes for bib_number field
   */
  public function AddNumber($number) {
    // Do NOT add empty array
    if (empty($number) or $number == 0) {
      return;
    }
  
    // Do NOT add the same number
    $saved_numbers = field_get_items('node', $this->node, 'field_ocr_numbers');
    if ($saved_numbers != FALSE) {
      foreach ($saved_numbers as $saved_number) {
        if ($saved_number['value'] == $number) {
          return;
        } 
      }
    }
    $number['created'] = time();
    $this->node->field_ocr_numbers[$this->node->language][] = $number;
    $this->changed = TRUE;
    
  }
  
  public function ClearNumbers() {
    $items = field_get_items('node', $this->node, 'field_ocr_numbers');
    if ($items) {
      foreach ($items as $index => $item) {
        unset($this->node->field_ocr_numbers[$this->node->language][$index]);
      }   
    }
    $this->changed = TRUE;
  }
  
  /**
   * Remove runner's number
   */
  public function RemoveNumber($number) {
    $count_numbers = count($this->node->field_ocr_numbers[$this->node->language]);
    for ($i = 0; $i < $count_numbers; $i++) {
      if (!isset($this->node->field_ocr_numbers[$this->node->language][$i])) {
        $count_numbers++;
        continue;
      }
      if ($this->node->field_ocr_numbers[$this->node->language][$i]['value'] === $number) {
        unset($this->node->field_ocr_numbers[$this->node->language][$i]);
        $this->changed = TRUE;
      }
    }
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
   * Update verifyed by field.
   */
  public function SetVerifiedBy($uid) {
    $this->node->field_manual_tagging[$this->node->language][0]['value'] = TRUE;
    $this->node->field_verified_by[$this->node->language][0]['uid'] = $uid;
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
  
  /**
   * Get runner numbser from node as string (example: "1120,3123,11")
   */
  public function GetNumbersStr() {
    $runner_numbers = '';
    $numbers = field_get_items('node', $this->node, 'field_ocr_numbers');
    
    if (!$numbers) {
      return '';
    }
    
    foreach ($numbers as $number) {
      if (empty($runner_numbers)) {
        $runner_numbers = (string)$number['value'];
      } 
      else {
        $runner_numbers = $runner_numbers . ',' . (string)$number['value'];
      }
    }
    
    return $runner_numbers;
  }
  
  /**
   * Sets prices on the node 
   */
  public function SetPrice($price) {
    $event_nid = $this->node->field_event_reference[$this->node->language][0]['nid'];
    $event = node_load($event_nid);
    // Determine currency code for product from country code in event's address
    $country = field_get_value($event, 'field_address', 'GB', 'country');
    $currency = uc_currency_country_currency($country);
  
    $defaults = default_currency_prices($currency);
    $sales_fee = field_get_value($event, 'field_sales_fee', $defaults['sales_fee']);   
      
    $this->node->sell_price = $price + $sales_fee;
    $this->node->list_price = $price;
    $this->changed = TRUE;    
  }

}