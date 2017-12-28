<?php

/**
 * @file
 * Views hooks and callback registries.
 *
 * Created by: Topsitemakers
 * http://www.topsitemakers.com/
 */


/**
 * Implements hook_views_data().
 */
function boilerplate_views_data() {
  /**
   * Custom fields.
   */
  $data['node']['boilerplate_views_field_sample'] = array(
    'title' => t('Sample field'),
    'help' => t('Sample Views field for the node entity provided by the boilerplate module. Displays base64 encoded node title.'),
    'field' => array(
      'handler' => 'boilerplate_views_field_sample',
    ),
  );

  /**
   * Dynamic filters.
   */
  $data['node']['boilerplate_views_node_even_nid'] = array(
    'title' => t('Even NID'),
    'help' => t('Dynamic filter that filters only nodes that have an even node ID.'),
    'filter' => array(
      'handler' => 'boilerplate_views_node_even_nid',
    ),
  );

  return $data;
}


/**
 * Implements hook_views_plugins().
 */
function boilerplate_views_plugins() {
  return array(
    'access' => array(
      'even_uids' => array(
        'title' => t('Even user IDs'),
        'help' => t('Checks whether or not the current user ID is even.'),
        'handler' => 'boilerplate_views_plugin_access_even_uids',
      ),
    ),
  );
}
