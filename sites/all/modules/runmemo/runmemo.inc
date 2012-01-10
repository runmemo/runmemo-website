<?php

class photographer_model
{

	public function get_paypal_id($uid)
	{
		try
      		{
			$paypal_id=db_query("SELECT paypal_account_id FROM {photographer_account} WHERE uid=:uid",array(':uid'=>$uid))->fetchObject();
		}
		catch (exception $e)
		{
		    watchdog ("error", $e);
		}

		return $paypal_id;
	}

	public function get_role_id()
	{
		try
      		{
			$rid=db_query("SELECT rid FROM {role} WHERE name='Photographer'")->fetchObject();
		}
		catch (exception $e)
		{
		    watchdog ("error", $e);
		}
		return $rid;
	}

	public function user_role_update($role_id,$uid)
	{
		try
		{
			db_update('users')
			      ->fields(array(
				'role' => $role_id,
			      ))
			      ->condition('uid', $uid)
			      ->execute();
		}
		catch (exception $e)
		{
		    watchdog ("error", $e);
		}
	}

	public function photographer_account_id_insert($photographer_account_id,$uid)
	{
		try
		{
			db_insert('photographer_account')
					      	->fields(array(
						'paypal_account_id' => $photographer_account_id,
						'uid' => $uid,
						))->execute();
		}
		catch (exception $e)
		{
		    watchdog ("error", $e);
		}

	}

	public function user_role_id_insert($role_id,$uid)
	{
		try
		{
			db_insert('users_roles')
					      	->fields(array(
						'uid' => $uid,
						'rid' => $role_id,
						))->execute();
		}
		catch (exception $e)
		{
		    watchdog ("error", $e);
		}
	}

	public function get_uid()
	{
		try
		{
			$paypal_uid=db_query("SELECT uid FROM photographer_account");
		}
		catch (exception $e)
		{
		    watchdog ("error", $e);
		}
		return $paypal_uid;
	}


	public function paypal_id_update($paypal_id,$uid)
	{
		try
		{
			db_update('photographer_account')
			      ->fields(array(
				'paypal_account_id' => $paypal_id,
			      ))
			      ->condition('uid', $uid)
			      ->execute();
		}
		catch (exception $e)
		{
		    watchdog ("error", $e);
		}
	}
}

