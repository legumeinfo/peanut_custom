<?php
/**
 * @file
 * Contains function relating to drush-integration of this module.
 */

/**
 * Describes each drush command implemented by the module
 *
 * @return
 *   The first line of description when executing the help for a given command
 *
 * @ingroup tripal_drush
 */
function blast_ui_drush_help($command) {
  switch ($command) {
    case 'restore-blast-dbs':
      return dt('Restore the peanut BLAST dbs.');
    case 'restore-lis-blast-dbs':
      return dt('Restore all legume BLAST dbs.');
  }
}

/**
 * Registers a drush command and constructs the full help for that command
 *
 * @return
 *   And array of command descriptions
 *
 * @ingroup tripal_drush
 */
function blast_ui_drush_command() {
  $items = array();
  $items['restore-blast-dbs'] = array(
    'description' => dt('Restore PeanutBase BLAST dbs'),
    'options'    => array(),
    'examples' => array(
      'Standard example' => 'drush blast_ui-restore-blast-dbs',
    ),
    'aliases' => array('restoredb'),
  );
  $items['restore-lis-blast-dbs'] = array(
    'description' => dt('Restore LIS BLAST dbs'),
    'options'    => array(),
    'examples' => array(
      'Standard example' => 'drush blast_ui-restore-lis-blast-dbs',
    ),
    'aliases' => array('restoredb'),
  );

  return $items;
}

/**
 * Retrieves the sequence of the indicated features
 *
 * @ingroup tripal_drush
 */
