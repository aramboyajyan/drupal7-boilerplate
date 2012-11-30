<?php

/**
 * @file
 * Collection of module pages.
 *
 * Created by: Topsitemakers
 * http://www.topsitemakers.com/
 */

/**
 * Sample function - generate page content using theme() function and custom template.
 */
function boilerplate_sample_page_callback($argument1 = NULL, $argument2 = NULL) {
  return theme('sample-template', array('content' => 'Sample page content', 'argument1' => $argument1, 'argument2' => $argument2));
}

/**
 * Sample local tasks for user context.
 */
function boilerplate_local_task_user($account) {
  return 'Viewing user: ' . $account->name;
}

/**
 * Sample local tasks for user context.
 */
function boilerplate_local_task_node($node) {
  return 'Viewing node: ' . $node->title;
}
