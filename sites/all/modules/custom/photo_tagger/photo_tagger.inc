<?php

function photo_tagger_get_photos($nid, $uid, $limit) {
  
  
  $sql='select n.nid, upi.uc_product_image_fid fid 
        from {node} n 
        inner join {field_data_uc_product_image} upi
          on n.nid = upi.entity_id
        left join {field_data_field_ocr_numbers} fon 
          on n.nid = fon.entity_id
        where fon.field_ocr_numbers_value is null
          and n.nid>:nid
          and n.uid=:uid
        order by n.nid';
  $result = db_query_range($sql, 0, $limit, array(':uid'=>$uid, 'nid'=> $nid));
  
  $pool = array();
  $i = 0;
  foreach($result as $row) {
    
    $file = file_load($row->fid);
    $url = image_style_url('earch_preview', $file->uri);
    $pool[$i] = array('nid' => $row->nid, 'url' => $url);
    $i++;
   }
  return $pool;
 $img0 = array('nid' => 10, 'url' => 'http://runmemo-test.s3.amazonaws.com/styles/large/s3/IMG_6327_crop_0_1.jpg');
 $img1 = array('nid' => 20, 'url' => 'http://runmemo.dev/sites/default/files/styles/search_preview/public/RunMoscow_0.JPG');
 $img2 = array('nid' => 30, 'url' => 'http://runmemo.dev/sites/default/files/styles/search_preview/public/2011%2BGreat%2BNorth%2BRun-fd0000x_1.jpg');
 
 
 return array(0 => $img0, 1=> $img1, 2=>$img2);
}