<?php
print '<!doctype html public "-//W3C//DTD HTML 4.01 Transitional//EN"><html><head><meta http-equiv="Content-Type" content="text/html;charset=utf-8" >';
include_once("backend/globalvariables/passwordFile.inc");
include_once("backend/globalvariables/lists.inc");
$worker = 'Issa Rice';
$topic = '';
if (!empty($_REQUEST['topic'])) {
  $topic = $_REQUEST['topic'];
}
if ($topic != '') {
  $topicRegexMatcher = '`topic` REGEXP "'.$topic.'"';
  print "<title>$topic topic work details: Contract work for Vipul Naik</title>";
  print '</head>';
  print '<body>';
  print "<h3>Contract work related to topic $topic for Vipul Naik</h3>";
} else {
  $topicRegexMatcher = '1 = 1';
  print "<title>All task details: Contract work for Vipul Naik</title>";
  print '</head>';
  print '<body>';
  print "<h3>Contract work (all tasks) for Vipul Naik</h3>";
}

$taskSelectQuery = "select * from tasks where $topicRegexMatcher and private = false;";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
if ($taskSelectResult -> num_rows == 0) {
  print "<p>We could not find any tasks with a matching topic.</p>";
} else {
  include("backend/topicTaskPaymentsDueByTypeAndYear.inc");
  include("backend/topicTaskList.inc");
}
print '</body>';
?>