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

$paymentSelectQuery = "select payment_method, year(receipt_date) as year, coalesce(sum(payment), 0) as payment from payments where payee='$worker' and receipt_date is not null group by payment_method, year(receipt_date);";
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
        print '<td align="right">'.sprintf('%.2f',$payment[$paymentMethod][$year]).'</td>';
      }
      print '<td align="right">'.sprintf('%.2f',$totalPaymentMadeByMethod[$paymentMethod]).'</td></tr>';
    }
  }
  print "</tbody>\n<tfoot>\n";
  print '<tr><td><strong>Total across payment methods</strong></td>';
  foreach (array_reverse($yearList) as $year) {
    print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentMadeByYear[$year]).'</strong></td>';
  }
  print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentMadeToWorker).'</strong></td>';
  print '</tr>';
  print "</tfoot>\n</table>\n";
}
?>