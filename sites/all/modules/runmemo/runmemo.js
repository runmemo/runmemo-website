jQuery(document).ready(function()
{
	if(document.getElementById('user-register-form') != undefined && document.getElementById('user-register-form') != null && document.getElementById('user-register-form')!='')
	{
		document.getElementById('paypal_account_id').style.display = "none";
		document.getElementById('paypal_title').style.display = "none";
		document.getElementById('paypal_icon').style.display = "none";
	}
});
function user_photographer()
{
	
	if(document.getElementById('edit-field-select-user-photographer').checked==true)
	{
		document.getElementById('paypal_account_id').style.display = '';
		document.getElementById('paypal_title').style.display = '';
		document.getElementById('paypal_icon').style.display = "block";

	}
	if(document.getElementById('edit-field-select-user-runner').checked==true)
	{
		document.getElementById('paypal_account_id').style.display = "none";
		document.getElementById('paypal_title').style.display = "none";
		document.getElementById('paypal_icon').style.display = "none";
	}
}


//this function calling from amazon_s3.module
//when photographer select the event from select box to change url
function select_event()
{

	var event_name=document.getElementById('event').value;
	var base_path=Drupal.settings.basePath;
	window.location.href=base_path+'admin/structure/amazon-s3/bucket/'+event_name;
}
