<?php
print '<h4>Worker payments due by type and year</h4>';

# Initialize values to zero
foreach ($yearList as $year) {
  $taskPayment[$year] = 0;
  $totalTaskPayment = 0;
  $commissionOnTaskPayment[$year] = 0;
  $totalCommissionOnTaskPayment = 0;
  $stipendPayment[$year][0] = 0;
  $totalStipendPayment[0] = 0;
  $stipendPayment[$year][1] = 0;
  $totalStipendPayment[1] = 0;
  $royaltyPayment[$year] = 0;
  $totalRoyaltyPayment = 0;
  $commissionOnRoyaltyPayment[$year] = 0;
  $totalCommissionOnRoyaltyPayment = 0;
  $totalPaymentAwardedAcrossYears = 0;
  $totalPaymentAcrossYears = 0;
}  

# Get task payments

$taskSelectQuery = "select year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks where worker='$worker' group by year(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $taskPayment[$row['year']] = $row['payment'];
  $totalTaskPayment += $row['payment'];
}

# Get commission on task payments
$commissionOnTaskSelectQuery = "select year(completion_date) as year, coalesce(sum(payment), 0) as payment from (select commission_receiver, completion_date, (commission * payment) as payment from commissions left join tasks on commissions.earner = tasks.worker where (commission_validity_start is null or tasks.completion_date >= commission_validity_start) and (commission_validity_end is null or tasks.completion_date <= commission_validity_end)) t1 where commission_receiver='$worker' group by year(completion_date);";
$commissionOnTaskSelectResult = $mysqli -> query($commissionOnTaskSelectQuery);
for ($i = 0; $i < $commissionOnTaskSelectResult -> num_rows; $i++) {
  $row = $commissionOnTaskSelectResult -> fetch_assoc();
  $commissionOnTaskPayment[$row['year']] = $row['payment'];
  $totalCommissionOnTaskPayment += $row['payment'];
}

# Get stipend payments

$stipendSelectQuery = "select year(stipend_end_date) as year, (stipend_award_date is not null) as awarded, coalesce(sum(payment), 0) as payment  from stipends where payee='$worker' group by year(stipend_end_date), (stipend_award_date is not null);";
$stipendSelectResult = $mysqli -> query($stipendSelectQuery);
for ($i = 0; $i < $stipendSelectResult -> num_rows; $i++) {
  $row = $stipendSelectResult -> fetch_assoc();
  $stipendPayment[$row['year']][$row['awarded']] = $row['payment'];
  $totalStipendPayment[$row['awarded']] += $row['payment'];
}

# Get royalty payments
$royaltySelectQuery = "select year(royalty_end_date) as year, coalesce(sum(payment), 0) as payment from royalties where payee='$worker' group by year(royalty_end_date);";
$royaltySelectResult = $mysqli -> query($royaltySelectQuery);
for ($i = 0; $i < $royaltySelectResult -> num_rows; $i++) {
  $row = $royaltySelectResult -> fetch_assoc();
  $royaltyPayment[$row['year']] = $row['payment'];
  $totalRoyaltyPayment += $row['payment'];
}

# Get commission on royalty payments
$commissionOnRoyaltySelectQuery = "select year(royalty_end_date) as year, coalesce(sum(payment), 0) as payment from (select commission_receiver, royalty_end_date, (commission * payment) as payment from commissions left join royalties on commissions.earner = royalties.payee where (commission_validity_start is null or royalties.royalty_start_date >= commission_validity_start) and (commission_validity_end is null or royalties.royalty_end_date <= commission_validity_end)) t1 where commission_receiver='$worker' group by year(royalty_end_date);";
$commissionOnRoyaltySelectResult = $mysqli -> query($commissionOnRoyaltySelectQuery);
for ($i = 0; $i < $commissionOnRoyaltySelectResult -> num_rows; $i++) {
  $row = $commissionOnRoyaltySelectResult -> fetch_assoc();
  $commissionOnRoyaltyPayment[$row['year']] = $row['payment'];
  $totalCommissionOnRoyaltyPayment += $row['payment'];
}

foreach($yearList as $year) {
  $totalPaymentAwarded[$year] = 0;
  $totalPayment[$year] = 0;
  $totalPaymentAwarded[$year] = $taskPayment[$year] + $commissionOnTaskPayment[$year]  + $stipendPayment[$year][1] + $royaltyPayment[$year] + $commissionOnRoyaltyPayment[$year];
  $totalPaymentAwardedAcrossYears += $totalPaymentAwarded[$year];
  $totalPayment[$year] = $totalPaymentAwarded[$year] + $stipendPayment[$year][0];
  $totalPaymentAcrossYears += $totalPayment[$year];
}

# Print table
print '<table border="1">';
print '<tr><th>Type of payment due</th>';
foreach ($yearList as $year) {
  print "<th>Total in year $year</th>";
}
print '<th>Total across years</th></tr>';
print '<tr><td>Tasks</td>';
foreach ($yearList as $year) {
  print '<td align="right">'.sprintf('%.2f',$taskPayment[$year]).'</td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$totalTaskPayment).'</strong></td>';
print '</tr>';
print '<tr><td>Commissions on tasks</td>';
foreach ($yearList as $year) {
  print '<td align="right">'.sprintf('%.2f',$commissionOnTaskPayment[$year]).'</td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$totalCommissionOnTaskPayment).'</strong></td>';
print '</tr>';
print '<tr><td>Stipends (awarded)</td>';
foreach ($yearList as $year) {
  print '<td align="right">'.sprintf('%.2f',$stipendPayment[$year][1]).'</td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$totalStipendPayment[1]).'</strong></td>';
print '</tr>';
print '<tr><td>Royalties</td>';
foreach ($yearList as $year) {
  print '<td align="right">'.sprintf('%.2f',$royaltyPayment[$year]).'</td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$totalRoyaltyPayment).'</strong></td>';
print '</tr>';
print '<tr><td>Commissions on royalties</td>';
foreach ($yearList as $year) {
  print '<td align="right">'.sprintf('%.2f',$commissionOnRoyaltyPayment[$year]).'</td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$totalCommissionOnRoyaltyPayment).'</strong></td>';
print '</tr>';
print '<tr><td><strong>Total payment awarded</strong></td>';
foreach ($yearList as $year) {
  print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentAwarded[$year]).'</strong></td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentAwardedAcrossYears).'</strong></td>';
print '</tr>';
print '<tr><td>Stipends (deferred)</td>';
foreach ($yearList as $year) {
  print '<td align="right">'.sprintf('%.2f',$stipendPayment[$year][0]).'</td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$totalStipendPayment[0]).'</strong></td>';
print '</tr>';
print '<tr><td><strong>Total payment</strong></td>';
foreach ($yearList as $year) {
  print '<td align="right"><strong>'.sprintf('%.2f',$totalPayment[$year]).'</strong></td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentAcrossYears).'</strong></td>';
print '</tr>';

print '</table>';
?>