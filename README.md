# [Drupal 7](http://drupal.org) custom module boilerplate

Full featured custom module boilerplate with already setup structure and default functionality.  
The module and all example code is built completely using Drupal best practices and standards.

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

### Why this module isn't on Drupal.org?

This module does nothing on its own. It is opinionated and might not be suitable for anyone. However, if there is enough interest, it can be turned into a full module, hosted on Drupal.org.

<hr>

By: [topsitemakers.com](http://www.topsitemakers.com).
