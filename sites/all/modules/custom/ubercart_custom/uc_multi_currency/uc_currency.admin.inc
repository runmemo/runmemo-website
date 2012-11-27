<?php

/**
 * @file
 * Ubercart currency admin configuration page
 */

/**
 * Tmplements hook_form().
 */
function uc_currency_settings_form($form, $form_state) {


  $default_currency_code = variable_get('uc_currency_base', 'none');

  $currencies_arr = unserialize(variable_get('uc_currency_convert'));

  $form['currency_base'] = array(
    '#type' => 'textfield',
    '#title' => 'Base Currency ',
    '#description' => 'Enter here your three character <a href="http://en.wikipedia.org/wiki/ISO_4217#Active_codes">ISO 4217</a> currency code. (separate with comma for multiple currencies)',
    '#value' => variable_get('uc_currency_base', UC_CURRENCY_DEFAULT_CURRENCY),
  );

  $form['currencies_convert'] = array(
    '#type' => 'textfield',
    '#title' => 'Allowed Currencies',
    '#description' => 'Enter here your three character <a href="http://en.wikipedia.org/wiki/ISO_4217#Active_codes">ISO 4217</a> currency code. (separate with comma for multiple currencies)',
    '#value' => implode(', ', (array) $currencies_arr),
    '#attributes' => array('onchange' => 'this.form.submit();'),
  );

  $options = array(
    UC_CURRENCY_RATE_AUTO => 'Automatic Rate Conversion (Rate From <a href="http://finance.yahoo.com/currency-converter/#from=USD;to=EUR;amt=1">Yahoo Finance</a>)',
    UC_CURRENCY_RATE_MANUAL => 'Manual Rate',
  );

  $form['currencies_converter_type'] = array(
    '#type' => 'radios',
    '#title' => 'Choose convertion type',
    '#default_value' => variable_get('uc_currency_converter_type', UC_CURRENCY_RATE_AUTO),
    '#options' => $options,
    '#attributes' => array('onchange' => 'this.form.submit();'),
  );

  if (variable_get('uc_currency_converter_type') == UC_CURRENCY_RATE_MANUAL) {

    $form['allowed_code_values'] = array(
      '#type' => 'fieldset',
      '#title' => 'Manual Rate Values',
    );

    $currencies_rate = unserialize(variable_get('uc_currency_rates', array()));

    if (!empty($currencies_rate)) {
      foreach ($currencies_arr as $item) {

        $value = isset($currencies_rate[$item]) ? $currencies_rate[$item] : '';

        $form['allowed_code_values'][$item] = array(
          '#type' => 'textfield',
          '#title' => check_plain($item) . ' rate to ' . check_plain($default_currency_code) . ':',
          '#size' => '10',
          '#value' => $currencies_rate[$item],
        );
      }
    }
  }


  $options = array(
    UC_CURRENCY_SELECT => 'Select List',
    UC_CURRENCY_RADIOS => 'Radio Buttons',
  );

  $form['currencies_form_type'] = array(
    '#type' => 'radios',
    '#title' => 'Choose switcher type',
    '#default_value' => variable_get('uc_currency_form_type', UC_CURRENCY_SELECT),
    '#options' => $options,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Save',
  );

  return $form;
}

/**
 * Implements uc_currency_settings_form().
 */
function uc_currency_settings_form_submit(&$form, $form_state) {

  $input = $form_state['input'];

  $convert_currencies_tmp = explode(', ', $input['currencies_convert']);

  if (is_array($convert_currencies_tmp)) {
    foreach ($convert_currencies_tmp as $item) {
      $convert_currencies[$item] = $item;
    }
  }
  else {
    $convert_currencies[$convert_currencies_tmp] = $convert_currencies_tmp;
  }

  foreach ($convert_currencies as $item) {
    $currencies_rate[$item] = $input[$item];
  }

  variable_set('uc_currency_convert', serialize($convert_currencies));

  variable_set('uc_currency_rates', serialize($currencies_rate));

  variable_set('uc_currency_form_type', $input['currencies_form_type']);


  variable_set('uc_currency_base', $input['currency_base']);
  variable_set('uc_currency_code', $input['currency_base']);
  variable_set('uc_currency_sign', currency_api_get_symbol($input['currency_base']));

  variable_set('uc_currency_converter_type', $input['currencies_converter_type']);

  drupal_set_message(t('Currency configurations saved'), 'status');
}
