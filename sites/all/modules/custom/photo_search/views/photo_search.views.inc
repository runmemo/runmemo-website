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
      'left_field' => 'nid', 
      'field' => 'eventid',
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
  
  return $data;
}