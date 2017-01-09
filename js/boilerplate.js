
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

      // Sample action.
      /*
      $('#header', context).click(function () {
        console.log('Called from boilerplate.js');
      });
      */

      // Let's check if the user has AdBlock enabled.
      if (window.AdBlockNotPresent !== undefined) {
        console.log('You do not have AdBlock enabled.');
      }
      else {
        console.log('You have AdBlock enabled.');
      }

    }
  };
})(jQuery);
