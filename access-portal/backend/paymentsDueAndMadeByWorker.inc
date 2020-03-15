<?php
print '<h4 id="paymentsDueAndMadeByWorker">Payments due and payments made by worker</h4>';

$totalReimbursementDueAcrossWorkers = 0;

foreach ($workerList as $worker) {
  $reimbursementDueToWorker[$worker] = 0;
  $pendingPayment[$worker] = 0;
}
$reimbursementSelectQuery = "select intermediary, coalesce(sum(sent_payment), 0) as payment from payments where intermediary is not null group by intermediary;";
$reimbursementSelectResult = $mysqli -> query($reimbursementSelectQuery);
for ($i=0;$i < $reimbursementSelectResult -> num_rows; $i++) {
  $row = $reimbursementSelectResult -> fetch_assoc();
  $reimbursementDueToWorker[$row['intermediary']] = $row['payment'];
  $totalReimbursementDueAcrossWorkers += $row['payment'];
}

foreach($workerList as $worker) {
  $pendingPayment[$worker] = $totalPaymentAwarded[$worker] + $reimbursementDueToWorker[$worker] - $totalPaymentMadeToWorker[$worker];
}

function cmpWorkersByPendingPayment($firstWorker, $secondWorker) {
  global $pendingPayment;
  if (intval($pendingPayment[$firstWorker]) == intval($pendingPayment[$secondWorker])) {
      return 0;
  }
  return (intval($pendingPayment[$firstWorker]) > intval($pendingPayment[$secondWorker])) ? -1 : 1;
}

usort($workerList,"cmpWorkersByPendingPayment");


# Print table
print "\n";
print '<table id="myTablePaymentsDueAndMadeByWorker" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Worker</th>';
print '<th>Total payment awarded</th>';
print '<th>Reimbursement due</th>';
print '<th>Total payment made</th>';
print '<th>Pending payment</th>';
print '</tr>';
print "</thead>\n<tbody>\n";

$starting = true;
foreach ($workerList as $worker) {
  printWorker($worker);
  print '<td align="right">'.number_format($totalPaymentAwarded[$worker],2).'</td>';
  print '<td align="right">'.number_format($reimbursementDueToWorker[$worker],2).'</td>';
  print '<td align="right">'.number_format($totalPaymentMadeToWorker[$worker],2).'</td>';
  print '<td align="right">'.number_format($pendingPayment[$worker],2).'</td>';
  print '</tr>';
}

print '<tr><td>Adjustment for payment via an intermediary (this would otherwise get double-counted in payments made)</td>';
print '<td align="right">0.00</td>';
print '<td align="right">0.00</td>';
print '<td align="right">'.number_format(-$totalPaymentMadeViaIntermediaries, 2).'</td>';
print '<td align="right">'.number_format($totalPaymentMadeViaIntermediaries, 2).'</td>';
print '</tr>';
print "</tbody>\n<tfoot>\n";

print '<tr><td><strong>Total across workers</strong></td>';
print '<td align="right"><strong>'.number_format($totalPaymentAwardedAcrossWorkers,2).'</strong></td>';
print '<td align="right"><strong>'.number_format($totalReimbursementDueAcrossWorkers,2).'</strong></td>';
print '<td align="right"><strong>'.number_format($totalPaymentMadeAcrossWorkers,2).'</strong></td>';
print '<td align="right"><strong>'.number_format($totalPaymentAwardedAcrossWorkers + $totalReimbursementDueAcrossWorkers - $totalPaymentMadeAcrossWorkers,2).'</strong></td>';
print '</tr>';

print "</tfoot>\n</table>\n";
?>
