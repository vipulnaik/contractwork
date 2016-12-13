<?php
print '<!doctype html public "-//W3C//DTD HTML 4.01 Transitional//EN"><html><head><meta http-equiv="Content-Type" content="text/html;charset=utf-8" >';
include_once("backend/globalvariables/passwordFile.inc");
include_once("backend/globalvariables/lists.inc");
$worker = 'Issa Rice';
if (!empty($_REQUEST['topic'])) {
  $topic = $_REQUEST['topic'];
}
print "<title>$topic topicwork details: Contract work for Vipul Naik</title>";
print '</head>';
print '<body>';
print "<h3>Contract work related to topic $topic for Vipul Naik</h3>";
$taskSelectQuery = 'select * from tasks where topic REGEXP "'.$topic.'";';
$taskSelectResult = $mysqli -> query($taskSelectQuery);
if ($taskSelectResult -> num_rows == 0) {
  print "<p>We could not find any tasks whose topic matched $topic.</p>";
} else {
  include("backend/topicTaskPaymentsDueByTypeAndYear.inc");
  include("backend/topicTaskList.inc");
}
print '</body>';
?>