<?php
include_once('doctype.inc');
include_once("backend/globalVariables/passwordFile.inc");
include_once("backend/globalVariables/lists.inc");
include_once("backend/stringFunctions.inc");
$worker = 'Issa Rice';
if (!empty($_REQUEST['worker'])) {
  $worker = $_REQUEST['worker'];
}
print "<title>$worker work details: Contract work for Vipul Naik</title>";
include_once('analytics.inc');
include_once('strip-commas.inc');
print '<link href="style.css" rel="stylesheet" type="text/css" />'."\n";
print '<script type="text/javascript" src="./jquery-3.1.1.min.js"></script>'."\n";
print '<script type="text/javascript" src="./jquery.tablesorter.js"></script>'."\n";
print '</head>';
print '<body>';
print '<script>$(document).ready(function(){$("table").tablesorter({textExtraction: stripCommas});});</script>'."\n";
print "<h3>Contract work by $worker for Vipul Naik</h3>";
$workerSelectQuery = "select * from workers where worker=".'"'.str_replace('"','\"',$worker).'"'." and private = false;";
$workerSelectResult = $mysqli -> query($workerSelectQuery);
if ($workerSelectResult -> num_rows == 0) {
  print '<p>Sorry, we did not find a worker with this name in our public list of workers. Go back to the <a href="/">home page</a> for a full list of workers.</p>';
} else {
  print '<h4>Table of contents</h4>';
  print '<ul>';
  print '<li><a href="#workerInfo">Basic worker information</a></li>';
  print '<li><a href="#workerPaymentsDueByTypeAndYear">Worker payments due by type and year</a></li>';
  print '<li><a href="#workerPaymentsMadeByMethodAndYear">Worker payments made by method and year</a></li>';
  print '<li><a href="#workerTaskPaymentsDueByTypeAndYear">Worker task payments due by type and year</a></li>';
  print '<li><a href="#workerTaskPaymentsDueByTopicAndYear">Worker task payments due by topic and year</a></li>';
  print '<li><a href="#workerTaskPaymentsDueByVenueAndYear">Worker task payments due by venue and year</a></li>';
  print '<li><a href="#workerTaskPaymentsDueByFormatAndYear">Worker task payments due by format and year</a></li>';
  print '<li><a href="#workerImpact">Worker impact</a></li>';
  print '<li><a href="#workerPaymentsDueByTypeAndMonth">Worker payments due by type and month</a></li>';
  print '<li><a href="#workerTaskPaymentsDueByTypeAndMonth">Worker task payments due by type and month</a></li>';
  print '<li><a href="#workerTaskPaymentsDueByTopicAndMonth">Worker task payments due by topic and month</a></li>';
  print '<li><a href="#workerTaskPaymentsDueByVenueAndMonth">Worker task payments due by venue and month</a></li>';
  print '<li><a href="#workerTaskPaymentsDueByFormatAndMonth">Worker task payments due by format and month</a></li>';
  print '<li><a href="#workerPaymentsDueAndMadeByMonth">Worker payments due and made by month</a></li>';
  print '<li><a href="#workerTaskList">Worker task list</a></li>';
  print '<li><a href="#workerCommissionsOnTasks">Commissions on tasks: breakdown by earner</a></li>';
  print '<li><a href="#workerFullStipendsList">Full list of awarded stipends in reverse chronological order</a></li>';
  print '<li><a href="#workerRoyaltyList">Full list of royalties in reverse chronological order</a></li>';
  print '<li><a href="#workerCommissionOnRoyaltyList">Commissions on royalties</a></li>';
  print '<li><a href="#workerPaymentList">Full list of received payments in reverse chronological order</a></li>';
  print '</ul>';
  print "<p>All payment amounts are listed in current United States dollars (USD).</p>";
  $printTables = true;
  include("backend/workerInfo.inc");
  include("backend/workerPaymentsDueByTypeAndYear.inc");
  include("backend/workerPaymentsMadeByMethodAndYear.inc");
  include("backend/workerTaskPaymentsDueByTypeAndYear.inc");
  include("backend/workerTaskPaymentsDueByTopicAndYear.inc");
  include("backend/workerTaskPaymentsDueByVenueAndYear.inc");
  include("backend/workerTaskPaymentsDueByFormatAndYear.inc");
  include("backend/workerImpact.inc");
  include("backend/workerPaymentsDueByTypeAndMonth.inc");
  include("backend/workerTaskPaymentsDueByTypeAndMonth.inc");
  include("backend/workerTaskPaymentsDueByTopicAndMonth.inc");
  include("backend/workerTaskPaymentsDueByVenueAndMonth.inc");
  include("backend/workerTaskPaymentsDueByFormatAndMonth.inc");
  include("backend/workerPaymentsDueAndMadeByMonth.inc");
  include("backend/workerTaskList.inc");
  if ($totalCommissionOnTaskPayment > 0) {
    include("backend/workerCommissionOnTaskList.inc");
  }
  if ($totalStipendPaymentAwardedInSameMonth + $totalStipendPaymentStraddlingMonths > 0) {
    include("backend/workerAwardedStipendList.inc");
  }
  if ($totalUnawardedStipendPayment > 0) {
    include("backend/workerDeferredStipendList.inc");
  }
  if ($totalRoyaltyPayment > 0) {
    include("backend/workerRoyaltyList.inc");
  }
  if ($totalCommissionOnRoyaltyPayment > 0) {
    include("backend/workerCommissionOnRoyaltyList.inc");
  }
  if ($totalPaymentMadeToWorker > 0) {
    include("backend/workerPaymentList.inc");
  }
}
include_once('anchorjs.inc');
print '</body>';
?>
