<?php
/**
 * @file
 * Contains function that help to work with events
 */

/**
 * Get the event name from content type 'event'
 * @return
 * $event_title return event title,nid array
 */
function get_events($nids = array()) {
  // @todo: replace with field query and give an option to select events from the past only only.
  
  $query = new EntityFieldQuery();
  
  $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'event')
        ->propertyCondition('status', 1, '=');
  if (!empty($nids)) {
    $query->propertyCondition('nid', $nids, '=');
  }
  $result = $query->execute();
  
  global $language;
  $titles = array();
  if (!empty($result['node'])) {
     $nodes = entity_load('node', array_keys($result['node']));
    
     foreach ($nodes as $nid => $node) {
       if (!isset($node->title_field[$language->language])) {
         $lang = $node->language;
       } 
       else {
         $lang = $language->language;
       }
       $title  = $node->title_field[$lang][0]['value'];
       
       $country = 'GB';
       $field_address = field_get_items('node', $node, 'field_address');
       if ($field_address) {
         foreach ($field_address as $address) {
             $country = $address['country'];
             break;         
         } 
       } 
       $currency = country_currency($country);
       $defaults = default_currency_prices($currency);
       $min_price =         get_price_field_value($node, 'min_price', $defaults);
       $max_price =         get_price_field_value($node, 'max_price', $defaults);
       $recommended_price = get_price_field_value($node, 'recommended_price', $defaults);
       $sales_fee =         get_price_field_value($node, 'sales_fee', $defaults);
       $events[$node->nid] = array(
       		'nid' => $node->nid, 
       		'title' => $title,
            'country' => $country,
            'min_price' => $min_price,
            'max_price' => $max_price,
            'recommended_price' => $recommended_price,
            'currency_sign' => currency_api_get_symbol($currency),
            //'sales_fee' => $sales_fee,
       );
     }
     return $events;
  } 
  else { 
    return FALSE;
  }
}

function get_price_field_value($node, $field_name, $defaults) {
  $items = field_get_items('node', $node, 'field_' . $field_name);
  if ($items) {
      $value = $items[0]['value'];       
  }
  else {
    $value = $defaults[$field_name];
  }
  
  // @todo apply conversion rate from event's currency to a currency of the viewer
  
  return $value;
}

/**
 *
 * Gets title fo the event by node id.
 * @param integer $nid - node id of event
 */
function get_event($nid) {
  $nids = array('nid' => $nid);
  $events = get_events($nids);
  if ($events) {
    return $events[$nid];
  }
  return FALSE;
}


/**
 * 
 * Shows whether photographer is already registered for an event
 * @param integer $nid
 * @param integer $uid
 */
function sport_event_is_registered_photographer($nid, $uid) {

  $node = node_load($nid);
  $photographers = field_get_items('node', $node, 'field_photographers');

  if ($photographers) {
    foreach ($photographers as $index => $photographer) {
      if ($photographer['uid'] == $uid) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

/**
 *
 * Add photographer to the event's photographers field
 * @param integer $nid
 * @param integer $uid
 */
function sport_event_register_photographer($nid, $uid) {
  $is_registered = sport_event_is_registered_photographer($nid, $uid);
  if ($is_registered) {
    return FALSE;
  }
  
  $node = node_load($nid);
  if ($node == FALSE) {
    return FALSE;
  }
  $node->field_photographers[$node->language][]['uid'] = $uid;
  node_save($node);
  return TRUE;
}

/**
 *
 * Removes photographer from field_photographer on event node
 * @param integer $nid - event node id
 * @param integer $uid - user id
 * @return
 * 	TRUE if photogrpaher was removed, FALSE 
 */
function sport_event_unregister_photographer($nid, $uid) {
  $node = node_load($nid);
  $photographers = field_get_items('node', $node, 'field_photographers');

  $removed = FALSE;
  if ($photographers) {
    foreach ($photographers as $index => $photographer) {
      if ($photographer['uid'] === $uid) {
        unset($node->field_photographers[$node->language][$index]);
        $removed = TRUE;
      }
    }
  } 
  
  if (!$removed) {
    return FALSE; // user was not in the list of registered photogrpahers
  }
  
  node_save($node);
  return TRUE;
}


function default_currency_prices($currency) {
  
  $defaults = array(
    'GBP' => array('min_price' => 1, 'max_price' => 10, 'recommended_price' => 4, 'sales_fee' => 1, ),
    'RUB' => array('min_price' => 25, 'max_price' => 200, 'recommended_price' => 100, 'sales_fee' => 50, ),
    'EUR' => array('min_price' => 1, 'max_price' => 15, 'recommended_price' => 5, 'sales_fee' => 1, ),
    'USD' => array('min_price' => 1, 'max_price' => 20, 'recommended_price' => 5, 'sales_fee' => 1, ),
  );
  
  return $defaults[$currency];
}