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

  $event_id = db_query_range(
  	"SELECT nid FROM {node}
  	 WHERE type = :type 
	 ORDER BY nid DESC", $start, $end, array(':type' => 'event'))->fetchField();

  return $event_id;
}

/**
 * 
 * Add photographer to the event's photographers field
 * @param integer $nid
 * @param integer $uid
 */
function sport_event_register_photographer($nid, $uid) {
    $node = node_load($nid);  
    $node->field_photographers[$node->language][]['value'] = $uid;
    node_save($node);
}

function sport_event_unregister_photographer($nid, $uid) {
  
}