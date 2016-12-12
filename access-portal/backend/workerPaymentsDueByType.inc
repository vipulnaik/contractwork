<?php
print '<h4>Payments due by type</h4>';

print '<p>Note that private payments are not listed here.</p>';

$workerList = array();

# Get task payments

$workerSelectQuery = "select distinct worker from workers where worker='$worker' and private = false;";
$workerSelectResult = $mysqli -> query($workerSelectQuery);

$totalTaskPayment = 0;
$totalCommissionOnTaskPayment = 0;
$totalStipendPayment[0] = 0;
$totalStipendPayment[1] = 0;
$totalRoyaltyPayment = 0;
$totalCommissionOnRoyaltyPayment = 0;
$totalPaymentAwardedAcrossWorkers = 0;
$totalPaymentAcrossWorkers = 0;

for($i=0;$i < $workerSelectResult -> num_rows; $i++) {
  $row = $workerSelectResult -> fetch_assoc();
  array_push($workerList, $row['worker']);
  $taskPayment[$row['worker']] = 0;
  $commissionOnTaskPayment[$row['worker']] = 0;
  $stipendPayment[$row['worker']][0] = 0;
  $stipendPayment[$row['worker']][1] = 0;
  $royaltyPayment[$row['worker']] = 0;
  $commissionOnRoyaltyPayment[$row['worker']] = 0;
  $totalPaymentAwarded[$row['worker']] = 0;
  $totalPayment[$row['worker']] = 0;
}

$taskSelectQuery = "select worker, coalesce(sum(payment), 0) as payment from tasks group by worker";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $taskPayment[$row['worker']] = $row['payment'];
  $totalTaskPayment += $row['payment'];
}

# Get commission on task payments
$commissionOnTaskSelectQuery = "select commission_receiver, coalesce(sum(payment), 0) as payment from (select completion_date, commission_receiver, (commission * payment) as payment from commissions left join tasks on commissions.earner = tasks.worker where (commission_validity_start is null or tasks.completion_date >= commission_validity_start) and (commission_validity_end is null or tasks.completion_date <= commission_validity_end)) t1 group by commission_receiver;";
$commissionOnTaskSelectResult = $mysqli -> query($commissionOnTaskSelectQuery);
for ($i = 0; $i < $commissionOnTaskSelectResult -> num_rows; $i++) {
  $row = $commissionOnTaskSelectResult -> fetch_assoc();
  $commissionOnTaskPayment[$row['commission_receiver']] = $row['payment'];
  $totalCommissionOnTaskPayment += $row['payment'];
}

# Get stipend payments

$stipendSelectQuery = "select payee, (stipend_award_date is not null) as awarded, coalesce(sum(payment), 0) as payment  from stipends group by payee, (stipend_award_date is not null);";
$stipendSelectResult = $mysqli -> query($stipendSelectQuery);
for ($i = 0; $i < $stipendSelectResult -> num_rows; $i++) {
  $row = $stipendSelectResult -> fetch_assoc();
  $stipendPayment[$row['payee']][$row['awarded']] = $row['payment'];
  $totalStipendPayment[$row['awarded']] += $row['payment'];
}

# Get royalty payments
$royaltySelectQuery = "select payee, coalesce(sum(payment), 0) as payment from royalties group by payee;";
$royaltySelectResult = $mysqli -> query($royaltySelectQuery);
for ($i = 0; $i < $royaltySelectResult -> num_rows; $i++) {
  $row = $royaltySelectResult -> fetch_assoc();
  $royaltyPayment[$row['payee']] = $row['payment'];
  $totalRoyaltyPayment += $row['payment'];
}

# Get commission on royalty payments
$commissionOnRoyaltySelectQuery = "select commission_receiver, coalesce(sum(payment), 0) as payment from (select commission_receiver, royalty_end_date, (commission * payment) as payment from commissions left join royalties on commissions.earner = royalties.payee where (commission_validity_start is null or royalties.royalty_start_date >= commission_validity_start) and (commission_validity_end is null or royalties.royalty_end_date <= commission_validity_end)) t1 group by commission_receiver;";
$commissionOnRoyaltySelectResult = $mysqli -> query($commissionOnRoyaltySelectQuery);
for ($i = 0; $i < $commissionOnRoyaltySelectResult -> num_rows; $i++) {
  $row = $commissionOnRoyaltySelectResult -> fetch_assoc();
  $commissionOnRoyaltyPayment[$row['commission_receiver']] = $row['payment'];
  $totalCommissionOnRoyaltyPayment += $row['payment'];
}

foreach($workerList as $worker) {
  $totalPaymentAwarded[$worker] = $taskPayment[$worker] + $commissionOnTaskPayment[$worker]  + $stipendPayment[$worker][1] + $royaltyPayment[$worker] + $commissionOnRoyaltyPayment[$worker];
  $totalPaymentAwardedAcrossWorkers += $totalPaymentAwarded[$worker];
  $totalPayment[$worker] = $totalPaymentAwarded[$worker] + $stipendPayment[$worker][0];
  $totalPaymentAcrossWorkers += $totalPayment[$worker];
}

function cmpWorkers($firstWorker, $secondWorker) {
  global $totalPayment;
  if (intval($totalPayment[$firstWorker]) == intval($totalPayment[$secondWorker])) {
      return 0;
  }
  return (intval($totalPayment[$firstWorker]) > intval($totalPayment[$secondWorker])) ? -1 : 1;
}

usort($workerList,"cmpWorkers");

# Print table
print '<table border="1">';
print '<tr><th>Type</th>';
print '<th>Payment due</th>';
print '</tr>';

print '<tr><td>Tasks</td><td align="right">'.sprintf('%.2f',$taskPayment[$worker]).'</td></tr>';
print '<tr><td>Commissions on tasks</td><td align="right">'.sprintf('%.2f',$commissionOnTaskPayment[$worker]).'</td></tr>';
print '<tr><td>Stipends awarded</td><td align="right">'.sprintf('%.2f',$stipendPayment[$worker][1]).'</td></tr>';
print '<tr><td>Royalties</td><td align="right">'.sprintf('%.2f',$royaltyPayment[$worker]).'</td></tr>';
print '<tr><td>Commissions on royalties</td><td align="right">'.sprintf('%.2f',$commissionOnRoyaltyPayment[$worker]).'</td></tr>';
print '<tr><td>Total awarded</td><td align="right"><strong>'.sprintf('%.2f',$totalPaymentAwarded[$worker]).'</strong></td></tr>';
print '<tr><td>Stipends deferred</td><td align="right">'.sprintf('%.2f',$stipendPayment[$worker][0]).'</td></tr>';
print '<tr><td><strong>Total</strong></td><td align="right"><strong>'.sprintf('%.2f',$totalPayment[$worker]).'</strong></td></tr>';

print '</table>';
?>