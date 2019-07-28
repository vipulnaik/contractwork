<?php
print "<h4 id=\"venueTaskPaymentsDueByPayerAndMonth\">Task payments due for tasks related to venue $venue by payer and month</h4>";

$payerList = array();
$payerSelectQuery = "select distinct payer from tasks where $venueRegexMatcher;";
$payerSelectResult = $mysqli -> query($payerSelectQuery);

for($i=0;$i < $payerSelectResult -> num_rows; $i++) {
  $row = $payerSelectResult -> fetch_assoc();
  array_push($payerList, $row['payer']);
}

# Initialize values to zero
global $totalPaymentForPayer;
foreach($payerList as $payer) {
  $totalPaymentForPayer[$payer] = 0; 
  foreach ($monthList as $month) {
    $paymentForPayerAndMonth[$payer][$month] = 0;
  }
}  

foreach($monthList as $month) {
  $totalTaskPaymentForMonth[$month] = 0;
}

$totalTaskPayment = 0;

# Get task payments

$taskSelectQuery = "select payer, year(completion_date) as year,month(completion_date) as month, coalesce(sum(payment), 0) as payment from tasks where $venueRegexMatcher group by payer, year(completion_date), month(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  if (!isset($paymentForPayerAndMonth[$row['payer']])) {
    $paymentForPayerAndMonth[$row['payer']] = array();
  }
  if (!isset($totalPaymentForPayerUsingMonth[$row['payer']])) {
    $totalPaymentForPayerUsingMonth[$row['payer']] = 0;
  }
  $paymentForPayerAndMonth[$row['payer']][$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $totalTaskPaymentForMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] += $row['payment'];
  $totalPaymentForPayerUsingMonth[$row['payer']] += $row['payment'];
  $totalTaskPayment += $row['payment'];
}
# Sort payerList

function cmpPayersForMonth($firstPayer, $secondPayer) {
  global $totalPaymentForPayerUsingMonth;
  $firstPayerPayment = 0;
  $secondPayerPayment = 0;
  if (isset($totalPaymentForPayerUsingMonth[$firstPayer])) {
    $firstPayerPayment = $totalPaymentForPayerUsingMonth[$firstPayer];
  }
  if (isset($totalPaymentForPayerUsingMonth[$secondPayer])) {
    $secondPayerPayment = $totalPaymentForPayerUsingMonth[$secondPayer];
  }
  if (intval($firstPayerPayment) == intval($secondPayerPayment)) {
      return 0;
  }
  return (intval($firstPayerPayment) > intval($secondPayerPayment)) ? -1 : 1;
}

usort($payerList,"cmpPayersForMonth");

# Then print data by month

# Print table
print "\n";
print '<table id="myTableTaskPaymentsDueByPayerAndMonth" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Month</th>';
print "<th>Total across task payers</th>";
foreach ($payerList as $payer) {
  if (isset($totalPaymentForPayerUsingMonth[$payer]) && $totalPaymentForPayerUsingMonth[$payer] > 0) {
    print "<th><a href=\"https://contractwork.vipulnaik.com/payer.php?payer=".urlencode($payer)."\">$payer</a></th>";
  }
}
print '</tr>';
print "</thead>\n<tbody>\n";

foreach (array_reverse($monthList) as $month) {
  if ($totalTaskPaymentForMonth[$month] > 0) {
    print "<tr><td>$month</td>";
    print '<td align="right"><strong>'.number_format($totalTaskPaymentForMonth[$month],2).'</strong></td>';
    foreach ($payerList as $payer) {
      if (isset($totalPaymentForPayerUsingMonth[$payer]) && $totalPaymentForPayerUsingMonth[$payer] > 0) {
        $localPayment = 0;
        if (isset($paymentForPayerAndMonth[$payer][$month])) {
          $localPayment = $paymentForPayerAndMonth[$payer][$month];
        }
        print '<td align="right">'.number_format($localPayment,2).'</td>';
      }
    }
    print '</tr>';
  }
}
print "</tbody>\n<tfoot>\n";
print '<tr><td><strong>Total across months</strong></td>';
print '<td align="right"><strong>'.number_format($totalTaskPayment,2).'</strong></td>';
foreach($payerList as $payer) {
  if (isset($totalPaymentForPayerUsingMonth[$payer]) && $totalPaymentForPayerUsingMonth[$payer] > 0) {
    print '<td align="right"><strong>'.number_format($totalPaymentForPayerUsingMonth[$payer],2).'</strong></td>';
  }
}
print '</tr>';

print "</tfoot>\n</table>\n";

$graphs = timeSeriesGraphs(
  $monthList,
  $payerList,
  $totalTaskPaymentForMonth,
  $paymentForPayerAndMonth,
  $generateGraphCmdBase,
  $imagesPath,
  "https://contractwork.vipulnaik.com/venue.php?venue=" . urlencode($venue),
  "#venueTaskPaymentsDueByPayerAndMonth"
);

print "<p><strong>Graph of task payments due by payer and month (incremental, not cumulative)</strong></p>";
print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

print "<p><strong>Graph of task payments due by payer and month (cumulative)</strong></p>";
print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
?>
