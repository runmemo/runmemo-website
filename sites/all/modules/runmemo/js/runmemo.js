jQuery(document).ready(function()
{
	
        if(document.getElementById('selected_event_zip')!=null)
	document.getElementById('selected_event_zip').style.display='none';
	document.getElementById('selected_event_drag').style.display='none';


});


//this function calling from amazon_s3.module
//when photographer select the event from select box 
function select_event_upload()
{
	var selected_event=document.getElementById('event_select').value;


	//for get the selected the value from select box to the other zip file upload form hidded text field.because of two form in the single page.so we want to 		pass the selected event name from drag and drop upload form to zip file upload form

	if(selected_event!='select_event')
	{
		document.getElementById('selected_event_zip').value= selected_event;
		document.getElementById('selected_event_drag').value= selected_event;
		document.getElementById('upload_section').style.display= 'block';
	}
	else
	{

		document.getElementById('upload_section').style.display= 'none';

	}
	
}







//for runner select the event
function select_event_runner()
{

	var event_name=document.getElementById('event_runner').value;
	var base_path=Drupal.settings.basePath;
	if(event_name!='select_event')
		window.location.href=base_path+'runner/'+event_name;
	else
		window.location.href=base_path+'runner';
}

//validation for search button field in the home 
function search_validation()
{

	var event_name_search=document.getElementById('event_runner').value;
	if(event_name_search=='select_event')
		return false;
}



//draog and drop upload validation
function drag_drop_upload_validation()
{
	var selected_value=document.getElementById('event_select').value;

	if(selected_value=='select_event')
	{
		alert('Select the event');
		return false;
	
	}



}




//onclick function for in the my number text field to hide the default text
function my_number_hide()
{
	document.getElementById('runner_number').value='';	
}
function my_number_show()
{
	document.getElementById('runner_number').value='My Number';	
}

//for sell the photos in the runner side
function select_event_runner_sell()
{


}

