<div class="checkoutPane">
	<div class="paymentPane">
		<div><span class="checkout_title">Payment Details</span></div>
	<?php 
	  print $billing;
      print $customer;
      print $payment;
      print $form_build_id;
      print $form_token;
      print $form_id;
      print $submit;
    ?>
	</div>
	<div class="cartPane">
	<?php 
	$cid = uc_cart_get_id($create = TRUE);
	$count  = count_cart_items($cid);
	$subtotal = cart_total_amount($cid);
	
       ?>
	   <div class="cartSummary">
			<div class="blueHeading">Order Summary</div>
			<div class="order-items">Photos: <span id="order-items"><?php echo $count ?></span></div>
			<div class="total-price">Total Price: <span class="order-currency"><?php echo variable_get('uc_currency_sign') ?></span>
			<span id ='order-subtotal'><?php echo $subtotal ?></span>
			</div>
		</div>
		<div class = 'thumbnails'>
		  <?php 
		  $i = 0;    
		  foreach (uc_cart_get_contents($cid) as $index => $product) {
              $photo = $product->uc_product_image['und'][0];
              $nid = $product->nid;
              $i++;
		    ?>
		 	<div id = "thumb-<?php echo $nid ?>" class="image-thumbnail">
  		      <div id="<?php echo $nid ?>" class="remove-cart-item" >x</div>  
		      <?php echo theme("image_formatter", array('item' => $photo, 'image_style' => 'search_thumbnail'));?>
		  	</div>
		   <?php } ?>
		</div>
	</div>
</div>