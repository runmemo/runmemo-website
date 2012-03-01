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
   
    var event_name_search = document.getElementById('runner_number').value;
    if(event_name_search == ''){
      alert("Please enter your number");
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
      if ($('.page-search-result #block-system-main table.views-view-grid').length == 1) { 
              var initial_img = $('#block-system-main table.views-view-grid tr.row-first td.col-first img').attr('src');	
              var initial_preview = initial_img.replace('thumbnail', 'preview-with-watermark');
              //alert(replacementurl);
              $("#prev_img").html('<img src="'+initial_preview+'" />');

              var initial_cost = $('#block-system-main table.views-view-grid tr.row-first td.col-first #node_cost').text();
              $(".page-search-result span#photo_cost label").text(initial_cost);
              
              var initial_authour_name = $('#block-system-main table.views-view-grid tr.row-first td.col-first #authour_first_name').text();
              $(".page-search-result span#photo_author label").text(initial_authour_name);
      }
      
      else {
        $(".page-search-result #sidebar-second .content").hide();
      }



      $('div.node_check').each(function(){
              var name_id = $(this).parent().children('span').text();
              $(this).html('<input type="checkbox" name="'+name_id+'" value="'+name_id+'" />');
      });
      $('#block-system-main div.field-content img').bind('click', function(){ 
              var imgsrc = $(this).attr('src');	
                var price_txt = $(this).parents("td").find("span#node_cost").text();
                $(".page-search-result span#photo_cost label").text(price_txt);
                
                var node_author_txt = $(this).parents("td").find("span#authour_first_name").text();
                $(".page-search-result span#photo_author label").text(node_author_txt);
                
              var replacementurl = imgsrc.replace('thumbnail', 'preview-with-watermark');

              //alert(replacementurl);
              $("#prev_img").html('<img src="'+replacementurl+'" />');


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
	 
	 $("div.form-item-field-category-und label").each(function(){
		if ($(this).text() == 'Category *') {
			$(this).hide();
		}
	 });
  }



  };
  
  
  
     
})(jQuery);