jQuery(document).ready(function(){
      
});


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
      
      /*
    if($(".page-search-result .error").length > 0 ) {
         
         $(".page-search-result #sidebar-second .block .content").attr('style','top:62px');
         
     }*/
    
   
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