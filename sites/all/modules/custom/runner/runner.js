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
      if ($('#block-system-main table.views-view-grid td.col-first img').length == 1) {
              var initial_img = $('#block-system-main table.views-view-grid td.col2 img').attr('src');	
              var initial_preview=initial_img.replace('thumbnail', 'preview-with-watermark');
              /*alert(replacementurl);*/
              $("#preview_image").attr("src",initial_preview);

      }



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
    
    
   
    if (($("#block-feedback-form")).length > 0 ) {
        
        $("#block-feedback-form .content").hide();
        
      }
    
     Drupal.feedbackFormToggle = function ($block, enable) {
      $block.find('form').slideToggle('medium');
      if (enable) {
        $('#feedback-form-toggle', $block).html('[ + ]');
        $("#block-feedback-form .content").hide();
         $("#feedback-form").attr('style','display:none;');
        
      }
      else {
        $('#feedback-form-toggle', $block).html('[ &minus; ]');
        $("#block-feedback-form .content").show();
         $("#feedback-form").attr('style','display:block;');
         
      }
    };
    
     if($("#feedback-form .error").length > 0 ) {
         
         $("#block-feedback-form .content").show();
         $("#feedback-form").attr('style','display:block;');
         
     }
         
   
   
   $("#fb_close_link").click(function() {
     
      $("#feedback-form-toggle").trigger('click');
        
      if($("#feedback-form .error").length > 0 ) {
       $("#feedback-form-toggle").trigger('');
       
     }
     else {
       $("#feedback-form-toggle").trigger('');
     }
     
     });
  }



  };
  
  
  
     
})(jQuery);