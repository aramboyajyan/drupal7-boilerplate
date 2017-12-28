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

  return $data;
}