function drush_blast_ui_restore_blast_dbs() {
  global $user;

  $blast_recs = array(
    array(
      'name'                => 'Arachis duranensis - genome',
      'path'                => '/usr/local/www/drupal7/files/BLAST/aradu_genome.V14167.a1',
      'dbtype'              => 'nucleotide',
      'dbxref_id_regex'     => '/^\w+\.(\w+\.\w+)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'peanutbase_gbrowse',
      'cvitjs_enabled'      => 1,
    ),
    array(
      'name'                => 'Arachis duranensis - CDS',
      'path'                => '/usr/local/www/drupal7/files/BLAST/aradu_cds.V14167.a1.M1',
      'dbtype'              => 'nucleotide',
      'dbxref_id_regex'     => '/^\w+\.(\w+\.\w+)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'peanutbase_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
    array(
      'name'                => 'Arachis duranensis - proteins',
      'path'                => '/usr/local/www/drupal7/files/BLAST/aradu_prot.V14167.a1.M1',
      'dbtype'              => 'protein',
      'dbxref_id_regex'     => '/^\w+\.(\w+\.\w+)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'peanutbase_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
    array(
      'name'                => 'Arachis ipaensis - genome',
      'path'                => '/usr/local/www/drupal7/files/BLAST/araip_genome.K30076.a1',
      'dbtype'              => 'nucleotide',
      'dbxref_id_regex'     => '/^\w+\.(\S*)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'peanutbase_gbrowse',
      'cvitjs_enabled'      => 1,
    ),
    array(
      'name'                => 'Arachis ipaensis - proteins',
      'path'                => '/usr/local/www/drupal7/files/BLAST/araip_prot.K30076.a1.M1',
      'dbtype'              => 'protein',
      'dbxref_id_regex'     => '/^\w+\.(\w+\.\w+)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'peanutbase_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
    array(
      'name'                => 'Arachis ipaensis - CDS',
      'path'                => '/usr/local/www/drupal7/files/BLAST/araip_cds.K30076.a1.M1',
      'dbtype'              => 'nucleotide',
      'dbxref_id_regex'     => '/^\w+\.(\w+\.\w+)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'peanutbase_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
    array(
      'name'                => 'Cultivated peanut - genome',
      'path'                => '/usr/local/www/drupal7/files/BLAST/arahy.Tifrunner.gnm1',
      'dbtype'              => 'nucleotide',
      'dbxref_id_regex'     => '/^\w+\.(\S*)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'peanutbase_gbrowse',
      'cvitjs_enabled'      => 1,
    ),
    array(
      'name'                => 'Cultivated peanut - CDS',
      'path'                => '/usr/local/www/drupal7/files/BLAST/arahy_cds.Tifrunner.gnm1',
      'dbtype'              => 'nucleotide',
      'dbxref_id_regex'     => '/^\w+\.(.+)\.\d/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'peanutbase_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
    array(
      'name'                => 'Cultivated peanut - Protein',
      'path'                => '/usr/local/www/drupal7/files/BLAST/arahy_prot.Tifrunner.gnm1',
      'dbtype'              => 'protein',
      'dbxref_id_regex'     => '/^\w+\.(.+)\.\d/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'peanutbase_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
    array(
      'name'                => 'Gene Family Consensus - Phytozome 10.2 (deprecated)',
      'path'                => '/usr/local/www/drupal7/files/BLAST/gene_family_consensus_phytozome10.2',
      'dbtype'              => 'protein',
      'dbxref_id_regex'     => 'default',
      'dbxref_db_id'        => 689,
      'dbxref_linkout_type' => 'link',
      'cvitjs_enabled'      => 0,
    ),
    array(
      'name'                => 'Gene Family Consensus - Legume Federation 1.0',
      'path'                => '/usr/local/www/drupal7/files/BLAST/gene_family_consensus_legfed1.0',
      'dbtype'              => 'protein',
      'dbxref_id_regex'     => 'default',
      'dbxref_db_id'        => 689,
      'dbxref_linkout_type' => 'link',
      'cvitjs_enabled'      => 0,
    ),
    array(
      'name'                => 'All genomes',
      'path'                => '/usr/local/www/drupal7/files/BLAST/all_peanut_genomes',
      'dbtype'              => 'nucleotide',
      'dbxref_id_regex'     => '/^\w+\.(\w+\.\w+)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'peanutbase_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
    array(
      'name'                => 'All CDS',
      'path'                => '/usr/local/www/drupal7/files/BLAST/all_peanut_cds',
      'dbtype'              => 'nucleotide',
      'dbxref_id_regex'     => '/^\w+\.(\w+\.\w+)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'peanutbase_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
    array(
      'name'                => 'All proteins',
      'path'                => '/usr/local/www/drupal7/files/BLAST/all_peanut_peptides',
      'dbtype'              => 'protein',
      'dbxref_id_regex'     => '/^\w+\.(\w+\.\w+)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'peanutbase_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
  );
    
  foreach ($blast_recs as $rec) {
    $node = new stdClass();
    $node->title = $rec['name'];
    $node->type = 'blastdb';
    $node->name = 'ecannon';
    
    // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
    node_object_prepare($node); 

    // All BLAST nodes have these
    $node->language = LANGUAGE_NONE; 
    $node->uid = $user->uid; 
    $node->status  = 1; // published
    $node->promote = 0; // not promoted to front page
    $node->comment = 0; // comments disabled

    $node->db_name = $rec['name'];
    $node->db_path = $rec['path'];
    $node->db_dbtype = $rec['dbtype'];
    $node->dbxref_linkout_type = $rec['dbxref_linkout_type'];
    $node->cvitjs_enabled = $rec['cvitjs_enabled'];

    $node = node_submit($node); // Prepare node for saving
    node_save($node);
print "\nCreated node:\n";print_r($rec);
    
  // Update the record with remaining information (db_id and reqex not saved in $node)
  db_update('blastdb')->fields($rec)->condition('nid', $node->nid)->execute();
  }//each BLAST db
}//drush_blast_ui_restore_blast_dbs


function drush_blast_ui_restore_lis_blast_dbs() {
print "drush_blast_ui_restore_lis_blast_dbs()\n";
  $blast_recs = 
    array(
      array(
        'name'                => 'All genomes',
        'path'                => '/usr/local/www/drupal7/files/BLAST/all_legume_genomes',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/\w+\.(\S+).*/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'All CDS',
        'path'                => '/usr/local/www/drupal7/files/BLAST/all_legume_cds',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(\S+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'All proteins',
        'path'                => '/usr/local/www/drupal7/files/BLAST/all_legume_peptides',
        'dbtype'              => 'protein',
        'dbxref_id_regex'     => '/^\w+\.(\S+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
      'name'                => 'Arachis duranensis - genome',
      'path'                => '/usr/local/www/drupal7/files/BLAST/aradu_genome.V14167.a1',
      'dbtype'              => 'nucleotide',
      'dbxref_id_regex'     => '/^\w+\.(\w+\.\w+)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'lis_gbrowse',
      'cvitjs_enabled'      => 1,
    ),
      array(
      'name'                => 'Arachis duranensis - CDS',
      'path'                => '/usr/local/www/drupal7/files/BLAST/aradu_cds.V14167.a1.M1',
      'dbtype'              => 'nucleotide',
      'dbxref_id_regex'     => '/^\w+\.(\w+\.\w+)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'lis_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
      array(
      'name'                => 'Arachis duranensis - proteins',
      'path'                => '/usr/local/www/drupal7/files/BLAST/aradu_prot.V14167.a1.M1',
      'dbtype'              => 'protein',
      'dbxref_id_regex'     => '/^\w+\.(\w+\.\w+)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'lis_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
      array(
      'name'                => 'Arachis ipaensis - genome',
      'path'                => '/usr/local/www/drupal7/files/BLAST/araip_genome.K30076.a1',
      'dbtype'              => 'nucleotide',
      'dbxref_id_regex'     => '/^\w+\.(\S*)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'lis_gbrowse',
      'cvitjs_enabled'      => 1,
    ),
      array(
      'name'                => 'Arachis ipaensis - proteins',
      'path'                => '/usr/local/www/drupal7/files/BLAST/araip_prot.K30076.a1.M1',
      'dbtype'              => 'protein',
      'dbxref_id_regex'     => '/^\w+\.(\w+\.\w+)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'lis_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
      array(
      'name'                => 'Arachis ipaensis - CDS',
      'path'                => '/usr/local/www/drupal7/files/BLAST/araip_cds.K30076.a1.M1',
      'dbtype'              => 'nucleotide',
      'dbxref_id_regex'     => '/^\w+\.(\w+\.\w+)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'lis_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
      array(
      'name'                => 'Cultivated peanut - genome',
      'path'                => '/usr/local/www/drupal7/files/BLAST/arahy.Tifrunner.gnm1',
      'dbtype'              => 'nucleotide',
      'dbxref_id_regex'     => '/^\w+\.(\S*)/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'lis_gbrowse',
      'cvitjs_enabled'      => 1,
    ),
      array(
      'name'                => 'Cultivated peanut - CDS',
      'path'                => '/usr/local/www/drupal7/files/BLAST/arahy_cds.Tifrunner.gnm1',
      'dbtype'              => 'nucleotide',
      'dbxref_id_regex'     => '/^\w+\.(.+)\.\d/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'lis_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
      array(
      'name'                => 'Cultivated peanut - Protein',
      'path'                => '/usr/local/www/drupal7/files/BLAST/arahy_prot.Tifrunner.gnm1',
      'dbtype'              => 'protein',
      'dbxref_id_regex'     => '/^\w+\.(.+)\.\d/',
      'dbxref_db_id'        => 0,
      'dbxref_linkout_type' => 'lis_gbrowse',
      'cvitjs_enabled'      => 0,
    ),
      array(
        'name'                => 'Cajanus cajan - genome',
        'path'                => '/usr/local/www/drupal7/files/BLAST/cajca_genome.ICPL87119.a1',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(.*)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 1,
      ),
      array(
        'name'                => 'Cajanus cajan - CDS',
        'path'                => '/usr/local/www/drupal7/files/BLAST/cajca_cds.ICPL87119.a1.v1',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(\S+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Cajanus cajan - proteins',
        'path'                => '/usr/local/www/drupal7/files/BLAST/cajca_prot.ICPL87119.a1.v1',
        'dbtype'              => 'protein',
        'dbxref_id_regex'     => '/^\w+\.(\S+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Cicer arietinum (desi, ICC4958) - genome',
        'path'                => '/usr/local/www/drupal7/files/BLAST/cicar.ICC4958.a2_genome',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^cicar.ICC4958\.(\w+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 1,
      ),
      array(
        'name'                => 'Cicer arietinum (desi, ICC4958) - CDS',
        'path'                => '/usr/local/www/drupal7/files/BLAST/cicar.ICC4958.a2.v1_cds',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^(.+)\.\d/',
        'dbxref_db_id'        => 3557,
        'dbxref_linkout_type' => 'link',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Cicer arietinum (desi, ICC4958) - proteins',
        'path'                => '/usr/local/www/drupal7/files/BLAST/cicar.ICC4958.a2.v1_prot',
        'dbtype'              => 'protein',
        'dbxref_id_regex'     => '/^(.+)\.\d/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Cicer arietinum (kabuli, CDC Frontier) - genome',
        'path'                => '/usr/local/www/drupal7/files/BLAST/cicar.CDCFrontier.v1_genome',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^cicar.CDCFrontier.v1\.(\S*)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 1,
      ),
      array(
        'name'                => 'Cicer arietinum (kabuli, CDC Frontier) - CDS',
        'path'                => '/usr/local/www/drupal7/files/BLAST/cicar.CDCFrontier.v1_cds',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(\S*)/',
        'dbxref_db_id'        => 3555,
        'dbxref_linkout_type' => 'link',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Cicer arietinum (kabuli, CDC Frontier) - proteins',
        'path'                => '/usr/local/www/drupal7/files/BLAST/cicar.CDCFrontier.v1_prot',
        'dbtype'              => 'protein',
        'dbxref_id_regex'     => '/^\w+\.(\S*)/',
        'dbxref_db_id'        => 3555,
        'dbxref_linkout_type' => 'link',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Gene Family Consensus',
        'path'                => '/usr/local/www/drupal7/files/BLAST/gene_family_consensus',
        'dbtype'              => 'protein',
        'dbxref_id_regex'     => '/^(\S+).*/',
        'dbxref_db_id'        => 3297,
        'dbxref_linkout_type' => 'link',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Glycine max Wm82.a2 - genome',
        'path'                => '/usr/local/www/drupal7/files/BLAST/glyma_genome.Wm82.a2',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(.*)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 1,
      ),
      array(
        'name'                => 'Glycine max Wm82.a2 - CDS',
        'path'                => '/usr/local/www/drupal7/files/BLAST/glyma_cds.Wm82.a2.v1',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(\S+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Glycine max Wm82.a2 - proteins',
        'path'                => '/usr/local/www/drupal7/files/BLAST/glyma_prot.Wm82.a2.v1',
        'dbtype'              => 'protein',
        'dbxref_id_regex'     => '/^\w+\.(\S+)\.p/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Lotus japonicus v3.0 - genome',
        'path'                => '/usr/local/www/drupal7/files/BLAST/lotja_genome.MMG20.a3.0',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(.*)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 1,
      ),
      array(
        'name'                => 'Lotus japonicus v3.0 - CDS',
        'path'                => '/usr/local/www/drupal7/files/BLAST/lotja_cds.MMG20.a3.0.v1',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(\S+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Lotus japonicus v3.0 - proteins',
        'path'                => '/usr/local/www/drupal7/files/BLAST/lotja_prot.MMG20.a3.0.v1',
        'dbtype'              => 'protein',
        'dbxref_id_regex'     => '/^\w+\.(\S+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Lupinus angustifolius - genome',
        'path'                => '/usr/local/www/drupal7/files/BLAST/lupan.Tanjil.gnm1',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/lupan\.(NLL-\d\d|Sc\S+)\S*/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 1,
      ),
      array(
        'name'                => 'Lupinus angustifolius - CDS',
        'path'                => '/usr/local/www/drupal7/files/BLAST/lupan.Tanjil.gnm1.ann1.cds',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w\w\w\w\w\.(\w+)\.\d+/',
        'dbxref_db_id'        => 3560,
        'dbxref_linkout_type' => 'link',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Lupinus angustifolius - protein',
        'path'                => '/usr/local/www/drupal7/files/BLAST/lupan.Tanjil.gnm1.ann1.prot',
        'dbtype'              => 'protein',
        'dbxref_id_regex'     => '/^\w\w\w\w\w\.(\w+)\.\d+/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Medicago truncatula v4.0 - genome',
        'path'                => '/usr/local/www/drupal7/files/BLAST/medtr_genome.A17.a4',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(.*)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 1,
      ),
      array(
        'name'                => 'Medicago truncatula v4.0 - CDS',
        'path'                => '/usr/local/www/drupal7/files/BLAST/medtr_cds.A17.a4.v1',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(\w+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Medicago truncatula v4.0 - proteins',
        'path'                => '/usr/local/www/drupal7/files/BLAST/medtr_prot.A17.a4.v1',
        'dbtype'              => 'protein',
        'dbxref_id_regex'     => '/^\w+\.(\w+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Phaseolus vulgaris - genome',
        'path'                => '/usr/local/www/drupal7/files/BLAST/phavu_genome.G19833.a1',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(.*)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 1,
      ),
      array(
        'name'                => 'Phaseolus vulgaris - CDS',
        'path'                => '/usr/local/www/drupal7/files/BLAST/phavu_cds.G19833.a1.v1',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(\S+)/',
        'dbxref_db_id'        => 3299,
        'dbxref_linkout_type' => 'link',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Phaseolus vulgaris - protein',
        'path'                => '/usr/local/www/drupal7/files/BLAST/phavu_prot.G19833.a1.v1',
        'dbtype'              => 'protein',
        'dbxref_id_regex'     => '/^\w+\.(\S+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Trifolium pratense - genome',
        'path'                => '/usr/local/www/drupal7/files/BLAST/tripr_genome.MilvusB.a2.1',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(\S+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 1,
      ),
      array(
        'name'                => 'Trifolium pratense - CDS',
        'path'                => '/usr/local/www/drupal7/files/BLAST/tripr_cds.MilvusB.a2.1.v1',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(\w+)/',
        'dbxref_db_id'        => 3402,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Trifolium pratense - protein',
        'path'                => '/usr/local/www/drupal7/files/BLAST/tripr_prot.MilvusB.a2.1.v1',
        'dbtype'              => 'protein',
        'dbxref_id_regex'     => '/^\w+\.(\w+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Vigna angularis - genome',
        'path'                => '/usr/local/www/drupal7/files/BLAST/vigan_genome.Gyeongwon.a3',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/(Va\d\d|vigan.[Ss].+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 1,
      ),
      array(
        'name'                => 'Vigna angularis - CDS',
        'path'                => '/usr/local/www/drupal7/files/BLAST/vigan_cds.Gyeongwon.a3.v1',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(\S*)/',
        'dbxref_db_id'        => 3427,
        'dbxref_linkout_type' => 'link',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Vigna angularis - proteins',
        'path'                => '/usr/local/www/drupal7/files/BLAST/vigan_prot.Gyeongwon.a3.v1',
        'dbtype'              => 'protein',
        'dbxref_id_regex'     => '/^\w+\.(\S*)/',
        'dbxref_db_id'        => 3427,
        'dbxref_linkout_type' => 'link',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Vigna radiata - genome',
        'path'                => '/usr/local/www/drupal7/files/BLAST/vigra_genome.VC1973A.a1',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(.*)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 1,
      ),
      array(
        'name'                => 'Vigna radiata - CDS',
        'path'                => '/usr/local/www/drupal7/files/BLAST/vigra_cds.VC1973A.a1.v1',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(\w+)/',
        'dbxref_db_id'        => 3307,
        'dbxref_linkout_type' => 'link',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Vigna radiata - protein',
        'path'                => '/usr/local/www/drupal7/files/BLAST/vigra_prot.VC1973A.a1.v1',
        'dbtype'              => 'protein',
        'dbxref_id_regex'     => '/^\w+\.(\w+)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Vigna unguiculata - genome',
        'path'                => '/usr/local/www/drupal7/files/BLAST/vigun.IT97K-499-35.gnm1_genome',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+.(\S*)/',
        'dbxref_db_id'        => 0,
        'dbxref_linkout_type' => 'lis_gbrowse',
        'cvitjs_enabled'      => 1,
      ),
      array(
        'name'                => 'Vigna unguiculata - CDS',
        'path'                => '/usr/local/www/drupal7/files/BLAST/vigun.IT97K-499-35.gnm1.ann1_cds',
        'dbtype'              => 'nucleotide',
        'dbxref_id_regex'     => '/^\w+\.(\S*)/',
        'dbxref_db_id'        => 3709,
        'dbxref_linkout_type' => 'link',
        'cvitjs_enabled'      => 0,
      ),
      array(
        'name'                => 'Vigna unguiculata - Protein',
        'path'                => '/usr/local/www/drupal7/files/BLAST/vigun.IT97K-499-35.gnm1.ann1_prot',
        'dbtype'              => 'protein',
        'dbxref_id_regex'     => '/^\w+\.(\S*)/',
        'dbxref_db_id'        => 3709,
        'dbxref_linkout_type' => 'link',
        'cvitjs_enabled'      => 0,
      ),
  );
  
  _restoreBLASTtargets($blast_recs);
}//drush_blast_ui_restore_lis_last_dbs


function _restoreBLASTtargets($blast_recs) {
  foreach ($blast_recs as $rec) {
    $node = new stdClass();
    $node->title = $rec['name'];
    $node->type = 'blastdb';
    $node->name = 'ecannon';
    
    // Sets some defaults. Invokes hook_prepare() and hook_node_prepare().
    node_object_prepare($node); 

    // All BLAST nodes have these
    $node->language = LANGUAGE_NONE; 
    $node->uid = $user->uid; 
    $node->status  = 1; // published
    $node->promote = 0; // not promoted to front page
    $node->comment = 0; // comments disabled

    $node->db_name = $rec['name'];
    $node->db_path = $rec['path'];
    $node->db_dbtype = $rec['dbtype'];
    $node->dbxref_linkout_type = $rec['dbxref_linkout_type'];
    $node->cvitjs_enabled = $rec['cvitjs_enabled'];

    $node = node_submit($node); // Prepare node for saving
    node_save($node);
print "\nCreated node:\n";print_r($rec);
    
  // Update the record with remaining information (db_id and reqex not saved in $node)
  db_update('blastdb')->fields($rec)->condition('nid', $node->nid)->execute();
  }//each BLAST db
}//_restoreBLASTtargets