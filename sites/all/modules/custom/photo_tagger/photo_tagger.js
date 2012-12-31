
(function($) {
  Drupal.behaviors.runmemoPhotoTagger = {
    attach : function(context, settings) {
      
      /**
     * Apply tagsInput.
     */
      $('#tagsinput').tagsInput({
        //   'autocomplete_url': url_to_autocomplete_api,
        //   'autocomplete': { option: value, option: value},
        'height':'188px',
        'width':'100px',
        'interactive': true,
        'defaultText':'add number',
        'onAddTag' : onAddTag,
        'onRemoveTag' : onRemoveTag,
        //  'onChange' : onChangeTag,
        'removeWithBackspace' : false,
        'minChars' : 1,
        'maxChars' : 6 //if not provided there is no limit,
      // 'placeholder' : 'add number',
      //   'placeholderColor' : '#666666'
      });

      function onRemoveTag(elem) {
        tagger_numbers_changed();
      }
    
      function onAddTag(elem) {
        tagger_numbers_changed();
      }

      function tagger_numbers_changed() {
        var current = settings.PhotoTagger.current;
        var img_pool = settings.PhotoTagger.image_pool;
        img_pool[current].status = 'changed';
      }
    
      $(document).ready(function() {
        show_message('Keyboard shortcuts will help you to tag faster.');
        show_current_counter(1);
        settings.PhotoTagger.first = 0;
        settings.PhotoTagger.loaded = 0;
        settings.PhotoTagger.extending = false; // defines whether request was sent
        // to get new items to image buffer
        settings.PhotoTagger.complete = false; // defines whether all images were
        // loaded to the image pool buffer
      
        var nid = 0;
        for(var i= 0; i < settings.PhotoTagger.size; i++) {
          preload_next_image();
        
        }
      });
    
      function preload_next_image() {
        i = settings.PhotoTagger.loaded;
        var test = $('#image-' + i);
        if (test.length) {
          console.debug('Image node already exists.')
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
            console.debug('No images left to load.');
          } else {
            console.debug('Failed to preload image. possibly end of array.');
          }
        }
      
        // here we remove img nodes of old images
        //  don't do that currently as this does not affect memory usage
        //        current = settings.PhotoTagger.current;
        //        first = settings.PhotoTagger.first;
        //        if (current - first > 100) {
        //          $('#image-' + first).remove();
        //          first = settings.PhotoTagger.first = first + 1;
        //        }
        
        return;
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
          data: {
            nid: after_nid
          },
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
   
      function next_image(step) {
       
        var current = settings.PhotoTagger.current;
        var first = settings.PhotoTagger.first;
        if (current == first && step == -1) {
          show_message('You are back to the first available image.');
          return;
        }
        var pool_size = settings.PhotoTagger.size;
        var next = current + step; // @todo check that item exists
       
        // save numbers for the current photo
        save_tags() 
       
        // leave if we reached the end
        if (next >= pool_size) {
          show_message('Congratulations! You\'ve reached the last image.');
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
      
        // hide current image and show the next one
        $('#image-' + current).removeClass('active').addClass('inactive');
        $('#image-' + next).removeClass('inactive').addClass('active');
        show_saved_tags(next);
        show_current_counter(next+1); 
        settings.PhotoTagger.current = next;
         
        set_enter_shortcut_message('Next photo');
   
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
    
      function save_tags() {
        var img_pool = settings.PhotoTagger.image_pool;
        current = settings.PhotoTagger.current
      
      
        if (!('status' in img_pool[current]) 
          || img_pool[current].status !== 'saved'
          || img_pool[current].status !== 'saving') {
          // numbers were not set or were not saved yet
          var tagsinput = $("#tagsinput").siblings(".tagsinput").children(".tag");  
          var tags = [];  
          for (var i = tagsinput.length; i--;) {  
            tags.push($(tagsinput[i]).text().substring(0, $(tagsinput[i]).text().length -  1).trim());    
          } 
          
          img_pool[current].tags = tags; // here we cache tags
          var nid = img_pool[current].nid;
          ajax_save_numbers(current, nid, tags);  
          
        } else {
          console.debug('numbers did not change, changing photo.')
        }
      }
    
      function ajax_save_numbers(current, nid, tags) {
        var base_path = Drupal.settings.basePath;
        img = settings.PhotoTagger.image_pool[current];
        img.status = 'saving';
        show_message('Saving numbers for image ['+ current + '].');
        $.ajax({
          // type : "POST",
          url : base_path + "ajax/tagger_save_numbers",
          type: "POST",
          data: {
            nid: nid, 
            tags: tags
          },
          dataType: 'json',
          cache: false,
          success : function(msg) {
            settings.PhotoTagger.image_pool[current].status = 'saved';
            show_message('Saved numbers for image ['+ current + '].');
          },
          error: function(msg) {
            img.status = 'failed';
            show_message('Failed to save numbers to image ['+ current + '].');
            console.debug(msg);     
          }
        });
      
      }
      
      function show_message(msg) {
        $('#message-bar #message').html(msg);
      }
    
      function show_current_counter(msg) {
        $('#counter').html(msg);
      }
    
      function show_saved_tags(i) {
      
        // load values from previous image
      
        if('tags' in settings.PhotoTagger.image_pool[i]) {
          var tags = settings.PhotoTagger.image_pool[i].tags;
          $('#tagsinput').importTags(tags.join());
          $('#tagsinput_tag').focus();
          set_enter_shortcut_message('Next photo');
        }    
      }
    
      function set_enter_shortcut_message(msg) {
        $('#next_key_enter .key-action').html(msg);
      }
    
      $('#tagsinput_tag').bind('keydown', function(e) {    
        if(this.value == '') {
          if (e.keyCode == 8) { // backspace
            $('#tagsinput').importTags(''); // clear tags
          }
          else if (e.keyCode == 13 ) { // key enter
            next_image(1);
          } 
          else if (e.keyCode == 39) { // arrow right
            next_image(1);
            return false; 
          } 
          else if(e.keyCode == 37) { // arrow left
            next_image(-1);
            return false; 
          }
          else if(e.keyCode == 40) { // arrow down
            // @todo next value;
            return false; 
          }
          else {
            // @todo may be need to cancel out non numeric chars
          }
        } else {
          if (e.keyCode == 13 ) { // key enter
            set_enter_shortcut_message('Next photo');
          } else {
            set_enter_shortcut_message('Add number');
          }
        }
      });
    
      /**
     * Click event for the next arrow right shortcut.
     */
      $('#next_key_right').bind('click', function() {
        next_image(1);
      });
    
    
    /**
     * Click event for the next arrow right shortcut.
     */
      $('#next_key_enter').bind('click', function() {
        if($('#tagsinput_tag').value == '') {
          next_image(1);
        }
      });
     
    /**
     * Click event for the previous arrow left shortcut.
     */
      $('#previous_key_left').bind('click', function() {
        next_image(-1);
      });
   
    /**
     * Click event for the previous arrow left shortcut.
     */
      $('#backspace_key').bind('click', function() {
        $('#tagsinput').importTags(''); // clear tags
      });
    }
  }
})(jQuery);