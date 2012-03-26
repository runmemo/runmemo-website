<p><?php //print $intro_text; ?></p>

<div class="checkoutPane">
	<div class="paymentPane"><div><span class="checkout_title">Payment Details</span></div>
	<?php print $billing;
              print $customer;
              echo '<fieldset id="payment-pane" class="form-wrapper"><legend><span class="fieldset-legend">Payment Method</span></legend>';
	      print $payment;
              echo '</fieldset>';
              print $submit;
    ?>
	</div>
	<div class="cartPane">
	<?php 
	
	$num = count($cart);
	$count = 1;
	$total = 0;
	$photographer = array();
	$cart_content = "";
       
	foreach($cart as $product => $value){
          
          
	    $qty = $value->qty;
		$price = $qty*$value->price;
		$total += $price;
		if($photographer[$value->uid]){
		$photographer[$value->uid] += 1;
		}
		else
		$photographer[$value->uid] = 1;
		   
		  //$uri = str_replace('public://',base_path().'sites/default/files/styles/thumbnail/public/',$value->uc_product_image['und'][0]['uri']);
		 
		  //$cart_content .=  '<td><a href=""><img src = "'.$uri.'"></a></td>';
                
                  //file_create_url();
                
                  $photo = $value->uc_product_image['und'][0];
                  $cart_content .=  '<td>'.  theme("image_formatter", array('item' => $photo, 'image_style' => 'thumbnail')).'</td>';
                  
                  
		  if($count%3==0){
			$cart_content .= '</tr><tr>';
			}
			
		 
		  $count+=1;
		  
		  }
	  $checkout_heading  =  '<div class="cartSummary"><div class="blueHeading">Order Summary</div>';
	  if($num==1){
	  $checkout_heading .= '<div class="boldText">'.$num.' photo by 1 photographer</div>';
	  }else if(count($photographer)==1){
	  $checkout_heading .= '<div class="boldText">'.$num.' photos by '.count($photographer).' photographer </div>';
	  }else{
	  $checkout_heading .= '<div class="boldText">'.$num.' photos by '.count($photographer).' different photographers </div>';
      }
	  $checkout_heading .= '<div class="totalPrice">Total Price: <div class="currencyText">£'.$total.'</div></div></div>';
	  echo $checkout_heading;
	  echo '<table><tr>';
	  echo $cart_content;
	  echo '</tr></table>';
	  
	 ?>
	</div>

</div>
