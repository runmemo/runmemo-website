<?php 


/**
 * @file
 * ubercart_custom.field.inc
 */

/**
 * Gents definitions of custom fieds and instances for Event node.
 */
function _product_field_default_fields() {
  $fields = array();

  // Exported field: 'node-product-field_event_reference'.
  $fields['node-product-field_event_reference'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_event_reference',
      'foreign keys' => array(
        'nid' => array(
          'columns' => array(
            'nid' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'nid' => array(
          0 => 'nid',
        ),
      ),
      'locked' => '0',
      'module' => 'node_reference',
      'settings' => array(
        'referenceable_types' => array(
          'article' => 0,
          'event' => 'event',
          'page' => 0,
          'photos' => 0,
          'product' => 0,
        ),
        'view' => array(
          'args' => array(),
          'display_name' => '',
          'view_name' => '',
        ),
      ),
      'translatable' => '0',
      'type' => 'node_reference',
    ),
    'field_instance' => array(
      'bundle' => 'product',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'node_reference',
          'settings' => array(),
          'type' => 'node_reference_default',
          'weight' => '3',
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_event_reference',
      'label' => 'Sport Event',
      'required' => 1,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => '-1',
      ),
    ),
  );
  

  // Exported field: 'node-product-ocr_success'.
  $fields['node-product-ocr_success'] = array(
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
  
  // Translatables
  // Included for use with string extractors like potx.
  t('Sport Event');
  t('OCR Success');
  t('OCR Numbers');
  
  return $fields;
  
}
