jQuery(document).ready(function()
{
	

});

//Onclick function for in the my number text field to hide the default text
function my_number_hide()
{
	document.getElementById('runner_number').value='';	
}
function my_number_show()
{
	document.getElementById('runner_number').value='My Number';	
}

//for Sell the photos in the runner side
function select_event_runner_sell()
{


}


//Validation for search button field in the home 
function search_validation()
{

	var event_name_search=document.getElementById('event_runner').value;
	if(event_name_search=='select_event')
		return false;
}

