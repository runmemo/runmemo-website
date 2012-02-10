jQuery(document).ready(function(){
	

});

/**
 * onclick function for in the my number text field to hide the default text
 */
function my_number_hide(){
    document.getElementById('runner_number').value='';	
}
function my_number_show(){
    document.getElementById('runner_number').value='My Number';	
}

/**
 * validation for search button field in the home 
 */
function search_validation(){
    var event_name_search = document.getElementById('event_runner').value;
    if(event_name_search == 'select_event'){
      alert("Please select Event");
      return false;
    }

}

/**
 * Get started button validation in the home page
 */
function get_started_validation(){
    var event_name_search_id = document.getElementById('event_runner_sell').value;
    if(event_name_search_id == 'select_event'){
      alert("Please select Event");
      return false;
    }
           
}

/**
 * Search using runner number in the recent event section
 */
function find_recent_event1(){
  var recent_event1_number = document.getElementById('number_recent_event1').value;
  if(recent_event1_number == ''){
      alert("Please enter your number");
      return false;
    }
}