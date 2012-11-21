<?php

/**
 * @file
 * Views handler: Product price field.
 */

/**
 * Returns a formatted price value to display in the View.
 */
class uc_currency_handler_field_price extends uc_product_handler_field_price {

  /**
   * Overrides views_handler::option_definition().
   */
  function option_definition() {
    $options = parent::option_definition();

    $options['convert'] = array('default' => 0);

    return $options;
  }
  
  /**
   * Overrides views_handler::options_form().
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    
    $options = $this->options;
    
    $form['convert'] = array (
      '#type' => 'checkbox',
      '#title' => t('Convert currency'),
      '#default_value' => $options['convert'],
      '#description' => t('If checked, value will be converted from the currency of the product to currency of current session.'),
    );
    
    if (isset($form['format']['#dependency'])) {
      $form['format']['#dependency'] += array('checkbox:convert[convert]' => array(0));
      $form['format']['#dependency_count'] = count($form['format']['#dependency']);
    } 
    else {
      $form['format']['#dependency'] = array('checkbox[convert]' => array(0));
    }
  }

  /**
   * Overrides views_handler_field::render().
   */
  function render($values) {
    if ($this->options['convert']) {
      // currency on the product node
      print_nice($values);
      $currency = $values->field_field_currency[0]['raw']['value'];
      $currency = $currency != NULL ? $currency : default_currency_code(); 
      // value on the node
      $value = $this->get_value($values);
      
      //amount in the currency of the session
      $session_currency = current_currency_code();
      $converted_value = currency_api_convert($currency, $session_currency, $value);
      $converted_amount = $converted_value['value'];
      
      // format amount and append currency symbol
      $output = currency_api_get_symbol($session_currency) . number_format($converted_amount, 2); 
      return $output;
    }
    
    if ($this->options['format'] == 'numeric' || $this->options['format'] == 'uc_price') {
        return parent::render($values);
    }
  }
}
