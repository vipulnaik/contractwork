<?php
print '<h4 id="workerTaskPaymentsDueByTypeAndYear">Worker task payments due by type and year</h4>';

# Initialize values to zero
global $totalPaymentForTaskType;
foreach($taskTypes as $taskType) {
  $totalPaymentForTaskType[$taskType] = 0; 
  foreach ($yearList as $year) {
    $paymentForTaskTypeAndYear[$taskType][$year] = 0;
  }
}  

foreach($yearList as $year) {
  $totalPaymentForYear[$year] = 0;
}

$grandTotal = 0;

# Get task payments

$taskSelectQuery = "select task_type, year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks where worker=".'"'.str_replace('"','\"',$worker).'"'." group by task_type, year(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i = 0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  if (!isset($paymentForTaskTypeAndYear[$row['task_type']])) {
    $paymentForTaskTypeAndYear[$row['task_type']] = 0;
  }
  if (!isset($totalPaymentForTaskType[$row['task_type']])) {
    $totalPaymentForTaskType[$row['task_type']] = 0;
  }
  $paymentForTaskTypeAndYear[$row['task_type']][$row['year']] = $row['payment'];
  $totalPaymentForYear[$row['year']] += $row['payment'];
  $totalPaymentForTaskType[$row['task_type']] += $row['payment'];
  $grandTotal += $row['payment'];
}

function cmpTaskTypes($firstTaskType, $secondTaskType) {
  global $totalPaymentForTaskType;
  if (intval($totalPaymentForTaskType[$firstTaskType]) == intval($totalPaymentForTaskType[$secondTaskType])) {
      return 0;
  }
  return (intval($totalPaymentForTaskType[$firstTaskType]) > intval($totalPaymentForTaskType[$secondTaskType])) ? -1 : 1;
}

usort($taskTypes,"cmpTaskTypes");

# Print table
print "\n";
print '<table id="myTableWorkerTaskPaymentsDueByTypeAndYear" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Task type</th>';
print '<th>Total across years</th>';
foreach (array_reverse($yearList) as $year) {
  if ($totalPaymentForYear[$year] > 0) {
    print "<th>Total in year $year</th>";
  }
}
print "</tr>\n</thead>\n<tbody>\n";
foreach($taskTypes as $taskType) {
  if ($totalPaymentForTaskType[$taskType] > 0) {
    print "<tr><td>$taskType</td>";
    print '<td align="right"><strong>'.number_format($totalPaymentForTaskType[$taskType],2).'</strong></td>';
    foreach (array_reverse($yearList) as $year) {
      if ($totalPaymentForYear[$year] > 0) {
        print '<td align="right">'.number_format($paymentForTaskTypeAndYear[$taskType][$year],2).'</td>';
      }
    }
    print '</tr>';
  }
}
print "</tbody>\n<tfoot>\n";
print "<tr><td><strong>Total</strong></td>";
print '<td align="right"><strong>'.number_format($grandTotal,2).'</strong></td>';
foreach (array_reverse($yearList) as $year) {
  if ($totalPaymentForYear[$year] > 0) {
    print '<td align="right"><strong>'.number_format($totalPaymentForYear[$year],2).'</strong></td>';
  }
}
print "</tr>\n</tfoot>\n</table>\n";

$graphs = timeSeriesGraphs(
  $yearList,
  $taskTypes,
  $totalPaymentForYear,
  $paymentForTaskTypeAndYear,
  $generateGraphCmdBase,
  $imagesPath,
  "https://contractwork.vipulnaik.com/worker.php",
  "#workerPaymentsDueByTypeAndYear"
);

print "<p><strong>Graph of task payments due by type and year (incremental, not cumulative)</strong></p>";
print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

print "<p><strong>Graph of task payments due by type and year (cumulative)</strong></p>";
print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
?>
