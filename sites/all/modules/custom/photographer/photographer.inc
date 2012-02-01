<?php

class photographer_upload
{
	/**
	 * Get the event name from content type 'event'
	 * @return
	 * $event_title return event title,nid array 
	 */
	public function get_event_name()
	{
	
		$event_title=db_query("SELECT title,nid FROM {node} WHERE type='event'");
		return $event_title;
	}


}

