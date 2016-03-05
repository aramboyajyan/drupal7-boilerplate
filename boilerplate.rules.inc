<?php

/**
 * @file
 * Implementation of rules hooks and actions.
 *
 * Created by: Topsitemakers
 * http://www.topsitemakers.com/
 */

/**
 * Implements hook_rules_event_info().
 * 
 * @see boilerplate_sample_send_email()
 */
function boilerplate_rules_event_info() {
  return array(
    'boilerplate_rules_event_email_is_sent' => array(
      'label' => t('Boilerplate email is sent'),
      'help' => t('Triggers when an email is sent using custom function.'),
      'group' => t('Custom'),
      'variables' => array(
        'account' => array(
          'type' => 'user',
          'label' => t('User'),
          'description' => t('User who sent the email.'),
        ),
      ),
    ),
  );
}

/**
 * Implements hook_rules_condition_info().
 */
function boilerplate_rules_condition_info() {
  return array(
    'boilerplate_rules_condition_compare_nids' => array(
      'label' => t('Sample condition'), 
      'parameter' => array(
        'node1' => array(
          'label' => t('First node parameter'),
          'type' => 'node',
        ), 
        'node2' => array(
          'label' => t('Second node parameter'),
          'type' => 'node',
        ), 
      ), 
      'group' => t('Custom'),
    ),
  );
}
/**
 * Implements hook_rules_action_info().
 */
function boilerplate_rules_action_info() {
  return array(
    'boilerplate_rules_action_log_user_in' => array(
      'label' => t('Log in a user'),
      'group' => t('Custom'),
      'parameter' => array(
        'account' => array(
          'type' => 'user',
          'label' => t('User')
        ),
      ),
    ),
  );
}

/**
 * Rules action callback to login the user provided in the function parameter.
 */
function boilerplate_rules_action_log_user_in($account) {
  global $user;
  $user = user_load($account->uid);
  user_login_finalize();
}

/**
 * Rules condition callback to perform a sample check.
 */
function boilerplate_rules_condition_compare_nids($node1, $node2) {
  return $node1->nid == $node2->nid;
}
