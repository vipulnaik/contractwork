<?php
include_once('doctype.inc');
include_once("backend/globalVariables/passwordFile.inc");
include_once("backend/globalVariables/lists.inc");
include_once("backend/stringFunctions.inc");
include_once('analytics.inc');
include_once('strip-commas.inc');
print '<link href="style.css" rel="stylesheet" type="text/css" />'."\n";
print '<script type="text/javascript" src="./jquery-3.1.1.min.js"></script>'."\n";
print '<script type="text/javascript" src="./jquery.tablesorter.js"></script>'."\n";
$venue = '';
$matchingMethod = "REGEXP";
if (!empty($_REQUEST['venue'])) {
  $venue = $_REQUEST['venue'];
}
if (!empty($_REQUEST['matching'])) {
  $matching = $_REQUEST['matching'];
  if ($matching == "exact") {
    $matchingMethod = "=";
  }
}
if ($venue != '') {
  $venueRegexMatcher = '`task_venue` '.$matchingMethod.' "'.str_replace('"','\"',$venue).'"';
  print "<title>$venue venue work details: Contract work for Vipul Naik</title>";
  print '</head>';
  print '<body>';
  print '<script>$(document).ready(function(){$("table").tablesorter({textExtraction: stripCommas});});</script>'."\n";
  print "<h3>Contract work related to venue $venue for Vipul Naik</h3>";
} else {
  $venueRegexMatcher = '1 = 1';
  print "<title>All task details: Contract work for Vipul Naik</title>";
  print '</head>';
  print '<body>';
  print '<script>$(document).ready(function(){$("table").tablesorter({textExtraction: stripCommas});});</script>'."\n";
  print "<h3>Contract work (all tasks) for Vipul Naik</h3>";
}

$taskSelectQuery = "select * from tasks where $venueRegexMatcher and private = false;";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
if ($taskSelectResult -> num_rows == 0) {
  print "<p>We could not find any tasks with a matching venue.</p>";
} else {
  print '<h4>Table of contents</h4>';
  print '<ul>';
  print '<li><a href="#venueTaskPaymentsDueByTypeAndYear">Venue task payments due by type and year</a></li>';
  print '<li><a href="#venueImpact">Venue impact: Wikipedia</a></li>';
  print '<li><a href="#venueTaskPaymentsDueByTypeAndMonth">Venue task payments due by type and month</a></li>';
  print '<li><a href="#venueTaskList">Venue task list</a></li>';
  print '</ul>';
  include("backend/venueTaskPaymentsDueByTypeAndYear.inc");
  include("backend/venueImpact.inc");
  include("backend/venueTaskPaymentsDueByTypeAndMonth.inc");
  include("backend/venueTaskList.inc");
}
include_once('anchorjs.inc');
print '</body>';
?>
