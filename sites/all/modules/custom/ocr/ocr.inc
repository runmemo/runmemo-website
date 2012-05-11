<?php

class ocr_model{
   /**
   * Insert runner number from ocr response 
   */
   public function insert_runnernumber($nid = 0,$runner_num=0,$revision_id =0,$runner_count=0){

     db_insert('field_data_field_runner_number')->fields(
      array('entity_type' =>'node',
            'bundle' => 'product',
            'deleted' => 0,
            'revision_id' =>$revision_id,
            'language' => 'und',
            'delta' => $runner_count,
            'entity_id' =>$nid,
            'field_runner_number_value' => $runner_num
            ))->execute();
   }
   /**
   *Insert xy values for runner numbers
   */
   public function insert_xyvalues($nid,$number,$xvalue,$yvalue){
    db_insert('ocr_xyvalues')->fields(
	array('nid' => $nid,
	      'runner_number' => $number,
          'xvalue' => $xvalue,
		  'yvalue' => $yvalue
		  ))->execute();
          		  
   }
   /**
   * retrieve revision_id for a node
   */
   public function getnoderevision($nid = 0){
     $result = db_select('node_revision','vid')
          ->condition('nid', $nid)
          ->fields('vid')
          ->execute();
          return $result;

   }
   /**
   * insert response from OCR to ocr_response if response is success
   */
   public function insert_response($responsebody="",$success=0){
   $responsebody = mysql_real_escape_string($responsebody);
    db_insert('ocr_response')->fields(
            array('ocr_response' => $responsebody,
                  'ocr_status' => $success,
                  'received' => REQUEST_TIME,
                  ))
                  ->execute();
   }

   /**
   * insert response from OCR to ocr_response if response is success
   */
   public function insert_response_status($entity_id=0,$success=0){
    if($success == 1){
      $status = "Runner number received";
    }
    else{
     $status = "Runner number missing";
    }
    db_update('field_data_field_ocr_response')->fields(
            array('field_ocr_response_value' =>$status,
                  ))->condition('entity_id', $entity_id)
                  ->execute();
   }
   /**
   * insert response from OCR to ocr_status
   */
   public function insert_ocr_status($entity_id=0,$success = 0){
   watchdog('OCR Status','status'.$success);
    if($success == 1){
      $status = "Success";
    }
    else{
     $status = "Failure";
    }
    db_update('field_data_field_ocr_status')->fields(
            array('field_ocr_status_value' =>$status,
                  ))->condition('entity_id', $entity_id)
                  ->execute();
   }
   /**
   * get ocr status
   */
   public function getocr_status($nid =0){
   $result = db_select('field_data_field_ocr_response','field_ocr_response_value')
		->condition('entity_id', $nid)
		->fields('field_ocr_response_value')
		->execute();
   return $result;
  
  }
  /*
  * check if such a node exists
  */
  public function check_node($nid=0) {
   $result = db_select('node','nid')
		->condition('nid', $nid)
		->fields('nid')
		->execute();
   return $result;
  }
  /*
  * get images for which ocr status is pending
  */
  public function get_pendingphotos(){
 
    $query = db_select('file_managed', 'fm');
    $query->join('file_usage', 'fu', 'fm.fid = fu.fid');
    $query->join('field_data_field_s3_status', 'fs', 'fu.id = fs.entity_id');
	$query->join('field_data_field_ocr_response', 'ocr', 'fs.entity_id = ocr.entity_id');
	$query->condition('fs.field_s3_status_value', 1);
    $query->condition(db_or()->condition('ocr.field_ocr_response_value', 'Pending')->condition('ocr.field_ocr_response_value', ''));
	$query->condition('fm.filename', '', '<>');
    $query->addField('fm', 'fid');
    $query->addField('fm', 'filename');
    $query->addField('fm', 'uri');
    $query->addField('fm', 'uid');
    $query->addField('fs', 'entity_id');
	$query->addField('ocr', 'field_ocr_response_value');
    $query->orderBy('fm.timestamp', 'DESC');
    $results = $query->execute();
    return $results;
  
  }

 }
?>