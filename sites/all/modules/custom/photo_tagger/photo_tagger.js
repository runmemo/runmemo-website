
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
      settings.PhotoTagger.complete = false;
      var nid = 0;
      for(var i= 0; i < settings.PhotoTagger.size; i++) {
         preload_next_image();
        
      }
    });
    
    function preload_next_image() {
      i = settings.PhotoTagger.loaded;
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
        if(settings.PhotoTagger.complete) {
           console.debug('No images left to load.')
        } else {
            console.debug('failed to preload image. possibly end of array.');
        }
      }
      
      // @todo here we can remove img nodes of old images
    
      return 
    }
    
    // function loads data for next N images
    function extend_image_pool(after_nid) {
      
      if(settings.PhotoTagger.complete == true) {
        console.debug('Pool is fully loaded.')
        return;
      }
      
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
          
            if (new_image_pool.length == 0) {
              settings.PhotoTagger.complete = true;
            }
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
       
       // leave if we reached the end
       if(next >= pool_size) {
         console.debug('last image.');
         return;
       } 
       
       var img_pool = settings.PhotoTagger.image_pool;
       
       // need to extend if we are close to the end
       var images_left = pool_size - 1 - current;
       console.debug('Images to the end of array: '+ images_left);
       if(images_left < 10) {
          var img = img_pool[img_pool.length-1];
          extend_image_pool(img.nid);
       }
       
       // save numbers to the current image
       var img = img_pool[current];
       var nid = img.nid;
       
       var tagsinput = $("#tagsinput").siblings(".tagsinput").children(".tag");  
        var tags = [];  
        for (var i = tagsinput.length; i--;) {  
            tags.push($(tagsinput[i]).text().substring(0, $(tagsinput[i]).text().length -  1).trim());    
      }       
      img_pool[current].tags = tags; // here we cache tags
      save_numbers(nid, tags); 
      
      $('#tagsinput').importTags(''); // clear tags
      
       // hide current image and show the next one
       $('#image-' + current).removeClass('active').addClass('inactive');
       $('#image-' + next).removeClass('inactive').addClass('active');
       settings.PhotoTagger.current = next;
         
        
       // here we save the numbers from the current image
       // $ajax...
   
        // on sucess we can preload another image
       preload_next_image(); 
        
       // at some point start removing old ones
   
    }
    
    function count_tags() {
      var tagsinput = $("#tagsinput").siblings(".tagsinput").children(".tag");  
      var tags = [];  
      for (var i = tagsinput.length; i--;) {  
            tags.push($(tagsinput[i]).text().substring(0, $(tagsinput[i]).text().length -  1).trim());    
      } 
      return tags.length;
    }
    
    function save_numbers(nid, tags) {
      var base_path = Drupal.settings.basePath;
				$.ajax({
					// type : "POST",
					url : base_path + "ajax/tagger_save_numbers",
					type: "POST",
					data: {nid: nid, tags: tags},
					dataType: 'json',
				  cache: false,
					success : function(msg) {
            console.debug(msg);
          },
					error: function(msg) {
						console.debug(msg);
           
					}
				});
      
    }
    
    function previous_image() {
       console.debug('Now image is supposed to change to the previous one.');
       
       var current = settings.PhotoTagger.current;
       
       if (current == 0) { // @todo check that item exists
         console.debug('Back to first image.')
         return;
       }
       
       var previous = current - 1; 
       
       $('#image-' + current).removeClass('active').addClass('inactive');
       $('#image-' + previous).removeClass('inactive').addClass('active');
       settings.PhotoTagger.current = previous;
       
       // here we save the numbers from the current image image
       // $ajax...
       
    }
    
    function get_tags_from_previous() {
      
      // load values from previous image
        previous = settings.PhotoTagger.current-1;
        if('tags' in settings.PhotoTagger.image_pool[previous]) {
          var tags = settings.PhotoTagger.image_pool[previous].tags
          console.debug(tags.join());
          $('#tagsinput').importTags(tags.join());
        }
        
    }
    
    $('#tagsinput_tag').bind('keydown', function(e) {    
      if(this.value == '') {
        if (e.keyCode == 13 ) { // key enter
          console.debug(count_tags());
          if(count_tags() == 0) { // no values provided
            get_tags_from_previous()
          } else {
            next_image();
          }
              
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