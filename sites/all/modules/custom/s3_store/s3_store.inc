<?php

module_load_include('inc','amazon_s3','s3');

/**
 * Represents a class that moves file from local folder to S3 bucket
 */
class s3_mover {
  private $bucket;

  // @var local path prefix, e.g. "public://"
  private $path;
  private $s3;
  private $acl = S3::ACL_PUBLIC_READ;
  /**
   * Constracts s3_mover object
   *
   * @param string $pathPrefix
   * 	local path prefix in Drupal, e.g. "public://
   *
   * @param string $bucket
   * 	name of the bucket in S3 to which files will be saved.
   */
  public function __construct($pathPrefix, $bucket)
  {

    $this->bucket = $bucket;
    $this->path = $pathPrefix;
    if ($this->s3 == NULL) {
       
      $aws_access_key = variable_get('aws_access_key');
      $aws_secret_key = variable_get('aws_secret_key');

      if (!($aws_access_key) OR !($aws_secret_key)) {
        drupal_set_message('You must ' . l('set your aws access key and secret key', 'admin/config/amazon-s3') . '.', 'error');
      }

      $s3 = new S3($aws_access_key, $aws_secret_key);
    }
    $this->s3 = $s3;
  }

  /**
   * Moves original file from local path to S3
   *
   * @param object $file
   * 	Object with properties of the file to be moved.
   *
   * @param string $acl
   * 	security flag for the file to be set in S3.
   */
  public function move_file($file, $acl = NULL) {

    if (!$acl) {
      $acl = $this->acl;
    }

    $path=drupal_realpath($this->path);
    $file_path = drupal_realpath($file->uri);
    $success = $this->s3->putObjectFile($file_path, $this->bucket, $file->filename, $this->acl);
    if ($success) {
      // original file was sent to S3
      watchdog('S3 info', 'Sent file: ' . $file->uri . ' to s3://' . $this->bucket . '/' . $file->filename, array(), WATCHDOG_DEBUG);

      $local_uri = $file->uri;
      // update uri of the file to point to S3
      $this->update_uri($file->fid, $file->uri);
      // delete local file
      file_unmanaged_delete($local_uri);

      // update status on the node
      // $this->update_s3_status($file->nid, 1);
       
    }
    else {
      watchdog('S3 info', 'Failed to send file: ' . $file->uri . ' to s3://' . $this->bucket . '/' . $file->filename, array(), WATCHDOG_ERROR);
    }
  }

  public function move_imagecache ($file, $style) {
    // move imagecache to S3
    $derivative_uri = drupal_realpath(image_style_path($style, $file->uri));

    watchdog('Image caching', 'Sending file to S3 for Style == ' . $style, array(), WATCHDOG_DEBUG);
     
    if (file_exists($derivative_uri)) {
      try { // Copy file to S3 and remove local file.

        $success = $this->s3->putObjectFile($derivative_uri, $this->bucket, $this->getS3_uri($style) .  $file->filename, $this->acl);
        if($success) {
          file_unmanaged_delete($derivative_uri);
        }
      }
      catch (Exception $e) {
        watchdog_exception('Exception', $e);
      }
    }
    else { // cached file does not exist on the server
      watchdog('Image caching', 'Sending file to S3 failed as style for the image does not exist: ' . $derivative_uri, array(), WATCHDOG_ERROR);
    }
  }

  /**
   * Update the url field
   * @param $fid $fid is the file id
   * @param $uri uri of file in the local file system
   *
   * By using this function we can update the url to s3
   */
  private function update_uri($fid, $uri) {
    $s3_uri = str_replace($this->path, "s3://", $uri);
    db_update('file_managed')
    ->fields(array(
				'uri' => $s3_uri,
    ))
    ->condition('fid', $fid)
    ->execute();

  }

  /**
   * Update the s3 status field
   * @param integer $entity_id is node id of the photo
   * @param boolean $status status of S3 move:
   * 		0 -> file was not moved;
   *  	1 -> file was moved to s3.
   *
   *  By using this function we can set the status whether files are pushed to s3
   */
  private function update_s3_status($entity_id, $status) {
    db_update('field_data_field_s3_status')
    ->fields(array(
				'field_s3_status_value' => $status,
    ))
    ->condition('entity_id', $entity_id)
    ->execute();

  }
  /**
   * Gets path of the folder in S3 bucket for the style
   * @param string $styleName
   */
  private function getS3_uri($styleName) {
    return 'styles/' . $styleName . '/s3/';
  }

}
