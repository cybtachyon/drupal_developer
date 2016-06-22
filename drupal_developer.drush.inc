<?php
/**
 * @file
 * Drupal developer drush commands.
 */

/**
 * Implements hook_drush_command().
 */
function drupal_developer_drush_command() {
  $items = [];

  $items['developer-prep'] = [
    'description' => dt('Prepares the site for local development.'),
    'aliases' => ['dev'],
    'arguments' => [],
    'options' => [],
  ];

  return $items;
}

/**
 * Generate all demo content.
 *
 * Note: States and experiences are created from within other content imports.
 */
function drush_drupal_developer_developer_prep() {
  $developer_email = '';

  // Order: Core, Dependency, Alphabetical.
  \Drupal::service('module_installer')->install([
    'dblog',
    'field_ui',
    'menu_ui',
    'views_ui',
    'devel',
    'kint',
    'reroute_email',
  ], TRUE);
  drush_log(dt('Enabled developer modules and UI.'), 'ok');

  $config_factory = \Drupal::service('config.factory');
  $module_handler = \Drupal::service('module_handler');

  $config_factory->getEditable('system.logging')
    ->set('error_level', 'verbose');
  drush_log(dt('Set system error log level to verbose.'), 'ok');

  if ($module_handler->moduleExists('reroute_email')) {
    $config_factory->getEditable('reroute_email.settings')
      ->set('reroute_email_enable', 1);
    $config_factory->getEditable('reroute_email.settings')
      ->set('reroute_email_address', $developer_email);
    drush_log(dt(
      "Email is being rerouted to @email.",
      ['@email' => $developer_email]
    ), 'ok');
  }
  else {
    drush_log('Emails will be sent to users!', 'warning');
  }

  if ($module_handler->moduleExists('devel')) {
    user_role_grant_permissions(1, array('access devel information'));
    user_role_grant_permissions(2, array('access devel information'));
  }
  drush_log(dt('Enabled devel for all users.'), 'ok');

  drush_log(dt('Ready for development.'), 'ok');
}
