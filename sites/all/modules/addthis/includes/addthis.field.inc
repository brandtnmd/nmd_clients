<?php

/**
 * @file
 * Field related hook implementations for the AddThis-module.
 */
 
/**
 * Implements hook_field_info().
 *
 * Field settings:
 *   - max_length: the maximum length for a varchar field.
 *
 * Instance settings:
 *   - AddThis::STYLE_KEY: The style of AddThis widget to render for this field.
 */
function addthis_field_info() {
  return array(
    AddThis::FIELD_TYPE => array(
      'label' => t('AddThis'),
      'description' => t('This field stores addthis settings in the database.'),
      'settings' => array('max_length' => 255),
      'instance_settings' => array(
        AddThis::STYLE_KEY => AddThis::WIDGET_TYPE_COMPACT_BUTTON
       ),
      'default_widget' => AddThis::WIDGET_TYPE,
      'default_formatter' => AddThis::WIDGET_TYPE_DISABLED,
    ),
  );
}

/**
 * Implements hook_field_is_empty().
 */
function addthis_field_is_empty($item, $field) {
  return empty($item['value']) && (string) $item['value'] !== '0';
}

/**
 * Implements hook_field_formatter_info().
 */
function addthis_field_formatter_info() {
  $formatters = array();

  // Create a formatter element for all the default style types we have.
  foreach (AddThis::getInstance()->getWidgetTypes() as $key => $label) {
    $formatters[$key] = array(
      'label' => $label,
      'field types' => array(AddThis::FIELD_TYPE)
    );
  }

  return $formatters;
}

/**
 * Implements hook_field_formatter_view().
 */
function addthis_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {
  // We have only one item to display, the share item.
  // Get the markup for the share and add that to the $element[0] to display.
  $element = array();
  $widget_type = $display['type'];
  $markup = AddThis::getInstance()->getWidgetMarkup($widget_type, $entity);
  if (!isset($element[0]) && !is_array($markup)) {
    // Supporting #markup is for legacy in this module.
    // We move towards using the render array.
    $element[0] = array('#markup' => $markup);
  } 
  elseif (!isset($element[0])) {
    $element[0] = $markup;
  }
  return $element;
}

/**
 * Implements hook_field_presave().
 */
function addthis_field_presave($entity_type, $entity, $field, $instance, $langcode, &$items) {
  // We don't add items in the instance form therefore we check for a item
  // if not there we (which is the case almost always) we add it. This item
  // is need for the field_formatter in $items to attach a renderable item to.
  if (count($items) == 0) {
    $items += array(array('value' => AddThis::WIDGET_TYPE_DISABLED));
  }
  else {
    foreach ($items as $delta => $value) {
      $items[$delta]['value'] = AddThis::WIDGET_TYPE_DISABLED;
    }
  }
}

/**
 * Implements hook_field_widget_info().
 */
function addthis_field_widget_info() {
  return array(
    AddThis::WIDGET_TYPE => array(
      'label' => t('AddThis button'),
      'field types' => array(AddThis::FIELD_TYPE),
    ),
  );
}

/**
 * Implements hook_field_widget_form().
 */
function addthis_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {

  // @todo Write explaining comments
  if ($instance['widget']['type'] == AddThis::WIDGET_TYPE) {
    $main_widget = $element + array(
      '#access' => FALSE,
    );
    $element['value'] = $main_widget;
  }

  return $element;
}

/**
 * Implements hook_field_widget_error().
 */
function addthis_field_widget_error($element, $error, $form, &$form_state) {
  switch ($error['error']) {
    default:
      $error_element = $element[$element['#columns'][0]];
      break;
  }

  form_error($error_element, $error['message']);
}
