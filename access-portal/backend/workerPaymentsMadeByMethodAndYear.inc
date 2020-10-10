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

$paymentSelectQuery = "select payment_method, year(receipt_date) as year, coalesce(sum(payment), 0) as payment from payments where payee=? and receipt_date is not null group by payment_method, year(receipt_date);";
$stmt = $mysqli->prepare($paymentSelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$paymentSelectResult = $stmt->get_result();
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
  print '<th>Total across years</th>';
  foreach (array_reverse($yearList) as $year) {
    if ($totalPaymentMadeByYear[$year] != 0) {
      print "<th>Total in year $year</th>";
    }
  }
  print "</tr>\n</thead>\n<tbody>\n";
  foreach ($paymentMethods as $paymentMethod) {
    if ($totalPaymentMadeByMethod[$paymentMethod] != 0) {
      print "<tr><td>$paymentMethod</td>";
      print '<td align="right"><strong>'.number_format($totalPaymentMadeByMethod[$paymentMethod],2).'</strong></td>';
      foreach (array_reverse($yearList) as $year) {
        if ($totalPaymentMadeByYear[$year] != 0) {
          print '<td align="right">'.number_format($payment[$paymentMethod][$year],2).'</td>';
        }
      }
      print "</tr>\n";
    }
  }
  print "</tbody>\n<tfoot>\n";
  print '<tr><td><strong>Total across payment methods</strong></td>';
  print '<td align="right"><strong>'.number_format($totalPaymentMadeToWorker,2).'</strong></td>';
  foreach (array_reverse($yearList) as $year) {
    if ($totalPaymentMadeByYear[$year] != 0) {
      print '<td align="right"><strong>'.number_format($totalPaymentMadeByYear[$year],2).'</strong></td>';
    }
  }
  print "</tr>\n</tfoot>\n</table>\n";
  if (count(array_filter($totalPaymentMadeByYear)) > 1) {
    $graphs = timeSeriesGraphs(
      $yearList,
      $paymentMethods,
      $totalPaymentMadeByYear,
      $payment,
      $generateGraphCmdBase,
      $imagesPath,
      "https://contractwork.vipulnaik.com/worker.php?worker=" . urlencode($worker),
      "#workerPaymentsMadeByMethodAndYear"
    );

    print "<p><strong>Graph of payments made by method and year (incremental, not cumulative)</strong></p>";
    print '<img src="/images/'.$graphs[0].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';

    print "<p><strong>Graph of payments made by method and year (cumulative)</strong></p>";
    print '<img src="/images/'.$graphs[1].'-timeseries.png" alt="Graph of payments should have loaded here"></img>';
  }
}
?>
