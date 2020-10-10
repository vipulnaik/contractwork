<?php
print '<h4 id="paymentsMadeByMethodAndYear">Payments made by method and year</h4>';

# Initialize values to zero
$grandTotal = 0;
foreach ($paymentMethods as $paymentMethod) {
  $totalPaymentByMethod[$paymentMethod] = 0;
  foreach ($yearList as $year) {
    $payment[$paymentMethod][$year] = 0;
    $totalPaymentMadeByYear[$year] = 0;
  }
}  

# Get payments

$paymentSelectQuery = "select payment_method, year(receipt_date) as year, coalesce(sum(payment), 0) as payment from payments where intermediary is null and receipt_date is not null group by payment_method, year(receipt_date);";
$paymentSelectResult = $mysqli -> query($paymentSelectQuery);
for ($i=0; $i < $paymentSelectResult -> num_rows; $i++) {
  $row = $paymentSelectResult -> fetch_assoc();
  $payment[$row['payment_method']][$row['year']] = $row['payment'];
  $totalPaymentByMethod[$row['payment_method']] += $row['payment'];
  $totalPaymentMadeByYear[$row['year']] += $row['payment'];
  $grandTotal += $row['payment'];
}

function cmpPaymentMethods($firstPaymentMethod, $secondPaymentMethod) {
  global $totalPaymentByMethod;
  if (intval($totalPaymentByMethod[$firstPaymentMethod]) == intval($totalPaymentByMethod[$secondPaymentMethod])) {
      return 0;
  }
  return (intval($totalPaymentByMethod[$firstPaymentMethod]) > intval($totalPaymentByMethod[$secondPaymentMethod])) ? -1 : 1;
}

usort($paymentMethods,"cmpPaymentMethods");

# Print table
print "\n";
print '<table id="myTablePaymentsMadeByMethodAndYear" class="tablesorter">'."\n";
print "<thead>\n";
print "<tr>\n    <th>Payment method</th>\n";
print "    <th>Total across years</th>\n";
foreach (array_reverse($yearList) as $year) {
  print "    <th>Total in year $year</th>\n";
}
print "</tr>\n</thead>\n<tbody>\n";
foreach ($paymentMethods as $paymentMethod) {
  if ($totalPaymentByMethod[$paymentMethod] != 0) {
    print "<tr>\n    <td>$paymentMethod</td>\n";
    print '    <td align="right"><strong>'.number_format($totalPaymentByMethod[$paymentMethod],2)."</strong></td>\n";
    foreach (array_reverse($yearList) as $year) {
      print '    <td align="right">'.number_format($payment[$paymentMethod][$year],2)."</td>\n";
    }
    print "</tr>\n";
  }
}
print "</tbody>\n<tfoot>\n";
print "<tr>\n    <td><strong>Total across payment methods</strong></td>\n";
print '    <td align="right"><strong>'.number_format($grandTotal,2)."</strong></td>\n";
foreach (array_reverse($yearList) as $year) {
  print '    <td align="right"><strong>'.number_format($totalPaymentMadeByYear[$year],2)."</strong></td>\n";
}
print "</tr>\n";
print "</tfoot>\n";
print "</table>\n";

if (count(array_filter($totalPaymentMadeByYear)) > 1) {
  $graphs = timeSeriesGraphs(
    $yearList,
    $paymentMethods,
    $totalPaymentMadeByYear,
    $payment,
    $generateGraphCmdBase,
    $imagesPath,
    "https://contractwork.vipulnaik.com/index.php",
    "#paymentsMadeByMethodAndYear"
  );

  print "<p><strong>Graph of payments made by method and year (incremental, not cumulative)</strong></p>";
  print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

  print "<p><strong>Graph of payments made by method and year (cumulative)</strong></p>";
  print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
}
?>
