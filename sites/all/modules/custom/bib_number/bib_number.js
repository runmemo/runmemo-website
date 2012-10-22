/**
 * jQuery Behaviors for Bib Numbers Field
 */
(function($) {
	Drupal.behaviors.runmemoBibNumbersField = {
		attach : function(context, settings) {

	function onAddTag(elem) {
	  var base_path = Drupal.settings.basePath;
	  var nid = $('.node-type-product #product_id').val();
	
	  //define php info and make ajax call
	  $.ajax({
	      url : base_path + "ajax/save_numbers",
	      type: "POST",
	      data: {nid: nid, number: elem, option: "add"},
              dataType: 'json',
	      cache: false,
	      success : function(msg) {
                if (msg.success) {
                  $( ".node-type-product #product-nice-message-container" ).text("Number " + elem + " was added");
                } else {
	          $('.tag').each(function() {
	            if($(this).children('span').text() == elem) {
                      $(this).css('background-color', 'yellow'); 
                    }
                  });
                  $( ".node-type-product #product-nice-message-container" ).text(elem + " cannot be added");
                }
	      }
	  });
	}
	
	//
	function onRemoveTag(elem) {
	  var base_path = Drupal.settings.basePath;
	  var nid = $('.node-type-product #product_id').val();
	
	  //define php info and make ajax call
	  $.ajax({
	      url : base_path + "ajax/save_numbers",
	      type: "POST",
	      data: {nid: nid, number: elem, option: "remove"},
              dataType: 'json',              
	      cache: false,
	      success : function(msg) {
                if (msg.success) {
                  $( ".node-type-product #product-nice-message-container" ).text("Number " + elem + " was  removed");
                } else {

                }
	      }
	  });
	}
	
	// @todo: implement some validation
	function onChangeTag(elem_tags, elem) {
	//    $('.tag').each(function() {
	//            if(IsValidAge($(this).text()))
	//                    $(this).css('background-color', 'yellow');
	//    });
	}
	
    $('#tags-input').tagsInput({
	  //   'autocomplete_url': url_to_autocomplete_api,
	  //   'autocomplete': { option: value, option: value},
	  //   'height':'100px',
	        'width':'100px',
	        'interactive': true,
	        'defaultText':'add number',
	        'onAddTag' : onAddTag,
	        'onRemoveTag' : onRemoveTag,
	        'onChange' : onChangeTag,
	        'removeWithBackspace' : false,
	         'minChars' : 1,
	         'maxChars' : 6 //if not provided there is no limit,
	  //   'placeholderColor' : '#666666'
	  });
    }
  }
})(jQuery);