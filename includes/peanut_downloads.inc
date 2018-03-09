<?php
/**
 * @file
 *
 * PeanutBase-specific downloads.
 */


/**
 * Implements hook_register_trpdownload_type().
 */
function peanut_custom_register_trpdownload_type() {
  $types = array();

  // The key is the machine name of my download type.
  $types['marker_csv'] = array(
    // A human readable name to show in an administrative interface one day.
    'type_name' => 'Marker CSV',
    // A human readable description of the format.
    'format' => 'Comma-separated Values',
    // An array of functions that the API will use to customize your experience.
    'functions' => array(
      // The function that tripal jobs will call to generate the file.
      'generate_file' => 'trpdownload_marker_csv_generate_file',
      // OPTIONAL: provide a summary to the user on the download page.
      'summarize' => 'trpdownload_marker_csv_summarize_download',
      // OPTIONAL: determine your own filename.
      'get_filename' => 'trpdownload_marker_csv_get_filename',
      // OPTIONAL: Change the file suffix (defaults to .txt)
      'get_file_suffix' => 'trpdownload_marker_csv_get_suffix',
    ),
  );

  return $types;
}//trpdownload_peanut_register_trpdownload_type


/**
 * Generates a file listing feature in CSV.
 *
 * @param $variables
 *   An associative array of parameters including:
 *     - q: all the query paramters.
 *     - site_safe_name: a sanitized version of your site name for use in variables & filenames.
 *     - type_info: an array of info for the download type.
 *     - suffix: the file format suffix.
 *     - filename: the filename of the file to generate not including path.
 *     - fullpath: the full path and filename of the file to generate.
 *     - format_name: a human-readable description of the format.
 * @param $job_id
 *   The ID of the tripal job executing this function ;-).
 */
function trpdownload_marker_csv_generate_file($variables, $job_id = NULL) {

  // Create the file and ready it for writting to.
  $filepath = variable_get('trpdownload_fullpath', '') . $variables['filename'];
  drush_print("File: " . $filepath);
  $FILE = fopen($filepath, 'w') or die ('Uable to create file to write to');

  $headers = peanut_custom_getViewColumns('marker_download');
  
  // Add header to the file.
  fputcsv($FILE, $headers);
  
  // Determine which where criteria to include based on what is in query parameters.
  $where = array();
  $where_args = array();
  
  // search term
  if (isset($variables['q']['marker_name']) AND !empty($variables['q']['marker_name'])) {
    $where[] = "all_names LIKE :name";
    $where_args[':name'] = '%' . $variables['q']['marker_name'] . '%';
  }

  $query = "
    SELECT * FROM {marker_download} 
    WHERE ".implode(' AND ', $where)." ORDER BY marker_name";

  // Determine the total number of lines resulting from the query for tracking progress.
  // Since this number can be an estimate, use trpdownload_estimate_rows() which is much
  // faster then count(*). However, we need to keep in mind it can be off by a lot
  // and ensure that the user is never told the file is complete before it is.
  $count_query = preg_replace('/SELECT.*FROM/s', 'SELECT count(*) as num_lines FROM', $query);
  $count_query = preg_replace('/ORDER BY .*$/', '', $count_query);
  $total_lines = chado_query($count_query, $where_args)->fetchField();
  drush_print('Estimated Total Lines: '.$total_lines);

  // Execute the original query to get the results.
  $resource = chado_query($query, $where_args);

  // For each db result write a CSV line to the file.
  $cur_line = 0;
  foreach ($resource as $row) {

    // Output the progress.
    $cur_line++;
    $percent = $cur_line/$total_lines * 100;
    // Here we make sure not to tell the use that we are done before we are ($percent != 100)
    // This is needed because we estimated the total number of lines above.
    if ( ($percent%5 == 0) AND ($percent != 100) ) {
      drush_print(round($percent,2).'% Complete.');
      db_query('UPDATE {tripal_jobs} SET progress=:percent WHERE job_id=:id',
        array(':percent' => round($percent), ':id' => $job_id));
    }

    // Don't forget to write the line to the file ;-).
    fputcsv($FILE, (array)$row );
  }

  // Finally, close the file.
  fclose($FILE);

  // This is needed to ensure the user is always told we are done even if the estimated
  // number of lines is greater then what we had.
  db_query('UPDATE {tripal_jobs} SET progress=:percent WHERE job_id=:job_id',
    array(':percent' => 100, ':job_id' => $job_id));
}//trpdownload_marker_csv_generate_file


/**
 * Customize the filename for the download type.
 *
 * @param $vars
 *   An array of variables available to this function. Including:
 *     - ['download_args']['q']: all the arguments in the path passed to the Tripal Download API
 *     - ['download_args']['safe_site_name']: a sanitized version of the site-name for use in filenames
 *     - ['download_args']['type_info']: what you defined in hook_register_trpdownload_type() for the current download type
 * @return
 *   A string representing the filename for a specific download.
 */
function trpdownload_marker_csv_get_filename($vars) {
  $filename = $vars['download_args']['safe_site_name'] 
            . '.sequence_features.' 
            . date('YMj-his');

  return $filename;
}//trpdownload_marker_csv_get_filename


/**
 * Customize the file suffix for the download type.
 *
 * @param $vars
 *   An array of variables available to this function.  Including:
 *     - ['download_args']['q']: all the arguments in the path passed to the Tripal Download API
 *     - ['download_args']['safe_site_name']: a sanitized version of the site-name for use in filenames
 *     - ['download_args']['type_info']: what you defined in hook_register_trpdownload_type() for the current download type
 * @return
 *   A string representing the file suffix for a specific download.
 */
function trpdownload_marker_csv_get_suffix($vars) {
  return 'csv';
}//trpdownload_marker_csv_get_suffix


/**
 * Summarize the current download for Feature CSV download type.
 *
 * @param $vars
 *   An array of variables available to this function. Including:
 *     - ['download_args']['q']: all the arguments in the path passed to the Tripal Download API
 *     - ['download_args']['safe_site_name']: a sanitized version of the site-name for use in filenames
 *     - ['download_args']['type_info']: what you defined in hook_register_trpdownload_type() for the current download type
 * @return
 *   A string representing the summary (can include html).
 */
function trpdownload_marker_csv_summarize_download($vars) {
  $output = ''; // The variable storing the HTML output.

  // First, put the query arguments in a more accessible variable.
  $q = $vars['download_args']['q'];

  $output .= '<span>Sequence features where</span>';
  $output .= '<ul>';

  // Unique Name:
  // Since the operator is exposed we have two variables: uniquename_op has the operator and uniquename has the value.
  // Check the URL of your view after filtering to determine what these variables will be.
  if (!empty($q['marker_name'])) {
    $output .= '<li>Marker Name ' . $q['marker_name_op'] . ' <em>"' . $q['marker_name'] . '"</em></li>';
  }

  return $output;
}//trpdownload_marker_csv_summarize_download


function peanut_custom_getViewColumns($view) {
  $columns = array();
  
  $sql = "
    SELECT a.attname
    FROM pg_attribute a
      JOIN pg_class t on a.attrelid = t.oid
      JOIN pg_namespace s on t.relnamespace = s.oid
    WHERE a.attnum > 0 
      AND NOT a.attisdropped
      AND t.relname = '$view'  
      AND s.nspname = 'chado'  
    ORDER BY a.attnum";
  $sth = db_query($sql, array());
  foreach ($sth as $row) {
    array_push($columns, $row->attname);
  }
  
  return $columns;
}//peanut_custom_getViewColumns

