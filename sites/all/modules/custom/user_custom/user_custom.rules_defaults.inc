<?php
/**
 * @file
 * user_custom.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function user_custom_default_rules_configuration() {
  $items = array();
  $rid = user_custom_helper::get_photographer_rid();
  $items['flickr_assign_photographer_role'] = entity_import('rules_config', '{ "flickr_assign_photographer_role" : {
      "LABEL" : "Flickr account: Assign photographer role",
      "PLUGIN" : "reaction rule",
      "TAGS" : [ "role assignment" ],
      "REQUIRES" : [ "rules", "rpx_rules" ],
      "ON" : [ "rpx_account_add" ],
      "IF" : [
        { "NOT user_has_role" : {
            "account" : [ "rpx:user" ],
            "roles" : { "value" : { "' . $rid .'" : "' . $rid .'" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [
        { "user_add_role" : { "account" : [ "rpx:user" ], "roles" : { "value" : { "'. $rid . '" : "' . $rid .'" } } } }
      ]
    }
  }');
  return $items;
}