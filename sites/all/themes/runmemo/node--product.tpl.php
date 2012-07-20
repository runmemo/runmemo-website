<?php
/**
 * @file
 * Zen theme's implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   - view-mode-[mode]: The view mode, e.g. 'full', 'teaser'...
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 *   The following applies only to viewers who are registered users:
 *   - node-by-viewer: Node is authored by the user currently viewing the page.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $pubdate: Formatted date and time for when the node was published wrapped
 *   in a HTML5 time element.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content. Currently broken; see http://drupal.org/node/823380
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see zen_preprocess_node()
 * @see template_process()
 */
?>
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.5.2/jquery.min.js"></script>
<!--<script type="text/javascript" src="<?php //@todo //drupal_get_path('module', 'ubercart_custom') . '/jquery.tagsinput.js'; ?>"></script>-->
<script type="text/javascript" src="http://xoxco.com/projects/code/tagsinput/jquery.tagsinput.js"></script>
<script type='text/javascript' src='https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.13/jquery-ui.min.js'></script>
<link rel="stylesheet" type="text/css" href="http://ajax.googleapis.com/ajax/libs/jqueryui/1.8.13/themes/start/jquery-ui.css" />

<script type="text/javascript"> 
  //
  function onAddTag(elem) {
    var base_path = Drupal.settings.basePath;
    var nid = $('#product_id').val();

    //define php info and make ajax call
    $.ajax({
        url : base_path + "ajax/save_numbers",
        type: "POST",
        data: { nid: nid, number: elem, option: "add" },
        cache: false,
        success : function(msg) {
          console.debug(msg);
        }
    });
  }
  
  //
  function onRemoveTag(elem) {
    var base_path = Drupal.settings.basePath;
    var nid = $('#product_id').val();

    //define php info and make ajax call
    $.ajax({
        url : base_path + "ajax/save_numbers",
        type: "POST",
        data: { nid: nid, number: elem, option: "remove" },
        cache: false,
        success : function(msg) {
          console.debug(msg);
        }
    });
  }
  
  // @todo: implement some validation
  function onChangeTag(elem_tags, elem) {
//    $('.tag', elem_tags).each(function() {
//            if(IsValidAge($(this).text()))
//                    $(this).css('background-color', 'yellow');
//    });
  }
  
// function IsValidAge(value) {
//        if (value.length == 0) {
//            return false;
//        }
//
//        var intValue = parseInt(value);
//        if (intValue == Number.NaN) {
//            return false;
//        }
//
//        if (intValue <= 0)
//        {
//            return false;
//        }
//        return true;
//  }

// 
  $(function() {
    $('#runner_number').tagsInput({
    //   'autocomplete_url': url_to_autocomplete_api,
    //   'autocomplete': { option: value, option: value},
    //   'height':'100px',
         'width':'200px',
         'interactive': true,
         'defaultText':'add number',
         'onAddTag' : onAddTag,
         'onRemoveTag' : onRemoveTag,
         'onChange' : onChangeTag,
         'removeWithBackspace' : false
//         'minChars' : 1,
//         'maxChars' : 5 //if not provided there is no limit,
    //   'placeholderColor' : '#666666'
    });


    function onSlide( event, ui ) {
       $( "#amount" ).val( "£" + ui.value );
    }
    
    function onPriceChange( event, ui ) {
      var sell_price = $( "#sell_price" ).slider( "value" );
      var base_path = Drupal.settings.basePath;
      var nid = $('#product_id').val();

      //define php info and make ajax call
      $.ajax({
          url : base_path + "ajax/change_price",
          type: "POST",
          data: { nid: nid, sell_price: sell_price },
          cache: false,
          success : function(msg) {
            console.debug(msg);
          }
      });       
    }
    
    var sell_price = $( "#sell_price_value" ).val();
    $( "#sell_price" ).slider({
            range: "min",
            value: sell_price,
            min: 2,
            max: 99,
            step: 0.5,
            slide: onSlide,
            change: onPriceChange
    });
    
    $( "#amount" ).val( "£" + $( "#sell_price" ).slider( "value" ) );

  });
  
</script>
  
<h2> <?php print "Photo profile"; ?> </h2>
  
<?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
?>

<div class="product_preview">
  <?php print render($content['uc_product_image']) ?>
</div>

<div class="product_content">
  <div class="product-info display-price">
    <input type="text" id="amount" style="border: 0; width: 60px;" /> 
  </div>  
  
  <?php print render($content); ?>
  
  <label for="amount" class="field-label">Sell price:</label>
  <div id="sell_price"></div>

  
  
  <label for="runner_number" class="field-label">Runner numbers:</label>
  <input name="runner_number" id="runner_number" value="<?php 
    require_once(DRUPAL_ROOT . '/' . drupal_get_path('module', 'ocr') . '/ocr_product_node_saver.inc');
    $productSaver = new ProductNodeSaver($node->nid);
    echo $productSaver->GetNumbersStr(); 
  ?>" />

  <?php
    print render( drupal_get_form('product_node_custom_form') );
  ?>
</div>

