<?php


function photo_search_views_default_views() {
  $views = array();
  
 /**
 * =============================================================================
 * 1. List of photo requests
 * =============================================================================
 */
  
  $view = new view;
  $view->name = 'photo_requests';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'photo_requests';
  $view->human_name = 'Photo Requests';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Photo Requests';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
  3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all'] = 0;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
  'email' => 'email',
  'created' => 'created',
  'number' => 'number',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
  'email' => array(
    'align' => 'views-align-right',
    'separator' => '',
    'empty_column' => 0,
  ),
  'created' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => 'views-align-center',
    'separator' => '',
    'empty_column' => 0,
  ),
  'number' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => 'views-align-left',
    'separator' => '',
    'empty_column' => 0,
  ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Photo Requests: Event Foreign Key */
  $handler->display->display_options['relationships']['eventid']['id'] = 'eventid';
  $handler->display->display_options['relationships']['eventid']['table'] = 'photo_requests';
  $handler->display->display_options['relationships']['eventid']['field'] = 'eventid';
  $handler->display->display_options['relationships']['eventid']['required'] = 1;
  /* Field: Photo Requests: Email */
  $handler->display->display_options['fields']['email']['id'] = 'email';
  $handler->display->display_options['fields']['email']['table'] = 'photo_requests';
  $handler->display->display_options['fields']['email']['field'] = 'email';
  /* Field: Photo Requests: Created On */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'photo_requests';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Photo Requests: Number */
  $handler->display->display_options['fields']['number']['id'] = 'number';
  $handler->display->display_options['fields']['number']['table'] = 'photo_requests';
  $handler->display->display_options['fields']['number']['field'] = 'number';
  $handler->display->display_options['fields']['number']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['number']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['number']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['number']['alter']['external'] = 0;
  $handler->display->display_options['fields']['number']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['number']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['number']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['number']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['number']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['number']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['number']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['number']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['number']['alter']['html'] = 0;
  $handler->display->display_options['fields']['number']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['number']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['number']['hide_empty'] = 0;
  $handler->display->display_options['fields']['number']['empty_zero'] = 0;
  $handler->display->display_options['fields']['number']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['number']['separator'] = '';
  $handler->display->display_options['fields']['number']['format_plural'] = 0;
  /* Field: Content: Distance */
  $handler->display->display_options['fields']['field_distance']['id'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['table'] = 'field_data_field_distance';
  $handler->display->display_options['fields']['field_distance']['field'] = 'field_distance';
  $handler->display->display_options['fields']['field_distance']['relationship'] = 'eventid';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'eventid';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 1;
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
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'eventid';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Select Event';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['required'] = 0;
  $handler->display->display_options['filters']['title']['expose']['remember'] = 1;
  $handler->display->display_options['filters']['title']['expose']['multiple'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'eventid';
  $handler->display->display_options['filters']['type']['value'] = array(
  'event' => 'event',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/reports/photo_requests';
  
  $views[$view->name] = $view;
  
 /**
 * =============================================================================
 * End of List of Photo Requests View
 * =============================================================================
 */
  
   // At the end, return array of default views.
  return $views;

}