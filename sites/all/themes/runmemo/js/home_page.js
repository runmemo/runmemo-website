jQuery(document).ready(function($) {
	$('.front #runner_number').val('My Number');
	$('.recent-event .form-text').val('My Number');
	
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
			// recent event 'My Number' text
			$('.recent-event .form-text').focus( function() {

				if ($(this).val() == 'My Number') {
					$(this).val("");
				}
			});
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
