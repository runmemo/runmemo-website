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
function get_events() {

  $events= db_query('SELECT nid, title FROM {node} WHERE type = :type', array(':type' => 'event'));
  return $events;
}

/**
 *
 * Gets title fo the event by node id.
 * @param integer $nid - node id of event
 */
function get_event($nid) {

  $event = db_query('SELECT nid, title
    					FROM {node} 
    					WHERE nid = :nid', 
  array(':nid' => $nid));
  return $event;

}

/**
 * Get the recent event id
 * @return
 * $event_id recently created event id
 */
function get_recent_event_id($start, $end) {

  $query = new EntityFieldQuery();
  
  $results = $query->entityCondition('entity_type', 'node', '=')
  ->entityCondition('bundle', 'event')
  ->propertyCondition('status', 1, '=')
  ->fieldCondition('field_date', 'value', date('Y-m-d'), '<')
  ->fieldOrderBy('field_date', 'value', 'ASC')
  ->range($start, $end)
  ->execute();
  
  $nodes = node_load_multiple(array_keys($results['node']));
  
  foreach ($nodes as $node) {
    return $node->nid;
  }
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
    foreach($photographers as $index => $photographer) {
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
  if($photographers) {
    foreach($photographers as $index => $photographer) {
      if ($photographer['uid'] === $uid) {
        unset($node->field_photographers[$node->language][$index]);
        $removed = TRUE;
      }
    }
  } 
  
  if(!$removed) {
    return FALSE; // user was not in the list of registered photogrpahers
  }
  
  node_save($node);
  return TRUE;
}