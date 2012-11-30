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
function boilerplate_sample_form() {
  $form['sample'] = array(
    '#type' => 'fieldset',
    '#title' => t('Personal information'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['sample']['sample_textfield'] = array(
    '#title' => t('Text field'),
    '#type' => 'textfield',
    '#required' => TRUE,
  );
  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array('#type' => 'submit', '#value' => t('Submit the form'));
  return $form;
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
