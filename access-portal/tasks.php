<?php
include_once('doctype.inc');
include_once("backend/globalVariables/passwordFile.inc");
include_once("backend/globalVariables/lists.inc");
include_once("backend/stringFunctions.inc");
$receptacle = "";
$receptacle_url = "";
$matchingMethod = "REGEXP";
$titleExtras = "";
if (!empty($_REQUEST['receptacle'])) {
  $receptacle = $_REQUEST['receptacle'];
  $titleExtras .= "receptacle $receptacle, ";
}
if (!empty($_REQUEST['matching'])) {
  $matching = $_REQUEST['matching'];
  if ($matching == "exact") {
    $matchingMethod = "=";
  }
}
if (!empty($_REQUEST['receptacle_url'])) {
  $receptacle_url = $_REQUEST['receptacle_url'];
  $titleExtras .= "receptable_url $receptacle_url";
}
$filterQuery = "";
if ($receptacle != "" && $receptacle_url != "") {
  $filterQuery = "task_receptacle $matchingMethod \"".str_replace('"','\"',$receptacle)."\" and task_receptacle_url $matchingMethod \"".str_replace('"','\"',$receptacle_url)."\"";
} else if ($receptacle != "") {
  $filterQuery = "task_receptacle $matchingMethod \"".str_replace('"','\"',$receptacle)."\"";
} else if ($receptacle_url != "") {
  $filterQuery = "task_receptacle_url $matchingMethod \"".str_replace('"','\"',$receptacle_url)."\"";
}

include_once('analytics.inc');
include_once('strip-commas.inc');
print "<title>$titleExtras contract work for Vipul Naik</title>\n";
print '<link href="style.css" rel="stylesheet" type="text/css" />'."\n";
print '<script type="text/javascript" src="./jquery-3.1.1.min.js"></script>'."\n";
print '<script type="text/javascript" src="./jquery.tablesorter.js"></script>'."\n";
print '</head>';
print '<body>';
print '<script>$(document).ready(function(){$("table").tablesorter({textExtraction: stripCommas});});</script>'."\n";
print "<h3>$titleExtras contract work for Vipul Naik</h3>";
print '<h4>Table of contents</h4>';
print '<ul>';
print '<li><a href="#filteredTaskPaymentsDueByTypeAndYear">Filtered task payments due by type and year</a></li>';
print '<li><a href="#filteredTaskPaymentsDueByVenueAndYear">Filtered task payments due by venue and year</a></li>';
print '<li><a href="#filteredTaskPaymentsDueByFormatAndYear">Filtered task payments due by format  and year</a></li>';
print '<li><a href="#filteredTaskList">Filtered task list</a></li>';
print '</ul>';

include("backend/filteredTaskPaymentsDueByTypeAndYear.inc");
include("backend/filteredTaskPaymentsDueByVenueAndYear.inc");
include("backend/filteredTaskPaymentsDueByFormatAndYear.inc");
include("backend/filteredTaskList.inc");
include_once('anchorjs.inc');
print '</body>';
?>
