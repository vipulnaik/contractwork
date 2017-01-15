<?php
print '<!doctype html public "-//W3C//DTD HTML 4.01 Transitional//EN"><html><head><meta http-equiv="Content-Type" content="text/html;charset=utf-8" >';
include_once("backend/globalVariables/passwordFile.inc");
include_once("backend/globalVariables/lists.inc");
include_once('analytics.inc');
print '<link href="style.css" rel="stylesheet" type="text/css" />'."\n";
print '<script type="text/javascript" src="./jquery-3.1.1.min.js"></script>'."\n";
print '<script type="text/javascript" src="./jquery.tablesorter.js"></script>'."\n";
$topic = '';
if (!empty($_REQUEST['topic'])) {
  $topic = $_REQUEST['topic'];
}
if ($topic != '') {
  $topicRegexMatcher = '`topic` REGEXP "'.$topic.'"';
  print "<title>$topic topic work details: Contract work for Vipul Naik</title>";
  print '</head>';
  print '<body>';
  print '<script>$(document).ready(function()
    {
        $("#myTableTopicTaskPaymentsDueByTypeAndYear").tablesorter();
        $("#myTableTopicTaskPaymentsDueByTypeAndMonth").tablesorter();
        $("#myTableTopicTaskList").tablesorter();
    }
  ); </script>'."\n";
  print "<h3>Contract work related to topic $topic for Vipul Naik</h3>";
} else {
  $topicRegexMatcher = '1 = 1';
  print "<title>All task details: Contract work for Vipul Naik</title>";
  print '</head>';
  print '<body>';
  print '<script>$(document).ready(function()
    {
        $("#myTableTopicTaskPaymentsDueByTypeAndYear").tablesorter();
        $("#myTableTopicTaskPaymentsDueByTypeAndMonth").tablesorter();
        $("#myTableTopicTaskList").tablesorter();
    }
  ); </script>'."\n";
  print "<h3>Contract work (all tasks) for Vipul Naik</h3>";
}

$taskSelectQuery = "select * from tasks where $topicRegexMatcher and private = false;";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
if ($taskSelectResult -> num_rows == 0) {
  print "<p>We could not find any tasks with a matching topic.</p>";
} else {
  print '<h4>Table of contents</h4>';
  print '<ul>';
  print '<li><a href="#topicTaskPaymentsDueByTypeAndYear">Topic task payments due by type and year</a></li>';
  print '<li><a href="#topicTaskPaymentsDueByTypeAndMonth">Topic task payments due by type and month</a></li>';
  print '<li><a href="#topicTaskList">Topic task list</a></li>';
  print '</ul>';
  include("backend/topicTaskPaymentsDueByTypeAndYear.inc");
  include("backend/topicTaskPaymentsDueByTypeAndMonth.inc");
  include("backend/topicTaskList.inc");
}
print '</body>';
?>