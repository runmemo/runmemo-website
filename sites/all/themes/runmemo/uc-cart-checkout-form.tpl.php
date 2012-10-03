<?php 
    print drupal_render($form['form_build_id']);
    print drupal_render($form['form_id']);
    print drupal_render($form['form_token']);
?>
<div class='checkout-container'>
<div class="checkoutPane">
	<div class="checkout-title green-heading"><?php print t('Payment details'); ?></div>
	<div class="checkout-form">
		
	<?php 
	
	  print $billing;
      print $customer;
      print $payment;
      print $submit; 
      
	?>
	</div>
</div>
	<div class="cartPane">
	<?php 
  	$cid = uc_cart_get_id($create = TRUE);
  	$count  = count_cart_items($cid);
  	$subtotal = cart_total_amount($cid);
  	$max_order_value = variable_get('max_order_value', 20);
  	if ($subtotal > $max_order_value) {
  	  $subtotal = $max_order_value; // @todo:bulat - replace with variable or value on the event.
  	}
       ?>
       <div class="checkout-title blue-heading"><?php print t('Order summary'); ?></div>
	   <div class="checkout-cart-summary">
			
			<div class="order-items"><?php print t('Photos'); ?>: <span id="order-items"><?php echo $count ?></span></div>
			<div class="total-price"><?php print t('Total Price'); ?>: <span class="order-currency"><?php echo variable_get('uc_currency_sign') ?></span>
			<span id ='order-subtotal'><?php echo $subtotal ?></span>
			</div>
			<fieldset class="form-wrapper" id="selected-photos-pane">
				<legend><span class="fieldset-legend"><?php print t('Selected photos'); ?></span></legend>
			</fieldset>
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
    		   <?php } 
    		   ?>
    		</div>
		</div>
		
	</div>
</div>