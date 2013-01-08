/**
 * Function to generate preview in search results
 */
(function($) {
	Drupal.behaviors.SearchPage = {
		attach : function(context, settings) {
			/*
			$('.page-search-result table.views-view-grid td').each(function() {
				var markup = $(this).html();
				if ($(this).has("div").length == 0) {
					$(this).css("border", "none");
				}
			});
			
			$(document).ready(function() {
				set_preview_area_height();
			});
			*/
     
      var $checkoutButton = $('.proceed_to_cart a');
      var $itemSelectButton = $('#add_to_cart');            

      /**
			 * Shows Add to Cart button
			 */
      $itemSelectButton.ShowAdd = function () {
				 this.removeClass('search-remove-button').addClass('search-add-button');				
			}
     
      /**
			 * Shows Remove from Cart button
			 */
		  $itemSelectButton.ShowRemove = function() {
				this.removeClass('search-add-button').addClass('search-remove-button');
			}
      
      $itemSelectButton.isAdd = function() {
				return this.hasClass('search-add-button');
			}
      
      /**
			 * changes Add/Remove buttons for specified node ID
			 */
			$itemSelectButton.Switch = function() {
        if (this.isAdd()) {
          this.ShowRemove();
        } else {
          this.ShowAdd();
        }
			}

      /**
			 * Click Event for Add to Cart button
			 */
			$itemSelectButton.click(function() {
        var nid = cart.selected;
        var in_cart = cart.Contains(nid);
        if (in_cart) {
          cart.Remove(nid);
          $itemSelectButton.ShowAdd();

        } else {
          cart.Add(nid);
          $itemSelectButton.ShowRemove();
        }

        return false;
      });
          
      var cart = settings.cart;
      
      cart.Initialize = function() {
				uncheck_all_checks_on_page();
				var nid = 0;
				// update checkboxes for items in cart
				for (var i in this.items) {
					nid = this.items[i].nid;
					set_to_checked(nid);
				}	
				set_cart_summary(this);
			}
      
      /**
       * Tells whether product with specified nid is in the cart on the page
       */
      cart.Contains = function(nid) {		
        for (var i in this.items) {
          if(nid == this.items[i].nid)
          {
            return true;
          }
        }		
				return false;
			}
      
      /**
			 * Gets Size of the cart from HTML tags on the page
			 */
			cart.Size = function () {
					this.items.length();
			}
      
      /**
       * Sets specified nid as selected product
       */
      cart.Select = function(nid) {
        this.selected = nid;
        // var temp = new Array();
        if ($('#check_' + nid).hasClass('checked') == true) {
          $itemSelectButton.ShowRemove();
        } else {
          $itemSelectButton.ShowAdd();
        }
        
        // this is a thumbnail that was selected
        var $thumbnail = $('#thumb-' + nid + ' img');
        
        // highlight selected image
        $('img.selected-thumbnail').removeClass('selected-thumbnail').addClass('thumbnail');
        $thumbnail.removeClass('thumbnail').addClass('selected-thumbnail');

        // change the price of the photo
        var price_txt = $('span#item-price-' + nid).text();
        $('span#photo_cost label').text(price_txt);
        // change the autor text
        var author_txt = $("span#item-author-" + nid).text();
        $("span#photo_author label").text(author_txt);

        var url = $thumbnail.attr('src').replace('search_thumbnail', 'search_preview');
        // show new preview image
        $preview.setImageUrl(url);
        
      }
    
			/**
       * Adds item to the cart
       * @param nid - nid of the product that will be added to the cart 
       */
			cart.Add = function(nid) {
				set_to_pending(nid);
			
        if(!('items' in this)) {
          this.items=[];
        }
          
				// add item to browser cart
				var match = this.Contains(nid);
				if (!match) {
					item = new Object();
					item.nid = nid;
					item.price = price_of_item(nid);
					item.qty = 1;
					this.items.push(item);
				} 
				
				// ajax call to add item to ubercart
				$.ajax({
					// type : "POST",
					url : settings.basePath + "ajax/cart_add_item",
					type: "POST",
					data: {nid: nid},
					dataType: 'json',
          cache: false,
					success : function(msg) {
						set_to_checked(nid);
						set_cart_summary(msg);
					},
					error: function(msg) {
						set_error_message(nid, 'Sorry, we could not add item to the cart...');
						console.debug(msg);
					}
				});
			}
      
      /**
			 * Removes item from cart
			 * @param nid id of the item
			 */
			cart.Remove = function(nid) {
				set_to_unchecked(nid);
				set_to_pending(nid);
				
				// remove item from browser cart;
				for (var i in this.items) {
					if (this.items[i].nid == nid) {
						this.items.splice(i, 1);
					}
				}
				
				// remove item from ubercart
				$.ajax({
					url : settings.basePath + "ajax/cart_remove_item",
					type: "POST",
					data: {nid: nid},
					dataType: 'json',
				    cache: false,
				    success : function(msg) {
						set_to_unchecked(nid);
						set_cart_summary(msg);
					},
					error : function(msg) {
						set_error_message(nid, 'Sorry, we could not remove item from the cart...');
					}
				});
			}
      
      var $preload = []; // containsr for preloaded preview images
      // preloads preview images to make interface faster
      function preload_previews() {
        
        $('.image-thumbnail img').each(function() {
          var $img = $(this);         
          var imgsrc = $img.attr('src');
          var url = imgsrc.replace('search_thumbnail', 'search_preview');
          $preload.push($('<img />').attr('src', url));
        })
      }
      
      preload_previews();
      
      var $preview = $("#prev_img img"); // preview image element
      
      /**
       * Shows image for the specified url of the file.
       * @param url Url to the file of the preview image
       */
      $preview.setImageUrl = function(url) {
    
        var current_url = this.attr('src');
        if (current_url != url) {
            // fade out old image and fade in the new one
            $preview.animate({opacity: 0.40}, 100, function() {
              $preview.attr('src', url);
              $preview.setHeight();
              $preview.animate({opacity: 1}, 100);              
            });
        }
      }
      
      /**
       * Changes height of the preview area according to the size of the image
       */
      $preview.setHeight = function() {
        var img_height = 0;
				if (this.height() == 0) {
					img_height = 650;
				} else {
          img_height = this.height();
        }				
				var preview_height = 70 + img_height + 2; 
				this.parents('.search-image-preview').height(preview_height);				
			}
			
      cart.Initialize();      
			
			/**
			 * Click Event for the thumbnail image.
			 */
			$('.image-thumbnail img').bind('click', function() {           
						var nid = $(this).parent().attr('title');
						cart.Select(nid);
			});

			
			if ($('.view-search-results .views-view-grid').length == 1) {
				$('.image-thumbnail img').first().click(); // select first image
				// load_selected_products_from_ubercart();
				$('.prev_img').show();
			}
			else { // hide cart details block
				$(".region-sidebar-second .content").hide();
			}

			
 			$('a').click(function(event){
  			if ($(this).hasClass('disabled')) {
					event.preventDefault();
				}
   				
 			});
	
			// Onclick event for checkbox 
			$('.search-checkbox').click(function() {
				var nid = $(this).attr('title');
				switch_check_box(nid);
        if(cart.selected == nid) {
          $itemSelectButton.Switch();
        }
				
			});

		
			// uncheck all checks on the page
			function uncheck_all_checks_on_page() {
				$('.search-checkbox').each(function() {
					var nid = $(this).attr('title');
					set_to_unchecked(nid);	
				});
			}
			
			// pending all checks on the page
			function pending_all_checks_on_page() {
				$('.search-checkbox.checked').each(function() {
					var nid = $(this).attr('title');
					set_to_pending(nid);	
				});
			}
	

			// Action check event
			function on_product_check(nid) {

				// @todo

			}

			/**
			 * Set number of selected items in the cart details section of the
			 * page
			 * 
			 * @param items number of items in the cart
			 *           
			 */
			function set_total_items(items) {
				$('.search-summary-photos .placeholder').html(items);
			}

			/**
			 * Sets total price in the cart details section of the page
			 * 
			 * @param price total price of products in the cart
			 *            
			 */
			function set_total_price(price) {
				$(".search-summary-cost .placeholder").text(price);
			}

			/**
			 * Sets the total price in curt summary section
			 */
			function set_cart_summary(data) {
				set_total_items(data.count);
				set_total_price(data.total);
				
				if (data.count > 0) {
					$checkoutButton.removeClass('disabled');
				} else {
					$checkoutButton.addClass('disabled');
				}
			}
      

			/**
			 * Gets the price of the product
			 * 
			 * @param nid
			 *            identifier of the product node
			 * @returns Price of product with specified nid
			 */
			function price_of_item(nid) {
				var price_txt = $('span#item-price-' + nid).html();
				return parseFloat(price_txt); // @todo
			}
			
			function switch_check_box(nid) {
				if ($('#check_' + nid).hasClass('checked')) {
					cart.Remove(nid);
				} else {
					cart.Add(nid);
				}
			}
			
			function set_to_pending(nid) {
				if ( $('#check_'+ nid).children().length == 0 ) {
					$('#check_'+ nid).removeClass('checked');
					$('#check_'+ nid).append('<div class="ajax-pending"></div>');
				}
			}
			
			function set_to_checked(nid) {
				$('#check_'+ nid).empty();
				$('#check_'+ nid).addClass('checked');
				
			}
			
			function set_to_unchecked(nid) {
				$('#check_'+ nid).empty();
				$('#check_'+ nid).removeClass('checked');
			}
      
      
			
			function set_error_message(nid, msg) {
				$('#check_'+ nid + ' .ajax-pending').remove();
				if ($('#check_'+ nid).children().length == 0) {
					$('#check_'+ nid).append('<div class="ajax-error" title = "' + msg + '"></div>');
				}
			}
			
			function get_currency_sign() {
				return $('#currency-sign').html();
			}
						
					
			function clear_cart() {
				// @todo
			}
		
		
			/**
			 * Click event for clear all link
			 */
      $clearAllCheckBox = $('#clear-all');
			$clearAllCheckBox.click(function() {
				pending_all_checks_on_page();
				var base_path = Drupal.settings.basePath;
				$.ajax({
					url : base_path + "ajax/cart_clear",
					type: "POST",
					dataType: 'json',
				  cache: false,
					success : function(msg) {
						cart.items = [];
						set_cart_summary(msg);						
						uncheck_all_checks_on_page();
					},
          error: function(msg) {
            console.log(msg);
          }
				});
				
			});

			/**
			 * Click event for select all link
			 */
      $selectAllCheckbox = $('#select-all')
			$selectAllCheckbox.click(function() {
				$('.search-checkbox').each(function() {
					var nid = $(this).attr('title');
          if(!cart.Contains(nid)) {
            cart.Add(nid);
          }
				});
			});
			
			
			/**
			 * Mouseover Event for thumbnail image that shows the bubble with
			 * price (search results page)
			 */
			$(".page-search-result #block-system-main div.field-content img")
					.mouseover(
							function() {
								var img_cost = $(this).parents("td").find(
										"span.node_cost").html();
								var img_cost_arr = img_cost.split('.');
								if (img_cost_arr['1'] == '00') {
									$(this).parents("td")
											.find("span.node_cost").html(img_cost_arr['0']);
								}

								$(this).parents("td").find("span.node_cost")
										.attr('style', 'display:block!important;');
							}).mouseout(
							function() {
								$(this).parents("td").find("span.node_cost")
										.attr('style', 'display:none!important;');
							});

			/**
			 * Mouseover event for thumbnail image that shows the bubble with
			 * price (review order page)
			 */
			$(".page-cart-checkout-review .order-review-table .review-order-img img")
				.mouseover(
					function() {
						$(this).parent("td").find("span.node_cost")
								.attr('style', 'display:block !important;');
					}).mouseout(
					function() {
						$(this).parent("td").find("span.node_cost")
								.attr('style', 'display:none !important;');
					});

			// change the first tr class name in the review order page
			if ($('.page-cart-checkout-review .content .order-review-table').length > 0) {
				$(
						'.page-cart-checkout-review .content .order-review-table tr:first')
						.removeClass('pane-title-row').addClass('review-order-title');
				$(
						'.page-cart-checkout-review .content .order-review-table tr.review-button-row #uc-cart-checkout-review-form div:first')
						.attr('id', 'review-order-action');
			}      
		

}}})(jQuery);
