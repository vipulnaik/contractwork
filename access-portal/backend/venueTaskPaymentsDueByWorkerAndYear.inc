<?php
print "<h4 id=\"venueTaskPaymentsDueByWorkerAndYear\">Task payments due for tasks related to venue $venue by worker and year</h4>";

$workerList = array();
$workerSelectQuery = "select distinct worker from workers where private = false;";
$workerSelectResult = $mysqli -> query($workerSelectQuery);

for($i=0;$i < $workerSelectResult -> num_rows; $i++) {
  $row = $workerSelectResult -> fetch_assoc();
  array_push($workerList, $row['worker']);
}

$paymentForWorkerAndYear = array();
foreach($yearList as $year) {
  $totalPaymentForYear[$year] = 0;
}

$grandTotal = 0;

# Get task payments

$taskSelectQuery = "select worker, year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks where $venueRegexMatcher group by worker, year(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i = 0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  if (!isset($paymentForWorkerAndYear[$row['worker']])) {
    $paymentForWorkerAndYear[$row['worker']] = array();
  }
  if (!isset($totalPaymentForWorkerUsingYear[$row['worker']])) {
    $totalPaymentForWorkerUsingYear[$row['worker']] = 0;
  }
  $paymentForWorkerAndYear[$row['worker']][$row['year']] = $row['payment'];
  $totalPaymentForYear[$row['year']] += $row['payment'];
  $totalPaymentForWorkerUsingYear[$row['worker']] += $row['payment'];
  $grandTotal += $row['payment'];
}

function cmpWorkersUsingYear($firstWorker, $secondWorker) {
  global $totalPaymentForWorkerUsingYear;
  if (intval($totalPaymentForWorkerUsingYear[$firstWorker]) == intval($totalPaymentForWorkerUsingYear[$secondWorker])) {
      return 0;
  }
  return (intval($totalPaymentForWorkerUsingYear[$firstWorker]) > intval($totalPaymentForWorkerUsingYear[$secondWorker])) ? -1 : 1;
}

usort($workerList,"cmpWorkersUsingYear");

# Print table
print "\n";
print '<table id="myTableTaskPaymentsDueByWorkerAndYear" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Task worker</th>';
foreach (array_reverse($yearList) as $year) {
  print "<th>Total in year $year</th>";
}
print '<th>Total across years</th></tr>';
print "</thead>\n<tbody>\n";
foreach($workerList as $worker) {
  if (isset($totalPaymentForWorkerUsingYear[$worker]) && $totalPaymentForWorkerUsingYear[$worker] > 0) {
    print "<tr><td><a href=\"https://contractwork.vipulnaik.com/worker.php?worker=".urlencode($worker)."\">$worker</a></td>";
    foreach (array_reverse($yearList) as $year) {
      $localPayment = 0;
      if (isset($paymentForWorkerAndYear[$worker][$year])) {
        $localPayment = $paymentForWorkerAndYear[$worker][$year];
      }
      print '<td align="right">'.number_format($localPayment,2).'</td>';
    }
    print '<td align="right"><strong>'.number_format($totalPaymentForWorkerUsingYear[$worker],2).'</strong></td>';
    print '</tr>';
  }
}
print "</tbody>\n<tfoot>\n";
print "<tr><td><strong>Total</td>";
foreach (array_reverse($yearList) as $year) {
  print '<td align="right"><strong>'.number_format($totalPaymentForYear[$year],2).'</strong></td>';
}
print '<td align="right"><strong>'.number_format($grandTotal,2).'</strong></td>';
print '</tr>';
print "</tfoot>\n</table>\n";

?>
