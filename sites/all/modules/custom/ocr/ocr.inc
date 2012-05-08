<?php

class ocr_model{

	/**
	 * Insert runner number from ocr response
	 */
	public function insert_runnernumber($nid, $runner_num, $revision_id){

		db_insert('field_data_field_runner_number')->fields(
				array('entity_type' =>'node',
						'bundle' => 'product',
						'deleted' => 0,
						'revision_id' =>$revision_id,
						'language' => 'und',
						'entity_id' =>$nid,
						'field_runner_number_value' => $runner_num
				))->execute();
	}
	/**
	 * retrieve revision_id for a node
	 */
	public function getnoderevision($nid){
		$result = db_select('node_revision','vid')
		->condition('nid', $nid)
		->fields('vid')
		->execute();
		return $result;

	}
	/**
	 * insert response from OCR to ocr_response if response is success
	 */
	public function insert_response($responsebody, $success){
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
	public function insert_ocr_status($entity_id, $success){
		if($success == 1){
			$status = "Success";
		}
		else{
			$status = "Failure";
		}
		db_update('field_data_field_ocr_response')->fields(
				array('field_ocr_response_value' =>$status,
				))->condition('entity_id', $entity_id)
				->execute();
	}
	public function getocr_status($nid){
		$result = db_select('field_data_field_ocr_response','field_ocr_response_value')
		->condition('entity_id', $nid)
		->fields('field_ocr_response_value')
		->execute();
		return $result;

	}
	public function check_node($nid) {
		$result = db_select('node','nid')
		->condition('nid', $nid)
		->fields('nid')
		->execute();
		return $result;
	}
}

/**
 * updating OCR response
 */
function update_drupal_with_responce ($message)
{
	if($message){
		$responsearr = json_decode(trim($message));
		$nid         = $responsearr->ExternalReference;
		$imagekey    = $responsearr->ImageKey;
		$imagebucket = $responsearr->ImageBucket;
		$success = $responsearr->Success;
		$error       = $responsearr->ErrorMessage;
		$numbers[]    = $responsearr->Numbers;
		$ocr_object = new ocr_model();
		if ($success == true) {
			$check_node = $ocr_object->check_node($nid);
			foreach($check_node as $nodeid){
				$node_exists = $nodeid->nid;
			}
			if($node_exists)
			{ //inserting runner number
				//checking OCR status of the node
				$ocr_status = $ocr_object->getocr_status($nid);
				foreach($ocr_status as $ocr_response){
					$ocr_responce = $ocr_response->field_ocr_response_value;
				}
				if (!empty($responsearr->Numbers)) {
					foreach($responsearr->Numbers as $responsenumber){
						$revision   = $ocr_object->getnoderevision($nid);
						foreach($revision as $revision_id){
							$node_revid = $revision_id->vid;
						}
						if ($responsenumber->Number) 
						{
							$result = $ocr_object->insert_runnernumber($nid,$responsenumber->Number,$node_revid);
							$insert_status   = $status_object->insert_ocr_status($nid,1);
						}
					}
				}
				else { // numbers are empty
					
					if($ocr_responce == "Pending" || $ocr_responce == "")
					{
						$insert_status   = $ocr_object->insert_ocr_status($nid,0);
						watchdog('OCR Info','Runner number not present in OCR response for node: ' . $nid);
					}
				}
			}
			else{ // Node does not exist
				watchdog('OCR Error','Response received for a node that does not exists',array(), WATCHDOG_ERROR);
			}
		}
		else { // OCR response: Success == False
			// @todo
		}
	}
}

?>