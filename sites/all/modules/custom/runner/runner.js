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
              $(this).html('<label class="label_check" for="'+name_id+'"><input type="checkbox" name="'+name_id+'" value="'+name_id+'" /></label>');
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
      
      
    if($(".page-search-result .error ").length > 0 ) {
        if($(".page-search-result .error ul li").length > 0 ) {
          $(".page-search-result #sidebar-second .block .content").attr('style','top:92px');
          $(".page-search-result .left-corner").attr('style',' min-height: 974px;');
        }
        else {
          $(".page-search-result #sidebar-second .block .content").attr('style','top:62px');
           $(".page-search-result .left-corner").attr('style',' min-height: 944px;');
        }
            
     }
    
   
    if (($("#block-feedback-form")).length > 0 ) {
        
        $("#block-feedback-form .content").hide();
        $("body.page-feedback #block-feedback-form .content").show();
		$("body.page-feedback #block-feedback-form #feedback-form").show();
		var txt_link = parent.window.document.location;
		$("input#edit-url-hidden").val(txt_link);
      }
	 var link_chg = $("div#link-display").text();
    $("#block-feedback-form h2").html('<a class="feedback-link-new" href="'+link_chg+'">link</a>');
	
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
     
	 parent.Drupal.overlay.close();
	
	
	 
      /*$("#feedback-form-toggle").trigger('click');
        
      if($("#feedback-form .error").length > 0 ) {
       $("#feedback-form-toggle").trigger('');
       
     }
     else {
       $("#feedback-form-toggle").trigger('');
     }*/
     
     });
	 
/**
 * Re-collapse the feedback form after every successful form submission.
 */
Drupal.behaviors.feedbackFormSubmit = {
  attach: function (context) {
   
    var $context = $(context);
    if (!$context.is('#feedback-status-message')) {
      return;
    }
    // Collapse the form.
    $('#block-feedback-form .feedback-link').click();
    // Blend out and remove status message.
    window.setTimeout(function () {
      $context.fadeOut('slow', function () {
        $context.remove();
      });
    }, 3000);
	
	parent.Drupal.overlay.close();
  }
};
}
//onload ends here..
};
  
  
  /*Check box design for search results page*/
  
  var d = document;
    var safari = (navigator.userAgent.toLowerCase().indexOf('safari') != -1) ? true : false;
    var gebtn = function(parEl,child) { return parEl.getElementsByTagName(child); };
    onload = function() {
        
        var body = gebtn(d,'body')[0];
        body.className = body.className && body.className != '' ? body.className + ' has-js' : 'has-js';
        
        if (!d.getElementById || !d.createTextNode) return;
        var ls = gebtn(d,'label');
        for (var i = 0; i < ls.length; i++) {
            var l = ls[i];
            if (l.className.indexOf('label_') == -1) continue;
            var inp = gebtn(l,'input')[0];
            if (l.className == 'label_check') {
                l.className = (safari && inp.checked == true || inp.checked) ? 'label_check c_on' : 'label_check c_off';
                l.onclick = check_it;
            };
            if (l.className == 'label_radio') {
                l.className = (safari && inp.checked == true || inp.checked) ? 'label_radio r_on' : 'label_radio r_off';
                l.onclick = turn_radio;
            };
        };
    };
    var check_it = function() {
        var inp = gebtn(this,'input')[0];
        if (this.className == 'label_check c_off' || (!safari && inp.checked)) {
            this.className = 'label_check c_on';
            if (safari) inp.click();
        } else {
            this.className = 'label_check c_off';
            if (safari) inp.click();
        };
    };
    var turn_radio = function() {
        var inp = gebtn(this,'input')[0];
        if (this.className == 'label_radio r_off' || inp.checked) {
            var ls = gebtn(this.parentNode,'label');
            for (var i = 0; i < ls.length; i++) {
                var l = ls[i];
                if (l.className.indexOf('label_radio') == -1)  continue;
                l.className = 'label_radio r_off';
            };
            this.className = 'label_radio r_on';
            if (safari) inp.click();
        } else {
            this.className = 'label_radio r_off';
            if (safari) inp.click();
        };
    };
  /*End Check box design for search results page*/
     
})(jQuery);