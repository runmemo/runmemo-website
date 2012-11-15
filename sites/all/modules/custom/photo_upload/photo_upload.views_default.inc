<?php

/**
 * @file
 * Default views for photo_upload.module.
 */

/**
 * Implements hook_views_default_views().
 */
function photo_upload_views_default_views() {
  
$view = new view();
$view->name = 'myphotos';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'My Photos';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'My photos';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access_photographer';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['query_comment'] = FALSE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'grid';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: Content: Author */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
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
$handler->display->display_options['pager']['type'] = 'mini';
$handler->display->display_options['pager']['options']['items_per_page'] = '15';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Photos per page';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'grid';
$handler->display->display_options['style_options']['columns'] = '5';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['hide_empty'] = TRUE;
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
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
$handler->display->display_options['fields']['uc_product_image']['alter']['text'] = '<div id="thumb-[nid]"><a href="http://runmemo.dev/sites/default/files/p17bstrb87heq112k11j5a8pnsh12.jpg" rel="lightbox[gallery]">[uc_product_image]</a></div>';
$handler->display->display_options['fields']['uc_product_image']['alter']['path'] = '[uc_product_image]';
$handler->display->display_options['fields']['uc_product_image']['alter']['rel'] = 'lightbox';
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
$handler->display->display_options['path'] = 'photographer/myphotos';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'My Photos';
$handler->display->display_options['menu']['weight'] = '2';
$handler->display->display_options['menu']['context'] = 0;
$translatables['myphotos'] = array(
  t('Master'),
  t('My photos'),
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
  t('author'),
  t('<div id="thumb-[nid]">[uc_product_image]</div>'),
  t('Event Name'),
  t('Page'),
  t('Photos per page'),
  t('<div id="thumb-[nid]"><a href="http://runmemo.dev/sites/default/files/p17bstrb87heq112k11j5a8pnsh12.jpg" rel="lightbox[gallery]">[uc_product_image]</a></div>'),
);

  
    
  
 // (Export ends here.)

  // Add view to list of views to provide.
  $views[$view->name] = $view;

  // ...Repeat all of the above for each view the module should provide.

  // At the end, return array of default views.
  return $views;
}