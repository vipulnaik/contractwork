<?php
print '<h4 id="workerTaskPaymentsDueByFormatAndYear">Worker task payments due by format and year</h4>';

# Initialize values to zero
foreach($taskFormats as $taskFormat) {
  $totalPaymentForTaskFormat[$taskFormat] = 0; 
  foreach ($yearList as $year) {
    $paymentForTaskFormatAndYear[$taskFormat][$year] = 0;
  }
}  

foreach($yearList as $year) {
  $totalTaskPaymentForYear[$year] = 0;
}

$grandTotal = 0;

# Get task payments

$taskSelectQuery = "select format, year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks where worker=? group by format, year(completion_date);";
$stmt = $mysqli->prepare($taskSelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$taskSelectResult = $stmt->get_result();
for ($i = 0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  if (!isset($paymentForTaskFormatAndYear[$row['format']])) {
    $paymentForTaskFormatAndYear[$row['format']] = array();
  }
  if (!isset($totalPaymentForTaskFormat[$row['format']])) {
    $totalPaymentForTaskFormat[$row['format']] = 0;
  }
  $paymentForTaskFormatAndYear[$row['format']][$row['year']] = $row['payment'];
  $totalTaskPaymentForYear[$row['year']] += $row['payment'];
  $totalPaymentForTaskFormat[$row['format']] += $row['payment'];
  $grandTotal += $row['payment'];
}

function cmpTaskFormats($firstTaskFormat, $secondTaskFormat) {
  global $totalPaymentForTaskFormat;
  if (intval($totalPaymentForTaskFormat[$firstTaskFormat]) == intval($totalPaymentForTaskFormat[$secondTaskFormat])) {
      return 0;
  }
  return (intval($totalPaymentForTaskFormat[$firstTaskFormat]) > intval($totalPaymentForTaskFormat[$secondTaskFormat])) ? -1 : 1;
}

usort($taskFormats,"cmpTaskFormats");

# Print table
print "\n";
print '<table id="myTableWorkerTaskPaymentsDueByFormatAndYear" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Format</th>';
print '<th>Total across years</th>';
foreach (array_reverse($yearList) as $year) {
  if ($totalTaskPaymentForYear[$year] > 0) {
    print "<th>Total in year $year</th>";
  }
}
print "</tr>\n</thead>\n<tbody>\n";
foreach($taskFormats as $taskFormat) {
  if ($totalPaymentForTaskFormat[$taskFormat] > 0) {
    print "<tr><td>$taskFormat</td>";
    print '<td align="right"><strong>'.number_format($totalPaymentForTaskFormat[$taskFormat],2).'</strong></td>';
    foreach (array_reverse($yearList) as $year) {
      if ($totalTaskPaymentForYear[$year] > 0) {
        print '<td align="right">'.number_format($paymentForTaskFormatAndYear[$taskFormat][$year],2).'</td>';
      }
    }
    print '</tr>';
  }
}
print "</tbody>\n<tfoot>\n";
print "<tr><td><strong>Total</td>";
print '<td align="right"><strong>'.number_format($grandTotal,2).'</strong></td>';
foreach (array_reverse($yearList) as $year) {
  if ($totalTaskPaymentForYear[$year] > 0) {
    print '<td align="right"><strong>'.number_format($totalTaskPaymentForYear[$year],2).'</strong></td>';
  }
}
print '</tr>';
print "</tfoot>\n</table>\n";

if (count(array_filter($totalTaskPaymentForYear)) > 1) {
  $graphs = timeSeriesGraphs(
    $yearList,
    $taskFormats,
    $totalTaskPaymentForYear,
    $paymentForTaskFormatAndYear,
    $generateGraphCmdBase,
    $imagesPath,
    "https://contractwork.vipulnaik.com/worker.php?worker=" . urlencode($worker),
    "#workerTaskPaymentsDueByFormatAndYear"
  );

  print "<p><strong>Graph of task payments due by format and year (incremental, not cumulative)</strong></p>";
  print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

  print "<p><strong>Graph of task payments due by format and year (cumulative)</strong></p>";
  print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
}
?>
