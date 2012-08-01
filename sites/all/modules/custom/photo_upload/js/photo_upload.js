jQuery(document).ready(function(){
    if(document.getElementById('selected_event_nid') != undefined && document.getElementById('selected_event_nid') != null && document.getElementById('selected_event_nid')!='')
    {
        document.getElementById('selected_event_nid').style.display='none';
        if(document.getElementById('event_select').value != 'All'){
            document.getElementById('upload_section').style.display= 'block';
        }
    }
	
});

/**
 * This function is used for show and hide the upload section when without selecting the event
 */
function select_event_upload(){
    var events=document.getElementById('event_select');
    var selected_event = events.options[events.selectedIndex].value;
    //for get the selected  value from select box to the other zip file upload form hidded text field.because of two form in the single page.so we want to 		pass the selected event name from drag and drop upload form to zip file upload form
    if (selected_event != 'All') {
            document.getElementById('selected_event_nid').value= selected_event;
            document.getElementById('upload_section').style.display= 'block';
    }
    else {
            document.getElementById('upload_section').style.display= 'none';
    }
	
}

/**
 * drag and drop upload validation
 */
function drag_drop_upload_validation() {
  var selected_value=document.getElementById('event_select').value;
  if (selected_value=='All') {
    alert(Drupal.t('Select the event'));
    return false;

  }

  var selected_value=document.getElementById('event_select').value;
  var uploader = jQuery("#edit-file").pluploadQueue();
  uploader.settings.url = Drupal.settings.plupload._default.url+'&event='+selected_value;
	//uploader.settings.unique_names  = false;
	
}

// add custom elements to upload form and
/**
 * Attaches the Plupload behavior to each Plupload form element.
 */

/**
 * Function to generate preview in search results
 */
(function($) {
	Drupal.behaviors.runmemoUploadPage = {
		attach : function(context, settings) {
		
			$('.plupload_droptext').html('<div class="drag_drop_text">Drag and drop your photos here</div><div class="start_upload_text">and click on Start Upload button below</div>');
			
			var uploader = $("#edit-file").pluploadQueue();
		    uploader.bind('UploadProgress', function(up, file) {
		    	if($('#' + file.id + ' .plupload_file_progress').length>0) {
		    		$('#' + file.id + ' .plupload_file_progress').css("width", file.percent + '%');
		    	}
		    	else {
		    		$('#' + file.id +' .plupload_file_name').after(
		    				'<div class="plupload_file_progress_background"><div class="plupload_file_progress"></div></div>');
		    	}
				up.refresh(); // Reposition Flash/Silverlight
			});
                        
                        function UploadPageonSlide( event, ui ) {
                            $(".page-photographer-upload #sell_price_val").val( ui.value );
                            console.debug($(".page-photographer-upload #sell_price_val"));
                            $(".page-photographer-upload #amount").text( "£" + ui.value );
                        }

                        var sell_price = 5; //$( "#sell_price_value" ).val();

                        $(".page-photographer-upload #sell_price").slider({
                                range: "min",
                                value: sell_price,
                                min: 2,
                                max: 10,
                                step: 1,
                                slide: UploadPageonSlide
                        });
                        $(".page-photographer-upload #sell_price_val").val( $( ".page-photographer-upload #sell_price" ).slider( "value" ) );
                        $(".page-photographer-upload #amount").text( "£" + $( ".page-photographer-upload #sell_price" ).slider( "value" ) );
				
		}

	};
        
})(jQuery);


