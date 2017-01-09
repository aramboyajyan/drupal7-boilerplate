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
    'topics' => array('docs-boilerplate'),
  );
  // Commandfiles may also add topics.  These will appear in
  // the list of topics when `drush topic` is executed.
  $items['docs-boilerplate'] = array(
    'description' => 'Info about boilerplate.',
    'hidden' => TRUE,
    'topic' => TRUE,
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'callback' => 'drush_print_file',
    'callback arguments' => array(dirname(__FILE__) . '/CHANGELOG.md'),
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
 * Implements drush_hook_COMMAND_validate().
 */
function drush_boilerplate_hello_validate() {
  $args = func_get_args();

  if ($args[0] == 'me') {
    $message = dt("You can't say hi to yourself");
    return drush_set_error('NON_AVAILABLE', $message);
  }
}

/**
 * Callback for the boilerplate-hello command.
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
