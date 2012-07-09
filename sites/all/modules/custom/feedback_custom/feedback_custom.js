/**
 * @file provides custom functions of interactive feedback form.
 */
(function($) {

	Drupal.behaviors.feedbackFormCustom = {
		attach: function (context) {
			/**
			 * Close overlay on close button click
			 */
			$("#fb_close_link").click(function() {
				$('#block-feedback-form .feedback-link').click();
			});
		}
	};

})(jQuery);
			

	