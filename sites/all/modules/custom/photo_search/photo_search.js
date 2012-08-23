jQuery(document).ready(function() {

});

/**
 * Function to generate preview in search results
 */
(function($) {
	Drupal.behaviors.runmemoSearchPage = {

		attach : function(context, settings) {

			$('#block-system-main table.views-view-grid td').each(function() {
				var markup = $(this).html();

				if ($(this).has("div").length == 0) {
					$(this).css("border", "none");
				}

			});

			if ($('.page-search-result #block-system-main table.views-view-grid').length == 1) {
				var initial_img = $('#block-system-main table.views-view-grid tr.row-first td.col-first img').attr('src');
				// for highlight the thumbnail image related to the preview
				// image
				$('#block-system-main table.views-view-grid tr.row-first td.col-first img').addClass('selected-thumbnail');

				var initial_preview = initial_img.replace('search_thumbnail', 'search_preview');

				$("#prev_img").html('<img src="' + initial_preview + '" />');

				var initial_cost = get_currency_sign() + $('#block-system-main table.views-view-grid tr.row-first td.col-first .node_cost').text();

				$("span#photo_cost label").text(initial_cost);

				var initial_authour_name = $(
						'#block-system-main table.views-view-grid tr.row-first td.col-first .authour_first_name')
						.text();
				$('.page-search-result span#photo_author label').text(
						initial_authour_name);
				// change the add to cart hidden value.
				var wrap_id = $(
						"#block-system-main table.views-view-grid tr.row-first td.col-first img")
						.parent().attr('id');
				var exploded = wrap_id.split('thumb-');
				var nid = exploded[1];
				$("#cart_hidden").val(nid);

				// Add/remove functionality based on the cart contents
				var cart_contents = new Array();
				var cart_str = $('.view-footer #cart_hidden_nids input').val();

				// var temp = new Array();
				cart_contents = cart_str.split(",");

				if (jQuery.inArray(nid, cart_contents) == -1) {
					show_add_button();

				} else {
					show_remove_button();
				}
			}

			else { // hide cart details block
				$(".region-sidebar-second .content").hide();
			}

			
 			$('a').click(function(event){
  				if ($(this).hasClass('disabled')) {
					event.preventDefault();
				}
   				
 			});
			

			// onload ajax calling in the search result page
			if ($('.page-search-result #block-system-main table.views-view-grid').length == 1) {
				load_selected_products_from_ubercart();
			}

			$('span.node_check').each(
				function() {
						var nid = $(this).parent().children('span').text();
						$(this).html(
						'<label class="label_check" for="'+ nid + '" id="check_'+ nid 
							+ '"><input type="checkbox" name="id_' + nid 
							+ '" id="' + nid + '" value="'+ nid
							+ '" class="img_check"/></label>');
							});

			// message for adding and removing cart
			// $(".page-search-result #center").prepend('<div class="cart_msg"
			// style="display:none"></div>');

			if ($('.page-search-result #search-result-cart .summary_selected_photos .placeholder').length > 0) {
				if ($(
						'.page-search-result #search-result-cart .summary_selected_photos .placeholder')
						.html() <= 0) {
					// for hide the proceed to checkout link in the search
					// result page
					// when no items in the cart
					hide_proceed_to_checkout();
				}
			}
			// for add to cart functionality when check the checkbox in the
			// search
			// result page
			// store this nids in the array
			var checked_products_nids = new Array();
			$('span.node_check input').click(
							function() {
								var nid = $(this).val();
								switch_check_box(nid);
								switch_add_remove_buttons(nid);
							});


		

			/**
			 * Tells whether product with specified nid is in the cart from HTML
			 * tags on the page
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
			
			function set_cart(cart_json) {
				window.cart = jQuery.parseJSON(cart_json);
				console.debug(cart_json);
				console.debug(window.cart);
				
				uncheck_all_checks_on_page();
				
				var nid = 0;
				// update checkboxes for items in cart
				for (var i in window.cart.items) {
					nid = window.cart.items[i].nid;
					set_to_checked(nid);
				}				

				set_cart_summary();
			}
			
			// uncheck all checks on the page
			function uncheck_all_checks_on_page() {
				$('span.node_check input').each(function() {
					var nid = $(this).val();
					set_to_unchecked(nid);	
				});
			}
			/**
			 * Gets Size of the cart from HTML tags on the page
			 */
			function size_of_the_cart() {
				if(window.cart.items) {
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
				$('.summary_selected_photos .placeholder').html(items);
			}

			/**
			 * Sets total price in the cart details section of the page
			 * 
			 * @param price
			 *            total price of products in the cart
			 */
			function set_total_price(price) {
				$("span.summary_cost span.placeholder").text(price);
			}

			/**
			 * Sets the total price in curt summary section
			 */
			function set_cart_summary() {
				var total_price = 0;
				var price = 0;

				for (var i in window.cart.items) {
					price = parseFloat(window.cart.items[i].price);
					total_price = total_price + price;
				}		
	
				set_total_items(size_of_the_cart());
				set_total_price(total_price);
				
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
				if ($('#check_' + nid).hasClass('c_on')) {
					remove_from_cart(nid);
				} else {
					add_to_cart(nid);
				}
			}
			
			function set_to_checked(nid) {
				$('#check_' + nid).addClass('c_on');
				$('span.node_check #'+ nid).attr('checked', true);
			}
			
			function set_to_unchecked(nid) {
				$('#check_' + nid).removeClass('c_on');
				$('span.node_check #'+ nid).attr('checked', false);
			
				
				
			}
		
			
			function add_to_cart(nid) {
				set_to_checked(nid);
				

				// add item to browser cart
				var match = is_product_in_cart(nid);
				if (!match) {
					item = new Object();
					item.nid = nid;
					item.price = price_of_item(nid);
					item.qty = 1;
					window.cart.items.push(item);
				} 
				
				set_cart_summary();
				
				// add item to ubercart
				var base_path = Drupal.settings.basePath;
				$.ajax({
					// type : "POST",
					url : base_path + "cart_add_item?nid=" + nid,
					success : function(msg) {
					//	console.debug(msg);
					}
				});
			}
			
			function get_currency_sign() {
				return $('#currency-sign').html();
			}
			
			function load_selected_products_from_ubercart() {

				var base_path = Drupal.settings.basePath;

				$.ajax({
					// type : "POST",
					url : base_path + "cart_list_items",
					success : function(msg) {
						set_cart(msg);
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
				
				// remove item from browser cart;
				for (var i in window.cart.items) {
					if (window.cart.items[i].nid == nid) {
						window.cart.items.splice(i, 1);
					}
				}
				
				set_cart_summary();
				// remove item from ubercart
				var base_path = Drupal.settings.basePath;
				$.ajax({
					// type : "POST",
					url : base_path + "cart_remove_item?nid=" + nid,
					success : function(msg) {
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

					if (currentclass[1] == 'add_cart') {
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
				$('#add_to_cart').removeClass('remove_cart').addClass('add_cart');				
			}

			/**
			 * Shows Remove from Cart button
			 */
			function show_remove_button() {
				$('#add_to_cart').removeClass('add_cart').addClass('remove_cart');
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
				uncheck_all_checks_on_page();
				
				console.debug('clear all - click');
				
				window.cart.items = [];
				
				set_cart_summary();
				var base_path = Drupal.settings.basePath;
				$.ajax({
					// type : "POST",
					url : base_path + "ajax/cart_clear",
					
					success : function(msg) {
						console.debug(msg);
					}
				});
				
			});

			/**
			 * Click event for select all link
			 */
			$('#select-all').click(function() {
				$('span.node_check').each(function() {
					var nid = $(this).parent().children('span').text();
					add_to_cart(nid);
				});
			});
			
			/**
			 * Click Event for the thumbnail image.
			 */
			$('div.field-content img').bind('click',function() {

						// for highlight the thumbnail image related to
						// the preview image
				
						$('div.field-content img').removeClass('selected-thumbnail').addClass('thumbnail');
						
						$(this).removeClass('thumbnail').addClass('selected-thumbnail');

						var imgsrc = $(this).attr('src');
						var price_txt = get_currency_sign() + $(this).parents('td').find('span.node_cost').text();
						$('.page-search-result span#photo_cost label').text(price_txt);

						var node_author_txt = $(this).parents("td").find("span.authour_first_name").text();
						$(".page-search-result span#photo_author label").text(node_author_txt);

						var replacementurl = imgsrc.replace('search_thumbnail', 'search_preview');

						$("#prev_img").html('<img src="' + replacementurl + '" />');

						// change the addtocart button id
						var wrap_id1 = $(this).parent().attr('id');
						var exploded = wrap_id1.split('thumb-');
						var new_id = exploded[1];
						$("#cart_hidden").val(new_id);

						// Add/remove functionality based on the cart
						// contents
						var cart_contents = new Array();
						var cart_str = $(
								'.view-footer #cart_hidden_nids input')
								.val();

						// var temp = new Array();
						if ($('#' + new_id).attr('checked') == true) {

							show_remove_button();
						} else {
							show_add_button();
						}

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
