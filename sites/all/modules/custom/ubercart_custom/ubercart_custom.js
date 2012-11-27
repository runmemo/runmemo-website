
/**
 * jQuery Behaviors for Product Node page
 */
(function($) {
	Drupal.behaviors.sliderfield = {
		attach : function(context, settings) {

	  function onSlide(event, ui) {
	      $( ".node-type-product #amount" ).text( currency_sign + ui.value );
	  }
	
	  function onPriceChange( event, ui ) {
	    var price = $("#price").slider( "value" );
	    var base_path = Drupal.settings.basePath;
	    var nid = $('.node-type-product #product_id').val();
	    //define php info and make ajax call
	    $.ajax({
	        url : base_path + "ajax/change_price",
	        type: "POST",
	        data: {nid: nid, price: price},
	        dataType: 'json',
	        cache: false,
	        success : function(msg) {              
                  if (msg.success) {
                    $( "#product-nice-message-container" ).text("Price was changed to " + currency_sign + ui.value);
                  }
	        }
	    }); 
            
	  }
	
	 var price = Math.floor($( ".node-type-product #price_val" ).val());
         var min_price = Math.floor($( ".node-type-product #min_price" ).val());
         var max_price = Math.floor($( ".node-type-product #max_price" ).val());
         var currency_sign = $( ".node-type-product #currency_sign" ).val();
         var step = 1;
         if (max_price - min_price > 100) {
            step = 10;
         } 
         else if (max_price - min_price > 50) {
            step = 5;
         }        
	 
	 $(".node-type-product #price").slider({
	          range: "min",
	          value: price,
	          min: min_price,
	          max: max_price,
	          step: step,
	          slide: onSlide,
	          change: onPriceChange
	  }); 
	
	  $(".node-type-product #amount").text( currency_sign + $(".edit-slider").slider( "value" ));
	
	
	  }
	};
	
	Drupal.behaviors.runmemoCheckoutPage = {
			attach : function(context, settings) {
				
				$('.remove-cart-item').click(function(event){
					var nid = $(this).attr('id');
	  				
	  				hide_item(nid);
	  				remove_from_cart(nid);
	  				
				
				});
				/**
				 * Removes item from cart and updates order summary on success
				 * 
				 * @param nid - Node id of the item that will be removed from cart
				 */
				function remove_from_cart(nid) {
					var base_path = Drupal.settings.basePath;
					// remove item from ubercart
					$.ajax({
						// type : "POST",
						url : base_path + "cart_remove_item?nid=" + nid,
						//dataType: 'json',
						success : function(msg) {
							set_checkout_summary(msg);
						}
					});
				}
				
				/**
				 * Sets page elements to values from ajax call response
				 * @param response_json
				 */
				function set_checkout_summary(response_json) {
					var response = jQuery.parseJSON(response_json)
					if (response.success) {
						$('#order-subtotal').html(response.subtotal);
						$('#order-items').html(response.items);
					}
					else {
						console.debug('Ajax call failed :' + response.message)
					}
				}
				
				function hide_item(nid) {
					console.debug('Removing div - ' + '#thumb-' + nid);
					$('#thumb-' + nid).remove();					
				}
				
		}
	}
				
})(jQuery);
