<?php


/**
 * Override or insert variables into the maintenance page template.
 */
function runmemo_preprocess_maintenance_page(&$vars) {
  // While markup for normal pages is split into page.tpl.php and html.tpl.php,
  // the markup for the maintenance page is all in the single
  // maintenance-page.tpl.php template. So, to have what's done in
  // runmemo_preprocess_html() also happen on the maintenance page, it has to be
  // called here.
  runmemo_preprocess_html($vars);
}

/**
 * Override or insert variables into the html template.
 */
function runmemo_preprocess_html(&$vars) {
  // Toggle fixed or fluid width.
  if (theme_get_setting('runmemo_width') == 'fluid') {
    $vars['classes_array'][] = 'fluid-width';
  }
  if (search_event_has_photos()) {
    $vars['classes_array'][] = 'event-has-photos';
  }
  // Add conditional CSS for IE6.
  drupal_add_css(path_to_theme() . '/fix-ie.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lt IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
}

/**
 * Override or insert variables into the html template.
 */
function runmemo_process_html(&$vars) {
  // Hook into color.module
  if (module_exists('color')) {
    _color_html_alter($vars);
  }
}

/**
 * Override or insert variables into the page template.
 */
function runmemo_preprocess_page(&$vars) {
  // Move secondary tabs into a separate variable.
  $vars['tabs2'] = array(
    '#theme' => 'menu_local_tasks',
    '#secondary' => $vars['tabs']['#secondary'],
  );
  unset($vars['tabs']['#secondary']);

  if (isset($vars['main_menu'])) {
    $vars['primary_nav'] = theme('links__system_main_menu', array(
      'links' => $vars['main_menu'],
      'attributes' => array(
        'class' => array('links', 'inline', 'main-menu'),
      ),
      'heading' => array(
        'text' => t('Main menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
    ));
  }
  else {
    $vars['primary_nav'] = FALSE;
  }
  if (isset($vars['secondary_menu'])) {
    $vars['secondary_nav'] = theme('links__system_secondary_menu', array(
      'links' => $vars['secondary_menu'],
      'attributes' => array(
        'class' => array('links', 'inline', 'secondary-menu'),
      ),
      'heading' => array(
        'text' => t('Secondary menu'),
        'level' => 'h2',
        'class' => array('element-invisible'),
      )
    ));
  }
  else {
    $vars['secondary_nav'] = FALSE;
  }

  // Prepare header.
  $site_fields = array();
  if (!empty($vars['site_name'])) {
    $site_fields[] = $vars['site_name'];
  }
  if (!empty($vars['site_slogan'])) {
    $site_fields[] = $vars['site_slogan'];
  }
  $vars['site_title'] = implode(' ', $site_fields);
  if (!empty($site_fields)) {
    $site_fields[0] = '<span>' . $site_fields[0] . '</span>';
  }
  $vars['site_html'] = implode(' ', $site_fields);

  // Set a variable for the site name title and logo alt attributes text.
  $slogan_text = $vars['site_slogan'];
  $site_name_text = $vars['site_name'];
  $vars['site_name_and_slogan'] = $site_name_text . ' ' . $slogan_text;

  drupal_add_js('jQuery("input[placeholder], textarea[placeholder]").placeholder();',
    array('type' => 'inline', 'scope' => 'footer', 'weight' => 5)
  );
}

/**
 * Override or insert variables into the node template.
 */
function runmemo_preprocess_node(&$vars) {
  $vars['submitted'] = $vars['date'] . ' — ' . $vars['name'];
  
  
}

function runmemo_field__field_photographers__event($variables) {
  
 $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }
  
  $counter = 0;
  foreach ($variables['items'] as $delta => $item) {
    $counter++;
  }

  $output .= '<div class="field-items"><div class="field-item"' . $variables['item_attributes'][$delta] . '>' . $counter . '</div></div>';
  
    // Render the top-level DIV.
  $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  return $output;
   
}

/**
 * 
 */
function runmemo_preprocess_field($variables) {
   // $photographers = $variables['items'];  
  //  print_r($variables);
    // @todo - fix numbe of photographers on event node.
 // 	print_r($photographers);
 //   $vars['photographers'] = $photographers ? count($photographers) : 0;
 // 	drupal_render($vars['photographers']);
}

/**
 * Override or insert variables into the comment template.
 */
function runmemo_preprocess_comment(&$vars) {
  $vars['submitted'] = $vars['created'] . ' — ' . $vars['author'];
}

/**
 * Override or insert variables into the block template.
 */
function runmemo_preprocess_block(&$vars) {
  $vars['title_attributes_array']['class'][] = 'title';
 // $vars['classes_array'][] = 'clearfix';
}

/**
 * Override or insert variables into the page template.
 */
function runmemo_process_page(&$vars) {
  // Hook into color.module
  if (module_exists('color')) {
    _color_page_alter($vars);
  }
}

/**
 * Override or insert variables into the region template.
 */
function runmemo_preprocess_region(&$vars) {
  if ($vars['region'] == 'header') {
    $vars['classes_array'][] = 'clearfix';
  }
}


/**
* Implementation of HOOK_theme().
*/
function runmemo_theme($existing, $type, $theme, $path) {
  
  return array( 
            'uc_cart_checkout_form' => array(
                    'render element' => 'form',
                    'template' => 'uc-cart-checkout-form',
                    'path' => drupal_get_path('theme', 'runmemo'),
                    ),
            
          );
}


/**
 * Override checkout page design.
 */
function runmemo_preprocess_uc_cart_checkout_form(&$variables) {
  
  $billing = $variables['form']['panes']['billing'];
  $customer = $variables['form']['panes']['customer'];
  $payment = $variables['form']['panes']['payment'];
  $submit = $variables['form']['actions'];
  
  foreach( $billing['address']['billing_first_name'] as $key => $val) {
    if( $key == '#title') {
      $billing['address']['billing_first_name'][$key]= t('First name');
    }
  }

  foreach( $billing['address']['billing_last_name'] as $key => $val) {
    if( $key == '#title') {
      $billing['address']['billing_last_name'][$key]= t('Last name');
    }
  }

  foreach( $billing['address']['billing_company'] as $key => $val) {
    if( $key == '#title') {
      $billing['address']['billing_company'][$key]= t('Company');
    }
  }  
  
  foreach( $billing['address']['billing_street1'] as $key => $val) {
    if( $key == '#title') {
      $billing['address']['billing_street1'][$key]= t('Street address');
    }
  }
  
  foreach( $billing['address']['billing_city'] as $key => $val) {
    if( $key == '#title') {
      $billing['address']['billing_city'][$key]= t('City');
    }
  }

  foreach( $billing['address']['billing_zone'] as $key => $val) {
    if( $key == '#title') {
      $billing['address']['billing_zone'][$key]= t('State/Province');
    }
  }
  
  foreach( $billing['address']['billing_country'] as $key => $val) {
    if( $key == '#title') {
      $billing['address']['billing_country'][$key]= t('Country');
    }
  }  
  
  foreach( $billing['address']['billing_postal_code'] as $key => $val) {
    if( $key == '#title') {
      $billing['address']['billing_postal_code'][$key]= t('Postal code');
    }
  }
  
  foreach( $billing['address']['billing_phone'] as $key => $val) {
    if( $key == '#title') {
      $billing['address']['billing_phone'][$key]= t('Phone number');
    }
  }

  foreach( $submit as $key => &$val) {
    if( $key == 'continue' ) {
      $val['#value'] = t('Continue');
    }
  }
  
  
  $variables['billing'] = drupal_render($billing);
  $variables['email'] = $customer['#theme']['primary_email'];
  $variables['customer'] = drupal_render($customer);
  $variables['payment']  = drupal_render_children($payment);
  $variables['submit'] = drupal_render($submit);
  $variables['form_build_id'] = drupal_render($form_build_id);
 
}

// Default function from uc_cart.module.
function runmemo_preprocess_uc_cart_checkout_review(&$variables) {
  
  $cart_items = uc_cart_get_contents();
  $no_of_cart_items = count($cart_items);
  foreach($cart_items as $product => $value){
 
    $photo[] = $value->uc_product_image['und'][0];
    
    //for cost format in the review order page mouse over image 
    $cost = $value->sell_price;
    $cost = number_format($cost, 2, '.', '');
    $cost_arr = explode('.', $cost);
    if($cost_arr['1'] == 00) {
      $price[] = $cost_arr['0'];
    }
    else {
      $price[] = $cost;
    }
  }
 
  $output = '<table class="review-order-img" ><tr>';
  $j = 0;
  for($i=0; $i<$no_of_cart_items; $i++) {
    $j++;
    $output .=  '<td>'. '<div class="views-field-sell-price"><span id="node_cost" style="display:none">&euro;'. $price[$i] . '</span></div>'  .theme("image_formatter", array('item' => $photo[$i], 'image_style' => 'search_thumbnail'));
    $output .= '</td>';
      
    if($j%4 == 0) {
     $output .= '</tr><tr>';
    }
  }
  
  if($no_of_cart_items < 4) {
      for($k=0;$k<(4-$no_of_cart_items);$k++){
        $output .= '<td></td>';
      }
  }
  
  $output .= '</tr></table>';
  $variables['panes']['Cart contents']['0'] =  $output;
  
  return $variables;
  
}
 
/**
 * Themes the sale completion page.
 *
 * @param $variables
 *   
 * @ingroup themeable
 */

function runmemo_preprocess_uc_cart_complete_sale(&$variables) { 
 
 foreach($variables['order']->products as $order=>$image){
    $nid = $image->nid;
    $node = node_load($nid);
    
    $img_uri[] = $node->uc_product_image['und'][0];
    $img_name[] = $node->uc_product_image['und'][0]['filename'];
  }
  
  
  $no_of_image = count($img_uri);
  
  $output = '<div class="order-complete-title">' . t('Your payment is complete, thank you for your order') . '</div><div class="order-complete-preview">';
  $output .= '<div class="order-sale-description">' . t('Click on the preview to open original size image in the new window') . '</div>'; 
  $output .= '<table><tr>';
  $j = 0;
  for($i=0; $i < $no_of_image; $i++) {
    
    $resource = $img_name[$i];
    if(module_exists('s3_store') && function_exists('get_s3_signed_url')) {
      $original_img_url = get_s3_signed_url($resource);
    }
    
    $j++;
    $output .=  '<td><a href="' . $original_img_url .'" target="_blank">' . theme("image_formatter", array('item' => $img_uri[$i], 'image_style' => 'search_thumbnail')) .'</a>';
    $output .= '</td>';
    
        
    if($j%4 == 0) {
     $output .= '</tr><tr>';
    }
  }
  
  if($no_of_image < 4) {
      for($k=0;$k<(4-$no_of_image);$k++){
        $output .= '<td></td>';
      }
  }
  
  $output .= '</tr></table><div style="clear:both;"></div></div>';
  
  $variables['message'] =  $output;
  
  return $variables;
}
 
/**
 * 
 * implements hook_alter for exposed view filters
 */
function runmemo_form_views_exposed_form_alter(&$form, &$form_state) {
  $form['submit']['#value'] = t('Search');
  $form['submit']['#attributes']['class'][] = 'button';
}

/**
 * 
 * Implements hook_html_head_alter
 */
function runmemo_html_head_alter(&$head_elements) {
  // remove a generator tag from the head for Drupal 7
  unset($head_elements['system_meta_generator']);
  
  
}

