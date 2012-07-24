

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
        $( "#product-nice-message-container" ).text("Number " + elem + " was added");
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
        $( "#product-nice-message-container" ).text("Number " + elem + " was removed");
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
  $('#product-node-runner-number').tagsInput({
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


  function onSlide( event, ui ) {
      $( "#amount" ).text( "£" + ui.value );

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

    $( "#product-nice-message-container" ).text("Price was changed to £" + ui.value);

  }

  var sell_price = $( "#sell_price_value" ).val();
  $( "#sell_price" ).slider({
          range: "min",
          value: sell_price,
          min: 2,
          max: 20,
          step: 1,
          slide: onSlide,
          change: onPriceChange
  });

  $( "#amount" ).text( "£" + $( "#sell_price" ).slider( "value" ) );

});
