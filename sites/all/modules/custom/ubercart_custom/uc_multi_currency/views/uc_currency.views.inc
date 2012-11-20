<?php 



/**
 * Implementation of hook_views_data_alter().
 */
function uc_currency_views_data_alter(&$data) {
  foreach ($data as $table => $config) {
    foreach ($config as $item => $item_config) {
      if (isset($item_config['field']['handler']) && $item_config['field']['handler'] == 'uc_product_handler_field_price') {
        $data[$table][$item]['field']['handler'] = 'uc_currency_handler_field_price';
      }
    }
  }
 
  return $data;
}