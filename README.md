Site Alert
------------

The Site Alert module is a lightweight solution for allowing site administrators to easily place an alert on their site, for example for maintenance downtime, or any generalinformational message. Alerts have start and end date/times,and can be assigned a severity level. Messages are refreshed by ajax and not subject to site caching, so changes made in the ui will be automatically displayed to users withoutnecessitating a cache clear. 

Installation
------------

- Install this module using the official Backdrop CMS instructions at
  https://docs.backdropcms.org/documentation/extend-with-modules.


Configuration
----------------

Enable the Site Alert module
Add the 'Site Alert' block to whichever layout you wish it to appear in. Ensure that all necessary roles have the 
'administer site alerts' permission.  (All roles can view alerts)  Create an alert (admin/config/system/alerts) Enjoy your exciting new site alert!

Differences from Drupal 7
-------------------------

- No changes.

Issues
------

Bugs and feature requests should be reported in 
[the Issue Queue](https://github.com/backdrop-contrib/imagezoom/issues).

Current Maintainers
-------------------

<!-- - [Justin Keiser](https://github.com/keiserjb). -->

Credits <!-- This section is required. -->
-------

- Ported to Backdrop CMS by [Justin Keiser](https://github.com/keiserjb).
- Maintained for Drupal by [Cecily Borzillo](https://www.drupal.org/u/cecrs).
- Also inspired by [Boostrap Site Alert](https://www.drupal.org/project/bootstrap_site_alert).

License
-------

This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.
