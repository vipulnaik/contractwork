<?php
print "<h4 id=\"venueTaskPaymentsDueByPayerAndYear\">Task payments due for tasks related to venue " . htmlspecialchars($venue) . " by payer and year</h4>";

$payerList = array();
$payerSelectQuery = "select distinct payer from tasks where $venueRegexMatcher;";
$stmt = $mysqli->prepare($payerSelectQuery);
if ($venueRegexMatcherParams) {
  $stmt->bind_param($venueRegexMatcherParamStr, ...$venueRegexMatcherParams);
}
$stmt->execute();
$payerSelectResult = $stmt->get_result();

for($i=0;$i < $payerSelectResult -> num_rows; $i++) {
  $row = $payerSelectResult -> fetch_assoc();
  array_push($payerList, $row['payer']);
}

$paymentForPayerAndYear = array();
foreach($yearList as $year) {
  $totalPaymentForYear[$year] = 0;
}

$grandTotal = 0;

# Get task payments

$taskSelectQuery = "select payer, year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks where $venueRegexMatcher group by payer, year(completion_date);";
$stmt = $mysqli->prepare($taskSelectQuery);
if ($venueRegexMatcherParams) {
  $stmt->bind_param($venueRegexMatcherParamStr, ...$venueRegexMatcherParams);
}
$stmt->execute();
$taskSelectResult = $stmt->get_result();
for ($i = 0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  if (!isset($paymentForPayerAndYear[$row['payer']])) {
    $paymentForPayerAndYear[$row['payer']] = array();
  }
  if (!isset($totalPaymentForPayerUsingYear[$row['payer']])) {
    $totalPaymentForPayerUsingYear[$row['payer']] = 0;
  }
  $paymentForPayerAndYear[$row['payer']][$row['year']] = $row['payment'];
  $totalPaymentForYear[$row['year']] += $row['payment'];
  $totalPaymentForPayerUsingYear[$row['payer']] += $row['payment'];
  $grandTotal += $row['payment'];
}

function cmpPayersUsingYear($firstPayer, $secondPayer) {
  global $totalPaymentForPayerUsingYear;
  if (intval($totalPaymentForPayerUsingYear[$firstPayer]) == intval($totalPaymentForPayerUsingYear[$secondPayer])) {
      return 0;
  }
  return (intval($totalPaymentForPayerUsingYear[$firstPayer]) > intval($totalPaymentForPayerUsingYear[$secondPayer])) ? -1 : 1;
}

usort($payerList,"cmpPayersUsingYear");

# Print table
print "\n";
print '<table id="myTableTaskPaymentsDueByPayerAndYear" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Task payer</th>';
print '<th>Total across years</th>';
foreach (array_reverse($yearList) as $year) {
  if ($totalPaymentForYear[$year] > 0) {
    print "<th>Total in year $year</th>";
  }
}
print "</tr></thead>\n<tbody>\n";
foreach($payerList as $payer) {
  if (isset($totalPaymentForPayerUsingYear[$payer]) && $totalPaymentForPayerUsingYear[$payer] > 0) {
    print "<tr><td><a href=\"https://contractwork.vipulnaik.com/payer.php?payer=".urlencode($payer)."\">" . htmlspecialchars($payer) . "</a></td>";
    print '<td align="right"><strong>'.number_format($totalPaymentForPayerUsingYear[$payer],2).'</strong></td>';
    foreach (array_reverse($yearList) as $year) {
      if ($totalPaymentForYear[$year] > 0) {
        $localPayment = 0;
        if (isset($paymentForPayerAndYear[$payer][$year])) {
          $localPayment = $paymentForPayerAndYear[$payer][$year];
        }
        print '<td align="right">'.number_format($localPayment,2).'</td>';
      }
    }
    print '</tr>';
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
print '</tr>';
print "</tfoot>\n</table>\n";

$graphs = timeSeriesGraphs(
  $yearList,
  $payerList,
  $totalPaymentForYear,
  $paymentForPayerAndYear,
  $generateGraphCmdBase,
  $imagesPath,
  "https://contractwork.vipulnaik.com/venue.php?venue=" . urlencode($venue),
  "#venueTaskPaymentsDueByPayerAndYear"
);

print "<p><strong>Graph of task payments due by payer and year (incremental, not cumulative)</strong></p>";
print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

print "<p><strong>Graph of task payments due by payer and year (cumulative)</strong></p>";
print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
?>
