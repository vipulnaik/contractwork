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
  $totalPaymentForYear[$year] = 0;
}

$grandTotal = 0;

# Get task payments

$taskSelectQuery = "select task_venue, year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks where payer='$payer' group by task_venue, year(completion_date);";
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
    print "<tr><td>$taskVenue</td>";
    foreach (array_reverse($yearList) as $year) {
      print '<td align="right">'.sprintf('%.2f',$paymentForTaskVenueAndYear[$taskVenue][$year]).'</td>';
    }
    print '<td align="right">'.sprintf('%.2f',$totalPaymentForTaskVenue[$taskVenue]).'</td>';
    print '</tr>';
  }
}
print "</tbody>\n<tfoot>\n";
print "<tr><td><strong>Total</td>";
foreach (array_reverse($yearList) as $year) {
  print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentForYear[$year]).'</strong></td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$grandTotal).'</strong></td>';
print '</tr>';
print "</tfoot>\n</table>\n";
?>