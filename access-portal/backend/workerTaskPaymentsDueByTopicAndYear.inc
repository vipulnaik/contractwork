<?php
print '<h4 id="workerTaskPaymentsDueByTopicAndYear">Worker task payments due by topic and year</h4>';

print '<p>Note that a single task may be assigned to multiple topics so a few tasks may be double-counted below. Also, the list below does not include all tasks.</p>';
# Initialize values to zero
$groupingString = '';
$columnsString = '';
foreach($topics as $topic) {
  $groupingString .= 'topic REGEXP "'.$topic.'",';
  $columnsString .= 'topic REGEXP "'.$topic.'" as `topic:'.$topic.'`,';
  $totalPaymentForTopic[$topic] = 0; 
  foreach ($yearList as $year) {
    $paymentForTopicAndYear[$topic][$year] = 0;
  }
}  

foreach($yearList as $year) {
  $totalPaymentForYear[$year] = 0;
}

$grandTotal = 0;

# Get task payments

$taskSelectQuery = "select $columnsString year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks where worker=".'"'.str_replace('"','\"',$worker).'"'." group by $groupingString year(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i = 0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  foreach ($topics as $topic) {
    if ($row['topic:' . $topic] == 1) {
      $paymentForTopicAndYear[$topic][$row['year']] += $row['payment'];
      $totalPaymentForTopic[$topic] += $row['payment'];
    }
  }
  $totalPaymentForYear[$row['year']] += $row['payment'];
  $grandTotal += $row['payment'];
}

function cmpTopics($firstTopic, $secondTopic) {
  global $totalPaymentForTopic;
  if (intval($totalPaymentForTopic[$firstTopic]) == intval($totalPaymentForTopic[$secondTopic])) {
      return 0;
  }
  return (intval($totalPaymentForTopic[$firstTopic]) > intval($totalPaymentForTopic[$secondTopic])) ? -1 : 1;
}

usort($topics,"cmpTopics");

# Print table
print "\n";
print '<table id="myTableWorkerTaskPaymentsDueByTopicAndYear" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Topic</th>';
print '<th>Total across years</th>';
foreach (array_reverse($yearList) as $year) {
  if ($totalPaymentForYear[$year] > 0) {
    print "<th>Total in year $year</th>";
  }
}
print "</tr>\n</thead>\n<tbody>\n";
foreach($topics as $topic) {
  if ($totalPaymentForTopic[$topic] > 0) {
    print "<tr><td>$topic</td>";
    print '<td align="right"><strong>'.number_format($totalPaymentForTopic[$topic],2).'</strong></td>';
    foreach (array_reverse($yearList) as $year) {
      if ($totalPaymentForYear[$year] > 0) {
        print '<td align="right">'.number_format($paymentForTopicAndYear[$topic][$year],2).'</td>';
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
  $topics,
  $totalPaymentForYear,
  $paymentForTopicAndYear,
  $generateGraphCmdBase,
  $imagesPath,
  "https://contractwork.vipulnaik.com/worker.php?worker=" . urlencode($worker),
  "#workerTaskPaymentsDueByTopicAndYear"
);

print "<p><strong>Graph of task payments due by topic and year (incremental, not cumulative)</strong></p>";
print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

print "<p><strong>Graph of task payments due by topic and year (cumulative)</strong></p>";
print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
?>
