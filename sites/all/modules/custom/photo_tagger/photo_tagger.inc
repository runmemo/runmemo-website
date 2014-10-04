<?php

function photo_tagger_get_photos($nid, $uid, $limit) {
  $title = '';
  $node = node_load($nid);
  if ($node) {
    $title = $node->title;
  }
  $sql='select n.nid, upi.uc_product_image_fid fid 
        from {node} n 
        inner join {field_data_uc_product_image} upi
          on n.nid = upi.entity_id
        left join {field_data_field_ocr_numbers} fon 
          on n.nid = fon.entity_id
        where fon.field_ocr_numbers_value is null
          and n.title > :title
          and n.uid = :uid
          and n.status = 1
        order by n.title';
  $result = db_query_range($sql, 0, $limit, array(':uid'=>$uid, ':title'=> $title));
  
  $pool = array();
  $i = 0;
  foreach($result as $row) {
    
    $file = file_load($row->fid);
    $url = image_style_url('search_preview', $file->uri);
    $pool[$i] = array('nid' => $row->nid, 'url' => $url);
    $i++;
   }
  return $pool;
}

function photo_tagger_count_photos($uid) {
    $sql='select COUNT(*)
          from {node} n 
          inner join {field_data_uc_product_image} upi
            on n.nid = upi.entity_id
          left join {field_data_field_ocr_numbers} fon 
            on n.nid = fon.entity_id
          where fon.field_ocr_numbers_value is null
            and n.uid = :uid
            and n.status = 1';
    
    $result = db_query($sql, array(':uid'=>$uid))->fetchField();
    return $result;
}
