<?php
if ($topic == "") {
  print '<h4 id="topicTaskPaymentsDueByTypeAndYear">Task payments due for all tasks (regardless of topic) by type and year</h4>';
} else {
  print '<h4 id="topicTaskPaymentsDueByTypeAndYear">Task payments due for tasks related to topic '.$topic.' by type and year</h4>';
}

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

$totalTaskPaymentAcrossYears = 0;

# Get task payments

$taskSelectQuery = "select task_type, year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks where $topicRegexMatcher group by task_type, year(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i = 0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $paymentForTaskTypeAndYear[$row['task_type']][$row['year']] = $row['payment'];
  $totalPaymentForYear[$row['year']] += $row['payment'];
  $totalPaymentForTaskType[$row['task_type']] += $row['payment'];
  $totalTaskPaymentAcrossYears += $row['payment'];
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
print '<table id="myTableTopicTaskPaymentsDueByTypeAndYear" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Task type</th>';
foreach (array_reverse($yearList) as $year) {
  print "<th>Total in year $year</th>";
}
print '<th>Total across years</th></tr>';
print "</thead>\n<tbody>\n";

foreach($taskTypes as $taskType) {
  if ($totalPaymentForTaskType[$taskType] > 0) {
    print "<tr>\n";
    print "    <td>$taskType</td>\n";
    foreach (array_reverse($yearList) as $year) {
      print '    <td align="right">'.sprintf('%.2f',$paymentForTaskTypeAndYear[$taskType][$year])."</td>\n";
    }
    print '    <td align="right">'.sprintf('%.2f',$totalPaymentForTaskType[$taskType])."</td>\n";
    print "</tr>\n";
  }
}

print "</tbody>\n<tfoot>\n";
print "<tr>\n    <td><strong>Total</td>\n";
foreach (array_reverse($yearList) as $year) {
  print '    <td align="right"><strong>'.sprintf('%.2f',$totalPaymentForYear[$year])."</strong></td>\n";
}
print '    <td align="right"><strong>'.sprintf('%.2f',$totalTaskPaymentAcrossYears)."</strong></td>\n";
print "</tr>\n";
print "</tfoot>\n</table>\n";
?>