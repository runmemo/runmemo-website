<?php

/**
 * Implements hook_rules_event_info().
 */
function ubercart_custom_rules_event_info() {
   $events['ubercart_custom_order_abandoned'] = array(
      'label' => t('Order abandoned'),
      'group' => t('Order'),
      'variables' => array(
        'order' => array(
          'type' => 'uc_order',
          'label' => t('Original order'),
        ),
      ),
    );
    return $events;
}