<?php
print '<h4 id="payerTaskPaymentsDueByTopicAndYear">Payer task payments due by topic and year</h4>';

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
  $totalTaskPaymentForYear[$year] = 0;
}

$grandTotal = 0;

# Get task payments

// Both $columnsString and $groupingString are constructed using safe values
// defined in access-portal/backend/globalVariables/lists.inc so there is no
// need to escape these.
$taskSelectQuery = "select $columnsString year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks where payer=? group by $groupingString year(completion_date);";
$stmt = $mysqli->prepare($taskSelectQuery);
$stmt->bind_param("s", $payer);
$stmt->execute();
$taskSelectResult = $stmt->get_result();
for ($i = 0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  foreach ($topics as $topic) {
    if ($row['topic:' . $topic] == 1) {
      $paymentForTopicAndYear[$topic][$row['year']] += $row['payment'];
      $totalPaymentForTopic[$topic] += $row['payment'];
    }
  }
  $totalTaskPaymentForYear[$row['year']] += $row['payment'];
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
print '<table id="myTablePayerTaskPaymentsDueByTopicAndYear" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Topic</th>';
foreach (array_reverse($yearList) as $year) {
  print "<th>Total in year $year</th>";
}
print '<th>Total across years</th></tr>';
print "</thead>\n<tbody>\n";
foreach($topics as $topic) {
  if ($totalPaymentForTopic[$topic] > 0) {
    print "<tr><td>$topic</td>";
    foreach (array_reverse($yearList) as $year) {
      print '<td align="right">'.number_format($paymentForTopicAndYear[$topic][$year],2).'</td>';
    }
    print '<td align="right">'.number_format($totalPaymentForTopic[$topic],2).'</td>';
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
    $topics,
    $totalTaskPaymentForYear,
    $paymentForTopicAndYear,
    $generateGraphCmdBase,
    $imagesPath,
    "https://contractwork.vipulnaik.com/payer.php?payer=" . urlencode($payer),
    "#payerTaskPaymentsDueByTopicAndYear"
  );

  print "<p><strong>Graph of payer task payments due by topic and year (incremental, not cumulative)</strong></p>";
  print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

  print "<p><strong>Graph of payer task payments due by topic and year (cumulative)</strong></p>";
  print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
}
?>
