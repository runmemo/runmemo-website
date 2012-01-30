<?php

class photographer_upload
{
	/**
	 * Get the event name from taxonomy terms
	 * @return
	 * $event_title return event name,tid array  
	 */
	public function get_event_name()
	{
	
		$event_title=db_query("SELECT name,tid FROM {taxonomy_term_data} WHERE vid='2'");
		return $event_title;
	}

}

