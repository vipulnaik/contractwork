<?php
if ($printTables == true) {
  print '<h4 id="workerTaskPaymentsDueByVenueAndMonth">Worker task payments due by venue and month</h4>';
}

# Initialize values to zero
global $totalPaymentForTaskVenue;
foreach($taskVenues as $taskVenue) {
  $totalPaymentForTaskVenue[$taskVenue] = 0; 
  foreach ($monthList as $month) {
    $paymentForTaskVenueAndMonth[$taskVenue][$month] = 0;
  }
}  

foreach($monthList as $month) {
  $totalTaskPaymentForMonth[$month] = 0;
}

$totalTaskPayment = 0;

# Get task payments

$taskSelectQuery = "select task_venue, year(completion_date) as year,month(completion_date) as month, coalesce(sum(payment), 0) as payment from tasks where worker=? group by task_venue, year(completion_date), month(completion_date);";
$stmt = $mysqli->prepare($taskSelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$taskSelectResult = $stmt->get_result();
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $paymentForTaskVenueAndMonth[$row['task_venue']][$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $totalTaskPaymentForMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] += $row['payment'];
  $totalPaymentForTaskVenue[$row['task_venue']] += $row['payment'];
  $totalTaskPayment += $row['payment'];
}
# Sort task venues

function cmpTaskVenuesForMonth($firstTaskVenue, $secondTaskVenue) {
  global $totalPaymentForTaskVenue;
  if (intval($totalPaymentForTaskVenue[$firstTaskVenue]) == intval($totalPaymentForTaskVenue[$secondTaskVenue])) {
      return 0;
  }
  return (intval($totalPaymentForTaskVenue[$firstTaskVenue]) > intval($totalPaymentForTaskVenue[$secondTaskVenue])) ? -1 : 1;
}

usort($taskVenues,"cmpTaskVenuesForMonth");

# Then print data by month

# Print table
if ($printTables == true) {
  print "\n";
  print '<table id="myTableWorkerTaskPaymentsDueByVenueAndMonth" class="tablesorter">'."\n";
  print "<thead>\n";
  print '<tr><th>Month</th>';
  print "<th>Total across task venues</th>";
  foreach ($taskVenues as $taskVenue) {
    if ($totalPaymentForTaskVenue[$taskVenue] > 0) {
     print "<th><a href=\"venue.php?venue=".urlencode($taskVenue)."&matching=exact\">$taskVenue</a></th>";
    }
  }
  print "</tr>\n</thead>\n<tbody>\n";
  foreach (array_reverse($monthList) as $month) {
    if ($totalTaskPaymentForMonth[$month] > 0) {
      print "<tr><td>$month</td>";
      print '<td align="right"><strong>'.number_format($totalTaskPaymentForMonth[$month],2).'</strong></td>';
      foreach ($taskVenues as $taskVenue) {
        if ($totalPaymentForTaskVenue[$taskVenue] > 0) {
          print '<td align="right">'.number_format($paymentForTaskVenueAndMonth[$taskVenue][$month],2).'</td>';
        }
      }
      print "</tr>\n";
    }
  }
  print "</tbody>\n<tfoot>\n";  
  print '<tr><td><strong>Total across months</strong></td>';
  print '<td align="right"><strong>'.number_format($totalTaskPayment,2).'</strong></td>';
  foreach($taskVenues as $taskVenue) {
    if ($totalPaymentForTaskVenue[$taskVenue] > 0) {
      print '<td align="right"><strong>'.number_format($totalPaymentForTaskVenue[$taskVenue],2).'</strong></td>';
    }
  }
  print "</tr>\n</tfoot>\n</table>\n";
}

$graphs = timeSeriesGraphs(
  $monthList,
  $taskVenues,
  $totalTaskPaymentForMonth,
  $paymentForTaskVenueAndMonth,
  $generateGraphCmdBase,
  $imagesPath,
  "https://contractwork.vipulnaik.com/worker.php?worker=" . urlencode($worker),
  "#workerTaskPaymentsDueByVenueAndMonth"
);

print "<p><strong>Graph of worker task payments due by venue and month (incremental, not cumulative)</strong></p>";
print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

print "<p><strong>Graph of worker task payments due by venue and month (cumulative)</strong></p>";
print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
?>
