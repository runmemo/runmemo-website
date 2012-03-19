<?php

class photographer_model{

    /**
     * Get the role id for set the user role as photographer to access the photgrapher page
     * this function return the role id of the photographer
     */
    public function get_role_id(){

        $rid=db_query("SELECT rid FROM {role} WHERE name='Photographer'")->fetchObject();

        return $rid;
    }

    /**
     * Update the user role as photographer
     * @param $role_id,$uid
     *  $role_id is the id of the photographer role
     *  $uid is user id of the current user
     *  By using this function we can set the user role as photographer when user creating the account 
     */

    public function user_role_update($role_id,$uid){
        db_update('users')
                        ->fields(array(
                        'role' => $role_id,
                        ))
                        ->condition('uid', $uid)
                        ->execute();

    }
    /**
     * To manage user role for each user like photographer or runner
     * @param $role_id
     * $role_id is user role id.It is used to set the role for user
     */

    public function user_role_id_insert($role_id,$uid){
        db_insert('users_roles')
                        ->fields(array(
                        'uid' => $uid,
                        'rid' => $role_id,
                        ))->execute();

    }
	
	public function get_local_photos(){
	
	
	    
        //$photos_url=db_query("SELECT fm.filename,fm.uri,fm.uid FROM {file_managed} as fm INNER JOIN {file_usage} as fu INNER JOIN {field_data_field_s3_status} as status ON fm.fid=fu.fid and fu.id=status.entity_id and status.field_s3_status_value=:st",array(':st' => 0));
		//return $photos_url;
		
		 
		$query = db_select('file_managed', 'fm');
	    
		$query->join('file_usage', 'fu', 'fm.fid = fu.fid');
    $query->join('field_data_field_s3_status', 'fs', 'fu.id = fs.entity_id');
		$query->condition('fs.field_s3_status_value', 0);
		$query->condition('fm.filename', '','<>');
		$query->addField('fm', 'fid');
		$query->addField('fm', 'filename');
		$query->addField('fm', 'uri');
		$query->addField('fm', 'uid');
		$query->addField('fs', 'entity_id');
		$query->orderBy('fm.timestamp','DESC');
		$query->range(0, 30);
              
		$results = $query->execute();
		
		
		
		//print (string)$query;exit;
		
		return $results;
		
		
		
		 
		
		
		
		
		
	}
	
	/**
     * Update the s3 status field as 1
     * @param $entity_id
     *  $entity_id is node_id of the photo
     *  By using this function we can set the status whether files are pushed to s3 
     */

    public function update_s3_status($entity_id){
	
	   
	   
        db_update('field_data_field_s3_status')
                        ->fields(array(
                        'field_s3_status_value' =>1,
                        ))
                        ->condition('entity_id', $entity_id)
                        ->execute();
       

    }
	
	/**
     * Update the url field 
     * @param $fid
	 * @param $url
     *  $fid is the file id
     *  $url url of is s3 bucket
     *  By using this function we can update the url to s3
     */

    public function update_url ($fid, $url) {
	
	   
	

		db_update('file_managed')
                        ->fields(array(
                        'uri ' =>$url,
                        ))
                        ->condition('fid', $fid)
                        ->execute();

          
						
       
	    
						
				

    }
    
/**
     * Update the thumbnail status field as 1
     * @param $fid
     *  $fid is file id of the photo
     *  By using this function we can set the status whether thumbnail is created 
     */

    public function update_thumb_status($fid){
	
	   
	   
        db_update('file_managed')
                        ->fields(array(
                        'thumbnail_status' =>1,
                        ))
                        ->condition('fid', $fid)
                        ->execute();
       

    }
    
		

}

