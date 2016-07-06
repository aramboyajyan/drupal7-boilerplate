<?php

/**
 * @file
 * Helper functions used in the module.
 *
 * Created by: Topsitemakers
 * http://www.topsitemakers.com/
 */

/**
 * Helper function - generate a random string.
 */
function _boilerplate_generate_random_string($length = 32) {
  $chars = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789';  
  $size  = strlen($chars);
  $str   = '';
  for ($i = 0; $i < $length; $i++) {
    $str .= $chars[rand(0, $size - 1)];
  }

  return $str;
}

/**
 * Helper function - get the list of all image styles on the site. For use in
 * administrative forms.
 */
function _boilerplate_get_image_styles() {
  $styles = array();
  $results = image_styles();
  foreach ($results as $result) {
    $styles[$item['name']] = $item['label'];
  }

  return $styles;
}

/**
 * Helper function - get the list of all users on the website. For use in
 * administrative forms.
 *
 * Optionally filter by a certain role.
 */
function _boilerplate_get_all_users($status = 1, $rids = NULL) {
  $users = array();
  $query = db_select('users', 'u')
    ->fields('u', array('uid', 'name'))
    ->condition('status', $status);
  if ($rids) {
    $query->leftJoin('users_roles', 'ur', 'ur.uid = u.uid');
    $query->leftJoin('role', 'r', 'r.rid = ur.rid');
    $query->condition('r.rid', $rids);
  }
  $results = $query->execute();
  foreach ($results as $result) {
    $users[$result->uid] = t('@name (ID: @uid)', array('@name' => $result->name, '@uid' => $result->uid));
  }

  return $users;
}

/**
 * Helper function - get the list of all roles on the website. For use in
 * administrative forms.
 */
function _boilerplate_get_roles() {
  $roles = array();
  $results = db_query("SELECT rid, name FROM {role} ORDER BY weight ASC");
  foreach ($results as $result) {
    $roles[$result->rid] = t('@name (ID: @rid)', array('@name' => ucfirst($result->name), '@rid' => $result->rid));
  }

  return $roles;
}

/**
 * Helper function - get the list of all nodes of specific type. For use in
 * administrative forms.
 */
function _boilerplate_get_all_nodes($type = NULL, $status = NODE_PUBLISHED) {
  $query = db_select('node', 'n')
    ->addTag('node_access')
    ->fields('n', array('nid', 'title'))
    ->condition('status', $status)
    ->orderBy('title', 'ASC');
  if (!empty($type)) {
    $query->condition('type', $type);
  }
  $results = $query
    ->execute()
    ->fetchAll();
  $nodes = array();
  foreach ($results as $result) {
    $nodes[$result->nid] = t('@title (ID: @nid)', array('@title' => $result->title, '@nid' => $result->nid));
  }

  return $nodes;
}

/**
 * Helper function - get the list of all node types. For use in administrative
 * forms.
 */
function _boilerplate_get_all_node_types() {
  $types = array();
  $results = db_query("SELECT type, name FROM {node_type} ORDER BY name");
  foreach ($results as $result) {
    $types[$result->type] = t('@name (machine name: @machine_name)', array('@name' => $result->name, '@machine_name' => $result->type));
  }

  return $types;
}

/**
 * Helper function - get the list of all fields. For use in administrative
 * forms.
 */
function _boilerplate_get_all_fields() {
  $fields = array();
  // We only need field names; it's way easier and faster to query the database
  // directly, than to invoke field_info_fields() and get all extra information
  // we don't need at all.
  $results = db_query("SELECT field_name FROM {field_config} ORDER BY field_name ASC");
  foreach ($results as $result) {
    $fields[$result->field_name] = $result->field_name;
  }

  return $fields;
}

/**
 * Helper function - get the list of all vocabularies. For use in administrative
 * forms.
 */
function _boilerplate_get_all_vocabularies() {
  $vocabularies = array();
  $results = db_query("SELECT vid, name FROM {taxonomy_vocabulary} ORDER BY weight ASC");
  foreach ($results as $result) {
    $vocabularies[$result->vid] = t('@vocabulary (ID: @vid)', array('@vocabulary' => $result->name, '@vid' => $result->vid));
  }

  return $vocabularies;
}

/**
 * Helper function - get the name of the country given the abbreviation.
 */
function _boilerplate_country($country) {
  $countries = &drupal_static(__FUNCTION__);
  if (empty($countries)) {
    require_once DRUPAL_ROOT . '/includes/locale.inc';
    $countries = country_get_list();
  }
  
  // Country abbreviations will always be two uppercase letters. 
  $country = drupal_strtoupper($country);
  if (!empty($country) && isset($countries[$country])) {
    return check_plain($countries[$country]);
  }

  return check_plain($country);
}

/**
 * Helper function - secure string comparison.
 *
 * Taken from HTTP Auth library of Zend Framework.
 * See http://stackoverflow.com/q/10576827/1520477 for discussion.
 */
function _boilerplate_secure_compare($a, $b) {
  if (strlen($a) !== strlen($b)) {
    return FALSE;
  }
  $result = 0;
  for ($i = 0; $i < strlen($a); $i++) {
    $result |= ord($a[$i]) ^ ord($b[$i]);
  }
  return $result == 0;
}

/**
 * Helper function - check if the current request is an AJAX request.
 */
function _boilerplate_is_ajax_request() {
  return !empty($_SERVER['HTTP_X_REQUESTED_WITH']) && drupal_strtolower($_SERVER['HTTP_X_REQUESTED_WITH']) == 'xmlhttprequest';
}

/**
 * Helper function - trim a string.
 */
function _boilerplate_trim_string_with_ellipsis($string, $length) {
  if (strlen($string) > $length) {
    $string = drupal_substr($string, 0, $length) . '&hellip;';
  }

  return $string;
}

/**
 * Helper function - check if a user exists by username or email.
 */
function _boilerplate_check_if_user_exists($identifier) {
  $query = db_select('users', 'u')
    ->fields('u', array('uid'));

  $identifier = drupal_strtolower($identifier);
  if (valid_email_address($identifier)) {
    $query->condition('mail', $identifier);
  }
  else {
    $query->condition('name', $identifier);
  }

  $result = $query
    ->execute()
    ->fetchField();

  return (bool) $result;
}

/**
 * Helper function - get default avatar public path.
 */
function _boilerplate_get_default_avatar_public_path() {
  return 'public://' . strtr(variable_get('user_picture_default'), array(
    variable_get('file_public_path', 'sites/default/files') . '/' => '',
  ));
}

/**
 * Helper function - get the user picture URI or get the one from default
 * picture.
 */
function _boilerplate_get_user_picture_or_default($account, $preset) {
  if (isset($account->picture->uri)) {
    $uri = $account->picture->uri;
  }
  else {
    $uri = _boilerplate_get_default_avatar_public_path();
  }

  return image_style_url($preset, $uri);
}

/**
 * Helper function - get aliased argument.
 */
function _boilerplate_get_aliased_arg($key = 0) {
  $items = explode('/', current_path());

  if (isset($items[$key])) return $items[$key];

  return FALSE;
}

/**
 * Helper function - clear views cache.
 */
function _boilerplate_clear_views_cache($view_name) {
  cache_clear_all('ctools_export:views_view:' . $view_name, 'cache_views', TRUE);
  cache_clear_all($view_name, 'cache_views_data', TRUE);
}
