jQuery(document).ready(function(){
	

});

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
 * Search using runner number in the recent event section
 */
function find_recent_event1(){
  var recent_event1_number = document.getElementById('number_recent_event1').value;
  if(recent_event1_number == ''){
      alert("Please enter your number");
      return false;
    }
}


/**
 * Search using runner number in the recent event2 section
 */
function find_recent_event2(){
  var recent_event2_number = document.getElementById('number_recent_event2').value;
  if(recent_event2_number == ''){
      alert("Please enter your number");
      return false;
    }
}


/**
 * Function to generate preview in search results
 */


(function ($) {
		   
		
		
		Drupal.behaviors.runmemo = { 
       
	    attach: function (context,settings) {
		
			    $('#block-system-main table.views-view-grid td').each(function(){
					var markup = $(this).html();
					
					if ($(this).has("div").length == 0) {
						$(this).css("border", "none");
					}
					
				});
				$('div.node_check').each(function(){
					var name_id = $(this).parent().children('span').text();
					$(this).html('<input type="checkbox" name="'+name_id+'" value="'+name_id+'" />');
				});
				$('#block-system-main div.field-content img').bind('click', function(){ 
					var imgsrc = $(this).attr('src');	
					var replacementurl = imgsrc.replace('thumbnail', 'preview-with-watermark');
					
					//alert(replacementurl);
					$("#preview_image").attr("src",replacementurl);
	
																								 
				});	
			
			
		}



		};
		
		   
})(jQuery);
