<?php 

/**
 * @file
 * Provides views integration
 */

/**
 * Implements hook_views_data
 *
 */
function photo_search_views_data() {
  // Group
  $data['photo_requests']['table']['group'] = t('Photo Requests');
  // Base
  $data['photo_requests']['table']['base'] = array(
    'field' => 'id', // This is the identifier field for the view. 
    'title' => t('Photo Requests'), 
    'help' => t('Photo Requests contains request for photos left by runners.'), 
    'weight' => -10,
  );
  
  // join requests to event
  // @todo: test that this works
   $data['node']['table']['join']['photo_requests'] = array(
      'left_field' => 'ocr_numbers', 
      'field' => 'number',
   );
  
  // Unique Identifier
   $data['photo_requests']['id'] = array(
    'title' => t('id'), 
    'help' => t('Unique id of photo request.'),
  );

  // Email.
  $data['photo_requests']['email'] = array(
    'title' => t('Email'), 
    'help' => t('Email of the runner'), 
    'field' => array(
      'handler' => 'views_handler_field', 
      'click sortable' => FALSE, // This is use by the table display plugin.
    ), 
  );
  
   // Runner's number.
  $data['photo_requests']['number'] = array(
    'title' => t('Number'), 
    'help' => t('Number of the runner.'), 
    'field' => array(
      'handler' => 'views_handler_field_numeric', 
      'click sortable' => TRUE,
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
    // Created On.
  $data['photo_requests']['created'] = array(
    'title' => t('Created On'), 
    'help' => t('Timestamp of request.'), 
    'field' => array(
      'handler' => 'views_handler_field_date', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  
  // Performed On.
  $data['photo_requests']['performed'] = array(
    'title' => t('Performed On'), 
    'help' => t('Timestamp of response.'), 
    'field' => array(
      'handler' => 'views_handler_field_date', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  // Event nid
  $data['photo_requests']['eventid'] = array(
    'title' => t('Event Foreign Key'), 
    'help' => t('Node ID of corresponding event.'),
    // The nid is a foreign key to the {node} table. This allows us to (easily)
    // add a relationship handler for this table field, making all the table
    // fields for the related node available. 
    'field' => array(
      'handler' => 'views_handler_field_numeric', 
      'click sortable' => TRUE,
    ),
    'relationship' => array(
      'base' => 'node', // The name of the table to join with 
      'base field' => 'nid', // The name of the field to join with 
      'handler' => 'views_handler_relationship', 
      'label' => t('Event'),
    ),
  );
  
   // OCR Numbers table
  $data['ocr_numbers']['table']['group'] = t('Photo Requests');
  
   // Runner's number.
  $data['ocr_numbers']['nid'] = array(
    'title' => t('Number'), 
    'help' => t('Node id of the product.'), 
    'field' => array(
      'handler' => 'views_handler_field_numeric', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
    // Runner's number.
  $data['ocr_numbers']['number'] = array(
    'title' => t('Number'), 
    'help' => t('Number of the runner.'), 
    'field' => array(
      'handler' => 'views_handler_field_numeric', 
      'click sortable' => TRUE,
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
    // @todo: test that this works
   $data['field_data_ocr_numbers']['table']['join']['ocr_numbers'] = array(
      'left_field' => 'entity_id', 
      'field' => 'nid',
      'extra' => array (
         array(
            'field'    => 'ocr_numbers_value',
            'value'    => 'ocr_numbers.number',
            'operator' => '=',
            'numeric'  => true,
          ),      
       ),
   );
    // Runner's number.
  $data['ocr_numbers']['probability'] = array(
    'title' => t('Number'), 
    'help' => t('Probability that number is correct.'), 
    'field' => array(
      'handler' => 'views_handler_field_numeric', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  
  
    // Created On.
  $data['ocr_numbers']['created'] = array(
    'title' => t('Created On'), 
    'help' => t('Timestamp of request.'), 
    'field' => array(
      'handler' => 'views_handler_field_date', 
      'click sortable' => TRUE,
    ), 
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ), 
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );
  
  
  
  return $data;
}