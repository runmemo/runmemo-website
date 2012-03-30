jQuery(document).ready(function(){
     	
});



/**
 * Function to generate preview in search results
 */
(function ($) {
      
  Drupal.behaviors.runmemo = { 
       
     attach: function (context,settings) {  
    
    
    
      if($.browser.msie == true) { 
         
         $('#event_select_chzn .chzn-drop .chzn-results li').click(function() {
         $('.page-photographer .plupload .plupload_content1').html("");
         $('.page-photographer .plupload .plupload_content1').append('<ul class="plupload_filelist1" id="edit-file_filelist"></ul>');
         $('.page-photographer .plupload .plupload_content1 ul').append('<li class="plupload_droptext"><div class="drag_drop_text"><h2>Drag and Drop your photos here</h2></div><div class="start_upload_text">and click on Start Upload button bellow</div></li>');
       });
      }
      
    
    
      $('#block-system-main table.views-view-grid td').each(function(){
              var markup = $(this).html();

              if ($(this).has("div").length == 0) {
                      $(this).css("border", "none");
              }

      });
      if ($('.page-search-result #block-system-main table.views-view-grid').length == 1) { 
        var initial_img = $('#block-system-main table.views-view-grid tr.row-first td.col-first img').attr('src');
        //for highlight the thumbnail image related to the preview image
        $('#block-system-main table.views-view-grid tr.row-first td.col-first img').attr('style','border: 1px solid green;');
        
        var initial_preview = initial_img.replace('thumbnail', 'preview-with-watermark');
        
        $("#prev_img").html('<img src="'+initial_preview+'" />');

        var initial_cost = $('#block-system-main table.views-view-grid tr.row-first td.col-first #node_cost').text();
        $(".page-search-result span#photo_cost label").text(initial_cost);

        var initial_authour_name = $('#block-system-main table.views-view-grid tr.row-first td.col-first #authour_first_name').text();
        $(".page-search-result span#photo_author label").text(initial_authour_name);
        //change the addtocart hidden value.
		var wrap_id = $("#block-system-main table.views-view-grid tr.row-first td.col-first img").parent().attr('id');
		var exploded = wrap_id.split('thumb-');
		var new_id =  exploded[1];
		$("#cart_hidden").val(new_id) ; 
		
		// Add/remove functionality based on the cart contents
		var cart_contents = new Array();
        var cart_str = $('.view-footer #cart_hidden_nids input').val();
        
        //var temp = new Array();
        cart_contents = cart_str.split(",");
        
        if(jQuery.inArray(new_id, cart_contents) == -1) {
         $('.page-search-result #search-result-cart .form-submit').removeClass('remove_cart');
		$('.page-search-result #search-result-cart .form-submit').addClass('add_cart');
		  
		  
        }
		else{
		
		   $('.page-search-result #search-result-cart .form-submit').removeClass('add_cart');
		   $('.page-search-result #search-result-cart .form-submit').addClass('remove_cart');

		}
      }
      
      else {
        $(".page-search-result #sidebar-second .content").hide();
      }
      
      
      $('.page-search-result #block-system-main div.node_check').each(function(){
        var name_id = $(this).parent().children('span').text();
        var checked_products_nids = new Array();
        var str = $('.view-footer #cart_hidden_nids input').val();
        
        //var temp = new Array();
        checked_products_nids = str.split(",");
        
        if(jQuery.inArray(name_id, checked_products_nids) == -1) {
          $(this).html('<label class="label_check" for="'+name_id+'" id="check_'+name_id+'"><input type="checkbox" name="id_'+name_id+'" id="'+name_id+'" value="'+name_id+'" class="img_check"/></label>');

        }
        else {
          $(this).html('<label class="label_check c_on" for="'+name_id+'" id="check_'+name_id+'"><input type="checkbox" name="id_'+name_id+'" id="'+name_id+'" value="'+name_id+'" checked="checked" class="img_check"/></label>');
        }
          
       
        
        
      });
      
      
      if ($('.page-search-result #block-system-main table.views-view-grid').length == 1) { 
        var base_path = Drupal.settings.basePath;
        $.ajax({
                  type: "POST",
                  url: base_path + "cart_add_remove",
                  success: function(msg){
                    var msg_arr = msg.split("|");
                    var no_of_items = msg_arr['0'];
                    var total_cost = msg_arr['1'];
                    $('.summary_selected_photos .placeholder').html(no_of_items);
                    $(".summary_cost .placeholder").html(total_cost);
                    if(no_of_items != 0) {
                     $('.page-search-result .content #search-result-cart .proceed_to_cart a').attr('style','display:block');
                    }
                  }
        });
        
      }
      
      
      
      //runner number in the find section for front page
      if($(" #runner_number ").length > 0 ) {
        if(($(" #runner_number ").val() == '')) {
          $(" #runner_number ").val("My Number");
        
        }
      }
      
      $(" #runner_number ").click(function() {
       
        if($(" #runner_number ").val() == 'My Number') {
          $(" #runner_number ").val(""); 
        }
      });
      
      
      $("#runner_number ").blur(function() {
        if(($(" #runner_number ").val() == 'My Number') || ($(" #runner_number ").val() == ''))
          $(" #runner_number ").val("My Number"); 
      });
      
      
      //recent event 1 'My Number' text blur functionality 
      
      if($(" #number_recent_event1").length > 0 ) {
        if(($(" #number_recent_event1 ").val() == '')) {
          $(" #number_recent_event1 ").val("My Number");
        
        }
      }
      
      $(" #number_recent_event1 ").click(function() {
       
        if($(" #number_recent_event1 ").val() == 'My Number') {
          $(" #number_recent_event1 ").val(""); 
        }
      });
      
      
      $("#number_recent_event1 ").blur(function() {
        if(($(" #number_recent_event1 ").val() == 'My Number') || ($(" #number_recent_event1 ").val() == ''))
          $(" #number_recent_event1 ").val("My Number"); 
      });
      
      
      //recent event 2 'My Number' text blur functionality 
      
      if($(" #number_recent_event2").length > 0 ) {
        if(($(" #number_recent_event2 ").val() == '')) {
          $(" #number_recent_event2 ").val("My Number");
        
        }
      }
      
      $(" #number_recent_event2 ").click(function() {
       
        if($(" #number_recent_event2 ").val() == 'My Number') {
          $(" #number_recent_event2 ").val(""); 
        }
      });
      
      
      $("#number_recent_event2 ").blur(function() {
        if(($(" #number_recent_event2 ").val() == 'My Number') || ($(" #number_recent_event2 ").val() == ''))
          $(" #number_recent_event2 ").val("My Number"); 
      });
      
      //message for adding and removing cart
      //$(".page-search-result #center").prepend('<div class="cart_msg" style="display:none"></div>');

      //for remove the set message when adding items in the cart 
     if($('.messages a').length>0) {
       
       if($('.messages a').html() == 'your shopping cart') {
         $('.messages').attr('style','display:none');
       }
     }
     
     if($('.page-search-result #search-result-cart .summary_selected_photos .placeholder').length > 0) {
          if($('.page-search-result #search-result-cart .summary_selected_photos .placeholder').html() <= 0) {
            //for hide the proceed to checkout link in the search result page when no items in the cart
            $('.page-search-result .content #search-result-cart .proceed_to_cart a').attr('style','display:none');
          }
        }
      //for add to cart functionality when check the checkbox in the search result page
      //store this nids in the array
       var checked_products_nids = new Array();
       $('div .node_check input').click(function() {

          var class_name = $(this).parent('label').attr('class');
          if(class_name == 'label_check c_on'){
            $(this).parent('label').removeClass('label_check c_on').addClass('label_check');
          }
          else {
            $(this).parent('label').removeClass('label_check').addClass('label_check c_on');
          }

          
          var base_path = Drupal.settings.basePath;
          var checked_id = $(this).val();
                $.ajax({
                  type: "POST",
                  url: base_path + "cart_add_remove?nid="+checked_id,
                  success: function(msg){

                    var msg_arr = msg.split("|");
                    var op = msg_arr['0'];
                    var cost = msg_arr['1'];
                    if(op == 1){
                      cart_add(cost,checked_id);
                      


                    //for display the message when user add the item in to the cart
                    /*
                    $('.cart_msg').html('Item added to your shopping cart');
                    $('.cart_msg').show();
                    $('.cart_msg').delay(10000).fadeOut();
                      */


                    $('#check_'+checked_id).attr('class','label_check c_on');
                    //$('.page-search-result #search-result-cart .form-submit').removeClass('add_cart');
                    //$('.page-search-result #search-result-cart .form-submit').addClass('remove_cart');

                    }
                    else {
                    cart_remove(cost,checked_id);
                    

                    /*
                    $('.cart_msg').html('Item removed from your shopping cart');
                    $('.cart_msg').show();
                    $('.cart_msg').delay(10000).fadeOut();
                      */

                    $('#check_'+checked_id).attr('class','label_check');
                    //$('.page-search-result #search-result-cart .form-submit').removeClass('remove_cart');
                    // $('.page-search-result #search-result-cart .form-submit').addClass('add_cart');
                    }

                  }
              });
              //change add to cart button
              var cart_hidden  = $('#cart_hidden').val();
              var buttonclass  = $('#add_to_cart').attr('class');
              var currentclass = buttonclass.split('form-submit ');

              if(checked_id == cart_hidden){

                if(currentclass[1] == 'add_cart'){
                  $('.page-search-result #search-result-cart .form-submit').removeClass('add_cart');
                  $('.page-search-result #search-result-cart .form-submit').addClass('remove_cart');

                }
                else{
                  $('.page-search-result #search-result-cart .form-submit').removeClass('remove_cart');
                  $('.page-search-result #search-result-cart .form-submit').addClass('add_cart');
                }
              }
        
       });
       
       
       //cart add functionality
       function cart_add(cost,checked_id)  {
        //changing no of photos
        var no_of_photo = $(".summary_selected_photos .placeholder").html();
        no_of_photo = parseInt(no_of_photo) + parseInt(1);
        $(".summary_selected_photos .placeholder").html(no_of_photo);
        //changing total cost of the added photos
        var total_cost = $(".summary_cost .placeholder").html();
        total_cost = parseInt(total_cost) + parseInt(cost);
        $(".summary_cost .placeholder").html(total_cost);
        
        //For changing default cart items
       $(".cart-block-summary-items .num-items").html(no_of_photo);
        
        //for changing default cart cost
        $(".cart-block-summary-total .uc-price").html('£' + total_cost);
                
        //for display the proceed to checkout link in the search result page
        $('.page-search-result .content #search-result-cart .proceed_to_cart a').attr('style','display:block');
        
        //for add the nid in the views hidden field
          var checked_products_nids = new Array();
          var str = $('.view-footer #cart_hidden_nids input').val();
          checked_products_nids = str.split(",");
          if(jQuery.inArray(checked_id, checked_products_nids) == -1) {
            checked_products_nids.push(checked_id);
            $('.view-footer #cart_hidden_nids input').val(checked_products_nids);

          }
       }
       
       //cart remove functionality 
       function cart_remove(cost,checked_id)  {
         //changing no of photos
        var no_of_photo = $(".summary_selected_photos .placeholder").html();
        no_of_photo = parseInt(no_of_photo) - parseInt(1);
        //for hide the proceed to checkout link in the search result page when no items in the cart
        if(no_of_photo <= 0) {
          $('.page-search-result .content #search-result-cart .proceed_to_cart a').attr('style','display:none');
        }
        
        $(".summary_selected_photos .placeholder").html(no_of_photo);
        //changing total cost of the added photos
        var total_cost = $(".summary_cost .placeholder").html();
        total_cost = parseInt(total_cost) - parseInt(cost);
        $(".summary_cost .placeholder").html(total_cost);
        
        //For changing default cart items
        $(".cart-block-summary-items .num-items").html(no_of_photo);
        
        //for changing default cart cost
        $(".cart-block-summary-total .uc-price").html('£' + total_cost);
        
        //for add the nid in the views hidden field
          var checked_products_nids = new Array();
          var str = $('.view-footer #cart_hidden_nids input').val();
          checked_products_nids = str.split(",");
          checked_products_nids = jQuery.grep(checked_products_nids, function(value) {
                                              return value != checked_id;
                                              });
          $('.view-footer #cart_hidden_nids input').val(checked_products_nids);
        
       }
      // addtocart button functionality
         $('#add_to_cart').click(function() {
         
         var base_path = Drupal.settings.basePath;
         var checked_id = $('#cart_hidden').val();
		 
		 
            $.ajax({
              type: "POST",
              url: base_path + "cart_add_remove?nid="+checked_id,
              success: function(msg){
                //console.log(msg);
                var msg_arr = msg.split("|");
                var op = msg_arr['0'];
                var cost = msg_arr['1'];
                if(op == 1){
                  cart_add(cost,checked_id);
                  /*
                    $('.cart_msg').html('Item added to your shopping cart');
                    $('.cart_msg').show();
                    $('.cart_msg').delay(10000).fadeOut();
                  */
		
                    $('#check_'+checked_id).attr('class','label_check c_on');
                     $('.page-search-result #search-result-cart .form-submit').removeClass('add_cart');
                     $('.page-search-result #search-result-cart .form-submit').addClass('remove_cart');
                }
                else {
                  cart_remove(cost,checked_id);
                  /*
                  $('.cart_msg').html('Item removed from your shopping cart');
                  $('.cart_msg').show();
                  $('.cart_msg').delay(10000).fadeOut();
                  */
                  
                  $('#check_'+checked_id).attr('class','label_check');
                  $('.page-search-result #search-result-cart .form-submit').removeClass('remove_cart');
                  $('.page-search-result #search-result-cart .form-submit').addClass('add_cart');
				 
                }
              
              }
          });
          return false;
       });
         
         
      
      $('.page-search-result #block-system-main div.field-content img').bind('click', function() { 
	 //for highlight the thumbnail image related to the preview image
        $('.page-search-result #block-system-main div.field-content img').attr('style','border: 1px solid #E9E9E9;'); 
        $(this).attr('style','border: 1px solid green;');
        
        var imgsrc = $(this).attr('src');	
        var price_txt = $(this).parents("td").find("span#node_cost").text();
        $(".page-search-result span#photo_cost label").text(price_txt);

        var node_author_txt = $(this).parents("td").find("span#authour_first_name").text();
        $(".page-search-result span#photo_author label").text(node_author_txt);

        var replacementurl = imgsrc.replace('thumbnail', 'preview-with-watermark');

        $("#prev_img").html('<img src="'+replacementurl+'" />');
        
        //change the addtocart button id
        var wrap_id1 = $(this).parent().attr('id');
        var exploded = wrap_id1.split('thumb-');
        var new_id =  exploded[1];
        $("#cart_hidden").val(new_id) ;
        
        // Add/remove functionality based on the cart contents
        var cart_contents = new Array();
        var cart_str = $('.view-footer #cart_hidden_nids input').val();
        
        //var temp = new Array();
        if($('#'+new_id).attr('checked') == true){
		
          $('.page-search-result #search-result-cart .form-submit').removeClass('add_cart');
          $('.page-search-result #search-result-cart .form-submit').addClass('remove_cart');
		}
		else{
		
          $('.page-search-result #search-result-cart .form-submit').removeClass('remove_cart');
		  $('.page-search-result #search-result-cart .form-submit').addClass('add_cart');
		}
        if(jQuery.inArray(new_id, cart_contents) == -1) {
		
			
        }
        else{
		

        }

      });
      
      //mouseover cost bubble for search result page
      $(".page-search-result #block-system-main div.field-content img").mouseover(function() {        
        $(this).parents("td").find("span#node_cost").attr('style','display:block !important;');   
      }).mouseout(function(){
       $(this).parents("td").find("span#node_cost").attr('style','display:none !important;');
      });
     
      
   
    if (($("#block-feedback-form")).length > 0 ) {

      $("#block-feedback-form .content").hide();
      $("body.page-feedback #block-feedback-form .content").show();
      $("body.page-feedback #block-feedback-form #feedback-form").show();
      var txt_link = parent.window.document.location;
      $("input#edit-url-hidden").val(txt_link);
    }
	 var link_chg = $("div#link-display").text();
    $("#block-feedback-form h2").html('<a class="feedback-link-new" href="'+link_chg+'"></a>');
	
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


  };
  


  
  /*Check box design for search results page*/
 /*
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
           //$(this).parents("td").find("span#node_cost").attr('style','display:block !important;');   
           if (safari) inp.click();
        } 
       else {
              this.className = 'label_check c_off';
            //$(this).parents("td").find("span#node_cost").attr('style','display:none !important;');
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
*/
  /*End Check box design for search results page*/
     
})(jQuery);

