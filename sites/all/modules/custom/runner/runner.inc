<?php

class runner_search{
  /**
    * Get the event name from content type 'event'
    * @return
    * $event_title return event title,nid array 
    */
  public function get_event_name(){

    $event_title = db_query("SELECT title,nid FROM {node} WHERE type = :type",array(':type' => 'event'));
    return $event_title;
  }

}

class runner_number_search{
  /**
   * Get the recent event id 
   * @return
   * $event_id recently created event id
   */
  public function get_recent_event_id(){

    $event_id = db_query("SELECT MAX(nid) as nid FROM {node} WHERE type = :type",array(':type' => 'event'))->fetchField();
    return $event_id;
  }
  
  /**
   * Get the recent event2 id 
   * @return
   * $event_id recently created event id
   */
  public function get_recent_event2_id(){

    $recent_event_id = db_query("SELECT MAX(nid) as nid FROM {node} WHERE type = :type",array(':type' => 'event'))->fetchField();
    
    $next_recent_event_id = db_query("SELECT MAX(nid) as nid FROM {node} WHERE type = :type AND nid != :nid",array(':type' => 'event',':nid' => $recent_event_id))->fetchField();
    
    return $next_recent_event_id;
  }
  
}