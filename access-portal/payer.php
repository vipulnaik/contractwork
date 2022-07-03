<?php
include_once('doctype.inc');
print '<script src="change-theme.js"></script>';
include_once("backend/globalVariables/passwordFile.inc");
include_once("backend/globalVariables/lists.inc");
include_once("backend/stringFunctions.inc");
include_once('backend/graphing.inc');
$payer = 'Vipul Naik';
if (!empty($_REQUEST['payer'])) {
  $payer = $_REQUEST['payer'];
}
print "<title>$payer sponsored task details: Contract work for Vipul Naik</title>";
include_once('analytics.inc');
include_once('strip-commas.inc');
print '<link href="style.css" rel="stylesheet" type="text/css" />'."\n";
include_once('style.inc');
print '<script type="text/javascript" src="./jquery-3.1.1.min.js"></script>'."\n";
print '<script type="text/javascript" src="./jquery.tablesorter.js"></script>'."\n";
print '</head>';
print '<body>';
print '<script>$(document).ready(function(){$("table").tablesorter({textExtraction: stripCommas});});</script>'."\n";
print "<h3>Contract work sponsored by $payer and managed through Vipul Naik</h3>";
print '<p><span id="changeThemeMenu" style="display: none;">Change <a href="javascript:;" onclick="change_theme_color()">color</a></span>   &thinsp;<!-- blank space to prevent cumulative layout shift --></p>';
$payerSelectQuery = "select * from payers where payer=?;";
$stmt = $mysqli->prepare($payerSelectQuery);
$stmt->bind_param("s", $payer);
$stmt->execute();
$payerSelectResult = $stmt->get_result();
if ($payerSelectResult -> num_rows == 0) {
  print '<p>Sorry, we did not find a payer with this name in our public list of payers. Go back to the <a href="/">home page</a> for a full list of payers.</p>';
} else {
  $row = $payerSelectResult -> fetch_assoc();
  $payerNotes = $row['notes'];
  print '<h4>Table of contents</h4>';
  print '<ul>';
  print '<li><a href="#payerInfo">Payer information</a></li>';
  print '<li><a href="#payerPaymentsDueByTypeAndYear">Payer payments due by type and year</a></li>';
  if ($payer != "Vipul Naik") {
    print '<li><a href="#payerPaymentsMadeByMethodAndYear">Payer payments made by method and year</a></li>';
  }
  print '<li><a href="#payerTaskPaymentsDueByTypeAndYear">Payer task payments due by type and year</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByTopicAndYear">Payer task payments due by topic and year</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByVenueAndYear">Payer task payments due by venue and year</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByFormatAndYear">Payer task payments due by format and year</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByWorkerAndType">Payer task payments due by worker and type</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByTypeAndMonth">Payer task payments due by type and month</a></li>';
  print '<li><a href="#payerPaymentsDueByTypeAndMonth">Payer payments due by type and month</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByTopicAndMonth">Payer task payments due by topic and month</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByVenueAndMonth">Payer task payments due by venue and month</a></li>';
  print '<li><a href="#payerTaskPaymentsDueByFormatAndMonth">Payer task payments due by format and month</a></li>';
  print '<li><a href="#payerPaymentsDueAndMadeByMonth">Payer payments due and made by month</a></li>';
  print '<li><a href="#payerTaskList">Payer task list</a></li>';
  if ($payer != "Vipul Naik") {
    print '<li><a href="#payerPaymentList">Payer payment list</a></li>';
  }

  if (showTocLine($mysqli, $payer, "select * from stipends where payer = ? and stipend_award_date is not null limit 1")) {
    print '<li><a href="#payerAwardedStipendList">Full list of awarded stipends in reverse chronological order</a></li>';
  }

  if (showTocLine($mysqli, $payer, "select * from stipends where payer = ? and stipend_award_date is null limit 1")) {
    print '<li><a href="#payerDeferredStipendList">Full list of deferred stipends in reverse chronological order</a></li>';
  }

  print '</ul>';
  print "<p>All payment amounts are listed in current United States dollars (USD).</p>";
  $printTables = true;
  print '<h4 id="payerInfo">Payer information for '.$payer.'</h4>';
  print '<p>'.cleanNotes($payerNotes).'</p>';
  include("backend/payerPaymentsDueByTypeAndYear.inc");
  if ($payer != "Vipul Naik") {
    include("backend/payerPaymentsMadeByMethodAndYear.inc");
  }
  include("backend/payerTaskPaymentsDueByTypeAndYear.inc");
  include("backend/payerTaskPaymentsDueByTopicAndYear.inc");
  include("backend/payerTaskPaymentsDueByVenueAndYear.inc");
  include("backend/payerTaskPaymentsDueByFormatAndYear.inc");
  include("backend/payerTaskPaymentsDueByWorkerAndType.inc");
  include("backend/payerTaskPaymentsDueByTypeAndMonth.inc");
  include("backend/payerPaymentsDueByTypeAndMonth.inc");
  include("backend/payerTaskPaymentsDueByTopicAndMonth.inc");
  include("backend/payerTaskPaymentsDueByVenueAndMonth.inc");
  include("backend/payerTaskPaymentsDueByFormatAndMonth.inc");
  include("backend/payerPaymentsDueAndMadeByMonth.inc");
  include("backend/payerTaskList.inc");
  if ($payer != "Vipul Naik") {
    include("backend/payerPaymentList.inc");
  }
  if ($totalStipendPaymentAwardedInSameMonth + $totalStipendPaymentStraddlingMonths > 0) {
    include("backend/payerAwardedStipendList.inc");
  }
  if ($totalUnawardedStipendPayment > 0) {
    include("backend/payerDeferredStipendList.inc");
  }
}
include_once('anchorjs.inc');
print '</body>';
?>
