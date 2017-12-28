<?php

/**
 * @file
 * Definition of boilerplate_views_field_sample.
 */

/**
 * A handler to provide a sample field.
 */
class boilerplate_views_field_sample extends views_handler_field {
  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
    $this->additional_fields['title'] = 'title';
  }

  function render($values) {
    $nid = $this->get_value($values, 'nid');
    $title = $this->get_value($values, 'title');

    return t('NID @nid: @title', array(
      '@nid' => $nid,
      '@title' => base64_encode($title),
    ));
  }
}
