<?php

/**
 * @file generate_thumbnails.inc
 */

function _pre_image_cache_styles() {
  $styles = array('search_preview', 'search_thumbnail'); 
  return $styles;
}


function search_results_image_styles() {
  $styles = array();

  // Exported image style: search_preview
  $styles['search_preview'] = array(
    'name' => 'search_preview',
    'effects' => array(
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '400',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
      6 => array(
        'label' => 'Overlay (watermark)',
        'help' => 'Choose the file image you wish to use as an overlay, and position it in a layer on top of the canvas.',
        'effect callback' => 'canvasactions_file2canvas_image',
        'form callback' => 'canvasactions_file2canvas_form',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_file2canvas',
        'data' => array(
          'xpos' => 'left',
          'ypos' => 'center',
          'alpha' => '30',
          'path' => 'module://generate_thumbnails/preview_watermark.png',
        ),
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: search_thumbnail
  $styles['search_thumbnail'] = array(
    'name' => 'search_thumbnail',
    'effects' => array(
      13 => array(
        'label' => 'Aspect switcher: Switch between portrait and landscape',
        'help' => 'Use different effects depending on whether the image is landscape of portrait shaped. This re-uses other preset definitions, and just chooses between them based on the rule.',
        'effect callback' => 'canvasactions_aspect_image',
        'form callback' => 'canvasactions_aspect_form',
        'module' => 'imagecache_canvasactions',
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'search_thumbnail_portrait',
          'landscape' => 'search_thumbnail_landscape',
          'ratio_adjustment' => '1',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: search_thumbnail_landscape
  $styles['search_thumbnail_landscape'] = array(
    'name' => 'search_thumbnail_landscape',
    'effects' => array(
      11 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => '100',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: search_thumbnail_portrait
  $styles['search_thumbnail_portrait'] = array(
    'name' => 'search_thumbnail_portrait',
    'effects' => array(
      12 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '100',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}