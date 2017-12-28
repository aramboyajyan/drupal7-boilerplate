<?php

/**
 * @file
 * Custom views access plugin.
 *
 * Created by: Topsitemakers
 * http://www.topsitemakers.com/
 */

/**
 * Access plugin that checks if current user ID is even.
 */
class boilerplate_views_plugin_access_even_uids extends views_plugin_access {

  function summary_title() {
    return t('Checks if current user ID is even');
  }

  function get_access_callback() {
    return array('kin_corridors_views_plugin_access_even_uids_callback', array());
  }

  function access($account) {
    return kin_corridors_views_plugin_access_even_uids_callback($account);
  }

}
