<?php
print '<!doctype html public "-//W3C//DTD HTML 4.01 Transitional//EN"><html><head><meta http-equiv="Content-Type" content="text/html;charset=utf-8" >';
include_once("backend/globalVariables/passwordFile.inc");
include_once("backend/globalVariables/lists.inc");
$worker = 'Issa Rice';
if (!empty($_REQUEST['worker'])) {
  $worker = $_REQUEST['worker'];
}
print "<title>$worker work details: Contract work for Vipul Naik</title>";
include_once('analytics.inc');
print '</head>';
print '<body>';
print "<h3>Contract work by $worker for Vipul Naik</h3>";
$workerSelectQuery = "select * from workers where worker='$worker' and private = false;";
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
  print '<li><a href="#workerImpact">Worker impact</a></li>';
  print '<li><a href="#workerPaymentsDueByTypeAndMonth">Worker payments due by type and month</a></li>';
  print '<li><a href="#workerTaskPaymentsDueByTypeAndMonth">Worker task payments due by type and month</a></li>';
  print '<li><a href="#workerPaymentsDueAndMadeByMonth">Worker task payments due and made by month</a></li>';
  print '<li><a href="#workerTaskList">Worker task list</a></li>';
  print '</ul>';
  print "<p>All payment amounts are listed in current United States dollars (USD).</p>";
  $printTables = true;
  include("backend/workerInfo.inc");
  include("backend/workerPaymentsDueByTypeAndYear.inc");
  include("backend/workerPaymentsMadeByMethodAndYear.inc");
  include("backend/workerTaskPaymentsDueByTypeAndYear.inc");
  include("backend/workerTaskPaymentsDueByTopicAndYear.inc");
  include("backend/workerTaskPaymentsDueByVenueAndYear.inc");
  include("backend/workerImpact.inc");
  include("backend/workerPaymentsDueByTypeAndMonth.inc");
  include("backend/workerTaskPaymentsDueByTypeAndMonth.inc");
  include("backend/workerPaymentsDueAndMadeByMonth.inc");
  include("backend/workerTaskList.inc");
  if ($totalCommissionOnTaskPayment > 0) {
    include("backend/workerCommissionOnTaskList.inc");
  }
  if ($totalStipendPayment[1] > 0) {
    include("backend/workerAwardedStipendList.inc");
  }
  if ($totalStipendPayment[0] > 0) {
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
print '</body>';
?>