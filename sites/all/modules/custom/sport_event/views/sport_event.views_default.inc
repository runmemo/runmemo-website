<?php

/**
 * @file
 * Default views for sport_event.module.
 */

/**
 * Implements hook_views_default_views().
 */
function sport_event_views_default_views() {
  $views = array();
  
  //Events view
  $view = new view;
  $view->name = 'events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Future Events';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
  'title' => 'title',
  'field_event_address1' => 'field_event_address1',
  'field_date' => 'field_date',
  'field_no_of_participant' => 'field_no_of_participant',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
  'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
  ),
  'field_event_address1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
  ),
  'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
  ),
  'field_no_of_participant' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
  ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 1;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_date']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_date']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_date']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_date']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_date']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_date']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_date']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_date']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_date']['settings'] = array(
  'format_type' => 'event_date',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => '',
  );
  $handler->display->display_options['fields']['field_date']['field_api_classes'] = 0;
  /* Field: Content: Address1 */
  $handler->display->display_options['fields']['field_event_address1']['id'] = 'field_event_address1';
  $handler->display->display_options['fields']['field_event_address1']['table'] = 'field_data_field_event_address1';
  $handler->display->display_options['fields']['field_event_address1']['field'] = 'field_event_address1';
  $handler->display->display_options['fields']['field_event_address1']['label'] = 'Place';
  $handler->display->display_options['fields']['field_event_address1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_event_address1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_event_address1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_event_address1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_event_address1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_event_address1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_event_address1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_event_address1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_event_address1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_event_address1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_event_address1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_event_address1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_event_address1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_event_address1']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_event_address1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_event_address1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_event_address1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_event_address1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_event_address1']['field_api_classes'] = 0;
  /* Field: Content: Number of Participant */
  $handler->display->display_options['fields']['field_no_of_participant']['id'] = 'field_no_of_participant';
  $handler->display->display_options['fields']['field_no_of_participant']['table'] = 'field_data_field_no_of_participant';
  $handler->display->display_options['fields']['field_no_of_participant']['field'] = 'field_no_of_participant';
  $handler->display->display_options['fields']['field_no_of_participant']['label'] = 'Participants';
  $handler->display->display_options['fields']['field_no_of_participant']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_no_of_participant']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_no_of_participant']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_no_of_participant']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_no_of_participant']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_no_of_participant']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_no_of_participant']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_no_of_participant']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_no_of_participant']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_no_of_participant']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_no_of_participant']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_no_of_participant']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_no_of_participant']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_no_of_participant']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_no_of_participant']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_no_of_participant']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_no_of_participant']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_no_of_participant']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_no_of_participant']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
  'event' => 'event',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'events';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  
 // (Export ends here.)

  // Add view to list of views to provide.
  
  $views[$view->name] = $view;

  // ...Repeat all of the above for each view the module should provide.

  // At the end, return array of default views.
 
  $view = new view;
  $view->name = 'event_registered_photographers';
  $view->description = 'To be used on Events profile page to show photographers who signed up for event';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Event Registered Photographers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Event Registered Photographers';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No Photographers';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'No photographers signed for this event yet, be first to join the team!';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  /* Relationship: User: Registered Photographers (field_photographers) - reverse */
  $handler->display->display_options['relationships']['reverse_field_photographers_node']['id'] = 'reverse_field_photographers_node';
  $handler->display->display_options['relationships']['reverse_field_photographers_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_photographers_node']['field'] = 'reverse_field_photographers_node';
  $handler->display->display_options['relationships']['reverse_field_photographers_node']['label'] = 'event_field_photographers';
  $handler->display->display_options['relationships']['reverse_field_photographers_node']['required'] = 1;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
  5 => '5',
  );
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $rid = user_custom_helper::get_photographer_rid();
  $handler->display->display_options['filters']['rid']['value'] = array(
    $rid => (string)$rid,
  );
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = 0;
  /* Filter criterion: Content: Event Name (field_event_reference) */
  $handler->display->display_options['filters']['field_event_reference_nid']['id'] = 'field_event_reference_nid';
  $handler->display->display_options['filters']['field_event_reference_nid']['table'] = 'field_data_field_event_reference';
  $handler->display->display_options['filters']['field_event_reference_nid']['field'] = 'field_event_reference_nid';
  $handler->display->display_options['filters']['field_event_reference_nid']['relationship'] = 'reverse_field_photographers_node';
  $handler->display->display_options['filters']['field_event_reference_nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_event_reference_nid']['expose']['operator_id'] = 'field_event_reference_nid_op';
  $handler->display->display_options['filters']['field_event_reference_nid']['expose']['label'] = 'Event Name (field_event_reference)';
  $handler->display->display_options['filters']['field_event_reference_nid']['expose']['operator'] = 'field_event_reference_nid_op';
  $handler->display->display_options['filters']['field_event_reference_nid']['expose']['identifier'] = 'field_event_reference_nid';
  $handler->display->display_options['filters']['field_event_reference_nid']['expose']['multiple'] = 1;
  $handler->display->display_options['filters']['field_event_reference_nid']['expose']['reduce'] = 0;
  $handler->display->display_options['path'] = 'event-registered-photographers';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Registered Photographers';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_photographers_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
   $rid => (string)$rid,
  );
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = 0;
  $handler->display->display_options['block_description'] = 'Registered Photographers';

  $views['registered_photographers'] = $view;
  
  return $views;
}