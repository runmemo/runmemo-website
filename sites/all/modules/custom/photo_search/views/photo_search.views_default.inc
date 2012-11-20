<?php
/**
 * @file
 */

/**
 * Implements hook_views_default_views().
 */
function photo_search_views_default_views() {

  $views = array();

  
/**
 * =============================================================================
 * 1. Search results view
 * =============================================================================
 */
  
  $view = new view;
  $view->name = 'search_results';
  $view->description = 'Results showing photos for selected event and bib number';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Search results';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search result';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan'] = '-1';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = 0;
  $handler->display->display_options['row_options']['default_field_elements'] = 1;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = 
    "<div id='select-all' class='search-select-all'>select all</div>
     <div id='clear-all' class='search-remove-all'>clear all</div>";
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 0;
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['label'] = 'Preview';
  $handler->display->display_options['footer']['php']['empty'] = FALSE;
  $handler->display->display_options['footer']['php']['php_output'] =
  '<?php  
  	$uri = $view->result[0]->_field_data["nid"]["entity"]->uc_product_image["und"][0]["uri"];
	
  	print render(photo_search_preview_area($uri));
   ?>';
  /* No results behavior: Global: PHP */
  $handler->display->display_options['empty']['php']['id'] = 'php';
  $handler->display->display_options['empty']['php']['table'] = 'views';
  $handler->display->display_options['empty']['php']['field'] = 'php';
  $handler->display->display_options['empty']['php']['empty'] = FALSE;
  $handler->display->display_options['empty']['php']['php_output'] =
  '<?php print render(drupal_get_form("photo_search_request_form")); ?>';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = 0;
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
  $handler->display->display_options['fields']['nid']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['nid']['alter']['html'] = 0;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['nid']['hide_empty'] = 0;
  $handler->display->display_options['fields']['nid']['empty_zero'] = 0;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['nid']['link_to_node'] = 0;
  /* Field: Product: Sell price */
  $handler->display->display_options['fields']['sell_price']['id'] = 'sell_price';
  $handler->display->display_options['fields']['sell_price']['table'] = 'uc_products';
  $handler->display->display_options['fields']['sell_price']['field'] = 'sell_price';
  $handler->display->display_options['fields']['sell_price']['label'] = '';
  $handler->display->display_options['fields']['sell_price']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['sell_price']['alter']['text'] = '<span id="item-price-[nid]" class="node_cost" style="display:none;">[sell_price]</span>';
  $handler->display->display_options['fields']['sell_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sell_price']['precision'] = '0';
  $handler->display->display_options['fields']['sell_price']['convert'] = 1;

  /* Field: Content: Image */
  $handler->display->display_options['fields']['uc_product_image']['id'] = 'uc_product_image';
  $handler->display->display_options['fields']['uc_product_image']['table'] = 'field_data_uc_product_image';
  $handler->display->display_options['fields']['uc_product_image']['field'] = 'uc_product_image';
  $handler->display->display_options['fields']['uc_product_image']['label'] = '';
  $handler->display->display_options['fields']['uc_product_image']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['uc_product_image']['alter']['text'] = 
  		'<div id="thumb-[nid]" class="image-thumbnail">[uc_product_image]</div>
  		 <div title="[nid]" id="check_[nid]" class="search-checkbox"></div>';
  $handler->display->display_options['fields']['uc_product_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uc_product_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uc_product_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uc_product_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uc_product_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uc_product_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['uc_product_image']['settings'] = array('image_style' => 'search_thumbnail', 'image_link' => '', );
  $handler->display->display_options['fields']['uc_product_image']['group_rows'] = 1;
  $handler->display->display_options['fields']['uc_product_image']['delta_offset'] = '0';
  $handler->display->display_options['fields']['uc_product_image']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['field_api_classes'] = 0;

  /* Field: User: First Name */

  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['text'] = '<span class="authour_first_name" style="display:none;">[field_first_name]</span>';
  $handler->display->display_options['fields']['field_first_name']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_first_name']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_first_name']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_first_name']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_first_name']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_first_name']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_first_name']['field_api_classes'] = 0;
  /* Sort criterion: OCR Probability */
  $handler->display->display_options['sorts']['field_ocr_numbers_probability']['id'] = 'field_ocr_numbers_probability';
  $handler->display->display_options['sorts']['field_ocr_numbers_probability']['table'] = 'field_data_field_ocr_numbers';
  $handler->display->display_options['sorts']['field_ocr_numbers_probability']['field'] = 'field_ocr_numbers_probability';
  $handler->display->display_options['sorts']['field_ocr_numbers_probability']['ui_name'] = 'OCR Probability';
  $handler->display->display_options['sorts']['field_ocr_numbers_probability']['order'] = 'DESC';
  /* Contextual filter: Content: Event Name */
  $handler->display->display_options['arguments']['field_event_reference_nid']['id'] = 'field_event_reference_nid';
  $handler->display->display_options['arguments']['field_event_reference_nid']['table'] = 'field_data_field_event_reference';
  $handler->display->display_options['arguments']['field_event_reference_nid']['field'] = 'field_event_reference_nid';
  $handler->display->display_options['arguments']['field_event_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_event_reference_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_event_reference_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_event_reference_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_event_reference_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_event_reference_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_event_reference_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_event_reference_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_event_reference_nid']['not'] = 0;
  /* Contextual filter: Content: OCR Numbers */
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['id'] = 'field_ocr_numbers_value';
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['table'] = 'field_data_field_ocr_numbers';
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['field'] = 'field_ocr_numbers_value';
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['not'] = 0;
  
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 0;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Default Page', 'page');
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Event Name (field_event_reference) */
  $handler->display->display_options['arguments']['field_event_reference_nid']['id'] = 'field_event_reference_nid';
  $handler->display->display_options['arguments']['field_event_reference_nid']['table'] = 'field_data_field_event_reference';
  $handler->display->display_options['arguments']['field_event_reference_nid']['field'] = 'field_event_reference_nid';
  $handler->display->display_options['arguments']['field_event_reference_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_event_reference_nid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_event_reference_nid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_event_reference_nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_event_reference_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_event_reference_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_event_reference_nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_event_reference_nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_event_reference_nid']['not'] = 0;
  /* Contextual filter: Content: Runner Numbers (field_ocr_numbers) */
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['id'] = 'field_ocr_numbers_value';
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['table'] = 'field_data_field_ocr_numbers';
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['field'] = 'field_ocr_numbers_value';
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_ocr_numbers_value']['not'] = 0;

  $handler->display->display_options['path'] = 'search-result/%/%';

  $views[$view->name] = $view;
  
/**
 * =============================================================================
 * 2. List of photo requests
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
  /* Field: Photo Requests: Performed On */
  $handler->display->display_options['fields']['performed']['id'] = 'performed';
  $handler->display->display_options['fields']['performed']['table'] = 'photo_requests';
  $handler->display->display_options['fields']['performed']['field'] = 'performed';
  $handler->display->display_options['fields']['performed']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['performed']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['performed']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['performed']['alter']['external'] = 0;
  $handler->display->display_options['fields']['performed']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['performed']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['performed']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['performed']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['performed']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['performed']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['performed']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['performed']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['performed']['alter']['html'] = 0;
  $handler->display->display_options['fields']['performed']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['performed']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['performed']['hide_empty'] = 0;
  $handler->display->display_options['fields']['performed']['empty_zero'] = 0;
  $handler->display->display_options['fields']['performed']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['performed']['date_format'] = 'short';
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

  return $views;
}