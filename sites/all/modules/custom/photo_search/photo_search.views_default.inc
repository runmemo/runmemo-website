<?php
/**
 * @file
 */

/**
 * Implements hook_views_default_views().
 */
function photo_search_views_default_views() {

  $export = array();

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
  $handler->display->display_options['cache']['output_lifespan'] = '300';
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
  /* Footer: Global: PHP */
  $handler->display->display_options['footer']['php']['id'] = 'php';
  $handler->display->display_options['footer']['php']['table'] = 'views';
  $handler->display->display_options['footer']['php']['field'] = 'php';
  $handler->display->display_options['footer']['php']['empty'] = FALSE;
  $handler->display->display_options['footer']['php']['php_output'] = '<?php
$cart_ids = array();
foreach (uc_cart_get_contents() as $item) {
    $cart_ids[]=$item->nid ;
  }
if(!empty($cart_ids)) {
$cart_items = implode(",", $cart_ids);
}
else {
$cart_items = \'\';
}
?>
<div id="cart_hidden_nids" style="display:none"><input type="text" name="cart_text"  value="<?php if($cart_items != \'\'){
echo $cart_items;}?>" />
</div>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] =
  	'<div class="no-result-found">
		It looks like not all photos have been uploaded to the website. 
		Come back in a few days, or email us at info@runmemo.com with your number in the subject line and we will keep you updated.
	</div>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
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
  $handler->display->display_options['fields']['sell_price']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['external'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sell_price']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sell_price']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sell_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sell_price']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['sell_price']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sell_price']['empty_zero'] = 0;
  $handler->display->display_options['fields']['sell_price']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['sell_price']['set_precision'] = 0;
  $handler->display->display_options['fields']['sell_price']['precision'] = '0';
  $handler->display->display_options['fields']['sell_price']['format_plural'] = 0;
  $handler->display->display_options['fields']['sell_price']['format'] = 'numeric';
  
  /* Field: Content: Image */
  $handler->display->display_options['fields']['uc_product_image']['id'] = 'uc_product_image';
  $handler->display->display_options['fields']['uc_product_image']['table'] = 'field_data_uc_product_image';
  $handler->display->display_options['fields']['uc_product_image']['field'] = 'uc_product_image';
  $handler->display->display_options['fields']['uc_product_image']['label'] = '';
  $handler->display->display_options['fields']['uc_product_image']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['uc_product_image']['alter']['text'] = '<div id="thumb-[nid]">[uc_product_image]</div>';
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
  $handler->display->display_options['fields']['uc_product_image']['settings'] = array('image_style' => 'search_thumbnail', 'image_link' => '',);
  $handler->display->display_options['fields']['uc_product_image']['group_rows'] = 1;
  $handler->display->display_options['fields']['uc_product_image']['delta_offset'] = '0';
  $handler->display->display_options['fields']['uc_product_image']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['field_api_classes'] = 0;
  
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['check_box']['id'] = 'check_box';
  $handler->display->display_options['fields']['check_box']['table'] = 'node';
  $handler->display->display_options['fields']['check_box']['field'] = 'nid';
  $handler->display->display_options['fields']['check_box']['label'] = '';
  $handler->display->display_options['fields']['check_box']['alter']['alter_text'] = 1;
  $handler->display->display_options['fields']['check_box']['alter']['text'] = '<span class="node_check" ></span><span class="node_check_id" style="display:none;">[check_box]</span>';
  $handler->display->display_options['fields']['check_box']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['check_box']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['check_box']['alter']['external'] = 0;
  $handler->display->display_options['fields']['check_box']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['check_box']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['check_box']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['check_box']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['check_box']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['check_box']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['check_box']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['check_box']['alter']['html'] = 0;
  $handler->display->display_options['fields']['check_box']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['check_box']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['check_box']['hide_empty'] = 0;
  $handler->display->display_options['fields']['check_box']['empty_zero'] = 0;
  $handler->display->display_options['fields']['check_box']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['check_box']['link_to_node'] = 0;
  
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
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_runner_number_value']['id'] = 'field_runner_number_value';
  $handler->display->display_options['arguments']['field_runner_number_value']['table'] = 'field_data_field_runner_number';
  $handler->display->display_options['arguments']['field_runner_number_value']['field'] = 'field_runner_number_value';
  $handler->display->display_options['arguments']['field_runner_number_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_runner_number_value']['summary']['format'] = 'default_summary';
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
  /* Contextual filter: Content: ocr_numbers (ocr_numbers) */
  $handler->display->display_options['arguments']['ocr_numbers_value']['id'] = 'ocr_numbers_value';
  $handler->display->display_options['arguments']['ocr_numbers_value']['table'] = 'field_data_ocr_numbers';
  $handler->display->display_options['arguments']['ocr_numbers_value']['field'] = 'ocr_numbers_value';
  $handler->display->display_options['arguments']['ocr_numbers_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['ocr_numbers_value']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['ocr_numbers_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['ocr_numbers_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['ocr_numbers_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['ocr_numbers_value']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['ocr_numbers_value']['not'] = 0;

  $handler->display->display_options['path'] = 'search-result/%/%';

  $export['search_results'] = $view;
  return $export;
}