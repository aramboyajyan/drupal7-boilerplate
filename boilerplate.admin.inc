<?php

/**
 * @file
 * Administrative page callbacks of the module.
 *
 * Created by: Topsitemakers
 * http://www.topsitemakers.com/
 */

/**
 * Main administrative settings.
 */
function boilerplate_admin_settings() {
  $form['boilerplate_sample_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Sample field'),
    '#description' => t('Just a sample field'),
    '#default_value' => variable_get('boilerplate_sample_field'),
  );
  return system_settings_form($form);
}
