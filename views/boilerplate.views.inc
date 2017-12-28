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

/**
 * Implements hook_views_default_views().
 */
function boilerplate_views_default_views() {
  $views = array();

  /**
   * Sample view that uses our field, filter and access plugin.
   */
  $view = new view();
  $view->name = 'boilerplate_sample';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Boilerplate Sample';
  $view->core = 7;
  $view->api_version = '3.0';
  // Edit this to true to make a default view disabled initially.
  $view->disabled = FALSE;
  // Display: Master
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sample';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'even_uids';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  // Field: Content: Sample field
  $handler->display->display_options['fields']['boilerplate_views_field_sample']['id'] = 'boilerplate_views_field_sample';
  $handler->display->display_options['fields']['boilerplate_views_field_sample']['table'] = 'node';
  $handler->display->display_options['fields']['boilerplate_views_field_sample']['field'] = 'boilerplate_views_field_sample';
  // Sort criterion: Content: Post date
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  // Filter criterion: Content: Published
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  // Filter criterion: Content: Even NID
  $handler->display->display_options['filters']['boilerplate_views_node_even_nid']['id'] = 'boilerplate_views_node_even_nid';
  $handler->display->display_options['filters']['boilerplate_views_node_even_nid']['table'] = 'node';
  $handler->display->display_options['filters']['boilerplate_views_node_even_nid']['field'] = 'boilerplate_views_node_even_nid';
  $handler->display->display_options['filters']['boilerplate_views_node_even_nid']['expose']['operator_id'] = 'boilerplate_views_node_even_nid_op';
  $handler->display->display_options['filters']['boilerplate_views_node_even_nid']['expose']['label'] = 'Even NID';
  $handler->display->display_options['filters']['boilerplate_views_node_even_nid']['expose']['operator'] = 'boilerplate_views_node_even_nid_op';
  $handler->display->display_options['filters']['boilerplate_views_node_even_nid']['expose']['identifier'] = 'boilerplate_views_node_even_nid';
  // Display: Page
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'boilerplate-view';
  // Add the view to the list.
  $views[$view->name] = $view;

  return $views;
}
