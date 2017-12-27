<?php

/**
 * @file
 * Custom forms used in the module.
 *
 * Created by: Topsitemakers
 * http://www.topsitemakers.com/
 */

/**
 * Sample form.
 */
function boilerplate_sample_form($form, &$form_state, $arg1, $arg2) {
  $form['sample'] = array(
    '#type' => 'fieldset',
    '#title' => t('Personal information'),
    '#description' => t('Passed arguments: %arg1 and %arg2.', array(
      '%arg1' => $arg1,
      '%arg2' => $arg2,
    )),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['sample']['sample_textfield'] = array(
    '#title' => t('Text field'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );
  $form['sample']['sample_radios'] = array(
    '#title' => t('Radios'),
    '#type' => 'radios',
    '#options' => array(
      1 => t('Option 1'),
      2 => t('Option 2'),
      3 => t('Option 3'),
      4 => t('Option 4'),
    ),
    // Demonstration of our custom AJAX commands.
    '#ajax' => array(
      'boilerplate_sample_form_radios_ajax',
    ),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Submit the form'));

  return $form;
}

/**
 * Sample form AJAX callback.
 */
function boilerplate_sample_form_radios_ajax($form, $form_state) {
  $commands = array();
  $commands[] = boilerplate_ajax_command_add_value_to_window('sample_radios', $form_state['values']['sample_radios']);
  $commands[] = boilerplate_ajax_command_log_to_console(t('Radio buttons changed. Timestamp: @time', array('@time' => REQUEST_TIME)));

  return array('#type' => 'ajax', '#commands' => $commands);
}

/**
 * Sample form validation.
 */
function boilerplate_sample_form_validate($form, &$form_state) {
  if ($form_state['values']['sample_textfield'] == 'error') {
    form_set_error('sample_textfield', t('Custom form validation.'));
  }
}

/**
 * Sample form submit processing.
 */
function boilerplate_sample_form_submit($form, &$form_state) {
  drupal_set_message(t('Form submitted successfully.'));
  drupal_goto('<front>');
}
