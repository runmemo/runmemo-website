<?php

/**
 * Implements hook_views_data
 *
 */
function ubercart_custom_views_data() {
  // Group
  $data['uc_custom_order_discounts']['table']['group'] = t('Ordered product discounts');
 
  // Unique Identifier
   $data['uc_custom_order_discounts']['discount_id'] = array(
    'title' => t('discount_id'), 
    'help' => t('Unique id of order product dicsount.'),
  );

  
  // Join discounts to order products
   $data['uc_custom_order_discounts']['table']['join']['uc_order_products'] = array(
      'left_field' => 'order_product_id', 
      'field' => 'order_product_id',
   );

  // Discounted amount.
  $data['uc_custom_order_discounts']['amount'] = array(
    'title' => t('Discount'), 
    'help' => t('Amount of the discount'), 
    'field' => array(
      'handler' => 'views_handler_field_numeric', 
      'click sortable' => FALSE, // This is use by the table display plugin.
    ), 
  );
  
  return $data;
}