# drupal-developer
A Drupal custom module template used in prepping a site for local development.

Includes a `drush dev` drush command for prepping the environment.

See https://www.mediacurrent.com/blog/dont-send-testing-emails-real-users and
https://www.thirdandgrove.com/this-custom-drush-command-will-make-you-a-better-drupal-developer

## FAQ
*Why isn't this on drupal.org?*

This is a developer only module template that should never be enabled on
production. It also needs to be customized for each installation manually. It's
not a good fit for someone to just `drush en -y`. Unlike devel, this is meant to
be run out of the box without any settings change for prepping the environment.

*What's in the base box?*

Drupal Developer Module includes:

 - A drush command to prep the environment.
 - Developer-friendly settings for core.
 - Auto installation of common developer modules.
 - Enabling of UI modules.

*What do I need to customize?*

You'll want to set up redirect emails and peruse some of the other developer-
centric settings available.
