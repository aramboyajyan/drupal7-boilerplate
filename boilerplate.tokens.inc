<?php

/**
 * @file
 * Builds placeholder replacement tokens.
 *
 * Created by: Topsitemakers
 * http://www.topsitemakers.com/
 */

/**
 * Implements hook_token_info().
 */
function boilerplate_token_info() {
  /**
   * Define token type.
   */
  $types['boilerplate'] = array(
    'name' => t('Boilerplate'),
    'description' => t('Sample token created from a custom module.'),
  );

  /**
   * Provide custom tokens.
   *
   * The array key must match the type we defined above.
   */
  $tokens['boilerplate']['time'] = array(
    'name' => t('Time'),
    'description' => t('Shows the current time.'),
  );
  $tokens['boilerplate']['md5'] = array(
    'name' => t('MD5 Time'),
    'description' => t('Generates an MD5 hash of current time.'),
  );

  /**
   * Provide additional tokens for existing token types.
   */
  // Real username, not formatted user's name. This is important because the
  // token provided by default will return formatted user's name, which can be
  // changed using hook_username_alter().
  $tokens['user']['username'] = array(
    'name' => t('Real username'),
    'description' => t('Real username.'),
  );

  return array(
    'types' => $types,
    'tokens' => $tokens,
  );
}

/**
 * Implements hook_tokens().
 */
function boilerplate_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  switch ($type) {
    // Username replacements.
    case 'user':
    case 'account':
    case 'current-user':
      foreach ($tokens as $name => $original) {
        switch ($name) {
          case 'username':
            $replacements[$original] = $data['user']->name;
            break;
        }
      }
      break;

    // Our sample group.
    case 'boilerplate-test':
      foreach ($tokens as $name => $original) {
        switch ($name) {
          case 'time':
            $replacements[$original] = REQUEST_TIME;
            break;

          case 'md5':
            $replacements[$original] = md5(REQUEST_TIME);
            break;
        }
      }
      break;
  }
  return $replacements;
}
