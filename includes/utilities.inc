<?php

/**
 * @file
 * Utility functions.
 */

/**
 * Populate the usage statistics block for non-collection objects.
 */
function islandora_usage_stats_csv_generate_views_stats($pid) {
  $access_log_id = islandora_usage_stats_csv_get_object_access_id($pid);

  // Get usage stats going back X months and group them by month.
  $views_result = db_select('islandora_usage_stats_object_access_log')
    ->fields('islandora_usage_stats_object_access_log', array('time'))
    ->condition('pid_id', $access_log_id)
    ->execute();
  $views_data = array();
  foreach ($views_result as $row) {
    $label = date("Y-m", $row->time);
    if (array_key_exists($label, $views_data)) {
      $views_data[$label]++;
    }
    else {
      $views_data[$label] = 1;
    }
  }
  return $views_data;
}

function islandora_usage_stats_csv_generate_downloads_stats($pid) {
  $downloads_chart_values = array();
  $placeholders = array(
    ':ago' => $ago,
    ':now' => time(),
    ':pid_id' => $access_log_id,
  );

  $downloads_result = db_query("SELECT time FROM {islandora_usage_stats_datastreams}, {islandora_usage_stats_object_ds_access_log} WHERE {islandora_usage_stats_object_ds_access_log}.time BETWEEN :ago AND :now AND {islandora_usage_stats_datastreams}.pid_id = :pid_id", $placeholders);
  $downloads_data = array();
  foreach ($downloads_result as $row) {
    $label = date("Y-m", $row->time);
    if (array_key_exists($label, $downloads_data)) {
      $downloads_data[$label]++;
    }
    else {
      $downloads_data[$label] = 1;
    }
  }
}

/**
 * Get the ID in the object access table corresponding to the incoming PID.
 *
 * @param string $pid
 *   The object's PID.
 *
 * @return string
 *   The corresponding ID from the islandora_usage_stats_objects table.
 */
function islandora_usage_stats_csv_get_object_access_id($pid) {
  $result = db_select('islandora_usage_stats_objects')
    ->fields('islandora_usage_stats_objects', array('id'))
    ->condition('pid', $pid)
    ->execute();
  return $result->fetchAssoc();
}