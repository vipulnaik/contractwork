<?php
print '<h4>Payments due and payments made by worker</h4>';

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
print '<table border="1">';
print '<tr><th>Worker</th>';
print '<th>Total payment awarded</th>';
print '<th>Reimbursement due</th>';
print '<th>Total payment made</th>';
print '<th>Pending payment</th>';
print '</tr>';

$starting = true;
foreach ($workerList as $worker) {
  print '<tr><td><a href="/worker.php?worker='.urlencode($worker).'">'.$worker.'</a></td>';
  print '<td align="right">'.sprintf('%.2f',$totalPaymentAwarded[$worker]).'</td>';
  print '<td align="right">'.sprintf('%.2f',$reimbursementDueToWorker[$worker]).'</td>';
  print '<td align="right">'.sprintf('%.2f',$totalPaymentMadeToWorker[$worker]).'</td>';
  print '<td align="right">'.sprintf('%.2f',$pendingPayment[$worker]).'</td>';
  print '</tr>';
}

print '<tr><td><strong>Total across workers</strong></td>';
print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentAwardedAcrossWorkers).'</strong></td>';
print '<td align="right"><strong>'.sprintf('%.2f',$totalReimbursementDueAcrossWorkers).'</strong></td>';
print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentMadeAcrossWorkers).'</strong></td>';
print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentAwardedAcrossWorkers + $totalReimbursementDueAcrossWorkers - $totalReimbursementDueAcrossWorkers).'</strong></td>';
print '</tr>';

print '</table>';
?>