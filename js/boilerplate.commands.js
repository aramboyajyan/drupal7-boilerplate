
/**
 * @file
 * Custom AJAX commands.
 *
 * Created by: Topsitemakers
 * http://www.topsitemakers.com/
 */

(function ($) {
  Drupal.boilerplateModule = {};

  /**
   * Add a value to the window.
   */
  Drupal.boilerplateModule.addValueToWindow = function(ajax, data, status) {
    window[data.key] = data.value;
  }

  /**
   * Log a value to the console.
   */
  Drupal.boilerplateModule.logToConsole = function(ajax, data, status) {
    console.log(data.value);
  }

  $(function() {
    Drupal.ajax.prototype.commands.addValueToWindow = Drupal.boilerplateModule.addValueToWindow;
    Drupal.ajax.prototype.commands.logToConsole = Drupal.boilerplateModule.logToConsole;
  });

})(jQuery);
