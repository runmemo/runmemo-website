<?php

require_once drupal_get_path('module', 'user_custom') . '/user_custom.inc';

function sport_event_field_default_field_bases() {

  $photographer_rid = user_custom_helper::get_photographer_rid();
  // Field for photographers registered at the event
  $field_bases['field_photographers'] = array(
    'active' => '1',
    'cardinality' => '-1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_photographers',
    'foreign keys' => array(
      'uid' => array(
        'columns' => array(
          'uid' => 'uid',
        ),
        'table' => 'users',
      ),
    ),
    'indexes' => array(
      'uid' => array(
        0 => 'uid',
      ),
    ),
    'module' => 'user_reference',
    'settings' => array(
      'referenceable_roles' => array(
        'Photographer' => (string) $photographer_rid,
      ),
      'referenceable_status' => array(
        0 => 0,
        1 => '1',
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => '0',
    'type' => 'user_reference',
  );

  // Field Profile Image for Events
  $field_bases['field_profile_image'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_profile_image',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'module' => 'image',
    'settings' => array(
      'default_image' => '', // @todo references img id, need to load img first, then reference it here
      'uri_scheme' => 'public',
    ),
    'translatable' => '0',
    'type' => 'image',
  );

  $field_bases['field_distance'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_distance',
    'foreign keys' => array(
      'tid' => array(
        'columns' => array(
          'tid' => 'tid',
        ),
        'table' => 'taxonomy_term_data',
      ),
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'distance',
          'parent' => '0',
        ),
      ),
    ),
    'translatable' => '0',
    'type' => 'taxonomy_term_reference',
  );

  $field_bases['field_promoted'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_promoted',
    'field_permissions' => array(
      'type' => '1',
    ),
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => '0',
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'No',
        1 => 'Yes',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => '0',
    'type' => 'list_boolean',
  );

  $director_rid = user_custom_helper::get_rid('race director');
  // Field for director of the event
  $field_bases['field_director'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_director',
    'foreign keys' => array(
      'uid' => array(
        'columns' => array(
          'uid' => 'uid',
        ),
        'table' => 'users',
      ),
    ),
    'indexes' => array(
      'uid' => array(
        0 => 'uid',
      ),
    ),
    'module' => 'user_reference',
    'settings' => array(
      'referenceable_roles' => array(
        'race director' => (string) $director_rid,
      ),
      'referenceable_status' => array(
        0 => 0,
        1 => '1',
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => '0',
    'type' => 'user_reference',
  );

  // Exported field: 'node-event-field_website'.
  $field_bases['field_website'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_website',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => '0',
    'type' => 'link_field',
  );

  // Exported field: 'node-event-field_address'.
  $field_bases['field_address'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_address',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'addressfield',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => '0',
    'type' => 'addressfield',
  );

  // Exported field: 'node-event-field_max_price'.
  $field_bases['field_max_price'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_max_price',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'number',
    'settings' => array(
      'decimal_separator' => '.',
      'entity_translation_sync' => FALSE,
      'precision' => '10',
      'scale' => '2',
    ),
    'translatable' => '0',
    'type' => 'number_decimal',
  );

  $field_bases['field_min_price'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_min_price',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'number',
    'settings' => array(
      'decimal_separator' => '.',
      'entity_translation_sync' => FALSE,
      'precision' => '10',
      'scale' => '2',
    ),
    'translatable' => '0',
    'type' => 'number_decimal',
  );

  $field_bases['field_recommended_price'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_recommended_price',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'number',
    'settings' => array(
      'decimal_separator' => '.',
      'entity_translation_sync' => FALSE,
      'precision' => '10',
      'scale' => '2',
    ),
    'translatable' => '0',
    'type' => 'number_decimal',
  );

  // Exported field: 'node-event-field_sales_fee'.
  $field_bases['field_sales_fee'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_sales_fee',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'number',
    'settings' => array(
      'decimal_separator' => '.',
      'entity_translation_sync' => FALSE,
      'precision' => '10',
      'scale' => '2',
    ),
    'translatable' => '0',
    'type' => 'number_decimal',
  );

  $field_bases['field_count_photos'] = array(
    'active' => '1',
    'cardinality' => '1',
    'deleted' => '0',
    'entity_types' => array(),
    'field_name' => 'field_count_photos',
    'field_permissions' => array(
      'type' => '0',
    ),
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => '0',
    'module' => 'number',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => '0',
    'type' => 'number_integer',
  );


  return $field_bases;
}