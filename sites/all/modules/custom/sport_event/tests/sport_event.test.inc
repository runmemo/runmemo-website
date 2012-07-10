<?php


class sport_event_node_creator {
  
  public static function getNewEventNode () {
      // Create new event node to use for product node
    $event = new stdClass();
    $event->language = LANGUAGE_NONE;
    $event->field_pricing[$event->language]['0']['value'] = 5;
    $event->title = 'Test Event';
    $event->type = 'event';
    $event->status = 1;
    $event = node_submit($event); // Prepare node for a submit
    node_save($event); // After this call we'll get a nid
    return $event;
  }
  
}