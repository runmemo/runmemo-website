<?php
/**
 *@file 
 */

/**
 * Implements photo node create().
 * @param $file object
 * @param $event id
 */

function create_photo_node($file, $event) {
	global $user;
	$uid = $user->uid;
	$selected_event = $event;
	$price = node_load($selected_event)->field_pricing['und']['0']['value'];
	// We create a new node object
	$node = new stdClass();
	// content type
	$node->type = "product";
	//node title
	$node->title = $file['name'];
	//set language
	$node->language = 'und';
	//user id
	$node->uid = $uid;
	node_object_prepare($node);
	// Let's add standard body field
	$node->body[$node->language][0]['value'] = 'This is a body text';
	$node->body[$node->language][0]['summary'] = 'Here goes a summary';
	$node->body[$node->language][0]['format'] = 'filtered_html';
	//////////Change file extension////////////////////////
	$file_path = drupal_realpath('temporary://');
	$temp_name = $file['tmpname'];
	$temp_path = $file_path . '/' . $temp_name;
	chmod($temp_path, '777');
	$original_name = $file_path . '/' . $file['name'];
	rename($temp_path, $original_name);
	$file_obj = (object) array(
			'uid' => $uid,
			'uri' => $original_name,
			'filemime' => file_get_mimetype($original_name),
			'status' => 1,
			'filename' => $file['name'],
			'alt' => $file['name'],

	);
	//file moves from temp to public folder
	$file_obj = file_move($file_obj, 'public://', FILE_EXISTS_RENAME);
	$node->uc_product_image['und'][0] = (array)$file_obj; //associate the file object with the image field:

	if (($selected_event == '')) {
		$node->field_event_reference['und']['0']['nid'] = arg(1);
	}
	else{
		$node->field_event_reference['und']['0']['nid'] = $selected_event;
	}
	if ($price != '') {
		$node->sell_price = $price;
	}
	$node = node_submit($node); // Prepare node for a submit

	node_save($node); // After this call we'll get a nid
    
	$queue = DrupalQueue::get('generate_image_styles');
	$queue->createItem($file_obj);
	
	return $node;

}

