# [Drupal 7](http://drupal.org) custom module boilerplate

Full featured custom module boilerplate with already setup structure and default functionality.
The module and all example code is built completely using Drupal best practices and standards.

See the version for Drupal 8 [here](https://github.com/aramboyajyan/drupal8-boilerplate).

### Includes

- Custom forms, validation and submit handlers
- Batch jobs
- Cron integration
- Token integration
- Skinr integration
- Rules integration
- Drush integration
- Node and user tabs integration
- Webform field implementation
- Theme/template implementation
- Separation of module code in appropriate files (`.pages`, `.tokens`, `.forms`, `.admin`, `.batch`)
- Email implementation, including both - text only (default) and rich (HTML) emails
- Custom helper functions for:
    - Generating a random string of arbitrary length
    - Get the list of all image styles on the site `*`
    - Get the list of all nodes on the site `*`
    - Get the list of all node types on the site `*`
    - Get the list of all users on the site `*`
    - Get the list of all roles on the site `*`
    - Get the list of all vocabularies on the site `*`
    - Check if a user has a specific role
    - Check if a request is an AJAX request. Useful when overriding tricky form elements, e.g. setting a default value on [Addressfield](https://drupal.org/project/addressfield) on checkout page with [Commerce](https://drupal.org/project/commerce).
    - Secure string comparison from [HTTP Auth library of Zend Framework](http://stackoverflow.com/q/10576827/1520477)

`*` Admin form friendly - means you can use this output directly in select boxes or radio fields in admin forms.

### Why are all those implementations necessary?

Most bigger websites will have a main custom module, with general system modifications or general features and additional custom modules focused on a particular functionality. This boilerplate is suitable for creating that *main* module.

### How to use

Few different ways:

1. Copy/paste the parts you need in your custom module.
2. Clone the whole repo and make the following replacements:
    - Rename all `boilerplate.` files to `YOUR_MODULE.`.
    - Replace all `boilerplate` (lowercase) words with `YOUR_MODULE` (lowercase as well).
    - Replace all `BOILERPLATE` (uppercase) words with `YOUR_MODULE` (uppercase as well).
    - Replace all `Boilerplate` (capitalized) words with `YOUR_MODULE` (capitalized as well).
    - Customize the code to fit your project.

### Removing components

Not all projects will need every component that is included in this module. Below are instructions on how to remove those parts. If you want to do this after you have installed the module, don't forget to clear all caches after removing the components.

##### Sample pages

- open `boilerplate.module` file and remove the `boilerplate_menu()` function
- open `boilerplate.info` file and remove the following line: `configure = admin/config/boilerplate/settings`
- remove or empty the `boilerplate.forms.inc` file
- remove or empty the `boilerplate.pages.inc` file
- remove or empty the `boilerplate.admin.inc` file
- remove or empty the `boilerplate.batch.inc` file

##### Themable elements

- open `boilerplate.module` and remove the `boilerplate_theme()` function
- remove the `/theme` directory

##### Custom mailsystem

- open `boilerplate.module` file and remove the following line: `require_once dirname(__FILE__) . '/boilerplate.mailsystem.inc';`
- remove the `boilerplate.mailsystem.inc` file

##### Helper functions

- open `boilerplate.module` file and remove the following line: `require_once dirname(__FILE__) . '/boilerplate.helpers.inc';`
- remove the `boilerplate.helpers.inc` file

##### Tests

- open `boilerplate.info` file and remove the following line: `files[] = boilerplate.test`
- remove the `boilerplate.test` file

##### Views integration

- open `boilerplate.module` file and remove the `boilerplate_views_api()` function
- remove the `/views` directory

##### Token integration

- remove the `boilerplate.tokens.inc` file

##### Rules integration

- remove the `boilerplate.rules.inc` file

##### Drush integration

- remove the `boilerplate.drush.inc` file

##### Skinr integration

- open `boilerplate.module` and remove the `boilerplate_skinr_api_2()` function
- remove the `/skins` directory

<hr>

By: [topsitemakers.com](http://www.topsitemakers.com).
