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
 * Add to cart validation in the search result page
 */
function search_result_add_to_cart() {
  return false;
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
   
    $('#block-system-main div.field-content img').bind('click', function(){ 
     var imgsrc = $(this).attr('src'); 
     var replacementurl = imgsrc.replace('thumbnail', 'preview-with-watermark');
     
     //alert(replacementurl);
     $("#preview_image").attr("src",replacementurl);
 
                         
    }); 
   
   
     $("#feedback-form").prepend("<a id='feedback_close'>Close</a>");
     $("#feedback_close").css('cursor', 'pointer');
      
     $(".feedback-link").html('');
     $("#block-feedback-form h2").click(function() {

      $("#block-feedback-form .content").show();
      $("#feedback-form").show();
     });
     $("#feedback_close").click(function() {
         $("#block-feedback-form .content").hide();
         $("#feedback-form").attr('style','display:none;');
     });
     
     if (($("#block-feedback-form")).length > 0 ) {
        
        $("#block-feedback-form .content").hide();
        
      }
    
    /* 
    //for feedback content display
      if (($("#block-feedback-form")).length > 0 ) {
       
        $("#block-feedback-form .content").hide();
        //$("#block-feedback-form h2 span").hide();
        //$(".feedback-link").hide() ;
      }
      /**
      * Collapse or uncollapse the feedback form block.
      */
     
     /*
      Drupal.feedbackFormToggle = function ($block, enable) {
         
        $block.find('form').slideToggle('medium');
        if (enable) {
          $('#feedback-form-toggle', $block).html('');
          $("#block-feedback-form .content").hide();
          
        }
        else {
          $('#feedback-form-toggle', $block).html('');
          $("#block-feedback-form .content").show();
        }
      };
   
      $("#feedback-form").prepend("<a id='feedback_close'>Close</a>");
      $("#feedback_close").css('cursor', 'pointer');
     
     $("#feedback_close").click(function() {
      $("#block-feedback-form .content").hide();
     });
    
   */
   
  }



  };
  
     
})(jQuery);