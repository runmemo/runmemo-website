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

/**
 * =============================================================================
 * 1. Begin of Events view 
 * =============================================================================
 */
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
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
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
  /* Field: Content: Participants */
  $handler->display->display_options['fields']['field_no_of_participant']['id'] = 'field_no_of_participant';
  $handler->display->display_options['fields']['field_no_of_participant']['table'] = 'field_data_field_no_of_participant';
  $handler->display->display_options['fields']['field_no_of_participant']['field'] = 'field_no_of_participant';
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
  /* Sort criterion: Content: Date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
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
  /* Filter criterion: Content: Distance (field_distance) */
  $handler->display->display_options['filters']['field_distance_tid']['id'] = 'field_distance_tid';
  $handler->display->display_options['filters']['field_distance_tid']['table'] = 'field_data_field_distance';
  $handler->display->display_options['filters']['field_distance_tid']['field'] = 'field_distance_tid';
  $handler->display->display_options['filters']['field_distance_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_distance_tid']['expose']['operator_id'] = 'field_distance_tid_op';
  $handler->display->display_options['filters']['field_distance_tid']['expose']['label'] = 'Distance:';
  $handler->display->display_options['filters']['field_distance_tid']['expose']['operator'] = 'field_distance_tid_op';
  $handler->display->display_options['filters']['field_distance_tid']['expose']['identifier'] = 'distance';
  $handler->display->display_options['filters']['field_distance_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_distance_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_distance_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_distance_tid']['vocabulary'] = 'distance';
  $handler->display->display_options['filters']['field_distance_tid']['error_message'] = 1;
  /* Filter criterion: Content: Date (field_date) */
  $handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_date_value']['default_date'] = 'last week';
  $handler->display->display_options['filters']['field_date_value']['year_range'] = '-0:+3';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'events/search';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Events';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'OpenLayers Data Overlay', 'events_map_view');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    2 => '2',
    5 => '5',
  );
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'wkt',
    'other_lat' => 'title',
    'other_lon' => 'title',
    'wkt' => 'field_geolocation',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => 'body',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
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
  /* Field: Content: Participants */
  $handler->display->display_options['fields']['field_no_of_participant']['id'] = 'field_no_of_participant';
  $handler->display->display_options['fields']['field_no_of_participant']['table'] = 'field_data_field_no_of_participant';
  $handler->display->display_options['fields']['field_no_of_participant']['field'] = 'field_no_of_participant';
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
  /* Field: Content: Geolocation */
  $handler->display->display_options['fields']['field_geolocation']['id'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['table'] = 'field_data_field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['field'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_geolocation']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_geolocation']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_geolocation']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_geolocation']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_geolocation']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_geolocation']['settings'] = array(
    'data' => 'centroid',
  );
  $handler->display->display_options['fields']['field_geolocation']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '300',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  $translatables['events'] = array(
    t('Master'),
    t('Events'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('Name'),
    t('Date'),
    t('Place'),
    t('Participants'),
    t('Distance:'),
    t('Page'),
    t('OpenLayers Data Overlay'),
    t('Geolocation'),
    t('Body'),
  );



  // Add view to list of views to provide.

  $views[$view->name] = $view;
/**
 * =============================================================================
 * End of Events view 
 * =============================================================================
 */

  
/**
 * =============================================================================
 * 2. Begin of Registered Photographers view
 * =============================================================================
 */
  
  // VIEW Registreded Photographers
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
  $handler->display->display_options['filters']['rid']['value'] = array($rid => (string)$rid);
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
  $handler->display->display_options['filters']['rid']['value'] = array($rid => (string)$rid);
  $handler->display->display_options['filters']['rid']['reduce_duplicates'] = 0;
  $handler->display->display_options['block_description'] = 'Registered Photographers';

  $views[$view->name] = $view;
 
/**
 * =============================================================================
 * End of Event Registered Photographers view 
 * =============================================================================
 */

  
/**
 * =============================================================================
 * 3. Begin of My Events view 
 * =============================================================================
 */
  
  $view = new view;
  $view->name = 'my_events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'My Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    'admin' => user_custom_helper::get_rid('admin'),
    'photographer' => user_custom_helper::get_photographer_rid(),
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['links'] = 1;
  $handler->display->display_options['row_options']['comments'] = 0;
  /* Relationship: Content: Registered Photographers (field_photographers) */
  $handler->display->display_options['relationships']['field_photographers_uid']['id'] = 'field_photographers_uid';
  $handler->display->display_options['relationships']['field_photographers_uid']['table'] = 'field_data_field_photographers';
  $handler->display->display_options['relationships']['field_photographers_uid']['field'] = 'field_photographers_uid';
  $handler->display->display_options['relationships']['field_photographers_uid']['required'] = 0;
  $handler->display->display_options['relationships']['field_photographers_uid']['delta'] = '-1';
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
  /* Sort criterion: Content: Date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
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
  /* Filter criterion: Content: Distance (field_distance) */
  $handler->display->display_options['filters']['field_distance_tid']['id'] = 'field_distance_tid';
  $handler->display->display_options['filters']['field_distance_tid']['table'] = 'field_data_field_distance';
  $handler->display->display_options['filters']['field_distance_tid']['field'] = 'field_distance_tid';
  $handler->display->display_options['filters']['field_distance_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_distance_tid']['expose']['operator_id'] = 'field_distance_tid_op';
  $handler->display->display_options['filters']['field_distance_tid']['expose']['label'] = 'Distance:';
  $handler->display->display_options['filters']['field_distance_tid']['expose']['operator'] = 'field_distance_tid_op';
  $handler->display->display_options['filters']['field_distance_tid']['expose']['identifier'] = 'distance';
  $handler->display->display_options['filters']['field_distance_tid']['expose']['reduce'] = 0;
  $handler->display->display_options['filters']['field_distance_tid']['reduce_duplicates'] = 0;
  $handler->display->display_options['filters']['field_distance_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_distance_tid']['vocabulary'] = 'distance';
  $handler->display->display_options['filters']['field_distance_tid']['error_message'] = 1;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'field_photographers_uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'photographer/myevents';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My Events';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['context'] = 0;

  
  $views[$view->name] = $view;
/**
 * =============================================================================
 * End of My Events view 
 * =============================================================================
 */

  
/**
 * =============================================================================
 * 4. Begin of Upcoming Events view 
 * =============================================================================
 */  
$view = new view;
$view->name = 'upcoming_events';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Upcoming Events';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Upcoming Events';
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'grid';
$handler->display->display_options['style_options']['columns'] = '1';
$handler->display->display_options['style_options']['fill_single_line'] = 1;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'title' => 'title',
  'field_date' => 'field_date',
  'field_event_address1' => 'field_event_address1',
);
$handler->display->display_options['row_options']['hide_empty'] = 0;
$handler->display->display_options['row_options']['default_field_elements'] = 1;
/* Field: Content: Date */
$handler->display->display_options['fields']['field_date']['id'] = 'field_date';
$handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
$handler->display->display_options['fields']['field_date']['field'] = 'field_date';
$handler->display->display_options['fields']['field_date']['label'] = '';
$handler->display->display_options['fields']['field_date']['alter']['alter_text'] = 1;
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
$handler->display->display_options['fields']['field_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_date']['element_default_classes'] = 0;
$handler->display->display_options['fields']['field_date']['hide_empty'] = 0;
$handler->display->display_options['fields']['field_date']['empty_zero'] = 0;
$handler->display->display_options['fields']['field_date']['hide_alter_empty'] = 1;
$handler->display->display_options['fields']['field_date']['settings'] = array(
  'format_type' => 'day_month',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_repeat_rule' => 'show',
);
$handler->display->display_options['fields']['field_date']['field_api_classes'] = 0;
/* Field: Content: Заголовок */
$handler->display->display_options['fields']['title_field']['id'] = 'title_field';
$handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
$handler->display->display_options['fields']['title_field']['field'] = 'title_field';
$handler->display->display_options['fields']['title_field']['label'] = '';
$handler->display->display_options['fields']['title_field']['alter']['alter_text'] = 0;
$handler->display->display_options['fields']['title_field']['alter']['make_link'] = 0;
$handler->display->display_options['fields']['title_field']['alter']['absolute'] = 0;
$handler->display->display_options['fields']['title_field']['alter']['external'] = 0;
$handler->display->display_options['fields']['title_field']['alter']['replace_spaces'] = 0;
$handler->display->display_options['fields']['title_field']['alter']['trim_whitespace'] = 0;
$handler->display->display_options['fields']['title_field']['alter']['nl2br'] = 0;
$handler->display->display_options['fields']['title_field']['alter']['word_boundary'] = 1;
$handler->display->display_options['fields']['title_field']['alter']['ellipsis'] = 1;
$handler->display->display_options['fields']['title_field']['alter']['more_link'] = 0;
$handler->display->display_options['fields']['title_field']['alter']['strip_tags'] = 0;
$handler->display->display_options['fields']['title_field']['alter']['trim'] = 0;
$handler->display->display_options['fields']['title_field']['alter']['html'] = 0;
$handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title_field']['element_default_classes'] = 1;
$handler->display->display_options['fields']['title_field']['hide_empty'] = 0;
$handler->display->display_options['fields']['title_field']['empty_zero'] = 0;
$handler->display->display_options['fields']['title_field']['hide_alter_empty'] = 1;
$handler->display->display_options['fields']['title_field']['field_api_classes'] = 0;
$handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
/* Sort criterion: Content: Date (field_date) */
$handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
$handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
$handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
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
/* Filter criterion: Content: Date (field_date) */
$handler->display->display_options['filters']['field_date_value']['id'] = 'field_date_value';
$handler->display->display_options['filters']['field_date_value']['table'] = 'field_data_field_date';
$handler->display->display_options['filters']['field_date_value']['field'] = 'field_date_value';
$handler->display->display_options['filters']['field_date_value']['operator'] = '>=';
$handler->display->display_options['filters']['field_date_value']['default_date'] = 'now';

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'upcoming_events');
$handler->display->display_options['block_description'] = 'Upcoming Events';
$translatables['upcoming_events'] = array(
  t('Master'),
  t('Upcoming Events'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Block'),
);


  $views[$view->name] = $view;
/**
 * =============================================================================
 * End of Upcoming Events view 
 * =============================================================================
 */

/**
 * =============================================================================
 * Recent Events view 
 * =============================================================================
 */

  $view = new view;
  $view->name = 'recent_events';
  $view->description = 'Shows images from recent events';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Recent Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Recent Events';
  $handler->display->display_options['css_class'] = 'recent-events';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '2';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['style_options']['summary'] = 'Sample photos from recent events';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['external'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['nid']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Profile Image */
  $handler->display->display_options['fields']['field_profile_image']['id'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['table'] = 'field_data_field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['field'] = 'field_profile_image';
  $handler->display->display_options['fields']['field_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_profile_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_profile_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_profile_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_profile_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_profile_image']['element_class'] = 'recent-event-thumbnail';
  $handler->display->display_options['fields']['field_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_profile_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_profile_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_profile_image']['settings'] = array(
  'image_style' => 'search_thumbnail',
  'image_link' => '',
  );
  $handler->display->display_options['fields']['field_profile_image']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_profile_image']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_profile_image']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_profile_image']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_profile_image']['separator'] = '';
  $handler->display->display_options['fields']['field_profile_image']['field_api_classes'] = 0;
  /* Field: Search Form */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['ui_name'] = 'Search Form';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['php']['alter']['text'] = '<div class="recent-event">
  <div class="event-title">[title]</div>
  <div class="event-thumbnails">[field_profile_image]</div>
  <div class="event-search-form">[php]</div>
</div>';
  $handler->display->display_options['fields']['php']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['php']['alter']['external'] = 0;
  $handler->display->display_options['fields']['php']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['php']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['php']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['php']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['php']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['php']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['php']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['php']['alter']['html'] = 0;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['php']['hide_empty'] = 0;
  $handler->display->display_options['fields']['php']['empty_zero'] = 0;
  $handler->display->display_options['fields']['php']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'require_once DRUPAL_ROOT . \'/sites/all/modules/custom/sport_event/sport_event.module\';';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$form = drupal_get_form(\'recent_event_search_\' . $row->nid, $row->nid);
print drupal_render($form); 
?>
';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Sort criterion: Content: Date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
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
  /* Filter criterion: Content: Promoted (field_promoted) */
  $handler->display->display_options['filters']['field_promoted_value']['id'] = 'field_promoted_value';
  $handler->display->display_options['filters']['field_promoted_value']['table'] = 'field_data_field_promoted';
  $handler->display->display_options['filters']['field_promoted_value']['field'] = 'field_promoted_value';
  $handler->display->display_options['filters']['field_promoted_value']['value'] = array(
  1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Recent Events';
  $handler->display->display_options['block_caching'] = '-1';
  
  
  $views[$view->name] = $view;
  
/**
 * =============================================================================
 * End of Recent Events view 
 * =============================================================================
 */

/**
 * =============================================================================
 * Begin of Event Gallery view 
 * =============================================================================
 */
$view = new view();
$view->name = 'event_gallery';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Event Gallery';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Event Gallery';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'grid';
$handler->display->display_options['row_plugin'] = 'fields';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = '<em>No photos were uploaded yet</em>';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Image */
$handler->display->display_options['fields']['uc_product_image']['id'] = 'uc_product_image';
$handler->display->display_options['fields']['uc_product_image']['table'] = 'field_data_uc_product_image';
$handler->display->display_options['fields']['uc_product_image']['field'] = 'uc_product_image';
$handler->display->display_options['fields']['uc_product_image']['label'] = '';
$handler->display->display_options['fields']['uc_product_image']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['uc_product_image']['alter']['text'] = '<div id="thumb-[nid]">[uc_product_image]</div>';
$handler->display->display_options['fields']['uc_product_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uc_product_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['uc_product_image']['settings'] = array(
  'image_style' => 'search_thumbnail',
  'image_link' => '',
);
$handler->display->display_options['fields']['uc_product_image']['delta_offset'] = '0';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Contextual filter: Content: Event (field_event_reference) */
$handler->display->display_options['arguments']['field_event_reference_nid']['id'] = 'field_event_reference_nid';
$handler->display->display_options['arguments']['field_event_reference_nid']['table'] = 'field_data_field_event_reference';
$handler->display->display_options['arguments']['field_event_reference_nid']['field'] = 'field_event_reference_nid';
$handler->display->display_options['arguments']['field_event_reference_nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_event_reference_nid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['field_event_reference_nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_event_reference_nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_event_reference_nid']['summary_options']['items_per_page'] = '25';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'product' => 'product',
);
/* Filter criterion: User: Current */
$handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['table'] = 'users';
$handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
$handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
$handler->display->display_options['filters']['uid_current']['value'] = '1';
/* Filter criterion: Content: Event (field_event_reference) */
$handler->display->display_options['filters']['field_event_reference_nid']['id'] = 'field_event_reference_nid';
$handler->display->display_options['filters']['field_event_reference_nid']['table'] = 'field_data_field_event_reference';
$handler->display->display_options['filters']['field_event_reference_nid']['field'] = 'field_event_reference_nid';
$handler->display->display_options['filters']['field_event_reference_nid']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_event_reference_nid']['expose']['operator_id'] = 'field_event_reference_nid_op';
$handler->display->display_options['filters']['field_event_reference_nid']['expose']['label'] = 'Event Name';
$handler->display->display_options['filters']['field_event_reference_nid']['expose']['operator'] = 'field_event_reference_nid_op';
$handler->display->display_options['filters']['field_event_reference_nid']['expose']['identifier'] = 'field_event_reference_nid';
$handler->display->display_options['filters']['field_event_reference_nid']['expose']['remember'] = TRUE;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['use_ajax'] = FALSE;
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['exposed_form'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '20';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Photos per page';
$handler->display->display_options['pager']['options']['tags']['first'] = '';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ prev';
$handler->display->display_options['pager']['options']['tags']['last'] = '';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'grid';
$handler->display->display_options['style_options']['columns'] = '5';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Event Reference */
$handler->display->display_options['header']['php']['id'] = 'php';
$handler->display->display_options['header']['php']['table'] = 'views';
$handler->display->display_options['header']['php']['field'] = 'php';
$handler->display->display_options['header']['php']['ui_name'] = 'Event Reference';
$handler->display->display_options['header']['php']['empty'] = TRUE;
$handler->display->display_options['header']['php']['php_output'] = '<?php
  $eventid = arg(1);
  $event = node_load($eventid);
?>
<div id="links-block">
<div id="link-selected">
<?php
echo l( t("All photos"), "event/" . $event->nid . "/gallery");
?>
</div>
<div id="link-other">
<?php
echo l( t("Unmatched photos only"), "event/" . $event->nid . "/gallery/unmatched");
?>
</div>
</div>

<div id="photos-from">
<h4>
<?php
echo t("Photos from ");
echo l( $event->title, "node/" . $event->nid);
?>
</h4>
</div>';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['ui_name'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Gallery Thumbnail */
$handler->display->display_options['fields']['uc_product_image']['id'] = 'uc_product_image';
$handler->display->display_options['fields']['uc_product_image']['table'] = 'field_data_uc_product_image';
$handler->display->display_options['fields']['uc_product_image']['field'] = 'uc_product_image';
$handler->display->display_options['fields']['uc_product_image']['ui_name'] = 'Gallery Thumbnail';
$handler->display->display_options['fields']['uc_product_image']['label'] = '';
$handler->display->display_options['fields']['uc_product_image']['exclude'] = TRUE;
$handler->display->display_options['fields']['uc_product_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uc_product_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['uc_product_image']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['uc_product_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['uc_product_image']['settings'] = array(
  'image_style' => 'gallery_thumbnail',
  'image_link' => '',
);
$handler->display->display_options['fields']['uc_product_image']['delta_offset'] = '0';
/* Field: Search Preview */
$handler->display->display_options['fields']['uc_product_image_1']['id'] = 'uc_product_image_1';
$handler->display->display_options['fields']['uc_product_image_1']['table'] = 'field_data_uc_product_image';
$handler->display->display_options['fields']['uc_product_image_1']['field'] = 'uc_product_image';
$handler->display->display_options['fields']['uc_product_image_1']['ui_name'] = 'Search Preview';
$handler->display->display_options['fields']['uc_product_image_1']['label'] = '';
$handler->display->display_options['fields']['uc_product_image_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['uc_product_image_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uc_product_image_1']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['uc_product_image_1']['settings'] = array(
  'image_style' => 'search_preview',
  'image_link' => '',
);
/* Field: Colorbox: Colorbox trigger */
$handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
$handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
$handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
$handler->display->display_options['fields']['colorbox']['label'] = '';
$handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['colorbox']['trigger_field'] = 'uc_product_image';
$handler->display->display_options['fields']['colorbox']['popup'] = '[uc_product_image_1]';
$handler->display->display_options['fields']['colorbox']['gid'] = 1;
$handler->display->display_options['fields']['colorbox']['width'] = '';
$handler->display->display_options['fields']['colorbox']['height'] = '';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'product' => 'product',
);
$handler->display->display_options['path'] = 'event/%/gallery';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->display->display_options['defaults']['use_ajax'] = FALSE;
$handler->display->display_options['use_ajax'] = TRUE;
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['exposed_form'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '20';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Photos per page';
$handler->display->display_options['pager']['options']['tags']['first'] = '';
$handler->display->display_options['pager']['options']['tags']['previous'] = '‹ prev';
$handler->display->display_options['pager']['options']['tags']['last'] = '';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'grid';
$handler->display->display_options['style_options']['columns'] = '5';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Event Reference */
$handler->display->display_options['header']['php']['id'] = 'php';
$handler->display->display_options['header']['php']['table'] = 'views';
$handler->display->display_options['header']['php']['field'] = 'php';
$handler->display->display_options['header']['php']['ui_name'] = 'Event Reference';
$handler->display->display_options['header']['php']['empty'] = TRUE;
$handler->display->display_options['header']['php']['php_output'] = '<?php
  $eventid = arg(1);
  $event = node_load($eventid);
?>
<div id="links-block">
<div id="link-other">
<?php
echo l( t("All photos"), "event/" . $event->nid . "/gallery");
?>
</div>
<div id="link-selected">
<?php
echo l( t("Unmatched photos only"), "event/" . $event->nid . "/gallery/unmatched");
?>
</div>
</div>

<div id="photos-from">
<h4>
<?php
echo t("Photos from ");
echo l( $event->title, "node/" . $event->nid);
?>
</h4>
</div>';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['ui_name'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Gallery Thumbnail */
$handler->display->display_options['fields']['uc_product_image']['id'] = 'uc_product_image';
$handler->display->display_options['fields']['uc_product_image']['table'] = 'field_data_uc_product_image';
$handler->display->display_options['fields']['uc_product_image']['field'] = 'uc_product_image';
$handler->display->display_options['fields']['uc_product_image']['ui_name'] = 'Gallery Thumbnail';
$handler->display->display_options['fields']['uc_product_image']['label'] = '';
$handler->display->display_options['fields']['uc_product_image']['exclude'] = TRUE;
$handler->display->display_options['fields']['uc_product_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uc_product_image']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['uc_product_image']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['uc_product_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['uc_product_image']['settings'] = array(
  'image_style' => 'gallery_thumbnail',
  'image_link' => '',
);
$handler->display->display_options['fields']['uc_product_image']['delta_offset'] = '0';
/* Field: Search Preview */
$handler->display->display_options['fields']['uc_product_image_1']['id'] = 'uc_product_image_1';
$handler->display->display_options['fields']['uc_product_image_1']['table'] = 'field_data_uc_product_image';
$handler->display->display_options['fields']['uc_product_image_1']['field'] = 'uc_product_image';
$handler->display->display_options['fields']['uc_product_image_1']['ui_name'] = 'Search Preview';
$handler->display->display_options['fields']['uc_product_image_1']['label'] = '';
$handler->display->display_options['fields']['uc_product_image_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['uc_product_image_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uc_product_image_1']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['uc_product_image_1']['settings'] = array(
  'image_style' => 'search_preview',
  'image_link' => '',
);
/* Field: Colorbox: Colorbox trigger */
$handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
$handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
$handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
$handler->display->display_options['fields']['colorbox']['label'] = '';
$handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['colorbox']['trigger_field'] = 'uc_product_image';
$handler->display->display_options['fields']['colorbox']['popup'] = '[uc_product_image_1]';
$handler->display->display_options['fields']['colorbox']['gid'] = 1;
$handler->display->display_options['fields']['colorbox']['width'] = '';
$handler->display->display_options['fields']['colorbox']['height'] = '';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 0;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'product' => 'product',
);
/* Filter criterion: Content: OCR Numbers (field_ocr_numbers) */
$handler->display->display_options['filters']['field_ocr_numbers_value']['id'] = 'field_ocr_numbers_value';
$handler->display->display_options['filters']['field_ocr_numbers_value']['table'] = 'field_data_field_ocr_numbers';
$handler->display->display_options['filters']['field_ocr_numbers_value']['field'] = 'field_ocr_numbers_value';
$handler->display->display_options['filters']['field_ocr_numbers_value']['operator'] = 'empty';
$handler->display->display_options['filters']['field_ocr_numbers_value']['expose']['operator_id'] = 'field_ocr_numbers_value_op';
$handler->display->display_options['filters']['field_ocr_numbers_value']['expose']['label'] = 'OCR Numbers (field_ocr_numbers)';
$handler->display->display_options['filters']['field_ocr_numbers_value']['expose']['operator'] = 'field_ocr_numbers_value_op';
$handler->display->display_options['filters']['field_ocr_numbers_value']['expose']['identifier'] = 'field_ocr_numbers_value';
$handler->display->display_options['filters']['field_ocr_numbers_value']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  5 => 0,
  6 => 0,
);
$handler->display->display_options['path'] = 'event/%/gallery/unmatched';
$translatables['event_gallery'] = array(
  t('Master'),
  t('Event Gallery'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('Items per page'),
  t('- All -'),
  t('Offset'),
  t('« first'),
  t('‹ previous'),
  t('next ›'),
  t('last »'),
  t('<em>No photos were uploaded yet</em>'),
  t('<div id="thumb-[nid]">[uc_product_image]</div>'),
  t('All'),
  t('Event Name'),
  t('Page'),
  t('Photos per page'),
  t('‹ prev'),
  t('OCR Numbers (field_ocr_numbers)'),
);


  $views[$view->name] = $view;

/**
 * =============================================================================
 * End of Event Gallery view 
 * =============================================================================
 */

  
/**
 * =============================================================================
 * Begin of Event Carousel view 
 * =============================================================================
 */
  
  $view = new view();
$view->name = 'event_carousel';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Event Carousel';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Event Carousel';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'jcarousel';
$handler->display->display_options['style_options']['wrap'] = 'circular';
$handler->display->display_options['style_options']['skin'] = '';
$handler->display->display_options['style_options']['visible'] = '';
$handler->display->display_options['style_options']['scroll'] = '1';
$handler->display->display_options['style_options']['auto'] = '7';
$handler->display->display_options['style_options']['autoPause'] = 1;
$handler->display->display_options['style_options']['easing'] = '';
$handler->display->display_options['style_options']['vertical'] = 0;
$handler->display->display_options['style_options']['ajax'] = 1;
$handler->display->display_options['row_plugin'] = 'fields';
/* Footer: Grey line */
$handler->display->display_options['footer']['area']['id'] = 'area';
$handler->display->display_options['footer']['area']['table'] = 'views';
$handler->display->display_options['footer']['area']['field'] = 'area';
$handler->display->display_options['footer']['area']['ui_name'] = 'Grey line';
$handler->display->display_options['footer']['area']['content'] = '<div class="gray-bdr"></div>
<div class="gallery-link">
  <?php echo l(t("More photos"), "event/" . !1 . "/gallery"); ?>
</div>
';
$handler->display->display_options['footer']['area']['format'] = 'php_code';
$handler->display->display_options['footer']['area']['tokenize'] = TRUE;
/* No results behavior: Space */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['ui_name'] = 'Space';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = '<div class="margin10px"></div>';
$handler->display->display_options['empty']['area']['format'] = 'full_html';
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content: Image */
$handler->display->display_options['fields']['uc_product_image']['id'] = 'uc_product_image';
$handler->display->display_options['fields']['uc_product_image']['table'] = 'field_data_uc_product_image';
$handler->display->display_options['fields']['uc_product_image']['field'] = 'uc_product_image';
$handler->display->display_options['fields']['uc_product_image']['label'] = '';
$handler->display->display_options['fields']['uc_product_image']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uc_product_image']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['uc_product_image']['settings'] = array(
  'image_style' => 'search_thumbnail',
  'image_link' => '',
);
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Contextual filter: Content: Event (field_event_reference) */
$handler->display->display_options['arguments']['field_event_reference_nid']['id'] = 'field_event_reference_nid';
$handler->display->display_options['arguments']['field_event_reference_nid']['table'] = 'field_data_field_event_reference';
$handler->display->display_options['arguments']['field_event_reference_nid']['field'] = 'field_event_reference_nid';
$handler->display->display_options['arguments']['field_event_reference_nid']['default_action'] = 'default';
$handler->display->display_options['arguments']['field_event_reference_nid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['field_event_reference_nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_event_reference_nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_event_reference_nid']['summary_options']['items_per_page'] = '25';
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
  'product' => 'product',
);
/* Filter criterion: Content: Promote (field_promote) */
$handler->display->display_options['filters']['field_promote_value']['id'] = 'field_promote_value';
$handler->display->display_options['filters']['field_promote_value']['table'] = 'field_data_field_promote';
$handler->display->display_options['filters']['field_promote_value']['field'] = 'field_promote_value';
$handler->display->display_options['filters']['field_promote_value']['value'] = array(
  'all' => 'all',
  0 => '0',
  1 => '1',
);

/* Display: Block */
$handler = $view->new_display('block', 'Block', 'block');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['block_description'] = 'Event Carousel';
$translatables['event_carousel'] = array(
  t('Master'),
  t('Event Carousel'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('<div class="gray-bdr-bottom20px"></div>'),
  t('<div class="margin10px"></div>'),
  t('All'),
  t('Block'),
);

  
  $views[$view->name] = $view;

/**
 * =============================================================================
 * End of Event Carousel view 
 * =============================================================================
 */
  
  // At the end, return array of default views.
  return $views;
}