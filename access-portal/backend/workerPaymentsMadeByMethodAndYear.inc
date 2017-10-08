<?php
if ($printTables == true) {
  print '<h4 id="workerPaymentsMadeByMethodAndYear">Worker payments made by method and year</h4>';
}
# Initialize values to zero
$totalPaymentMadeToWorker = 0;
foreach ($paymentMethods as $paymentMethod) {
  $totalPaymentMadeByMethod[$paymentMethod] = 0;
  foreach ($yearList as $year) {
    $payment[$paymentMethod][$year] = 0;
    $totalPaymentMadeByYear[$year] = 0;
  }
}  

# Get payments

$paymentSelectQuery = "select payment_method, year(receipt_date) as year, coalesce(sum(payment), 0) as payment from payments where payee=".'"'.str_replace('"','\"',$worker).'"'." and receipt_date is not null group by payment_method, year(receipt_date);";
$paymentSelectResult = $mysqli -> query($paymentSelectQuery);
for ($i=0; $i < $paymentSelectResult -> num_rows; $i++) {
  $row = $paymentSelectResult -> fetch_assoc();
  $payment[$row['payment_method']][$row['year']] = $row['payment'];
  $totalPaymentMadeByMethod[$row['payment_method']] += $row['payment'];
  $totalPaymentMadeByYear[$row['year']] += $row['payment'];
  $totalPaymentMadeToWorker += $row['payment'];
}

function cmpPaymentMethods($firstPaymentMethod, $secondPaymentMethod) {
  global $totalPaymentMadeByMethod;
  if (intval($totalPaymentMadeByMethod[$firstPaymentMethod]) == intval($totalPaymentMadeByMethod[$secondPaymentMethod])) {
      return 0;
  }
  return (intval($totalPaymentMadeByMethod[$firstPaymentMethod]) > intval($totalPaymentMadeByMethod[$secondPaymentMethod])) ? -1 : 1;
}

usort($paymentMethods,"cmpPaymentMethods");

# Print table
if ($printTables == true) {
  print "\n";
  print '<table id="myTableWorkerPaymentsMadeByMethodAndYear" class="tablesorter">'."\n";
  print "<thead>\n";
  print '<tr><th>Payment method</th>';
  foreach (array_reverse($yearList) as $year) {
    print "<th>Total in year $year</th>";
  }
  print '<th>Total across years</th></tr>';
  print "</thead>\n<tbody>\n";
  foreach ($paymentMethods as $paymentMethod) {
    if ($totalPaymentMadeByMethod[$paymentMethod] > 0) {
      print "<tr><td>$paymentMethod</td>";
      foreach (array_reverse($yearList) as $year) {
        print '<td align="right">'.number_format($payment[$paymentMethod][$year],2).'</td>';
      }
      print '<td align="right">'.number_format($totalPaymentMadeByMethod[$paymentMethod],2).'</td></tr>';
    }
  }
  print "</tbody>\n<tfoot>\n";
  print '<tr><td><strong>Total across payment methods</strong></td>';
  foreach (array_reverse($yearList) as $year) {
    print '<td align="right"><strong>'.number_format($totalPaymentMadeByYear[$year],2).'</strong></td>';
  }
  print '<td align="right"><strong>'.number_format($totalPaymentMadeToWorker,2).'</strong></td>';
  print '</tr>';
  print "</tfoot>\n</table>\n";
}

$graphs = yearlyGraphs(
  $yearList,
  $paymentMethods,
  $totalPaymentMadeByYear,
  $payment,
  $generateGraphCmdBase,
  $imagesPath,
  "https://contractwork.vipulnaik.com/worker.php",
  "#workerPaymentsMadeByMethodAndYear"
);

print "<p><strong>Graph of payments made by method and year (incremental, not cumulative)</strong></p>";
print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

print "<p><strong>Graph of payments made by method and year (cumulative)</strong></p>";
print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
?>
