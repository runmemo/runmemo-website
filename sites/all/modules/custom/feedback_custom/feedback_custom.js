/**
 * @file provides custom functions of interactive feedback form.
 */
(function($) {

Drupal.behaviors.Runmemo = {
	attach: function (context) {
		if (($("#block-feedback-form")).length > 0) {

			$("#block-feedback-form .content").hide();
			$("body.page-feedback #block-feedback-form .content").show();
			$("body.page-feedback #block-feedback-form #feedback-form").show();
			
			var txt_link = parent.window.document.location;
			$("input#edit-url-hidden").val(txt_link);
		}
		
		var link_chg = $("div#link-display").text();
		$("#block-feedback-form h2").html('<a class="feedback-link-new" href="' + link_chg + '"></a>');

		if ($("#feedback-form .error").length > 0) {

			$("#block-feedback-form .content").show();
			$("#feedback-form").attr('style', 'display:block;');

		}

		/**
		 * Close overlay on close button click
		 */
		$("#fb_close_link").click(function() {

			parent.Drupal.overlay.close();

		});
	}
};
/**
 * Hide Overlay.
 */
Drupal.behaviors.feedbackFormSubmit = {
  attach: function (context) {
	  var $context = $(context);
	    if (!$context.is('#feedback-status-message')) {
	      return;
	    }
	  parent.Drupal.overlay.close();
  }

};
	
})(jQuery);
			

	