<?php
print '<h4>Task payments due by venue and year</h4>';

$taskVenues = array('Wikipedia','Wikipedia Views','Effective Altruism Forum','LessWrong','Personal website','Wikimedia meta','wikiHow','Quora','None');
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

$taskSelectQuery = "select task_venue, year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks group by task_venue, year(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i = 0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $paymentForTaskVenueAndYear[$row['task_venue']][$row['year']] = $row['payment'];
  $totalPaymentForYear[$row['year']] += $row['payment'];
  $totalPaymentForTaskVenue[$row['task_venue']] += $row['payment'];
  $grandTotal += $row['payment'];
}

# Print table
print '<table border="1">';
print '<tr><th>Task venue</th>';
foreach ($yearList as $year) {
  print "<th>Total in year $year</th>";
}
print '<th>Total across years</th></tr>';

foreach($taskVenues as $taskVenue) {
  print "<tr><td>$taskVenue</td>";
  foreach ($yearList as $year) {
    print '<td align="right">'.sprintf('%.2f',$paymentForTaskVenueAndYear[$taskVenue][$year]).'</td>';
  }
  print '<td align="right">'.sprintf('%.2f',$totalPaymentForTaskVenue[$taskVenue]).'</td>';
  print '</tr>';
}

print "<tr><td><strong>Total</td>";
foreach ($yearList as $year) {
  print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentForYear[$year]).'</strong></td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$grandTotal).'</strong></td>';
print '</tr>';
print '</table>';
?>