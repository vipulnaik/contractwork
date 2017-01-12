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

$taskSelectQuery = "select task_venue, year(completion_date) as year,month(completion_date) as month, coalesce(sum(payment), 0) as payment from tasks where worker='$worker' group by task_venue, year(completion_date), month(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
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
  print '<table border="1">';
  print '<tr><th>Month</th>';
  foreach ($taskVenues as $taskVenue) {
    if ($totalPaymentForTaskVenue[$taskVenue] > 0) {
      print "<th>$taskVenue</th>";
    }
  }
  print "<th>Total across task venues</th>";
  print '</tr>';
  
  foreach (array_reverse($monthList) as $month) {
    if ($totalTaskPaymentForMonth[$month] > 0) {
      print "<tr><td>$month</td>";
      foreach ($taskVenues as $taskVenue) {
        if ($totalPaymentForTaskVenue[$taskVenue] > 0) {
          print '<td align="right">'.sprintf('%.2f',$paymentForTaskVenueAndMonth[$taskVenue][$month]).'</td>';
        }
      }
      print '<td align="right"><strong>'.sprintf('%.2f',$totalTaskPaymentForMonth[$month]).'</strong></td>';
      print '</tr>';
    }
  }
  
  print '<tr><td><strong>Total across months</strong></td>';
  foreach($taskVenues as $taskVenue) {
    if ($totalPaymentForTaskVenue[$taskVenue] > 0) {
      print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentForTaskVenue[$taskVenue]).'</strong></td>';
    }
  }
  print '<td align="right"><strong>'.sprintf('%.2f',$totalTaskPayment).'</strong></td>';
  print '</tr>';
  
  print '</table>';
}
?>