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

  // Note: to make things easier and less confusing, it is the best to name
  // variables using the following pattern:
  // 
  //    [module_name]_var_[variable_title]
  // 
  // This way it will be easy to tell what is a function and what is a variable
  // in certain cases (e.g. editor autocomplete). This can be a real sanity
  // saver in larger projects where there are many big custom modules, each with
  // dozens of custom defined variables.

  // Add custom submit handler for this form, so we can change the status of
  // uploads.
  $form['#submit'][] = 'boilerplate_admin_settings_submit';

  $form['settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Settings fieldset'),
  );
  $form['settings']['boilerplate_var_text_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Text field'),
    '#description' => t('Just a sample textual field.'),
    '#default_value' => variable_get('boilerplate_var_text_field', 'Default text field value'),
  );
  $form['settings']['boilerplate_var_select_field'] = array(
    '#type' => 'select',
    '#title' => t('Select field'),
    '#description' => t('Just a sample select field.'),
    '#default_value' => variable_get('boilerplate_var_select_field', 5),
    '#options' => drupal_map_assoc(array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)),
  );
  $form['settings']['boilerplate_var_radios'] = array(
    '#type' => 'radios',
    '#title' => t('Radios field'),
    '#description' => t('Just a sample radios field.'),
    '#default_value' => variable_get('boilerplate_var_radios', 3),
    '#options' => drupal_map_assoc(array(1, 2, 3, 4, 5)),
  );
  $form['settings']['boilerplate_var_checkboxes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Checkboxes field'),
    '#description' => t('Just a sample radios field.'),
    '#default_value' => variable_get('boilerplate_var_checkboxes', array(3)),
    '#options' => drupal_map_assoc(array(1, 2, 3, 4, 5)),
  );
  $form['settings']['boilerplate_var_public_file'] = array(
    '#type' => 'managed_file',
    '#title' => t('Public file upload'),
    '#description' => t('Demonstrates how to add a public file upload field.'),
    '#default_value' => variable_get('boilerplate_var_public_file'),
    '#upload_validators' => array(
      'file_validate_extensions' => array('png gif jpg jpeg'),
    ),
    '#upload_location' => 'public://boilerplate-public-images/',
  );
  $form['settings']['boilerplate_var_private_file'] = array(
    '#type' => 'managed_file',
    '#title' => t('Private file upload'),
    '#description' => t('Demonstrates how to add a private file upload field.'),
    '#default_value' => variable_get('boilerplate_var_private_file'),
    '#upload_validators' => array(
      'file_validate_extensions' => array('png gif jpg jpeg'),
    ),
    '#upload_location' => 'private://boilerplate-private-images/',
  );
  $form['settings']['boilerplate_var_textarea'] = array(
    '#type' => 'textarea',
    '#title' => t('Textarea field'),
    '#description' => t('Just a sample textarea field.'),
    '#default_value' => variable_get('boilerplate_var_textarea', 'Default textarea value.'),
  );
  $editor_field = variable_get('boilerplate_var_text_format', NULL);
  $form['settings']['boilerplate_var_text_format'] = array(
    '#type' => 'text_format',
    '#base_type' => 'textarea',
    '#title' => t('Formatted textarea field'),
    '#description' => t('Just a sample formatted textarea field.'),
    '#default_value' => $editor_field['value'],
    '#format' => $editor_field['format'],
  );

  return system_settings_form($form);
}

/**
 * Submit handler for the boilerplate_admin_settings() form.
 */
function boilerplate_admin_settings_submit($form, &$form_state) {
  global $user;

  if ($form_state['values']['boilerplate_var_public_file'] > 0) {
    // Change the status of uploaded file, because the system will delete it
    // otherwise after 6 hours.
    $public_file = file_load($form_state['values']['boilerplate_var_public_file']);
    $public_file->status = FILE_STATUS_PERMANENT;
    file_save($public_file);
    // Store the relationship to this file to the database.
    file_usage_add($public_file, 'boilerplate_public_file', 'user', $user->uid);
  }

  if ($form_state['values']['boilerplate_var_private_file'] > 0) {
    // Change the status of uploaded file, because the system will delete it
    // otherwise after 6 hours.
    $private_file = file_load($form_state['values']['boilerplate_var_private_file']);
    $private_file->status = FILE_STATUS_PERMANENT;
    file_save($private_file);
    // Store the relationship to this file to the database.
    file_usage_add($private_file, 'boilerplate_private_file', 'user', $user->uid);
  }
}
