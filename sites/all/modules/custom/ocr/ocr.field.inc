<?php

/**
 * Gents definitions of custom fieds and instances for OCR module.
 */
function _ocr_default_fields() {
  $fields = array();
  
   // Exported field: 'node-product-ocr_success'.
  $fields['node-product-ocr-success'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'default_value' => NULL,
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'ocr_success',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'label' => 'OCR Success',
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          -1 => 'None',
          0 => 'False',
          1 => 'True',
        ),
        'allowed_values_function' => '',
      ),
      'size' => 'tiny',
      'translatable' => '0',
      'type' => 'list_integer',
    ),
    'field_instance' => array(
      'bundle' => 'product',
      'cardinality' => 1,
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => '12',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'ocr_success',
      'label' => 'OCR Success',
      'module' => 'list',
      'required' => FALSE,
      'settings' => array(
        'allowed_values' => array(
          -1 => 'None',
          0 => 'False',
          1 => 'True',
        ),
        'allowed_values_function' => '',
        'user_register_form' => FALSE,
      ),
      'size' => 'tiny',
      'translatable' => '0',
      'type' => 'list_integer',
      'widget' => array(
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 8,
      ),
    ),
  );
  
   // New Ocr Numbers
  $fields['node-product-ocr-numbers'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '10',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_ocr_numbers',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'number',
      'settings' => array(),
      'size' => 'normal',
      'translatable' => '0',
      'type' => 'bib_number',
    ),
    'field_instance' => array(
      'bundle' => 'product',
      'cardinality' => 10,
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'bib_number',
          'settings' => array(
          ),
          'type' => 'bib_number',
          'weight' => '11',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_ocr_numbers',
      'label' => 'OCR Numbers',
      'required' => FALSE,
      'settings' => array(
        'max' => '99999',
        'min' => '1',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'size' => 'normal',
      'type' => 'bib_number',
      'widget' => array(
      ),
    ),
  );
  
   t('OCR Success');
   t('OCR Numbers');
  return $fields;

}
 