<?php

/**
 * @file
 * Drush integration for boilerplate custom module.
 *
 * Created by: Topsitemakers
 * http://www.topsitemakers.com/
 */

/**
 * Implements hook_drush_command().
 */
function boilerplate_drush_command() {
  $items['boilerplate-hello'] = array(
    'callback' => 'boilerplate_hello_command',
    'description' => dt('Sample Drush command for boilerplate module.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(
      'name' => dt('Optional. A name which will be greeted upon running the command.'),
    ),
    'aliases' => array('boilerplate-hi'),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function boilerplate_drush_help($section) {
  switch ($section) {
    case 'meta:boilerplate:title':
      return dt("Boilerplate commands");

    case 'meta:boilerplate:summary':
      return dt("Interact with the Boilerplate module functionalities.");

    case 'drush:boilerplate-hello':
      return dt('Sample Drush command for boilerplate module. It will just greet you, optionally with a name you provided.');
  }
}

/**
 * Command to download the Chosen plugin.
 */
function boilerplate_hello_command() {
  $args = func_get_args();
  $name = (!empty($args[0])) ? $args[0] : FALSE;

  if ($name) {
    drush_log(dt('Hello @name!', array('@name' => $name)), 'success');
  }
  else {
    drush_log(dt('Hello there!'), 'success');
  }
}
