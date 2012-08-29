<?php
/**
 * @file 
 * user database query management 
 */

class user_custom_helper {

  /**
   * Get the role id for set the user role as photographer to access the photgrapher page
   * this function return the role id of the photographer
   */
  public static function get_photographer_rid() {
     return user_custom_helper::get_rid('Photographer');
  }
  
  /**
   * Get the role id for set the user role as photographer to access the photgrapher page
   * this function return the role id of the photographer
   */
  public static function get_runner_rid() {
     return user_custom_helper::get_rid('Runner');
  }
  
  public static function get_rid($role_name) { 
    $role = user_role_load_by_name($role_name);
    if($role) {
      return $role->rid;
    }
    return NULL;
  }

  /**
   * Update the user role as photographer
   * @param $role_id,$uid
   *  $role_id is the id of the photographer role
   *  $uid is user id of the current user
   *  By using this function we can set the user role as photographer when user creating the account 
   */

  public static function user_role_update($role_id, $uid) {
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
  public static function user_role_id_insert($role_id, $uid) {
    db_insert('users_roles')
                    ->fields(array(
                    'uid' => $uid,
                    'rid' => $role_id,
                    ))->execute();

  }
    
}

