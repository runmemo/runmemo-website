jQuery(document).ready(function($) {
	$('.front #runner_number').val('My Number');
	$('.recent-event .form-text').val('My Number');
	
	
	$('#user-login #edit-name').val('Username');
	
	$('#edit-pass').hide();
	
	
	// for remove the set message when adding items in the cart
	if ($('.messages a').length > 0) {

		if ($('.messages a').html() == 'your shopping cart') {
			$('.messages').attr('style', 'display:none');
		}
	}
	
});


/**
 * jQuery Behaviors for home page elements
 */
(function($) {
	Drupal.behaviors.runmemoHomePage = {
		attach : function(context, settings) {
		
			// runner number in the find section for front page
			$('.front #runner_number').focus( function() {
				if ($(this).val() == 'My Number') {
					$(this).val("");
				}
			});
			$('.front #runner_number').blur( function() {
				if ($(this).val() == '') {
					$(this).val('My Number');
				}
			});
	
			$('.front #runner_number').change( function() {
				if ($(this).val() == '') {
					$(this).val('My Number');
				}
			});
			
			$('#user-login #edit-name').focus( function() {
				if ($(this).val() == 'Username') {
					$(this).val("");
				}
			});
		
			$('#user-login #edit-name').blur( function() {
				if ($(this).val() == '') {
					$(this).val('Username');
				}
			});
		
			$('#edit-pass').blur( function() {
			    if ($(this).attr('value') == '') {
			        $(this).hide();
			        $('#edit-pass-fake').show();
			    }
				
			});
			
			$('#edit-pass-fake').focus( function() {
				 $(this).hide();
				 $('#edit-pass').show();
				 $('#edit-pass').focus();
			});
		
			
			// recent event 'My Number' text
			$('.recent-event .form-text').focus( function() {

				if ($(this).val() == 'My Number') {
					$(this).val("");
				}
			});
			// on recent event blur
			$('.recent-event .form-text').blur( function() {

				if ($(this).val() == '') {
					$(this).val('My Number');
				}
			});
			$(".recent-event .form-text").change( function() {
				if ($(this).val() == '') {
					$(this).val("My Number");
				}
			});
		}
	};
})(jQuery);
