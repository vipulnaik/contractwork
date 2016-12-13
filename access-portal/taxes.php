<?php
print '<!doctype html public "-//W3C//DTD HTML 4.01 Transitional//EN"><html><head><meta http-equiv="Content-Type" content="text/html;charset=utf-8" >';
include_once("backend/globalvariables/passwordFile.inc");
include_once("backend/globalvariables/lists.inc");
include_once("backend/globalvariables/taxVariables.inc");
$worker = 'Issa Rice';
if (!empty($_REQUEST['worker'])) {
  $worker = $_REQUEST['worker'];
}
print "<title>$worker tax details: Contract work for Vipul Naik</title>";
print '</head>';
print '<body>';
print "<h3>Contract work by $worker for Vipul Naik</h3>";
$workerSelectQuery = "select * from workers where worker='$worker' and private = false;";
$workerSelectResult = $mysqli -> query($workerSelectQuery);
if ($workerSelectResult -> num_rows == 0) {
  print '<p>Sorry, we did not find a worker with this name in our public list of workers. Go back to the <a href="/">home page</a> for a full list of workers.</p>';
} else {
  $row = $workerSelectResult -> fetch_assoc();
  $country = $row['country'];
  if ($country != "United States") {
    print "<p>Sorry! Since this worker is not based in the United States, we cannot offer information on the worker's tax situation or obligations.</p>";
  } else {
    print "<p>All payment amounts are listed in current United States dollars (USD).</p>";
    $printTables = false;
    include("backend/workerPaymentsDueByTypeAndYear.inc");
    include("backend/workerPaymentsMadeByMethodAndYear.inc");
    include("backend/taxAdvice.inc");
  }
}
print '</body>';
?>