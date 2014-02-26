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
