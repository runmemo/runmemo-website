
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
	    var nid = Drupal.settings.product['nid'];
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
	
         var product = Drupal.settings.product;
	 var price = Math.floor(product.price);
         var min_price = Math.floor(product.min_price);
         var max_price = Math.floor(product.max_price);
         var currency_sign = product.currency_sign;
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
				
})(jQuery);
