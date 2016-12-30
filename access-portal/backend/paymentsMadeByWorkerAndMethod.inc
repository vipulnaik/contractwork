<?php
print '<h4 id="paymentsMadeByWorkerAndMethod">Payments made by recipient worker and method</h4>';

# Initialize values to zero
$totalPaymentMadeAcrossWorkers = 0;
foreach ($workerList as $worker) {
  $totalPaymentMadeToWorker[$worker] = 0;
  foreach ($paymentMethods as $paymentMethod) {
    $payment[$worker][$paymentMethod] = 0;
    $totalPaymentByMethod[$paymentMethod] = 0;
  }
}  

# Get payments

$paymentSelectQuery = "select payment_method, payee, coalesce(sum(payment), 0) as payment from payments where receipt_date is not null group by payment_method, payee;";
$paymentSelectResult = $mysqli -> query($paymentSelectQuery);
for ($i=0; $i < $paymentSelectResult -> num_rows; $i++) {
  $row = $paymentSelectResult -> fetch_assoc();
  $payment[$row['payee']][$row['payment_method']] = $row['payment'];
  $totalPaymentByMethod[$row['payment_method']] += $row['payment'];
  $totalPaymentMadeToWorker[$row['payee']] += $row['payment'];
  $totalPaymentMadeAcrossWorkers += $row['payment'];
}

# Print table
print '<table border="1">';
print '<tr><th>Worker</th>';
foreach ($paymentMethods as $paymentMethod) {
  print "<th>$paymentMethod payments made</th>";
}
print '<th>Total across payment methods</th></tr>';
foreach ($workerList as $worker) {
  print '<tr><td><a href="http://contractwork.vipulnaik.com/worker.php?worker='.urlencode($worker).'">'.$worker.'</a></td>';
  foreach ($paymentMethods as $paymentMethod) {
    print '<td align="right">'.sprintf('%.2f',$payment[$worker][$paymentMethod]).'</td>';
  }
  print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentMadeToWorker[$worker]).'</strong></td></tr>';
}
print '<tr><td><strong>Total across workers</strong></td>';
foreach ($paymentMethods as $paymentMethod) {
  print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentByMethod[$paymentMethod]).'</strong></td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentMadeAcrossWorkers).'</strong></td>';
print '</tr>';

print '</table>';
?>
