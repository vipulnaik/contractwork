<?php
print '<!doctype html public "-//W3C//DTD HTML 4.01 Transitional//EN"><html><head><meta http-equiv="Content-Type" content="text/html;charset=utf-8" >';
include_once("backend/globalVariables/passwordFile.inc");
include_once("backend/globalVariables/lists.inc");
include_once("backend/stringFunctions.inc");
$payer = 'Vipul Naik';
if (!empty($_REQUEST['payer'])) {
  $payer = $_REQUEST['payer'];
}
print "<title>$payer sponsored task details: Contract work for Vipul Naik</title>";
include_once('analytics.inc');
print '<link href="style.css" rel="stylesheet" type="text/css" />'."\n";
print '<script type="text/javascript" src="./jquery-3.1.1.min.js"></script>'."\n";
print '<script type="text/javascript" src="./jquery.tablesorter.js"></script>'."\n";
print '</head>';
print '<body>';
print '<script>$(document).ready(function()
    {
        if ($payer != "Vipul Naik") {
          $("#myTablePayerPaymentsMadeByMethodAndYear").tablesorter();
        }
        $("#myTablePayerTaskPaymentsDueByTypeAndYear").tablesorter();
        $("#myTablePayerTaskPaymentsDueByTopicAndYear").tablesorter();
        $("#myTablePayerTaskPaymentsDueByVenueAndYear").tablesorter();
        $("#myTablePayerTaskPaymentsDueByFormatAndYear").tablesorter();
        $("#myTablePayerTaskPaymentsDueByWorkerAndType").tablesorter();
        $("#myTablePayerTaskPaymentsDueByTypeAndMonth").tablesorter();
        if ($payer != "Vipul Naik") {
          $("#myTablePayerPaymentsDueAndMadeByMonth").tablesorter();
        }
        $("#myTablePayerTaskPaymentsDueByTopicAndMonth").tablesorter();
        $("#myTablePayerTaskPaymentsDueByVenueAndMonth").tablesorter();
        $("#myTablePayerTaskPaymentsDueByFormatAndMonth").tablesorter();
        $("#myTablePayerTaskList").tablesorter();
        if ($payer != Vipul Naik") {
          $("#myTablePayerPaymentList").tablesorter();
        }
     }
); </script>'."\n";
print "<h3>Contract work sponsored by $payer for Vipul Naik</h3>";
$payerSelectQuery = "select payer from tasks where payer=".'"'.str_replace('"','\"',$payer).'"'.";";
$payerSelectResult = $mysqli -> query($payerSelectQuery);
if ($payerSelectResult -> num_rows == 0) {
  print '<p>Sorry, we did not find a payer with this name in our public list of payers. Go back to the <a href="/">home page</a> for a full list of payers.</p>';
} else {
  print '<h4>Table of contents</h4>';
  print '<ul>';
  if ($payer != "Vipul Naik") {
    print '<li><a href="#payerPaymentsMadeByMethodAndYear">Payer payments made by method and year</a></li>';
  }
  print '<li><a href="#payerTaskPaymentsDueByTypeAndYear">Payer task payments due by type and year</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByTopicAndYear">Payer task payments due by topic and year</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByVenueAndYear">Payer task payments due by venue and year</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByFormatAndYear">Payer task payments due by format and year</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByWorkerAndType">Payer task payments due by worker and type</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByTypeAndMonth">Payer task payments due by type and month</a></li>';
  if ($payer != "Vipul Naik") {
    print '<li><a href="#payerPaymentsDueAndMadeByMonth">Payer task payments due by type and month</a></li>';
  }
  print '<li><a href="#payerTaskPaymentsDueByTopicAndMonth">Payer task payments due by topic and month</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByVenueAndMonth">Payer task payments due by venue and month</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByFormatAndMonth">Payer task payments due by format and month</a></li>';
  print '<li><a href="#payerTaskList">Payer task list</a></li>';
  if ($payer != "Vipul Naik") {
    print '<li><a href="#payerPaymentList">Payer payment list</a></li>';
  }
  print '</ul>';
  print "<p>All payment amounts are listed in current United States dollars (USD).</p>";
  $printTables = true;
  if ($payer != "Vipul Naik") {
    include("backend/payerPaymentsMadeByMethodAndYear.inc");
  }
  include("backend/payerTaskPaymentsDueByTypeAndYear.inc");
  include("backend/payerTaskPaymentsDueByTopicAndYear.inc");
  include("backend/payerTaskPaymentsDueByVenueAndYear.inc");
  include("backend/payerTaskPaymentsDueByFormatAndYear.inc");
  include("backend/payerTaskPaymentsDueByWorkerAndType.inc");
  include("backend/payerTaskPaymentsDueByTypeAndMonth.inc");
  if ($payer != "Vipul Naik") {
    include("backend/payerPaymentsDueAndMadeByMonth.inc");
  }
  include("backend/payerTaskPaymentsDueByTopicAndMonth.inc");
  include("backend/payerTaskPaymentsDueByVenueAndMonth.inc");
  include("backend/payerTaskPaymentsDueByFormatAndMonth.inc");
  include("backend/payerTaskList.inc");
  if ($payer != "Vipul Naik") {
    include("backend/payerPaymentList.inc");
  }
}
print '</body>';
?>