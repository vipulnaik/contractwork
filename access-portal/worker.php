<?php
print '<!doctype html public "-//W3C//DTD HTML 4.01 Transitional//EN"><html><head><meta http-equiv="Content-Type" content="text/html;charset=utf-8" >';
include_once("backend/globalvariables/passwordFile.inc");
include_once("backend/globalvariables/lists.inc");
$worker = 'Issa Rice';
if (!empty($_REQUEST['worker'])) {
  $worker = $_REQUEST['worker'];
}
print "<title>$worker work details: Contract work for Vipul Naik</title>";
print '</head>';
print '<body>';
print "<h3>Contract work by $worker for Vipul Naik</h3>";
$workerSelectQuery = "select * from workers where worker='$worker' and private = false;";
$workerSelectResult = $mysqli -> query($workerSelectQuery);
if ($workerSelectResult -> num_rows == 0) {
  print '<p>Sorry, we did not find a worker with this name in our public list of workers. Go back to the <a href="/">home page</a> for a full list of workers.</p>';
} else {
  print "All payment amounts are listed in current United States dollars (USD).";
  include("backend/workerInfo.inc");
  include("backend/workerPaymentsDueByTypeAndYear.inc");
  include("backend/workerTaskPaymentsDueByTypeAndYear.inc");
  include("backend/workerTaskPaymentsDueByTopicAndYear.inc");
  include("backend/workerTaskPaymentsDueByVenueAndYear.inc");  
  include("backend/workerPaymentsDueByTypeAndMonth.inc");
  include("backend/workerPaymentsDueAndMadeByMonth.inc");
  include("backend/workerTaskList.inc");
}
print '</body>';
?>