<?php
print '<h4 id="paymentsMadeByWorkerAndMethod">Payments made by recipient worker and method</h4>';

# Initialize values to zero
$totalPaymentMadeAcrossWorkers = 0;
foreach ($workerList as $worker) {
  $totalPaymentMadeToWorker[$worker] = 0;
  foreach ($paymentMethods as $paymentMethod) {
    $payment[$worker][$paymentMethod] = 0;
  }
}  

foreach($paymentMethods as $paymentMethod) {
  $totalPaymentByMethod[$paymentMethod] = 0;
  $paymentMadeViaIntermediaries[$paymentMethod] = 0;
}

$totalPaymentMadeViaIntermediaries = 0;
# Get payments

$paymentSelectQuery = "select payment_method, case when private = 1 then 'Private' else payee end as payee, coalesce(sum(payment), 0) as payment from payments where receipt_date is not null group by payment_method, payee, private;";
$paymentSelectResult = $mysqli -> query($paymentSelectQuery);
for ($i=0; $i < $paymentSelectResult -> num_rows; $i++) {
  $row = $paymentSelectResult -> fetch_assoc();
  $payment[$row['payee']][$row['payment_method']] = $row['payment'];
  $totalPaymentByMethod[$row['payment_method']] += $row['payment'];
  $totalPaymentMadeToWorker[$row['payee']] += $row['payment'];
  $totalPaymentMadeAcrossWorkers += $row['payment'];
}

$paymentMadeViaIntermediariesQuery = "select payment_method, coalesce(sum(payment), 0) as payment from payments where intermediary is not null and receipt_date is not null group by payment_method;";
$paymentMadeViaIntermediariesResult = $mysqli -> query($paymentMadeViaIntermediariesQuery);
for ($i=0; $i < $paymentMadeViaIntermediariesResult -> num_rows; $i++) {
  $row = $paymentMadeViaIntermediariesResult -> fetch_assoc();
  $paymentMadeViaIntermediaries[$row['payment_method']] = $row['payment'];
  $totalPaymentMadeViaIntermediaries += $row['payment'];
  $totalPaymentMadeAcrossWorkers -= $row['payment'];
}


function cmpWorkersByPaymentsMade($firstWorker, $secondWorker) {
  global $totalPaymentMadeToWorker;
  if (floatval($totalPaymentMadeToWorker[$firstWorker]) == floatval($totalPaymentMadeToWorker[$secondWorker])) {
      return 0;
  }
  return (floatval($totalPaymentMadeToWorker[$firstWorker]) > floatval($totalPaymentMadeToWorker[$secondWorker])) ? -1 : 1;
}

usort($workerList,"cmpWorkersByPaymentsMade");

# Print table
print "\n";
print '<table id="myTablePaymentsMadeByWorkerAndMethod" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Worker</th>';
print '<th>Total across payment methods</th>';
foreach ($paymentMethods as $paymentMethod) {
  print "<th>$paymentMethod payments made</th>";
}
print "</tr>\n</thead>\n<tbody>\n";
foreach ($workerList as $worker) {
  if ($worker == 'Private') {
    print "<tr>\n".'<td>Private</td>';
  } else {
    print "<tr>\n".'<td><a href="http://contractwork.vipulnaik.com/worker.php?worker='.urlencode($worker).'">'.$worker.'</a></td>';
  }
  print '<td align="right"><strong>'.number_format($totalPaymentMadeToWorker[$worker],2).'</strong></td>';
  foreach ($paymentMethods as $paymentMethod) {
    print '<td align="right">'.number_format($payment[$worker][$paymentMethod],2).'</td>';
  }
  print "\n</tr>\n";
}
print "<tr>\n<td>Payment via an intermediary (subtract this row to avoid double-counting)</td>";
print '<td align="right"><strong>'.number_format($totalPaymentMadeViaIntermediaries,2).'</strong></td>';
foreach ($paymentMethods as $paymentMethod) {
  print '<td align="right">'.number_format($paymentMadeViaIntermediaries[$paymentMethod],2).'</td>';
}
print "\n</tr>\n";
print "<tbody>\n<tfoot>\n";
print '<tr><td><strong>Total across workers</strong></td>';
print '<td align="right"><strong>'.number_format($totalPaymentMadeAcrossWorkers,2).'</strong></td>';
foreach ($paymentMethods as $paymentMethod) {
  print '<td align="right"><strong>'.number_format($totalPaymentByMethod[$paymentMethod],2).'</strong></td>';
}
print '</tr>';

print "</tfoot>\n</table>\n";
?>
