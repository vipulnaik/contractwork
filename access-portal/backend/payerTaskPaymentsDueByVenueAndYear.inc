<?php
print '<h4 id="payerTaskPaymentsDueByVenueAndYear">Payer task payments due by venue and year</h4>';

# Initialize values to zero
foreach($taskVenues as $taskVenue) {
  $totalPaymentForTaskVenue[$taskVenue] = 0; 
  foreach ($yearList as $year) {
    $paymentForTaskVenueAndYear[$taskVenue][$year] = 0;
  }
}  

foreach($yearList as $year) {
  $totalTaskPaymentForYear[$year] = 0;
}

$grandTotal = 0;

# Get task payments

$taskSelectQuery = "select task_venue, year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks where payer=? group by task_venue, year(completion_date);";
$stmt = $mysqli->prepare($taskSelectQuery);
$stmt->bind_param("s", $payer);
$stmt->execute();
$taskSelectResult = $stmt->get_result();
for ($i = 0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  if (!isset($paymentForTaskVenueAndYear[$row['task_venue']])) {
    $paymentForTaskVenueAndYear[$row['task_venue']] = array();
  }
  if (!isset($totalPaymentForTaskVenue[$row['task_venue']])) {
    $totalPaymentForTaskVenue[$row['task_venue']] = 0;
  }
  $paymentForTaskVenueAndYear[$row['task_venue']][$row['year']] = $row['payment'];
  $totalTaskPaymentForYear[$row['year']] += $row['payment'];
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
print '<table id="myTablePayerTaskPaymentsDueByVenueAndYear" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Task venue</th>';
foreach (array_reverse($yearList) as $year) {
  print "<th>Total in year $year</th>";
}
print '<th>Total across years</th></tr>';
print "</thead>\n<tbody>\n";
foreach($taskVenues as $taskVenue) {
  if ($totalPaymentForTaskVenue[$taskVenue] > 0) {
    print "<tr><td><a href=\"venue.php?venue=".urlencode($taskVenue)."&matching=exact\">$taskVenue</a></td>";
    foreach (array_reverse($yearList) as $year) {
      print '<td align="right">'.number_format($paymentForTaskVenueAndYear[$taskVenue][$year],2).'</td>';
    }
    print '<td align="right">'.number_format($totalPaymentForTaskVenue[$taskVenue],2).'</td>';
    print '</tr>';
  }
}
print "</tbody>\n<tfoot>\n";
print "<tr><td><strong>Total</td>";
foreach (array_reverse($yearList) as $year) {
  print '<td align="right"><strong>'.number_format($totalTaskPaymentForYear[$year],2).'</strong></td>';
}
print '<td align="right"><strong>'.number_format($grandTotal,2).'</strong></td>';
print '</tr>';
print "</tfoot>\n</table>\n";

if (count(array_filter($totalTaskPaymentForYear)) > 1) {
  $graphs = timeSeriesGraphs(
    $yearList,
    $taskVenues,
    $totalTaskPaymentForYear,
    $paymentForTaskVenueAndYear,
    $generateGraphCmdBase,
    $imagesPath,
    "https://contractwork.vipulnaik.com/payer.php?payer=" . urlencode($payer),
    "#payerTaskPaymentsDueByVenueAndYear"
  );

  print "<p><strong>Graph of payer task payments due by venue and year (incremental, not cumulative)</strong></p>";
  print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

  print "<p><strong>Graph of payer task payments due by venue and year (cumulative)</strong></p>";
  print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
}
?>
