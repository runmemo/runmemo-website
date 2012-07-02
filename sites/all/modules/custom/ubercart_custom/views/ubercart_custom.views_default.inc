<?php

/**
 * Implements hook_views_default_views().
 */
function ubercart_custom_views_default_views() {

  $export = array();
  $view = new view;
  $view->name = 'sales_summary_by_photographer';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'uc_order_products';
  $view->human_name = 'Sales Summary by Photographer';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Photographer Ordered Products';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer store';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
  'model' => 'model',
  'created' => 'created',
  'primary_email' => 'primary_email',
  'order_status' => 'order_status',
  'cost' => 'cost',
  'price' => 'price',
  'qty' => 'qty',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
  'model' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'created' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'primary_email' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'order_status' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'cost' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'price' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'qty' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  );
  $handler->display->display_options['style_options']['override'] = 1;
  $handler->display->display_options['style_options']['sticky'] = 0;
  $handler->display->display_options['style_options']['empty_table'] = 0;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'photographer';
  $handler->display->display_options['relationships']['uid']['required'] = 1;
  /* Relationship: Order: Products */
  $handler->display->display_options['relationships']['products']['id'] = 'products';
  $handler->display->display_options['relationships']['products']['table'] = 'uc_orders';
  $handler->display->display_options['relationships']['products']['field'] = 'products';
  $handler->display->display_options['relationships']['products']['required'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Photographer';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['name']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['name']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['name']['link_to_user'] = 1;
  $handler->display->display_options['fields']['name']['overwrite_anonymous'] = 0;
  $handler->display->display_options['fields']['name']['format_username'] = 1;
  /* Field: Order: Order status */
  $handler->display->display_options['fields']['order_status']['id'] = 'order_status';
  $handler->display->display_options['fields']['order_status']['table'] = 'uc_orders';
  $handler->display->display_options['fields']['order_status']['field'] = 'order_status';
  $handler->display->display_options['fields']['order_status']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['order_status']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['order_status']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['order_status']['alter']['external'] = 0;
  $handler->display->display_options['fields']['order_status']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['order_status']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['order_status']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['order_status']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['order_status']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['order_status']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['order_status']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['order_status']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['order_status']['alter']['html'] = 0;
  $handler->display->display_options['fields']['order_status']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['order_status']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['order_status']['hide_empty'] = 0;
  $handler->display->display_options['fields']['order_status']['empty_zero'] = 0;
  $handler->display->display_options['fields']['order_status']['hide_alter_empty'] = 1;
  /* Field: COUNT(Order: Email address) */
  $handler->display->display_options['fields']['primary_email']['id'] = 'primary_email';
  $handler->display->display_options['fields']['primary_email']['table'] = 'uc_orders';
  $handler->display->display_options['fields']['primary_email']['field'] = 'primary_email';
  $handler->display->display_options['fields']['primary_email']['group_type'] = 'count';
  $handler->display->display_options['fields']['primary_email']['label'] = 'Runner\'s Email';
  $handler->display->display_options['fields']['primary_email']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['primary_email']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['primary_email']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['primary_email']['alter']['external'] = 0;
  $handler->display->display_options['fields']['primary_email']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['primary_email']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['primary_email']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['primary_email']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['primary_email']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['primary_email']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['primary_email']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['primary_email']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['primary_email']['alter']['html'] = 0;
  $handler->display->display_options['fields']['primary_email']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['primary_email']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['primary_email']['hide_empty'] = 0;
  $handler->display->display_options['fields']['primary_email']['empty_zero'] = 0;
  $handler->display->display_options['fields']['primary_email']['hide_alter_empty'] = 1;
  /* Field: SUM(Ordered product: Price) */
  $handler->display->display_options['fields']['price']['id'] = 'price';
  $handler->display->display_options['fields']['price']['table'] = 'uc_order_products';
  $handler->display->display_options['fields']['price']['field'] = 'price';
  $handler->display->display_options['fields']['price']['group_type'] = 'sum';
  $handler->display->display_options['fields']['price']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['price']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['price']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['price']['alter']['external'] = 0;
  $handler->display->display_options['fields']['price']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['price']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['price']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['price']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['price']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['price']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['price']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['price']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['price']['alter']['html'] = 0;
  $handler->display->display_options['fields']['price']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['price']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['price']['hide_empty'] = 0;
  $handler->display->display_options['fields']['price']['empty_zero'] = 0;
  $handler->display->display_options['fields']['price']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['price']['set_precision'] = 0;
  $handler->display->display_options['fields']['price']['precision'] = '0';
  $handler->display->display_options['fields']['price']['format_plural'] = 0;
  /* Field: SUM(Ordered product: Quantity) */
  $handler->display->display_options['fields']['qty']['id'] = 'qty';
  $handler->display->display_options['fields']['qty']['table'] = 'uc_order_products';
  $handler->display->display_options['fields']['qty']['field'] = 'qty';
  $handler->display->display_options['fields']['qty']['group_type'] = 'sum';
  $handler->display->display_options['fields']['qty']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['qty']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['qty']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['qty']['alter']['external'] = 0;
  $handler->display->display_options['fields']['qty']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['qty']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['qty']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['qty']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['qty']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['qty']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['qty']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['qty']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['qty']['alter']['html'] = 0;
  $handler->display->display_options['fields']['qty']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['qty']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['qty']['hide_empty'] = 0;
  $handler->display->display_options['fields']['qty']['empty_zero'] = 0;
  $handler->display->display_options['fields']['qty']['hide_alter_empty'] = 1;
  /* Sort criterion: Order: Creation date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'uc_orders';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['granularity'] = 'month';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'uid';
  /* Filter criterion: Order: Order status */
  $handler->display->display_options['filters']['order_status']['id'] = 'order_status';
  $handler->display->display_options['filters']['order_status']['table'] = 'uc_orders';
  $handler->display->display_options['filters']['order_status']['field'] = 'order_status';
  $handler->display->display_options['filters']['order_status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['order_status']['expose']['operator_id'] = 'order_status_op';
  $handler->display->display_options['filters']['order_status']['expose']['label'] = 'Order status';
  $handler->display->display_options['filters']['order_status']['expose']['operator'] = 'order_status_op';
  $handler->display->display_options['filters']['order_status']['expose']['identifier'] = 'order_status';
  $handler->display->display_options['filters']['order_status']['expose']['reduce'] = 0;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['uid']['expose']['reduce'] = 0;
  /* Filter criterion: Order: Creation date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'uc_orders';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Creation date';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['multiple'] = FALSE;
  $handler->display->display_options['filters']['created']['granularity'] = 'month';
  $handler->display->display_options['filters']['created']['year_range'] = '-2:+0';

  /* Display: Page */
  $handler = $view->new_display('page', 'Admin page', 'admin_page');
  $handler->display->display_options['path'] = 'admin/store/reports/sales/photographer';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Sales by Photographer';
  $handler->display->display_options['menu']['description'] = 'Allows to see total sales for photographer monthly';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';

  $export['sales_summary_by_photographer'] = $view;
  return $export;
}