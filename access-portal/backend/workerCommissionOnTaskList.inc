<?php

$earnerList = array();

$commissionOnTaskByEarnerSelectQuery = "select earner, commission, commission_reason, commission_validity_start, commission_validity_end, coalesce(sum(originalPayment), 0) as originalPayment, coalesce(sum(payment), 0) as payment from (select earner, commission_receiver, completion_date, commission, commission_reason, commission_validity_start, commission_validity_end, payment as originalPayment, (commission * payment) as payment from commissions left join tasks on commissions.earner = tasks.worker where (commission_validity_start is null or tasks.completion_date >= commission_validity_start) and (commission_validity_end is null or tasks.completion_date <= commission_validity_end)) t1 where commission_receiver=? group by earner, commission, commission_reason, commission_validity_start, commission_validity_end order by coalesce(sum(payment), 0) desc;";

$stmt = $mysqli->prepare($commissionOnTaskByEarnerSelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$commissionOnTaskByEarnerSelectResult = $stmt->get_result();

print '<h4 id="workerCommissionOnTaskList">Commissions on tasks: breakdown by earner</h4>'."\n";
print "\n";
print '<table id="myTableWorkerCommissionOnTaskList" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr>';
print '<th>Underlying earner</th>';
print '<th>Commission validity period</th>';
print '<th>Commission reason</th>';
print '<th>Commission rate</th>';
print '<th>Payment due to original earner</th>';
print '<th>Commission payment</th>';
print '</tr>';
print "</thead>\n<tbody>\n";
for ($i = 0; $i < $commissionOnTaskByEarnerSelectResult -> num_rows; $i++) {
  $row = $commissionOnTaskByEarnerSelectResult -> fetch_assoc();
  array_push($earnerList, $row['earner']);
  print '<tr>';
  print '<td><a href="http://contractwork.vipulnaik.com/worker.php?worker='.urlencode($row['earner']).'">'.$row['earner'].'</a></td>';
  print '<td>'.$row['commission_validity_start'];
  if ($row['commission_validity_end'] == '') {
    print ' onward';
  } else {
    print '–'.$row['commission_validity_end'].'</td>';
  }
  print '<td>'.$row['commission_reason'].'</td>';
  print '<td align="right">'.($row['commission'] * 100).'%</td>';
  print '<td align="right">'.number_format($row['originalPayment'],2).'</td>';
  print '<td align="right">'.number_format($row['payment'],2).'</td>';
  print '</tr>';
}
print "</tbody>\n</table>\n";
?>
