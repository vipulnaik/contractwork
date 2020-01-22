<?php

$earnerList = array();

$commissionOnRoyaltyByEarnerSelectQuery = "select earner, commission, commission_reason, commission_validity_start, commission_validity_end, coalesce(sum(originalPayment), 0) as originalPayment, coalesce(sum(payment), 0) as payment from (select earner, commission, commission_reason, commission_validity_start, commission_validity_end, commission_receiver, royalty_end_date, payment as originalPayment, (commission * payment) as payment from commissions left join royalties on commissions.earner = royalties.payee where (commission_validity_start is null or royalties.royalty_start_date >= commission_validity_start) and (commission_validity_end is null or royalties.royalty_end_date <= commission_validity_end)) t1 where commission_receiver=? group by earner, commission, commission_reason, commission_validity_start, commission_validity_end order by coalesce(sum(payment), 0) desc;";

$stmt = $mysqli->prepare($commissionOnRoyaltyByEarnerSelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$commissionOnRoyaltyByEarnerSelectResult = $stmt->get_result();

print '<h4 id="workerCommissionOnRoyaltyList">Commissions on royalties: breakdown by earner</h4>';
print "\n";
print '<table id="myTableWorkerCommissionOnRoyaltyList" class="tablesorter">'."\n";
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
for ($i = 0; $i < $commissionOnRoyaltyByEarnerSelectResult -> num_rows; $i++) {
  $row = $commissionOnRoyaltyByEarnerSelectResult -> fetch_assoc();
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
