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
$topic = '';
if (!empty($_REQUEST['topic'])) {
  $topic = $_REQUEST['topic'];
}
$topicRegexMatcherParamStr = "";
$topicRegexMatcherParams = array();
if ($topic != '') {
  $topicRegexMatcher = '`topic` REGEXP ?';
  $topicRegexMatcherParamStr .= "s";
  $topicRegexMatcherParams[] = $topic;
  print "<title>$topic topic work details: Contract work for Vipul Naik</title>";
  print '</head>';
  print '<body>';
  print '<script>$(document).ready(function(){$("table").tablesorter({textExtraction: stripCommas});});</script>'."\n";
  print "<h3>Contract work related to topic $topic for Vipul Naik</h3>";
} else {
  $topicRegexMatcher = '1 = 1';
  print "<title>All task details: Contract work for Vipul Naik</title>";
  print '</head>';
  print '<body>';
  print '<script>$(document).ready(function(){$("table").tablesorter({textExtraction: stripCommas});});</script>'."\n";
  print "<h3>Contract work (all tasks) for Vipul Naik</h3>";
}

$taskSelectQuery = "select * from tasks where $topicRegexMatcher and private = false;";
$stmt = $mysqli->prepare($taskSelectQuery);
if ($topicRegexMatcherParams) {
  $stmt->bind_param($topicRegexMatcherParamStr, ...$topicRegexMatcherParams);
}
$stmt->execute();
$taskSelectResult = $stmt->get_result();
if ($taskSelectResult -> num_rows == 0) {
  print "<p>We could not find any tasks with a matching topic.</p>";
} else {
  print '<h4>Table of contents</h4>';
  print '<ul>';
  print '<li><a href="#topicTaskPaymentsDueByTypeAndYear">Topic task payments due by type and year</a></li>';
  print '<li><a href="#topicImpact">Topic impact: Wikipedia</a></li>';
  print '<li><a href="#topicTaskPaymentsDueByTypeAndMonth">Topic task payments due by type and month</a></li>';
  print '<li><a href="#topicTaskList">Topic task list</a></li>';
  print '</ul>';
  include("backend/topicTaskPaymentsDueByTypeAndYear.inc");
  include("backend/topicImpact.inc");
  include("backend/topicTaskPaymentsDueByTypeAndMonth.inc");
  include("backend/topicTaskList.inc");
}
include_once('anchorjs.inc');
print '</body>';
?>
