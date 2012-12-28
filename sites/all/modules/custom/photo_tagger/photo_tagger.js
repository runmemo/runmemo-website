
(function($) {
	Drupal.behaviors.runmemoPhotoTagger = {
		attach : function(context, settings) {
      
     /**
     * Apply tagsInput.
     */
	   $('#tagsinput').tagsInput({
	  //   'autocomplete_url': url_to_autocomplete_api,
	  //   'autocomplete': { option: value, option: value},
	  //   'height':'100px',
	        'width':'100px',
	        'interactive': true,
	        'defaultText':'add number',
	       // 'onAddTag' : onAddTag,
	      //  'onRemoveTag' : onRemoveTag,
	      //  'onChange' : onChangeTag,
	        'removeWithBackspace' : false,
	         'minChars' : 1,
	         'maxChars' : 6 //if not provided there is no limit,
	  //   'placeholderColor' : '#666666'
	  });


    $(document).ready(function() {
      console.debug('photo tagger jQuery(document).ready.');
     
      settings.PhotoTagger.loaded = 0;
      settings.PhotoTagger.extending = false;
      var nid = 0;
      for(var i= 0; i < settings.PhotoTagger.size; i++) {
         preload_next_image();
        
      }
      var img_pool = settings.PhotoTagger.image_pool;
      var img = img_pool[img_pool.length-1];
      extend_image_pool(img.nid);
      
    });
    
    function preload_next_image() {
      i = settings.PhotoTagger.loaded;
      console.debug(i);
      var test = $('#image-' + i);
      if (test.length) {
        console.debug('image node already exists.')
        settings.PhotoTagger.loaded++;
        return;
      }
       
      var img_pool = settings.PhotoTagger.image_pool;
      if (i in img_pool) {
          img = $('<img id="image-' + i + '" class="inactive">');
          img.attr('src', img_pool[i].url);
          img.appendTo('#image-pool');
          settings.PhotoTagger.loaded++;
      }
      else {
        console.debug('failed to preload image. possibly end of array.')
      }
    
      return 
    }
    
    // function loads data for next N images
    function extend_image_pool(after_nid) {
      
       if (settings.PhotoTagger.extending) {
         console.debug('Already extending the pool.')
         return;
       }
       settings.PhotoTagger.extending = true;
       var base_path = Drupal.settings.basePath;
				$.ajax({
					// type : "POST",
					url : base_path + "ajax/tagger_get_list",
					type: "POST",
					data: {nid: after_nid},
					dataType: 'json',
				  cache: false,
					success : function(msg) {
            // @todo add new items to buffer
           new_image_pool = msg.data.image_pool;
            image_pool = settings.PhotoTagger.image_pool;
            var i = settings.PhotoTagger.size;
             
            for(j in new_image_pool) {
              image_pool[i]=new_image_pool[j];
              i++;
            }
            settings.PhotoTagger.size = i;
            settings.PhotoTagger.extending = false;
          },
					error: function(msg) {
						console.debug(msg);
            settings.PhotoTagger.extending = false;
					}
				});
      
    }
    
    function next_image() {
       console.debug('Now image is supposed to change to the next one.');
     
       var current = settings.PhotoTagger.current;
       var pool_size = settings.PhotoTagger.size;
       var next = current + 1; // @todo check that item exists

       // need to extend if we are close to the end
       var images_left = settings.PhotoTagger.size - 1 - settings.PhotoTagger.current;
       console.debug('Images to the end of array: '+ images_left);
       if(images_left < 10) {
          var img_pool = settings.PhotoTagger.image_pool;
          var img = img_pool[img_pool.length-1];
          extend_image_pool(img.nid);
       }

       if(next >= pool_size) {
         console.debug('last image.');
         return;
       } 
       
      //  var img = image_pool[next]; 
     //  console.debug(img);
     //  var src = img.url;
     
         $('#image-' + current).removeClass('active').addClass('inactive');
         $('#image-' + next).removeClass('inactive').addClass('active');
         settings.PhotoTagger.current = next;
         
        
       // here we save the numbers from the current image
       // $ajax...
   
        // on sucess we can preload another image
       preload_next_image(); 
       

        
       // at some point start removing old ones
   
    }
    
    function previous_image() {
       console.debug('Now image is supposed to change to the previous one.');
       
       var current = settings.PhotoTagger.current;
       var previous = current - 1; // @todo check that item exists
       
       $('#image-' + current).removeClass('active').addClass('inactive');
       $('#image-' + previous).removeClass('inactive').addClass('active');
       settings.PhotoTagger.current = previous;
       
       // here we save the numbers from the current image image
       // $ajax...
       
    }
    
    $('#tagsinput_tag').bind('keydown', function(e) {    
      if(this.value == '') {
        if (e.keyCode == 13 ) { // enter
              console.debug('enter key on empty value');
        } 
        else if (e.keyCode == 39) { // arrow right
           next_image();
           return false; 
        } 
        else if(e.keyCode == 37) { // arrow left
           previous_image();
           return false; 
        }
        else if(e.keyCode == 40) { // arrow down
           // @todo next value;
           return false; 
        }
        else {
          console.debug(e.keyCode);
        }
      }
    });
   
}}})(jQuery);