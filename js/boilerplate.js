
/**
 * @file
 * Boilerplate module JS.
 *
 * Created by: Topsitemakers
 * http://www.topsitemakers.com/
 */
(function ($) {
  Drupal.behaviors.boilerplateModule = {
    attach: function (context, settings) {

      // Let's check if the user has AdBlock enabled.
      $('body').once('adblock', function() {
        if (window.AdBlockNotPresent !== undefined) {
          console.log('You do not have AdBlock enabled.');
        }
        else {
          console.log('You have AdBlock enabled.');
        }
      });

      // Sample action.
      /*
      $('#header', context).click(function () {
        console.log('Called from boilerplate.js');
      });
      */

    }
  };
})(jQuery);
