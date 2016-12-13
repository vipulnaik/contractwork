<?php
print '<h4>Task payments due by type and year</h4>';

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

$taskSelectQuery = "select task_type, year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks group by task_type, year(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i = 0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
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
print '<table border="1">';
print '<tr><th>Task type</th>';
foreach (array_reverse($yearList) as $year) {
  print "<th>Total in year $year</th>";
}
print '<th>Total across years</th></tr>';

foreach($taskTypes as $taskType) {
  if ($totalPaymentForTaskType[$taskType] > 0) {
    print "<tr><td>$taskType</td>";
    foreach (array_reverse($yearList) as $year) {
      print '<td align="right">'.sprintf('%.2f',$paymentForTaskTypeAndYear[$taskType][$year]).'</td>';
    }
    print '<td align="right">'.sprintf('%.2f',$totalPaymentForTaskType[$taskType]).'</td>';
    print '</tr>';
  }
}

print "<tr><td><strong>Total</td>";
foreach (array_reverse($yearList) as $year) {
  print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentForYear[$year]).'</strong></td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$grandTotal).'</strong></td>';
print '</tr>';
print '</table>';
?>