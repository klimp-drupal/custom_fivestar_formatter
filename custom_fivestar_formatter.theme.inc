<?php
/**
 * @file
 * Theme functions for Custom Fivestar formatter module.
 */

/**
 * Returns HTML for a custom_fivestar_number_formatter.
 *
 * @param array $variables
 * An associative array containing:
 * - instance_settings: Fivestar instance settings.
 * - item: Item to theme.
 *
 * @return string
 *   Simple rating number.
 *
 * @ingroup themeable
 */
function theme_custom_fivestar_number_formatter($variables) {
  return custom_fivestar_number_get_rating($variables);
}

/**
 * Returns HTML for a custom_fivestar_range_formatter.
 *
 * @param array $variables
 * An associative array containing:
 * - instance_settings: Fivestar instance settings.
 * - item: Item to theme.
 *
 * @return string
 *   range rating.
 *
 * @ingroup themeable
 */
function theme_custom_fivestar_range_formatter($variables) {
  $rating = custom_fivestar_number_get_rating($variables);

  $max = ceil($rating * 2) / 2;
  $min = floor($rating * 2) / 2;

  if($rating == $min && $min == $max){
    if($rating != 5){
      $min = $rating;
      $max = $rating + 0.5;
    } else{
      $min = $rating - 0.5;
      $max = $rating;
    }
  }

  return $min . ' - ' . $max;
}
