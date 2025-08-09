<?php
print '<h4 id="taskPaymentsDueByWorkerAndMonth">Task payments due by worker and month</h4>';

$workerList = array();
$workerSelectQuery = "select distinct worker from workers where private = false and worker != 'Linchuan Zhang';";
$workerSelectResult = $mysqli -> query($workerSelectQuery);

for($i=0;$i < $workerSelectResult -> num_rows; $i++) {
  $row = $workerSelectResult -> fetch_assoc();
  array_push($workerList, $row['worker']);
}

# Initialize values to zero
global $totalPaymentForWorker;
foreach($workerList as $worker) {
  $totalPaymentForWorker[$worker] = 0; 
  foreach ($monthList as $month) {
    $paymentForWorkerAndMonth[$worker][$month] = 0;
  }
}  

foreach($monthList as $month) {
  $totalTaskPaymentForMonth[$month] = 0;
}

$totalTaskPayment = 0;

# Get task payments

$taskSelectQuery = "select worker, year(completion_date) as year,month(completion_date) as month, coalesce(sum(payment), 0) as payment from tasks group by worker, year(completion_date), month(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  if (!isset($paymentForWorkerAndMonth[$row['worker']])) {
    $paymentForWorkerAndMonth[$row['worker']] = array();
  }
  if (!isset($totalPaymentForWorkerUsingMonth[$row['worker']])) {
    $totalPaymentForWorkerUsingMonth[$row['worker']] = 0;
  }
  $paymentForWorkerAndMonth[$row['worker']][$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $totalTaskPaymentForMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] += $row['payment'];
  $totalPaymentForWorkerUsingMonth[$row['worker']] += $row['payment'];
  $totalTaskPayment += $row['payment'];
}
# Sort workerList

function cmpWorkersForMonth($firstWorker, $secondWorker) {
  global $totalPaymentForWorkerUsingMonth;
  if (!isset($totalPaymentForWorkerUsingMonth[$firstWorker])) {
    $paymentForFirstWorker = 0;
  } else {
    $paymentForFirstWorker = intval($totalPaymentForWorkerUsingMonth[$firstWorker]);
  }
  if (!isset($totalPaymentForWorkerUsingMonth[$secondWorker])) {
    $paymentForSecondWorker = 0;
  } else {
    $paymentForSecondWorker = intval($totalPaymentForWorkerUsingMonth[$secondWorker]);
  }
  if ($paymentForFirstWorker == $paymentForSecondWorker) {
      return 0;
  }
  return ($paymentForFirstWorker > $paymentForSecondWorker) ? -1 : 1;
}

usort($workerList,"cmpWorkersForMonth");

# Then print data by month

# Print table
print "\n";
print '<table id="myTableTaskPaymentsDueByWorkerAndMonth" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Month</th>';
print "<th>Total across task workers</th>";
foreach ($workerList as $worker) {
  if (isset($totalPaymentForWorkerUsingMonth[$worker]) && $totalPaymentForWorkerUsingMonth[$worker] > 0) {
    print "<th><a href=\"https://contractwork.vipulnaik.com/worker.php?worker=".urlencode($worker)."\">" . htmlspecialchars($worker) . "</a></th>";
  }
}
print '</tr>';
print "</thead>\n<tbody>\n";

foreach (array_reverse($monthList) as $month) {
  if ($totalTaskPaymentForMonth[$month] > 0) {
    print "<tr><td>$month</td>";
    print '<td align="right"><strong>'.number_format($totalTaskPaymentForMonth[$month],2).'</strong></td>';
    foreach ($workerList as $worker) {
      if (isset($totalPaymentForWorkerUsingMonth[$worker]) && $totalPaymentForWorkerUsingMonth[$worker] > 0) {
        print '<td align="right">'.number_format($paymentForWorkerAndMonth[$worker][$month],2).'</td>';
      }
    }
    print '</tr>';
  }
}
print "</tbody>\n<tfoot>\n";
print '<tr><td><strong>Total across months</strong></td>';
print '<td align="right"><strong>'.number_format($totalTaskPayment,2).'</strong></td>';
foreach($workerList as $worker) {
  if (isset($totalPaymentForWorkerUsingMonth[$worker]) && $totalPaymentForWorkerUsingMonth[$worker] > 0) {
    print '<td align="right"><strong>'.number_format($totalPaymentForWorkerUsingMonth[$worker],2).'</strong></td>';
  }
}
print '</tr>';

print "</tfoot>\n</table>\n";

$graphs = timeSeriesGraphs(
  $monthList,
  $workerList,
  $totalTaskPaymentForMonth,
  $paymentForWorkerAndMonth,
  $generateGraphCmdBase,
  $imagesPath,
  "https://contractwork.vipulnaik.com/index.php",
  "#taskPaymentsDueByWorkerAndMonth"
);

print "<p><strong>Graph of task payments due by worker and month (incremental, not cumulative)</strong></p>";
print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

print "<p><strong>Graph of task payments due by worker and month (cumulative)</strong></p>";
print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

?>
