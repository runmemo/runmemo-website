
<div class="checkoutPane">
	<div class="paymentPane"><div><span class="checkout_title">Payment Details</span></div>
	<?php print $billing;
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
	
	$num = count($cart);
	$count = 1;
	$total = 0;
	$photographer_1 = array();
	$cart_content = "";
       
	foreach($cart as $product => $value){
           
            $uid = $value->uid;
	    $qty = $value->qty;
		$price = $qty*$value->price;
		$total += $price;
		//if($uid){
                $photographer_1[] = $uid;
		//$photographer[$uid] += 1;
		//}
		//else
		//$photographer[$uid] = 1;
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
	  }else if(count(array_unique($photographer_1))==1){
	  $checkout_heading .= '<div class="boldText">'.$num.' photos by '.count(array_unique($photographer_1)).' photographer';
	  }else{
	  $checkout_heading .= '<div class="boldText">'.$num.' photos by '.count(array_unique($photographer_1)).' different photographers';
      }
	  $checkout_heading .= '<div class="totalPrice">Total Price: <div class="currencyText">£'.$total.'</div></div></div></div>';
	  echo $checkout_heading;
	  echo '<table><tr>';
	  echo $cart_content;
	  echo '</tr></table>';
	  
	 ?>
	</div>
  

</div>