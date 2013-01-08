
(function($) {
  Drupal.behaviors.PhotoTagger = {
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
        tagger.Changed();
      }
    
      function onAddTag(elem) {
        tagger.Changed();
      }

      var tagger = settings.PhotoTagger;
      tagger.first = 0;
      tagger.loaded = 0;      
      tagger.extending = false; // defines whether request was sent
                                // to get new items to image buffer
      tagger.complete = false;  // defines whether all images were
                                // loaded to the image pool buffer
      tagger.$images = [];
      
      tagger.Changed = function () {
        img = this.image_pool[this.current]
        img.status = 'changed';
      }
      
      $(document).ready(function() {
        for(var i= 0; i < tagger.size; i++) {
          tagger.PreloadNextImage();
        }
      });
    
      tagger.PreloadNextImage = function() {
        i = this.loaded;
        var $img = $('#image-' + i); // check whether img element exists
        if ($img.length > 0) {
          this.$images[i] = $img;
          this.loaded++;
          return;
        }
       
        if (i in this.image_pool) {
          $img = $('<img id="image-' + i + '" class="inactive">');
          $img.attr('src', this.image_pool[i].url);
          $img.appendTo('#image-pool');
          this.$images[i] = $img;
          this.loaded++;
        }
        else {
          if(this.complete) {
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
      tagger.Extend =  function (after_nid) {
      
        if(this.complete == true) {
          console.debug('Pool is fully loaded.');
          return;
        }
      
        if (this.extending) {
          console.debug('Already extending the pool.');
          return;
        }
        
        this.extending = true;
        var base_path = settings.basePath;
        var tagger = this;
        $.ajax({
          url : base_path + "ajax/tagger_get_list",
          type: "POST",
          data: {nid: after_nid},
          dataType: 'json',
          cache: false,
          success : function(msg) {
            // @todo add new items to buffer
            new_image_pool = msg.data.image_pool;
          
            var i = tagger.size;
             
            for(j in new_image_pool) {
              tagger.image_pool[i]=new_image_pool[j];
              i++;
            }
            tagger.size = i;
            tagger.extending = false;
          
            if (new_image_pool.length == 0) {
              tagger.complete = true;
            } 
            else {
              tagger.PreloadNextImage();
            }
          },
          error: function(msg) {
            console.debug(msg);
            tagger.extending = false;
          }
        });
      
      }
   
      tagger.NextImage = function (step) {
       
       if (this.current == this.first && step == -1) {
          show_message(Drupal.t('You are back to the first available image.'));
          return;
        }
       
        var next = this.current + step; // @todo check that item exists
                
       
        // save numbers for the current photo
        this.SaveChanges();
       
        // leave if we reached the end
        if (next >= this.size) {
          if (this.extending) {
            show_message(Drupal.t('We are loading more images for you.'));
          } else {
            show_message(Drupal.t('Congratulations! You\'ve reached the last image.'));
          }
          return;
        } 
       
        // hide current image and show the next one
        if (this.current in this.$images) {
          this.$images[this.current].removeClass('active').addClass('inactive');
        }
      
        this.current = next;
        this.RefreshControls();
        
        // need to extend if we are close to the end
        var images_left = this.size - 1 - this.current;
        console.debug('Images to the end of array: '+ images_left);
        if(images_left < 10) {
          var img = this.image_pool[this.image_pool.length-1];
          this.Extend(img.nid);
        }
        
        // preload another image
        this.PreloadNextImage();         
      }
      
      tagger.RefreshControls = function () {
        show_current_counter(this.current + 1);
        show_shortcut('key_enter', true, Drupal.t('Next photo'));
        img = this.image_pool[this.current];
        if ('delete_status' in img) {
          show_message(Drupal.t('This photo was deleted.'));
          show_shortcut('key_delete', false, '');
        } else {
          tagger.$images[this.current].removeClass('inactive').addClass('active');
          show_message('');
          show_shortcut('key_delete', true, Drupal.t('Delete photo'));
          show_saved_tags(this.current); 
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
    
      tagger.SaveChanges = function () {
        var img = this.image_pool[this.current];
        var nid = img.nid;
        
        if ('delete_status' in img) {
          if(img.delete_status == 'delete') {
             ajax_delete_node(this.current, nid);
             return;
          }
          // no need to save anything if image was deleted;
          return;
        }
        
        if ('status' in img) {
          if  (img.status == 'changed') {
            // numbers were not set or were not saved yet
            var tagsinput = $("#tagsinput").siblings(".tagsinput").children(".tag");  
            var tags = [];  
            for (var i = tagsinput.length; i--;) {  
              tags.push($(tagsinput[i]).text().substring(0, $(tagsinput[i]).text().length -  1).trim());    
            } 
            img.tags = tags; // here we cache tags
            ajax_save_numbers(this.current, nid, tags);  
          } 
        } else {
          console.debug(Drupal.t('Numbers did not change, changing photo.'))
        }
      }
    
      function ajax_save_numbers(current, nid, tags) {
        var base_path = settings.basePath;
        var img = tagger.image_pool[current];
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
            tagger.image_pool[current].status = 'saved';
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
      tagger.DeleteCurrent = function () {
        var img = this.image_pool[this.current];
        if('delete_status' in img) {
          if(img.delete_status == 'delete') {
            delete img.delete_status;
            show_shortcut('key_delete', true, Drupal.t('Delete photo'));
            show_message('');
          } else {
            show_message(Drupal.t('This photo was deleted.'))
          }
        } else {
           img.delete_status = 'delete';
           show_shortcut('key_delete', true, Drupal.t('Undelete'));
           show_message(Drupal.t('This photo will be deleted. Press Delete key to undo.'));
        }
       
      }
      
      /**
       * AJAX call to delete product node for the image
       */
      function ajax_delete_node(current, nid) {
        var base_path = settings.basePath;
        img = tagger.image_pool[current];
        img.delete_status = 'deleting';
        
        show_delete_icon(nid);
        
        $.ajax({
          url : base_path + "ajax/tagger_delete_node",
          type: "POST",
          data: {nid: nid},
          dataType: 'json',
          cache: false,
          success : function(msg) {
            tagger.image_pool[current].delete_status = 'deleted';
            tagger.image_pool[current].url = '';
            tagger.$images[current].remove();
            
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
      
      var $delete_icons = [];
      function show_delete_icon(nid) {
        $icon = $('<div id="delete-icon-' + nid + '" class="icon delete-icon" title="Deleting photo..."></div>');
        $('.icons').append($icon);
        $delete_icons[nid] = $icon;
      }
      
      function error_delete_icon(nid) {
        $delete_icons[nid].removeClass('delete-icon').addClass('delete-error-icon');
        $delete_icons[nid].attr('title', Drupal.t('Failed to delete photo.'))
      }
      
      function hide_delete_icon(nid) {
        $delete_icons[nid].remove(); 
      }
      
      var $save_icons = [];
      function show_save_icon(nid) {
        $icon = $('<div id="save-icon-' + nid + '" class="icon save-icon" title="Saving bib numbers..."></div>');
        $('.icons').append($icon);
        $save_icons[nid] = $icon;
      }
      
      function hide_save_icon(nid) {
         $save_icons[nid].remove(); 
      }
      
      function error_save_icon(nid) {
         $save_icons[nid].removeClass('save-icon').addClass('save-error-icon'); 
         $save_icons[nid].attr('title', Drupal.t('Failed to save bib numbers.')); 
      }
      
      var $msg = $('#message');
      function show_message(msg) {
        if (msg == '') {
          $msg.hide('slow');
          $msg.empty();
         // $('#message-bar').hide('slow');
        } 
        else {
          $msg.html(msg);
        //  $('#message-bar').show('slow');
          $msg.show("fast");
        }
      }
      
      
      var $current = $('#current');
      function show_current_counter(msg) {      
        var div = document.getElementById('current');
        div.innerHTML = msg;
        $current.show('slow');
      }
    
      function show_saved_tags(i) {
      
        // load values from previous image
        if('tags' in tagger.image_pool[i]) {
          var tags = tagger.image_pool[i].tags;
          $('#tagsinput').importTags(tags.join());
          $('#tagsinput_tag').focus();
        } 
        else {
          if(count_tags() > 0) {
            tagger.Changed();
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
            tagger.NextImage(1);            
          } 
          else if (e.keyCode == 39) { // arrow right
            tagger.NextImage(1);            
          } 
          else if (e.keyCode == 37) { // arrow left
            tagger.NextImage(-1);             
          }
          else if (e.keyCode == 40) { // arrow down
            // @todo next value;
            return; 
          }
          else if (e.keyCode == 46) { // delete key
            tagger.DeleteCurrent();
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
        tagger.NextImage(1);
      });
    
    
    /**
     * Click event for the enter key shortcut.
     */
      $('#key_enter').bind('click', function() {
        if(  $('#tagsinput_tag').value == '' ) {
          tagger.NextImage(1);
        }
      });
     
    /**
     * Click event for the previous arrow left shortcut.
     */
      $('#previous_key_left').bind('click', function() {
        tagger.NextImage(-1);
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
        tagger.DeleteCurrent();
      });
      
    }
  }
})(jQuery);