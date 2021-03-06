<?php
print '<h4 id="workerTaskPaymentsDueByFormatAndMonth">Worker task payments due by format and month</h4>';

# Initialize values to zero
global $totalPaymentForTaskFormat;
foreach($taskFormats as $taskFormat) {
  $totalPaymentForTaskFormat[$taskFormat] = 0; 
  foreach ($monthList as $month) {
    $paymentForTaskFormatAndMonth[$taskFormat][$month] = 0;
  }
}  

foreach($monthList as $month) {
  $totalTaskPaymentForMonth[$month] = 0;
}

$totalTaskPayment = 0;

# Get task payments

$taskSelectQuery = "select format, year(completion_date) as year,month(completion_date) as month, coalesce(sum(payment), 0) as payment from tasks where worker=? group by format, year(completion_date), month(completion_date);";
$stmt = $mysqli->prepare($taskSelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$taskSelectResult = $stmt->get_result();
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $paymentForTaskFormatAndMonth[$row['format']][$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $totalTaskPaymentForMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] += $row['payment'];
  $totalPaymentForTaskFormat[$row['format']] += $row['payment'];
  $totalTaskPayment += $row['payment'];
}
# Sort task formats

function cmpTaskFormatsForMonth($firstTaskFormat, $secondTaskFormat) {
  global $totalPaymentForTaskFormat;
  if (intval($totalPaymentForTaskFormat[$firstTaskFormat]) == intval($totalPaymentForTaskFormat[$secondTaskFormat])) {
      return 0;
  }
  return (intval($totalPaymentForTaskFormat[$firstTaskFormat]) > intval($totalPaymentForTaskFormat[$secondTaskFormat])) ? -1 : 1;
}

usort($taskFormats,"cmpTaskFormatsForMonth");

# Then print data by month

# Print table
print "\n";
print '<table id="myTableWorkerTaskPaymentsDueByFormatAndMonth" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Month</th>';
print "<th>Total across task formats</th>";
foreach ($taskFormats as $taskFormat) {
  if ($totalPaymentForTaskFormat[$taskFormat] > 0) {
    print "<th>$taskFormat</th>";
  }
}
print "</tr>\n</thead>\n<tbody>\n";

foreach (array_reverse($monthList) as $month) {
  if ($totalTaskPaymentForMonth[$month] > 0) {
    print "<tr><td>$month</td>";
    print '<td align="right"><strong>'.number_format($totalTaskPaymentForMonth[$month],2).'</strong></td>';
    foreach ($taskFormats as $taskFormat) {
      if ($totalPaymentForTaskFormat[$taskFormat] > 0) {
        print '<td align="right">'.number_format($paymentForTaskFormatAndMonth[$taskFormat][$month],2).'</td>';
      }
    }
    print '</tr>';
  }
}
print "</tbody>\n<tfoot>\n";
print '<tr><td><strong>Total across months</strong></td>';
print '<td align="right"><strong>'.number_format($totalTaskPayment,2).'</strong></td>';
foreach($taskFormats as $taskFormat) {
  if ($totalPaymentForTaskFormat[$taskFormat] > 0) {
    print '<td align="right"><strong>'.number_format($totalPaymentForTaskFormat[$taskFormat],2).'</strong></td>';
  }
}
print "</tr>\n</tfoot>\n</table>\n";

if (count(array_filter($totalTaskPaymentForMonth)) > 1) {
  $graphs = timeSeriesGraphs(
    $monthList,
    $taskFormats,
    $totalTaskPaymentForMonth,
    $paymentForTaskFormatAndMonth,
    $generateGraphCmdBase,
    $imagesPath,
    "https://contractwork.vipulnaik.com/worker.php?worker=" . urlencode($worker),
    "#workerTaskPaymentsDueByFormatAndMonth"
  );

  print "<p><strong>Graph of worker task payments due by format and month (incremental, not cumulative)</strong></p>";
  print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

  print "<p><strong>Graph of worker task payments due by format and month (cumulative)</strong></p>";
  print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
}
?>
