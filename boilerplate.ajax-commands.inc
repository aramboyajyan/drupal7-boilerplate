<?php

/**
 * @file
 * Custom AJAX commands.
 *
 * Created by: Topsitemakers
 * http://www.topsitemakers.com/
 */

/**
 * Add value to the window.
 */
function boilerplate_ajax_command_add_value_to_window($key, $value) {
  return array(
    'command' => 'addValueToWindow',
    'key' => $key,
    'value' => $value,
  );
}

/**
 * Log a value to browser console.
 */
function boilerplate_ajax_command_log_to_console($value) {
  return array(
    'command' => 'logToConsole',
    'value' => $value,
  );
}
