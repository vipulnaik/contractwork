<?php
if ($printTables == true) {
  print '<h4 id="workerTaskPaymentsDueByTypeAndMonth">Worker task payments due by type and month</h4>';
}

# Initialize values to zero
global $totalPaymentForTaskType;
foreach($taskTypes as $taskType) {
  $totalPaymentForTaskType[$taskType] = 0; 
  foreach ($monthList as $month) {
    $paymentForTaskTypeAndMonth[$taskType][$month] = 0;
  }
}  

foreach($monthList as $month) {
  $totalTaskPaymentForMonth[$month] = 0;
}

$totalTaskPayment = 0;

# Get task payments

$taskSelectQuery = "select task_type, year(completion_date) as year,month(completion_date) as month, coalesce(sum(payment), 0) as payment from tasks where worker=? group by task_type, year(completion_date), month(completion_date);";
$stmt = $mysqli->prepare($taskSelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$taskSelectResult = $stmt->get_result();
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $paymentForTaskTypeAndMonth[$row['task_type']][$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $totalTaskPaymentForMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] += $row['payment'];
  $totalPaymentForTaskType[$row['task_type']] += $row['payment'];
  $totalTaskPayment += $row['payment'];
}
# Sort task types

function cmpTaskTypesForMonth($firstTaskType, $secondTaskType) {
  global $totalPaymentForTaskType;
  if (intval($totalPaymentForTaskType[$firstTaskType]) == intval($totalPaymentForTaskType[$secondTaskType])) {
      return 0;
  }
  return (intval($totalPaymentForTaskType[$firstTaskType]) > intval($totalPaymentForTaskType[$secondTaskType])) ? -1 : 1;
}

usort($taskTypes,"cmpTaskTypesForMonth");

# Then print data by month

# Print table
if ($printTables == true) {
  print "\n";
  print '<table id="myTableWorkerTaskPaymentsDueByTypeAndMonth" class="tablesorter">'."\n";
  print "<thead>\n";
  print '<tr><th>Month</th>';
  print "<th>Total across task types</th>";
  foreach ($taskTypes as $taskType) {
    if ($totalPaymentForTaskType[$taskType] > 0) {
      print "<th>$taskType</th>";
    }
  }
  print "</tr>\n</thead>\n<tbody>\n";
  foreach (array_reverse($monthList) as $month) {
    if ($totalTaskPaymentForMonth[$month] > 0) {
      print "<tr><td>$month</td>";
      print '<td align="right"><strong>'.number_format($totalTaskPaymentForMonth[$month],2).'</strong></td>';
      foreach ($taskTypes as $taskType) {
        if ($totalPaymentForTaskType[$taskType] > 0) {
          print '<td align="right">'.number_format($paymentForTaskTypeAndMonth[$taskType][$month],2).'</td>';
        }
      }
      print "</tr>\n";
    }
  }
  print "</tbody>\n<tfoot>\n";
  print '<tr><td><strong>Total across months</strong></td>';
  print '<td align="right"><strong>'.number_format($totalTaskPayment,2).'</strong></td>';
  foreach($taskTypes as $taskType) {
    if ($totalPaymentForTaskType[$taskType] > 0) {
      print '<td align="right"><strong>'.number_format($totalPaymentForTaskType[$taskType],2).'</strong></td>';
    }
  }
  print "</tr>\n</tfoot>\n</table>\n";
}

if (count(array_filter($totalTaskPaymentForMonth)) > 1) {
  $graphs = timeSeriesGraphs(
    $monthList,
    $taskTypes,
    $totalTaskPaymentForMonth,
    $paymentForTaskTypeAndMonth,
    $generateGraphCmdBase,
    $imagesPath,
    "https://contractwork.vipulnaik.com/worker.php?worker=" . urlencode($worker),
    "#workerTaskPaymentsDueByTypeAndMonth"
  );
  
  print "<p><strong>Graph of worker task payments due by type and month (incremental, not cumulative)</strong></p>";
  print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
  
  print "<p><strong>Graph of worker task payments due by type and month (cumulative)</strong></p>";
  print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
}
?>
