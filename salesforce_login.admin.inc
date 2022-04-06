<?php

/**
 * @file
 * Administration.
 */

/**
 * Form callback for admin page.
 */
function salesforce_login_admin_form($form, $form_state) {
  $form = array();

  if (!variable_get('email_registration_login_with_username', TRUE)) {
    drupal_set_message(t('Salesforce Login: It is reccomended that you enable the "Allow users login with e-mail or username." option on the <a href="/admin/config/people/accounts">Account Settings</a> page.'), 'warning');
  }

  $form['salesforce_login_query_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Query field override.'),
    '#default_value' => variable_get('salesforce_login_query_field'),
    '#description' => t('Specify the Salesforce email field that should be queried when looking up a new user. This can usually be left blank, as it defaults to the email field in the <a href="@user-to-contact-link">user_to_contact</a> Salesforce mapping.', array('@user-to-contact-link' => '/springboard/settings/config/mappings/manage/user_to_contact')),
    '#size' => 60,
    '#maxlength' => 128,
  );

  $form['salesforce_login_copy_profile_fields_on_login'] = array(
    '#type' => 'checkbox',
    '#title' => t('Update profile fields on login'),
    '#description' => t('Enable this setting to copy Salesforce Contact fields to Springboard profile fields every time a user logs in. Only fields that have “Overwrite rule when importing into Drupal” set to "always" in the entity mapping are included.'),
    '#return_value' => 1,
    '#default_value' => variable_get('salesforce_login_copy_profile_fields_on_login', 0),
  );

  return system_settings_form($form);
}
