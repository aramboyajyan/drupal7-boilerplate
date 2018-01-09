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
    $users[$result->uid] = t('@user_name (ID: @user_id)', array('@user_name' => $result->name, '@user_id' => $result->uid));
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
    $roles[$result->rid] = t('@role_name (ID: @role_id)', array('@role_name' => ucfirst($result->name), '@role_id' => $result->rid));
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
    $nodes[$result->nid] = t('@node_title (ID: @node_id)', array('@node_title' => $result->title, '@node_id' => $result->nid));
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
    $types[$result->type] = t('@content_type_label (machine name: @machine_name)', array('@content_type_label' => $result->name, '@machine_name' => $result->type));
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
    $vocabularies[$result->vid] = t('@vocabulary (ID: @vocabulary_id)', array('@vocabulary' => $result->name, '@vocabulary_id' => $result->vid));
  }

  return $vocabularies;
}

/**
 * Helper function - get the name of the country given the abbreviation.
 */
function _boilerplate_get_country_name_by_abbreviation($country) {
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

  $identifier = drupal_strtolower(trim($identifier));
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

  if (isset($items[$key])) {
    return $items[$key];
  }

  return FALSE;
}

/**
 * Helper function - clear views cache.
 */
function _boilerplate_clear_views_cache($view_name) {
  cache_clear_all('ctools_export:views_view:' . $view_name, 'cache_views', TRUE);
  cache_clear_all($view_name, 'cache_views_data', TRUE);
}

/**
 * Helper function - get the label of a content type.
 */
function _boilerplate_get_content_type_label($content_type) {
  $all_content_types = node_type_get_types();
  if (isset($all_content_types[$content_type])) {
    return $all_content_types[$content_type]->name;
  }

  return FALSE;
}

/**
 * Helper function - join items with a comma and "and" at the end.
 */
function _boilerplate_join_items_with_comma_and_and($raw_items) {
  $items = array_values($raw_items);
  $number_of_items = count($items);

  switch ($number_of_items) {
    case 0:
      $formatted_items = NULL;
      break;

    case 1:
      $formatted_items = array_shift(array_values($items));
      break;

    case 2:
      $formatted_items = t('@item1 and @item2', array(
        '@item1' => $items[0],
        '@item2' => $items[1],
      ));
      break;

    default:
      $formatted_items = t('@comma_separated_items and @last_item', array(
        '@comma_separated_items' => implode(', ', array_slice($items, 0, count($items) - 1)),
        '@last_item' => end($items),
      ));
      break;
  }

  return $formatted_items;
}

/**
 * Helper function - get node title.
 */
function _boilerplate_get_node_title($nid) {
  static $results;

  if (isset($results[$nid]) && !empty($results[$nid])) {
    return $results[$nid];
  }

  $results[$nid] = db_query("SELECT title FROM {node} WHERE nid = :nid", array(':nid' => $nid))->fetchField();

  return $results[$nid];
}
