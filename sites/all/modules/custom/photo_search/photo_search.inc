<?php

/**
 * @file
 * Interface for photo_requests table
 *
 * @author leonid@runmemo.com
 */


/**
 * Contains attributes of runner's number on the photo.
 */
class PhotoRequest {
  const DBTABLE = 'photo_requests';

  /**
   * Adds request to table
   * @param string $email
   * @param integer $eventid
   * @param integer $number
   * @throws Exception 
   */
  public static function AddRequest($email, $eventid, $number) {
    if(!db_table_exists(self::DBTABLE)) {
      throw new Exception('DB table photo_requests does not exist.');
    }    
    //check if reuest already exists
    $query = db_select(self::DBTABLE, 'r')
      ->fields('r')
      ->condition('r.email', $email, '=')
      ->condition('r.eventid', $eventid, '=')
      ->condition('r.number', $number, '=')
      ->condition('r.performed', 0, '=');
    $num_rows  = $query->countQuery()->execute()->fetchField();
    
    if($num_rows == 0) {
      db_insert(self::DBTABLE)->fields(
        array( 
            'email'   => $email,
            'eventid' => $eventid,
            'number'  => $number,
            'created' => REQUEST_TIME,
            'performed' => 0,
        ))
      ->execute();
    }
  }
  
  /**
   * Returns requests that don't performed
   * @param timestamp $expires
   * @return array - rows
   */
  public static function GetRequests($expires) {
    $result = db_select(self::DBTABLE, 'r')
      ->fields('r')
      ->condition('r.created', $expires, '>=')
      ->condition('r.performed', 0, '=')
      ->execute();
    $requsts = $result->fetchAll();
    return $requsts;
  }
  
  /**
   * Mark request as performed
   * @param integer $id
   */
  public static function RequestPerformed($id) {

    $count = db_update(self::DBTABLE)
      ->fields(array('performed' => REQUEST_TIME))
      ->condition('id', $id, '=')
      ->execute();
  }
}