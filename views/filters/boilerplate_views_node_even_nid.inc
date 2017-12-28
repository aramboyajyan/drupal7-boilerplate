<?php

/**
 * @file
 * Definition of boilerplate_views_node_even_nid.
 */

/**
 * Filter nodes to show only the ones with even node IDs.
 */
class boilerplate_views_node_even_nid extends views_handler_filter {
  function admin_summary() {
    return t('Displays only nodes with even node IDs.');
  }

  function query() {
    $table = $this->ensure_my_table();
    $this->query->add_where_expression(0, "({$table}.nid % 2) = 0");
  }
}
