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
  // Define our token type.
  $types['boilerplate-test'] = array(
    'name' => t('Boilerplate'),
    'description' => t('Sample token created from a custom module.'),
  );
  // Define specific tokens.
  $tokens['time'] = array(
    'name' => t('Time'),
    'description' => t('Shows the current time.'),
  );
  $tokens['md5'] = array(
    'name' => t('MD5 Time'),
    'description' => t('Generates an MD5 hash of current time.'),
  );
  return array(
    'types' => $types,
    'tokens' => array(
      'boilerplate' => $tokens,
    ),
  );
}

/**
 * Implements hook_tokens().
 */
function boilerplate_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();
  switch ($type) {
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
