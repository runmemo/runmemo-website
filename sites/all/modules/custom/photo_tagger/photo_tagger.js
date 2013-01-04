
(function($) {
  Drupal.behaviors.runmemoPhotoTagger = {
    attach : function(context, settings) {
      
      /**
     * Apply tagsInput.
     */
      $('#tagsinput').tagsInput({
        //   'autocomplete_url': url_to_autocomplete_api,
        //   'autocomplete': { option: value, option: value},
        'height':'183px',
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
     
        settings.PhotoTagger.first = 0;
        settings.PhotoTagger.loaded = 0;
        settings.PhotoTagger.extending = false; // defines whether request was sent
        // to get new items to image buffer
        settings.PhotoTagger.complete = false; // defines whether all images were
        // loaded to the image pool buffer
      
        for(var i= 0; i < settings.PhotoTagger.size; i++) {
          preload_next_image();
        }
      });
    
      function preload_next_image() {
        i = settings.PhotoTagger.loaded;
        var test = $('#image-' + i); // check whether img element exists
        if (test.length) {
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
          console.debug('Pool is fully loaded.');
          return;
        }
      
        if (settings.PhotoTagger.extending) {
          console.debug('Already extending the pool.');
          return;
        }
        settings.PhotoTagger.extending = true;
        var base_path = Drupal.settings.basePath;
        $.ajax({
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
            else {
              preload_next_image();
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
          show_message(Drupal.t('You are back to the first available image.'));
          return;
        }
        var pool_size = settings.PhotoTagger.size;
        var next = current + step; // @todo check that item exists
                
       
        // save numbers for the current photo
        save_changes();
       
        // leave if we reached the end
        if (next >= pool_size) {
          if (settings.PhotoTagger.extending) {
            show_message(Drupal.t('We are loading more images for you.'));
          } else {
            show_message(Drupal.t('Congratulations! You\'ve reached the last image.'));
          }
          return;
        } 
       
        var img_pool = settings.PhotoTagger.image_pool;
      
        // hide current image and show the next one
        if ($('#image-' + current).length > 0) {
          $('#image-' + current).removeClass('active').addClass('inactive');
        }
      
        settings.PhotoTagger.current = next;
        
        console.log('Now at photo [' + (next + 1) +'].');
        
        show_current_counter(next + 1);
        show_shortcut('key_enter', true, Drupal.t('Next photo'));
        
        set_controls_new_photo(next);
        
        // need to extend if we are close to the end
        var images_left = pool_size - 1 - current;
        console.debug('Images to the end of array: '+ images_left);
        if(images_left < 10) {
          var img = img_pool[img_pool.length-1];
          extend_image_pool(img.nid);
        }
        
        // preload another image
        preload_next_image();         
      }
      
      function set_controls_new_photo(current) {

        if ('delete_status' in settings.PhotoTagger.image_pool[current]) {
          show_message(Drupal.t('This photo was deleted.'));
          show_shortcut('key_delete', false, '');
        } else {
          $('#image-' + current).removeClass('inactive').addClass('active');
          show_message('');
          show_shortcut('key_delete', true, Drupal.t('Delete photo'));
          show_saved_tags(current); 
        }
        return;
      }
    
      function count_tags() {
        var tagsinput = $("#tagsinput").siblings(".tagsinput").children(".tag");  
        var tags = [];  
        for (var i = tagsinput.length; i--;) {  
          tags.push($(tagsinput[i]).text().substring(0, $(tagsinput[i]).text().length -  1).trim());    
        } 
        return tags.length;
      }
    
      function save_changes() {
        var img_pool = settings.PhotoTagger.image_pool;
        var current = settings.PhotoTagger.current
        var nid = img_pool[current].nid;
        
        if ('delete_status' in img_pool[current]) {
          if(img_pool[current].delete_status == 'delete') {
             ajax_delete_node(current, nid);
             return;
          }
          // no need to save anything if image was deleted;
          return;
        }
        
        if ('status' in img_pool[current]) {
          if  (img_pool[current].status == 'changed') {
            // numbers were not set or were not saved yet
            var tagsinput = $("#tagsinput").siblings(".tagsinput").children(".tag");  
            var tags = [];  
            for (var i = tagsinput.length; i--;) {  
              tags.push($(tagsinput[i]).text().substring(0, $(tagsinput[i]).text().length -  1).trim());    
            } 
            img_pool[current].tags = tags; // here we cache tags
            ajax_save_numbers(current, nid, tags);  
          } 
        } else {
          console.debug(Drupal.t('Numbers did not change, changing photo.'))
        }
      }
    
      function ajax_save_numbers(current, nid, tags) {
        var base_path = Drupal.settings.basePath;
        var img = settings.PhotoTagger.image_pool[current];
        img.status = 'saving';
        
        show_save_icon(nid);
        
        show_message(Drupal.t('Saving numbers for image [!current].', {'!current': current + 1}));
        $.ajax({
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
            show_message(Drupal.t('Saved numbers for image [!current].', {'!current': current + 1}));
            hide_save_icon(nid);
          },
          error: function(msg) {
            img.status = 'failed';
            show_message(Drupal.t('Failed to save numbers to image [!current].', {'!current': current + 1}));
            error_save_icon(nid)
            console.debug(msg);     
          }
        });
      
      }
      
      /**
       * Shows or hides shortcut for specific id
       */
      function show_shortcut(id, show, msg) {
        if(show) {
          $('#' + id + ' .key-action').text(msg);
          $('#' + id).show();
        } else {
          //$('#' + id).hide();
          $('#' + id + ' .key-action').empty();
        }
        
      }
      
      /**
       * Sets delete_status of the current message
       */
      function delete_current() {
        var img_pool = settings.PhotoTagger.image_pool;
        var current = settings.PhotoTagger.current;
        if('delete_status' in img_pool[current]) {
          if(img_pool[current].delete_status == 'delete') {
            delete img_pool[current].delete_status;
            show_shortcut('key_delete', true, Drupal.t('Delete photo'));
            show_message('');
          } else {
            show_message(Drupal.t('This photo was deleted.'))
          }
        } else {
           img_pool[current].delete_status = 'delete';
           show_shortcut('key_delete', true, Drupal.t('Undelete'));
           show_message(Drupal.t('This photo will be deleted. Press Delete key to undo.'));
        }
       
      }
      
      /**
       * AJAX call to delete product node for the image
       */
      function ajax_delete_node(current, nid) {
        var base_path = Drupal.settings.basePath;
        img = settings.PhotoTagger.image_pool[current];
        img.delete_status = 'deleting';
        
        show_delete_icon(nid);
        
        $.ajax({
          url : base_path + "ajax/tagger_delete_node",
          type: "POST",
          data: {nid: nid},
          dataType: 'json',
          cache: false,
          success : function(msg) {
            settings.PhotoTagger.image_pool[current].delete_status = 'deleted';
            settings.PhotoTagger.image_pool[current].url = '';
            $('#image-' + current).remove();
            
            hide_delete_icon(nid);         
            console.debug(msg);
          },
          error: function(msg) {
            img.delete_status = 'failed';
            show_message(Drupal.t('Failed to delete photo [!current].', {'!current' : current + 1}));
            error_delete_icon(nid)
            console.debug(msg);     
          }
        });
      }
      
      
      function show_delete_icon(nid) {
        icon = $('<div id="delete-icon-' + nid + '" class="icon delete-icon" title="Deleting photo..."></div>');
        $('.icons').append(icon);
      }
      
      function error_delete_icon(nid) {
        $('#delete-icon-' + nid).removeClass('delete-icon').addClass('delete-error-icon');
        $('#delete-icon-' + nid).attr('title', Drupal.t('Failed to delete photo.'))
      }
      
      function hide_delete_icon(nid) {
        $('#delete-icon-' + nid).remove(); 
      }
      
      function show_save_icon(nid) {
        icon = $('<div id="save-icon-' + nid + '" class="icon save-icon" title="Saving bib numbers..."></div>');
        $('.icons').append(icon);
      }
      
      function hide_save_icon(nid) {
        $('#save-icon-' + nid).remove(); 
      }
      
      function error_save_icon(nid) {
        $('#save-icon-' + nid).removeClass('save-icon').addClass('save-error-icon'); 
        $('#save-icon-' + nid).attr('title', Drupal.t('Failed to save bib numbers.')); 
      }
      
      function show_message(msg) {
        if (msg == '') {
          $('#message').hide('slow');
          $('#message').empty();
         // $('#message-bar').hide('slow');
        } 
        else {
          $('#message').html(msg);
        //  $('#message-bar').show('slow');
          $('#message').show("fast");
        }
      }
    
      function show_current_counter(msg) {      
        var div = document.getElementById('current');
        div.innerHTML = msg;
        $('#current').show('slow');
      }
    
      function show_saved_tags(i) {
      
        // load values from previous image
        if('tags' in settings.PhotoTagger.image_pool[i]) {
          var tags = settings.PhotoTagger.image_pool[i].tags;
          $('#tagsinput').importTags(tags.join());
          $('#tagsinput_tag').focus();
        } 
        else {
          if(count_tags() > 0) {
            tagger_numbers_changed();
          }
        }
      }
      
      /**
       * Here we catch keys for shortcuts.
       */
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
          } 
          else if (e.keyCode == 37) { // arrow left
            next_image(-1);             
          }
          else if (e.keyCode == 40) { // arrow down
            // @todo next value;
            return; 
          }
          else if (e.keyCode == 46) { // delete key
            delete_current();
            return;
          }
          else {
            // @todo may be need to cancel out non numeric chars
            // console.log(e.keyCode);
          }
        } else {
          if (e.keyCode == 13 ) { // key enter
            show_shortcut('key_enter', true, Drupal.t('Next photo'));
          } else {
            show_shortcut('key_enter', true, Drupal.t('Add number'));
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
     * Click event for the enter key shortcut.
     */
      $('#key_enter').bind('click', function() {
        if(  $('#tagsinput_tag').value == '' ) {
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
     * Click event for the backspace key shortcut.
     */
      $('#backspace_key').bind('click', function() {
        $('#tagsinput').importTags(''); // clear tags
      });
      
   
    /**
     * Click event for the delete key shortcut.
     */
      $('#key_delete').bind('click', function() {
        delete_current();
      });
      
    }
  }
})(jQuery);