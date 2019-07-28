<?php
function show_toc_line($mysqli, $worker, $query) {
  if ($stmt = $mysqli->prepare($query)) {
    $stmt->bind_param("s", $worker);
    $stmt->execute();
    // Get result to allow the next query to happen, but we only need the
    // number of rows so don't bother assigning to a variable
    $stmt->get_result();
    if ($mysqli->affected_rows > 0) {
      return true;
    }
  }
  return false;
}

include_once('doctype.inc');
include_once("backend/globalVariables/passwordFile.inc");
include_once("backend/globalVariables/lists.inc");
include_once("backend/stringFunctions.inc");
include_once('backend/graphing.inc');
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
  print '<li><a href="#workerPaymentsDueByTypeAndMonth">Worker payments due by type and month</a></li>';
  print '<li><a href="#workerTaskPaymentsDueByTypeAndMonth">Worker task payments due by type and month</a></li>';
  print '<li><a href="#workerTaskPaymentsDueByTopicAndMonth">Worker task payments due by topic and month</a></li>';
  print '<li><a href="#workerTaskPaymentsDueByVenueAndMonth">Worker task payments due by venue and month</a></li>';
  print '<li><a href="#workerTaskPaymentsDueByFormatAndMonth">Worker task payments due by format and month</a></li>';
  print '<li><a href="#workerPaymentsDueAndMadeByMonth">Worker payments due and made by month</a></li>';
  print '<li><a href="#workerTaskList">Worker task list</a></li>';

  if (show_toc_line($mysqli, $worker, "select commission from commissions where commission_receiver= ? limit 1")) {
    print '<li><a href="#workerCommissionOnTaskList">Commissions on tasks: breakdown by earner</a></li>';
  }

  if (show_toc_line($mysqli, $worker, "select * from stipends where payee = ? and stipend_award_date is not null limit 1")) {
    print '<li><a href="#workerAwardedStipendList">Full list of awarded stipends in reverse chronological order</a></li>';
  }

  if (show_toc_line($mysqli, $worker, "select * from stipends where payee = ? and stipend_award_date is null limit 1")) {
    print '<li><a href="#workerDeferredStipendList">Full list of deferred stipends in reverse chronological order</a></li>';
  }

  if (show_toc_line($mysqli, $worker, "select * from royalties where payee = ? limit 1")) {
    print '<li><a href="#workerRoyaltyList">Full list of royalties in reverse chronological order</a></li>';
  }

  if (show_toc_line($mysqli, $worker, "select earner, commission, commission_reason, commission_validity_start, commission_validity_end, coalesce(sum(originalPayment), 0) as originalPayment, coalesce(sum(payment), 0) as payment from (select earner, commission, commission_reason, commission_validity_start, commission_validity_end, commission_receiver, royalty_end_date, payment as originalPayment, (commission * payment) as payment from commissions left join royalties on commissions.earner = royalties.payee where (commission_validity_start is null or royalties.royalty_start_date >= commission_validity_start) and (commission_validity_end is null or royalties.royalty_end_date <= commission_validity_end)) t1 where commission_receiver = ?  group by earner, commission, commission_reason, commission_validity_start, commission_validity_end limit 1")) {
    print '<li><a href="#workerCommissionOnRoyaltyList">Commissions on royalties</a></li>';
  }

  if (show_toc_line($mysqli, $worker, "select * from payments where payee = ? and receipt_date is not null limit 1")) {
    print '<li><a href="#workerPaymentList">Full list of received payments in reverse chronological order</a></li>';
  }

  print '</ul>';
  print "<p>All payment amounts are listed in current United States dollars (USD).</p>";
  $printTables = true;
  print date("Y-m-d h:i:sa").";
  include("backend/workerInfo.inc");
  print date("Y-m-d h:i:sa").";
  include("backend/workerPaymentsDueByTypeAndYear.inc");
  print date("Y-m-d h:i:sa").";
  include("backend/workerPaymentsMadeByMethodAndYear.inc");
  print date("Y-m-d h:i:sa").";
  include("backend/workerTaskPaymentsDueByTypeAndYear.inc");
  print date("Y-m-d h:i:sa").";
  include("backend/workerTaskPaymentsDueByTopicAndYear.inc");
  print date("Y-m-d h:i:sa").";
  include("backend/workerTaskPaymentsDueByVenueAndYear.inc");
  print date("Y-m-d h:i:sa").";
  include("backend/workerTaskPaymentsDueByFormatAndYear.inc");
  print date("Y-m-d h:i:sa").";
  include("backend/workerPaymentsDueByTypeAndMonth.inc");
  print date("Y-m-d h:i:sa").";
  include("backend/workerTaskPaymentsDueByTypeAndMonth.inc");
  print date("Y-m-d h:i:sa").";
  include("backend/workerTaskPaymentsDueByTopicAndMonth.inc");
  print date("Y-m-d h:i:sa").";
  include("backend/workerTaskPaymentsDueByVenueAndMonth.inc");
  print date("Y-m-d h:i:sa").";
  include("backend/workerTaskPaymentsDueByFormatAndMonth.inc");
  print date("Y-m-d h:i:sa").";
  include("backend/workerPaymentsDueAndMadeByMonth.inc");
  print date("Y-m-d h:i:sa").";
  include("backend/workerTaskList.inc");
  print date("Y-m-d h:i:sa").";
  if ($totalCommissionOnTaskPayment > 0) {
    include("backend/workerCommissionOnTaskList.inc");
  }
  print date("Y-m-d h:i:sa").";
  if ($totalStipendPaymentAwardedInSameMonth + $totalStipendPaymentStraddlingMonths > 0) {
    include("backend/workerAwardedStipendList.inc");
  }
  print date("Y-m-d h:i:sa").";
  if ($totalUnawardedStipendPayment > 0) {
    include("backend/workerDeferredStipendList.inc");
  }
  print date("Y-m-d h:i:sa").";
  if ($totalRoyaltyPayment > 0) {
    include("backend/workerRoyaltyList.inc");
  }
  print date("Y-m-d h:i:sa").";
  if ($totalCommissionOnRoyaltyPayment > 0) {
    include("backend/workerCommissionOnRoyaltyList.inc");
  }
  print date("Y-m-d h:i:sa").";
  if ($totalPaymentMadeToWorker > 0) {
    include("backend/workerPaymentList.inc");
  }
}
include_once('anchorjs.inc');
print '</body>';
?>
