/**
 * jQuery Behaviors for Bib Numbers Field
 */
(function($) {
	Drupal.behaviors.runmemoBibNumbersField = {
		attach : function(context, settings) {


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

	function onAddTag(elem) {
	  
	  //define php info and make ajax call
	  $.ajax({
	      url : settings.basePath + "ajax/save_numbers",
	      type: "POST",
	      data: {nid: settings.product.nid, number: elem, option: "add"},
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
	      },
        error : function(msg) {
          console.log(msg);
        }
	  });
	}
	
	//
	function onRemoveTag(elem) {
	 
   //define php info and make ajax call
	  $.ajax({
	      url : settings.basePath + "ajax/save_numbers",
	      type: "POST",
	      data: {nid: settings.product.nid, number: elem, option: "remove"},
              dataType: 'json',              
	      cache: false,
	      success : function(msg) {
                if (msg.success) {
                  $( ".node-type-product #product-nice-message-container" ).text("Number " + elem + " was  removed");
                } else {

                }
	      }, 
        error: function(msg) {
          console.log(msg);
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
	
  
    }
  }
})(jQuery);