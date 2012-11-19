jQuery(document).ready(function() {

});

/**
 * Function to generate preview in search results
 */
(function($) {
	Drupal.behaviors.runmemoSearchPage = {
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
		
			function set_preview_area_height(img_height) {
				var preview = $("#prev_img img");
				var img_height = preview.height();
				if (img_height == 0) {
					img_height = 650;
				};
				
				var preview_height = 70 + img_height + 2; 
				$('.search-image-preview').height(preview_height);
				
			}
			
			
			/**
			 * Click Event for the thumbnail image.
			 */
			$('.image-thumbnail img').bind('click', function() {

						// highlight selected image
						$('div.field-content img').removeClass('selected-thumbnail').addClass('thumbnail');
						$(this).removeClass('thumbnail').addClass('selected-thumbnail');

						// change the price of the photo
						var price_txt = $(this).parents('td').find('span.node_cost').text();
						$('.page-search-result span#photo_cost label').text(price_txt);
						// change the autor text
						var node_author_txt = $(this).parents("td").find("span.authour_first_name").text();
						$(".page-search-result span#photo_author label").text(node_author_txt);

						var imgsrc = $(this).attr('src');
						var replacement_url = imgsrc.replace('search_thumbnail', 'search_preview');
						
						// preload image
						var image = $('<img />').attr('src', replacement_url);
					
						var preview = $("#prev_img img");
					
						var current_preview_url = preview.attr('src');
						if (current_preview_url != replacement_url) {
								// fade out old image and fade in the new one
								preview.animate({opacity: 0.40}, 200, function() {
								preview.attr('src', replacement_url);
								preview.animate({ opacity: 1 }, 200);
								set_preview_area_height(preview.height());
							});
						}
					
						// # contains the nid 
						// of currently selected product
						var wrap_id1 = $(this).parent().attr('id');
						var exploded = wrap_id1.split('thumb-');
						var new_id = exploded[1];
						$("#cart_hidden").val(new_id);

						// var temp = new Array();
						if ($('#check_' + new_id).hasClass('checked') == true) {
							show_remove_button();
						} else {
							show_add_button();
						}

			});

			
			if ($('.view-search-results .views-view-grid').length == 1) {
				$('.image-thumbnail img').first().click(); // select first image
				load_selected_products_from_ubercart();
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

			if ($('.search-summary-photos .placeholder').length > 0) {
				if ($(
						'.search-summary-photos .placeholder')
						.html() <= 0) {
					// for hide the proceed to checkout link in the search
					// result page
					// when no items in the cart
					hide_proceed_to_checkout();
				}
			}
			
			// Onclick event for checkbox 
			$('.search-checkbox').click(function() {
				var nid = $(this).attr('title');
				switch_check_box(nid);
				switch_add_remove_buttons(nid);
			});

			/**
			 * Tells whether product with specified nid is in the cart on the page
			 */
			function is_product_in_cart(nid) {
				if (window.cart) {
					for (var i in window.cart.items) {
						if(nid == window.cart.items[i].nid)
						{
							return true;
						};
					}
				}
				return false;
			}
			
			function set_cart(data) {
				window.cart = data;				
				uncheck_all_checks_on_page();
				
				var nid = 0;

				// update checkboxes for items in cart
				for (var i in window.cart.items) {
					nid = window.cart.items[i].nid;
					set_to_checked(nid);
				}	
				set_cart_summary(data);
			}
			
			// uncheck all checks on the page
			function uncheck_all_checks_on_page() {
				$('.search-checkbox').each(function() {
					var nid = $(this).attr('title');
					set_to_unchecked(nid);	
				});
			}
			
			// pending all checks on the page
			function pending_all_checks_on_page() {
				$('.search-checkbox').each(function() {
					var nid = $(this).attr('title');
					set_to_pending(nid);	
				});
			}
			
			/**
			 * Gets Size of the cart from HTML tags on the page
			 */
			function size_of_the_cart() {
		
				if(window.cart) {
					return window.cart.items.length;
				}
				else {
					return 0;
				}
			}

			// Action check event
			function on_product_check(nid) {

				// @todo

			}

			/**
			 * Set number of selected items in the cart details section of the
			 * page
			 * 
			 * @param items
			 *            number of items in the cart
			 */
			function set_total_items(items) {
				$('.search-summary-photos .placeholder').html(items);
			}

			/**
			 * Sets total price in the cart details section of the page
			 * 
			 * @param price
			 *            total price of products in the cart
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
				
				if (size_of_the_cart() > 0) {
					show_proceed_to_checkout();
				} else {
					hide_proceed_to_checkout();
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
					remove_from_cart(nid);
				} else {
					add_to_cart(nid);
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
		
			
			function add_to_cart(nid) {
				set_to_pending(nid);
			

				// add item to browser cart
				var match = is_product_in_cart(nid);
				if (!match) {
					item = new Object();
					item.nid = nid;
					item.price = price_of_item(nid);
					item.qty = 1;
					window.cart.items.push(item);
				} 
				
				
				// add item to ubercart
				var base_path = Drupal.settings.basePath;
				$.ajax({
					// type : "POST",
					url : base_path + "ajax/cart_add_item",
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
					}
				});
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
			
			function load_selected_products_from_ubercart() {

				var base_path = Drupal.settings.basePath;

				var event = $('#event_runner option:selected').val();
				var number = $('#runner_number').val();
				
				$.ajax({
					url : base_path + "ajax/cart_list_items",
					type: "POST",
					data: {event: event, number: number},
					dataType: 'json',
				    cache: false,
					success : function(msg) {
						set_cart(msg);
						
						// show add/remove button
						if ($('.search-checkbox').first().hasClass('checked')) {
							show_remove_button();
						} else {
							show_add_button();
						}
					}
				});
			}
					
			function clear_cart() {
				// @todo
			}
			
			/**
			 * Removes item from cart
			 * @param nid id of the item
			 */
			function remove_from_cart(nid) {
				set_to_unchecked(nid);
				set_to_pending(nid);
				
				// remove item from browser cart;
				for (var i in window.cart.items) {
					if (window.cart.items[i].nid == nid) {
						window.cart.items.splice(i, 1);
					}
				}
				
				// remove item from ubercart
				var base_path = Drupal.settings.basePath;
				$.ajax({
					url : base_path + "ajax/cart_remove_item",
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

			/**
			 * Shows proceed to checkout button
			 */
			function show_proceed_to_checkout() {
				$('#search-result-cart .proceed_to_cart a').removeClass('disabled');
			}
			/**
			 * Hides proceed to checkout button
			 */
			function hide_proceed_to_checkout() {
				$('#search-result-cart .proceed_to_cart a').addClass('disabled');
				
			}

			/**
			 * changes Add/Remove buttons for specified node ID
			 * 
			 * @param nid
			 */
			function switch_add_remove_buttons(nid) {
				// change add to cart button
				var cart_hidden = $('#cart_hidden').val();
				var buttonclass = $('#add_to_cart').attr('class');
				var currentclass = buttonclass.split('form-submit ');

				if (nid == cart_hidden) {

					if (currentclass[1] == 'search-add-button') {
						show_remove_button();
					} else {
						show_add_button();
					}
				}
			}

			/**
			 * Shows Add to Cart button
			 */
			function show_add_button() {
				$('#add_to_cart').removeClass('search-remove-button').addClass('search-add-button');				
			}

			/**
			 * Shows Remove from Cart button
			 */
			function show_remove_button() {
				$('#add_to_cart').removeClass('search-add-button').addClass('search-remove-button');
			}

			/**
			 * Click Event for Add to Cart button
			 */
			$('#add_to_cart').click(function() {

								var base_path = Drupal.settings.basePath;
								var nid = $('#cart_hidden').val();
								var in_cart = is_product_in_cart(nid);
								if (in_cart) {
									remove_from_cart(nid);
									show_add_button();

								} else {
									add_to_cart(nid);
									show_remove_button();
								}

								return false;
							});

			/**
			 * Click event for clear all link
			 */
			$('#clear-all').click(function() {
				pending_all_checks_on_page();
				var base_path = Drupal.settings.basePath;
				$.ajax({
					url : base_path + "ajax/cart_clear",
					type: "POST",
					dataType: 'json',
				    cache: false,
					success : function(msg) {
						window.cart.items = [];
						set_cart_summary(msg);						
						uncheck_all_checks_on_page();
					}
				});
				
			});

			/**
			 * Click event for select all link
			 */
			$('#select-all').click(function() {
				$('.search-checkbox').each(function() {
					var nid = $(this).attr('title');
					add_to_cart(nid);
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
			$(
				".page-cart-checkout-review .order-review-table .review-order-img img")
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
			
		}

	};

	/* End Check box design for search results page */

})(jQuery);
