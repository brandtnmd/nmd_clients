<?php

/**
 * @file
 * Administrative page callbacks for the AddThis-module.
 */
 
/**
 * Implements hook_admin_settings_form().
 */
function addthis_admin_settings_form($form_state) {
  AddThis::getInstance()->addStylesheets();
  $form[AddThis::PROFILE_ID_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis Profile ID'),
    '#default_value' => AddThis::getInstance()->getProfileId(),
    '#required' => FALSE,
    '#description' => t('Profile ID at <a href="http://addthis.com/" target="_blank">AddThis.com</a>. Required for statistics.'),
  );
  $form['visual_settings_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Visual settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['visual_settings_fieldset'][AddThis::LARGE_ICONS_ENABLED_KEY] = array(
    '#type' => 'checkbox',
    '#title' => t('Use large 32x32 pixel toolbox icons instead of smaller 16x16 pixel icons'),
    '#default_value' => AddThis::getInstance()->areLargeIconsEnabled(),
    '#required' => FALSE,
  );
  $form['visual_settings_fieldset'][AddThis::CLICK_TO_OPEN_COMPACT_MENU_ENABLED_KEY] = array(
    '#type' => 'checkbox',
    '#title' => t('Click to open compact menu'),
    '#description' => t('If checked, the compact menu will never appear upon mousing over the regular button. Instead, it will be revealed upon clicking the button.'),
    '#default_value' => AddThis::getInstance()->isClickToOpenCompactMenuEnabled(),
    '#required' => FALSE,
  );
  $form['visual_settings_fieldset'][AddThis::OPEN_WINDOWS_ENABLED_KEY] = array(
    '#type' => 'checkbox',
    '#title' => t('Use pop-up windows'),
    '#description' => t('If true, all shares will open in a new pop-up window instead of a new tab or regular browser window.'),
    '#default_value' => AddThis::getInstance()->isOpenWindowsEnabled(),
    '#required' => FALSE,
  );
  $form['visual_settings_fieldset'][AddThis::STANDARD_CSS_ENABLED_KEY] = array(
    '#type' => 'checkbox',
    '#title' => t('Use standard AddThis stylesheet'),
    '#description' => t('If not checked, AddThis will not load standard CSS file, allowing you to style everything yourself without incurring the cost of an additonal load. Always global; must be defined in a page-level global variable.'),
    '#default_value' => AddThis::getInstance()->isStandardCssEnabled(),
    '#required' => FALSE,
  );
  $form['visual_settings_fieldset'][AddThis::NUMBER_OF_PREFERRED_SERVICES_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('Number of preferred service icons displayed when using the toolbox widget'),
    '#default_value' => AddThis::getInstance()->getNumberOfPreferredServices(),
    '#required' => FALSE,
    '#size' => 1,
    '#maxlength' => 1,
  );
  $form['visual_settings_fieldset'][AddThis::UI_DELAY_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('UI delay'),
    '#description' => t('Delay, in milliseconds, before compact menu appears when mousing over a regular button. Capped at 500 ms.'),
    '#default_value' => AddThis::getInstance()->getUiDelay(),
    '#required' => FALSE,
    '#size' => 3,
    '#maxlength' => 3,
  );
  $form['visual_settings_fieldset'][AddThis::UI_HEADER_COLOR_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis user interface header text color (like #ffffff)'),
    '#default_value' => AddThis::getInstance()->getUiHeaderColor(),
    '#required' => FALSE,
  );
  $form['visual_settings_fieldset'][AddThis::UI_HEADER_BACKGROUND_COLOR_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis user interface header background color (like #000000)'),
    '#default_value' => AddThis::getInstance()->getUiHeaderBackgroundColor(),
    '#required' => FALSE,
  );
  $form['visual_settings_fieldset'][AddThis::CO_BRAND_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('Additional branding message to be rendered in the upper-right-hand corner of the menus'),
    '#description' => t('Should be less than 15 characters in most cases to render properly.'),
    '#default_value' => AddThis::getInstance()->getCoBrand(),
    '#required' => FALSE,
    '#maxlength' => 15,
  );
  $form['accessibility_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Accessibility'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['accessibility_fieldset'][AddThis::COMPLIANT_508_KEY] = array(
    '#type' => 'checkbox',
    '#title' => t('508 compliant'),
    '#description' => 'If checked, clicking the AddThis button will open a new window to a page that is keyboard navigable.',
    '#default_value' => AddThis::getInstance()->get508Compliant(),
    '#required' => FALSE,
  );
  $form['data_tracking_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Data tracking'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['data_tracking_fieldset'][AddThis::CLICKBACK_TRACKING_ENABLED_KEY] = array(
    '#type' => 'checkbox',
    '#title' => t('Track clickback'),
    '#description' => 'Check to allow AddThis to append a variable to your URLs upon sharing. AddThis will use this to track how many people come back to your content via links shared with AddThis. Highly recommended. Always global.',
    '#default_value' => AddThis::getInstance()->isClickbackTrackingEnabled(),
    '#required' => FALSE,
  );
  $form['email_settings_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Email settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['email_settings_fieldset'][AddThis::ADDRESSBOOK_ENABLED_KEY] = array(
    '#type' => 'checkbox',
    '#title' => t('Use addressbook'),
    '#description' => 'If checked, the user will be able import their contacts from popular webmail services when using AddThis\'s email sharing.',
    '#default_value' => AddThis::getInstance()->isAddressbookEnabled(),
    '#required' => FALSE,
  );
  $form['facebook_settings_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Facebook settings'),
    '#description' => t('Facebook functionality requires some meta-tags to be added to your pages (<a href="http://developers.facebook.com/docs/opengraph/" target="_blank">Open Graph protocol</a>). You can use the <a href="http://drupal.org/project/opengraph_meta">Open Graph meta tags module</a> or add the tags some other way.'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['facebook_settings_fieldset'][AddThis::FACEBOOK_LIKE_ENABLED_KEY] = array(
    '#type' => 'checkbox',
    '#title' => t('Add Facebook Like to toolbox'),
    '#default_value' => AddThis::getInstance()->isFacebookLikeEnabled(),
    '#required' => FALSE,
  );
  $form['twitter_settings_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Twitter settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['twitter_settings_fieldset'][AddThis::TWITTER_ENABLED_KEY] = array(
    '#type' => 'checkbox',
    '#title' => t('Add Twitter to toolbox'),
    '#default_value' => AddThis::getInstance()->isTwitterEnabled(),
    '#required' => FALSE,
  );
  $form['google_plus_one_settings_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Google +1 settings'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['google_plus_one_settings_fieldset'][AddThis::GOOGLE_PLUS_ONE_ENABLED_KEY] = array(
    '#type' => 'checkbox',
    '#title' => t('Add Google +1 to toolbox'),
    '#default_value' => AddThis::getInstance()->isGooglePlusOneEnabled(),
    '#required' => FALSE,
  );
  $form['service_urls_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Service URLs'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['service_urls_fieldset'][AddThis::BOOKMARK_URL_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis bookmark URL'),
    '#default_value' => AddThis::getInstance()->getBaseBookmarkUrl(),
    '#required' => TRUE,
  );
  $form['service_urls_fieldset'][AddThis::SERVICES_CSS_URL_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis services stylesheet URL'),
    '#default_value' => AddThis::getInstance()->getServicesCssUrl(),
    '#required' => TRUE,
  );
  $form['service_urls_fieldset'][AddThis::SERVICES_JSON_URL_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis services json URL'),
    '#default_value' => AddThis::getInstance()->getServicesJsonUrl(),
    '#required' => TRUE,
  );
  $form['service_urls_fieldset'][AddThis::WIDGET_JS_URL_KEY] = array(
    '#type' => 'textfield',
    '#title' => t('AddThis javascript widget URL'),
    '#default_value' => AddThis::getInstance()->getBaseWidgetJsUrl(),
    '#required' => TRUE,
  );
  $form['enabled_services_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Enabled services'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['enabled_services_fieldset'][AddThis::ENABLED_SERVICES_KEY] = array(
    '#type' => 'checkboxes',
    '#title' => t('Enabled services'),
    '#options' => AddThis::getInstance()->getServices(),
    '#default_value' => AddThis::getInstance()->getEnabledServices(),
    '#required' => FALSE,
  );
  $form['advanced_settings_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advanced settings'),
    '#access' => user_access(AddThis::PERMISSION_ADMINISTER_ADVANCED_ADDTHIS),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['advanced_settings_fieldset'][AddThis::CUSTOM_CONFIGURATION_CODE_ENABLED_KEY] = array(
    '#type' => 'checkbox',
    '#title' => t('Use custom AddThis configuration code'),
    '#default_value' => AddThis::getInstance()->isCustomConfigurationCodeEnabled(),
    '#required' => FALSE,
    '#description' => t('Use custom AddThis configuration code. If checked, custom configuration will be used instead of other configuration settings provided in AddThis administration user interface.'),
  );
  $form['advanced_settings_fieldset'][AddThis::CUSTOM_CONFIGURATION_CODE_KEY] = array(
    '#type' => 'textarea',
    '#title' => t('AddThis custom configuration code'),
    '#default_value' => AddThis::getInstance()->getCustomConfigurationCode(),
    '#required' => FALSE,
    '#description' => t('AddThis custom configuration code. See format at <a href="http://addthis.com/" target="_blank">AddThis.com</a>'),
  );
  return system_settings_form($form);
}