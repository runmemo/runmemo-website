<?php
class masspayment_model{
 /**
 * List payments for photographers 
 */
  public function list_photographerpayments($searching_month_year){
      
          
          if ($searching_month_year == '') {
          $query = "SELECT GROUP_CONCAT( ucp.order_product_id ) AS order_product_ids, COUNT( ucp.order_id ) AS no_of_images_sold, SUM( ucp.price ) AS sum, node.uid AS uid
		FROM uc_order_products ucp
		JOIN uc_orders uo ON uo.order_id = ucp.order_id
		AND uo.order_status = 'completed'
		JOIN node ON node.nid = ucp.nid
		
		WHERE  DATE_FORMAT( DATE( FROM_UNIXTIME( uo.modified ) ) , '%M' ) = DATE_FORMAT( now( ) , '%M' )
		GROUP BY node.uid ";
          $mp_listquery = db_query($query);
          }
          else {
            $query = "SELECT GROUP_CONCAT( ucp.order_product_id ) AS order_product_ids, COUNT( ucp.order_id ) AS no_of_images_sold, SUM( ucp.price ) AS sum, node.uid AS uid
		FROM uc_order_products ucp
		JOIN uc_orders uo ON uo.order_id = ucp.order_id
		AND uo.order_status = 'completed'
		JOIN node ON node.nid = ucp.nid
		
		WHERE  DATE_FORMAT( DATE( FROM_UNIXTIME( uo.modified ) ) , '%M' ) = DATE_FORMAT( FROM_UNIXTIME(:searching_time) , '%M' )
		GROUP BY node.uid ";
            $mp_listquery = db_query($query, array(':searching_time' => $searching_month_year));
          }
    	
          
          
          return $mp_listquery;  
  }
/**
 * get user deatils
 */
  public function getuserdetails($uid=0){
          $userdetails = db_query("select * from {users} JOIN {field_data_field_paypal_id} paypal  on paypal.entity_id = users.uid LEFT JOIN {field_data_field_phone_number} phone on phone.entity_id = users.uid WHERE uid=".$uid );

          foreach($userdetails as $details){

                  $userarr['phone'] = $details->field_phone_number_value;
                  $userarr['email'] = $details->field_paypal_id_value;
                  $userarr['name']  = $details->name;

          }

          return $userarr;
  }
  public function insert_masspayment($status = 0){
    $mp_insertid = db_insert('masspayment_list')
          ->fields(array(
          'masspayment_time' => REQUEST_TIME,
          'masspayment_txnid' => $status,

          ))
          ->execute();
          return $mp_insertid;
  }
  public function masspayment_photographer($values = array()){
    $query = db_insert('masspayment_photographer')
      ->fields(array('masspayment_id','uid','amount','paymentdate','payment_status'));
                  foreach ($values as $record) {
                  $query->values($record);
                  }
                  $query->execute();
  }

  public function masspayment_order($values = array()){

    $query = db_insert('masspayment_order')
      ->fields(array('order_product_id','masspayment_id'));
                  foreach ($values as $record) {
                  $query->values($record);
                  }
                  $query->execute();


  }

  
   
  public function get_paid_amount_details($status,$uid){

    $photographer_amount = db_query("SELECT COUNT(masspayment_id) as count,SUM(amount) as amount FROM masspayment_photographer WHERE payment_status=:status AND uid=:uid AND DATE_FORMAT(DATE( FROM_UNIXTIME( paymentdate)),'%M')= DATE_FORMAT( now(),'%M')GROUP BY uid=:uid ", array(':status' => $status, ':uid' => $uid ))->fetchObject();
    return $photographer_amount;
  }
                

  public function get_site_created_time($uid){
    $start_time = db_query("SELECT created FROM users WHERE uid=:uid", array(':uid' => $uid))->fetchObject();
    return $start_time->created;
  }
  
}
  
