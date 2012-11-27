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
 * drag and drop upload validation
 */
function drag_drop_upload_validation() {
  var selected_value=document.getElementById('event_select').value;
  if (selected_value=='All') {
    alert(Drupal.t('Select the event'));
    return false;
  }

  var eventid = document.getElementById('event_select').value;
  var price = document.getElementById('price_val').value;
  var uploader = jQuery("#edit-file").pluploadQueue();
  uploader.settings.url = Drupal.settings.plupload._default.url+'&event='+eventid +'&price='+price;
  
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
		
			$('.plupload_droptext').html('<div class="drag_drop_text">Drag and drop your photos here</div><div class="start_upload_text">and click on Start Upload button below<br />(<i>works in Chrome, Firefox and Safari</i>).</div>');
			
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
                        
	        function UploadPageonSlide(event, ui) {
	            $(".page-photographer-upload #price_val").val( ui.value );
	            var event_id = selected_event_id();
	            var currency_sign = "£"
	            if (event_id != 'All') {
	            	var event = Drupal.settings.photo_upload[event_id];
	            	currency_sign = event.currency_sign;
	            }
	            $(".page-photographer-upload #amount").text(currency_sign + ui.value );
	        }
	        
	        function selected_event_id() {
	          var events = document.getElementById('event_select');
		      var event_id = events.options[events.selectedIndex].value;
		      return event_id;
	        }
	        
	        var price = $(".page-photographer-upload #price_val").val();
	
	        var slider = $(".page-photographer-upload #price").slider({
	                range: "min",
	                value: price,
	                min: 1,
	                max: 10,
	                step: 1,
	                slide: UploadPageonSlide
	        });
	        $(".page-photographer-upload #price_val").val( $( ".page-photographer-upload #price" ).slider( "value" ) );
	        $(".page-photographer-upload #amount").text( "£" + $( ".page-photographer-upload #price" ).slider( "value" ) );
				
	        $("#event_select").change(function() {event_selected()});
	        /**
	    	 * This function is used for show and hide the upload section when without selecting the event
	    	 */
	    	function event_selected(){
	    	   
	    	    var event_id = selected_event_id();
	    	    //for get the selected  value from select box to the other zip file upload form hidded text field.because of two form in the single page.so we want to 		pass the selected event name from drag and drop upload form to zip file upload form
	    	    if (event_id != 'All') {
	    	            document.getElementById('selected_event_nid').value = event_id;
	    	            document.getElementById('upload_section').style.display= 'block';
	    	            
	    	            var event = Drupal.settings.photo_upload[event_id];
	    	            var min_price = Math.floor(event.min_price);
	    	            var max_price = Math.floor(event.max_price);
	    	            var recommended_price = Math.floor(event.recommended_price) 
	    	         
	    	            slider.slider("option", "min", min_price);
		    	        slider.slider("option", "max", max_price);
		    	        slider.slider("value", recommended_price);
		    	        if (max_price - min_price > 100) {
		    	        	slider.slider("option", "step", 10);
		    	        } 
		    	        else if (max_price - min_price > 50) {
		    	        	slider.slider("option", "step", 5);
		    	        }
		    	        else {
		    	        	slider.slider("option", "step", 1);
		    	        }
		    	      
	    	            $(".page-photographer-upload #price_val").val(slider.slider( "value" ) );
	    		        $(".page-photographer-upload #amount").text( event.currency_sign + slider.slider( "value" ) );
	    		        $("#price-container").show();
	    	    }
	    	    else {
	    	            document.getElementById('upload_section').style.display= 'none';
	    	            $("#price-container").hide();
		    	     
	    	    }
	    	}
		}

	};
        
})(jQuery);


