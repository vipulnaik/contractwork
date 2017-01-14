<?php

print '<h4 id="taskPaymentsDueByTopicAndMonth">Task payments due by topic and month</h4>';
print '<p>Note that a single task may be assigned to multiple topics so a few tasks may be double-counted below. Also, the list below does not include all tasks.</p>';

# Initialize values to zero
$groupingString = '';
$columnsString = '';
foreach($topics as $topic) {
  $groupingString .= 'topic REGEXP "'.$topic.'",';
  $columnsString .= 'topic REGEXP "'.$topic.'" as `topic:'.$topic.'`,';
  $totalPaymentForTopic[$topic] = 0; 
  foreach ($monthList as $month) {
    $paymentForTopicAndMonth[$topic][$month] = 0;
  }
}  

foreach($monthList as $month) {
  $totalTaskPaymentForMonth[$month] = 0;
}

$totalTaskPayment = 0;

# Get task payments

$taskSelectQuery = "select $columnsString year(completion_date) as year,month(completion_date) as month, coalesce(sum(payment), 0) as payment from tasks group by $groupingString year(completion_date), month(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  foreach ($topics as $topic) {
    if ($row['topic:' . $topic] == 1) {
      $paymentForTopicAndMonth[$topic][$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
      $totalPaymentForTopic[$topic] += $row['payment']; 
    }
  }
  $totalTaskPaymentForMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] += $row['payment'];
  $totalTaskPayment += $row['payment'];
}

# Sort topics

function cmpTopicsForMonth($firstTopic, $secondTopic) {
  global $totalPaymentForTopic;
  if (intval($totalPaymentForTopic[$firstTopic]) == intval($totalPaymentForTopic[$secondTopic])) {
      return 0;
  }
  return (intval($totalPaymentForTopic[$firstTopic]) > intval($totalPaymentForTopic[$secondTopic])) ? -1 : 1;
}

usort($topics,"cmpTopicsForMonth");

# Then print data by month

# Print table
print "\n";
print '<table id="myTableTaskPaymentsDueByTopicAndMonth" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Month</th>';
foreach ($topics as $topic) {
  if ($totalPaymentForTopic[$topic] > 0) {
    print "<th>$topic</th>";
  }
}
print "<th>Total across topics</th>";
print '</tr>';
print "</tfoot>\n<tbody>\n";
foreach (array_reverse($monthList) as $month) {
  if ($totalTaskPaymentForMonth[$month] > 0) {
    print "<tr><td>$month</td>";
    foreach ($topics as $topic) {
      if ($totalPaymentForTopic[$topic] > 0) {
        print '<td align="right">'.sprintf('%.2f',$paymentForTopicAndMonth[$topic][$month]).'</td>';
      }
    }
    print '<td align="right"><strong>'.sprintf('%.2f',$totalTaskPaymentForMonth[$month]).'</strong></td>';
    print '</tr>';
  }
}

print "</tbody>\n<tfoot>\n";
print '<tr><td><strong>Total across months</strong></td>';
foreach($topics as $topic) {
  if ($totalPaymentForTopic[$topic] > 0) {
    print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentForTopic[$topic]).'</strong></td>';
  }
}
print '<td align="right"><strong>'.sprintf('%.2f',$totalTaskPayment).'</strong></td>';
print '</tr>';

print "</tfoot>\n</table>\n";

?>