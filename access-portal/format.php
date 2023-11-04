<?php
include_once('doctype.inc');
print '<script src="change-theme.js"></script>';
include_once("backend/globalVariables/passwordFile.inc");
include_once("backend/globalVariables/lists.inc");
include_once("backend/functions.inc");
include_once('backend/graphing.inc');
include_once('analytics.inc');
include_once('strip-commas.inc');
print '<link href="style.css" rel="stylesheet" type="text/css" />'."\n";
include_once('style.inc');
print '<script type="text/javascript" src="./jquery-3.1.1.min.js"></script>'."\n";
print '<script type="text/javascript" src="./jquery.tablesorter.js"></script>'."\n";
$format = '';
if (!empty($_REQUEST['format'])) {
  $format = $_REQUEST['format'];
}
$formatRegexMatcherParamStr = "";
$formatRegexMatcherParams = array();
if ($format != '') {
  $formatRegexMatcher = '`format` REGEXP ?';
  $formatRegexMatcherParamStr .= "s";
  $formatRegexMatcherParams[] = $format;
  print "<title>$format format work details: Contract work for Vipul Naik</title>";
  print '</head>';
  print '<body>';
  print '<script>$(document).ready(function(){$("table").tablesorter({textExtraction: stripCommas});});</script>'."\n";
  print "<h3>Contract work related to format $format for Vipul Naik</h3>";
} else {
  $formatRegexMatcher = '1 = 1';
  print "<title>All task details: Contract work for Vipul Naik</title>";
  print '</head>';
  print '<body>';
  print '<script>$(document).ready(function(){$("table").tablesorter({textExtraction: stripCommas});});</script>'."\n";
  print "<h3>Contract work (all tasks) for Vipul Naik</h3>";
}
print '<p><span id="changeThemeMenu" style="display: none;">Change <a href="javascript:;" onclick="change_theme_color()">color</a></span>   &thinsp;<!-- blank space to prevent cumulative layout shift --></p>';
$taskSelectQuery = "select * from tasks where $formatRegexMatcher and private = false;";
$stmt = $mysqli->prepare($taskSelectQuery);
if ($formatRegexMatcherParams) {
  $stmt->bind_param($formatRegexMatcherParamStr, ...$formatRegexMatcherParams);
}
$stmt->execute();
$taskSelectResult = $stmt->get_result();
if ($taskSelectResult -> num_rows == 0) {
  print "<p>We could not find any tasks with a matching format.</p>";
} else {
  print '<h4>Table of contents</h4>';
  print '<ul>';
  print '<li><a href="#formatTaskPaymentsDueByTypeAndYear">Format task payments due by type and year</a></li>';
  # print '<li><a href="#formatImpact">Format impact: Wikipedia</a></li>';
  print '<li><a href="#formatTaskPaymentsDueByTypeAndMonth">Format task payments due by type and month</a></li>';
  print '<li><a href="#formatTaskList">Format task list</a></li>';
  print '</ul>';
  include("backend/formatTaskPaymentsDueByTypeAndYear.inc");
  # Disabling the line below as its dependency on Wikipedia Views creates further complications
  # include("backend/formatImpact.inc");
  include("backend/formatTaskPaymentsDueByTypeAndMonth.inc");
  include("backend/formatTaskList.inc");
}
include_once('anchorjs.inc');
print '</body>';
?>
