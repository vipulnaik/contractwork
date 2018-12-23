<?php
print '<h4 id="workerTaskPaymentsDueByVenueAndYear">Worker task payments due by venue and year</h4>';

# Initialize values to zero
foreach($taskVenues as $taskVenue) {
  $totalPaymentForTaskVenue[$taskVenue] = 0; 
  foreach ($yearList as $year) {
    $paymentForTaskVenueAndYear[$taskVenue][$year] = 0;
  }
}  

foreach($yearList as $year) {
  $totalPaymentForYear[$year] = 0;
}

$grandTotal = 0;

# Get task payments

$taskSelectQuery = "select task_venue, year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks where worker=".'"'.str_replace('"','\"',$worker).'"'." group by task_venue, year(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i = 0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $paymentForTaskVenueAndYear[$row['task_venue']][$row['year']] = $row['payment'];
  $totalPaymentForYear[$row['year']] += $row['payment'];
  $totalPaymentForTaskVenue[$row['task_venue']] += $row['payment'];
  $grandTotal += $row['payment'];
}

function cmpTaskVenues($firstTaskVenue, $secondTaskVenue) {
  global $totalPaymentForTaskVenue;
  if (intval($totalPaymentForTaskVenue[$firstTaskVenue]) == intval($totalPaymentForTaskVenue[$secondTaskVenue])) {
      return 0;
  }
  return (intval($totalPaymentForTaskVenue[$firstTaskVenue]) > intval($totalPaymentForTaskVenue[$secondTaskVenue])) ? -1 : 1;
}

usort($taskVenues,"cmpTaskVenues");

# Print table
print "\n";
print '<table id="myTableWorkerTaskPaymentsDueByVenueAndYear" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Task venue</th>';
print '<th>Total across years</th>';
foreach (array_reverse($yearList) as $year) {
  if ($totalPaymentForYear[$year] > 0) {
    print "<th>Total in year $year</th>";
  }
}
print "</tr>\n</thead>\n<tbody>\n";
foreach($taskVenues as $taskVenue) {
  if ($totalPaymentForTaskVenue[$taskVenue] > 0) {
    print "<tr><td><a href=\"venue.php?venue=".urlencode($taskVenue)."&matching=exact\">$taskVenue</a></td>";
    print '<td align="right"><strong>'.number_format($totalPaymentForTaskVenue[$taskVenue],2).'</strong></td>';
    foreach (array_reverse($yearList) as $year) {
      if ($totalPaymentForYear[$year] > 0) {
        print '<td align="right">'.number_format($paymentForTaskVenueAndYear[$taskVenue][$year],2).'</td>'; 
      }
    }
    print "</tr>\n";
  }
}
print "</tbody>\n<tfoot>\n";
print "<tr><td><strong>Total</td>";
print '<td align="right"><strong>'.number_format($grandTotal,2).'</strong></td>';
foreach (array_reverse($yearList) as $year) {
  if ($totalPaymentForYear[$year] > 0) {
    print '<td align="right"><strong>'.number_format($totalPaymentForYear[$year],2).'</strong></td>';
  }
}
print "</tr>\n</tfoot>\n</table>\n";

$graphs = timeSeriesGraphs(
  $yearList,
  $taskVenues,
  $totalPaymentForYear,
  $paymentForTaskVenueAndYear,
  $generateGraphCmdBase,
  $imagesPath,
  "https://contractwork.vipulnaik.com/worker.php",
  "#workerTaskPaymentsDueByVenueAndYear"
);

print "<p><strong>Graph of task payments due by venue and year (incremental, not cumulative)</strong></p>";
print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

print "<p><strong>Graph of task payments due by venue and year (cumulative)</strong></p>";
print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
?>
