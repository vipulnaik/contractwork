<?php
print '<h4 id="paymentsDueByTypeAndMonth">Payments due by type and month</h4>';

# Initialize values to zero
foreach ($monthList as $month) {
  $taskPayment[$month] = 0;
  $totalTaskPayment = 0;
  $commissionOnTaskPayment[$month] = 0;
  $totalCommissionOnTaskPayment = 0;
  $stipendPaymentAwardedInSameMonth[$month] = 0;
  $totalStipendPaymentAwardedInSameMonth = 0;
  $stipendPaymentAwardedFromEarlierMonth[$month] = 0;
  $stipendPaymentAwardedInLaterMonth[$month] = 0;
  $totalStipendPaymentStraddlingMonths = 0;
  $unawardedStipendPayment[$month] = 0;
  $totalUnawardedStipendPayment = 0;
  $royaltyPayment[$month] = 0;
  $totalRoyaltyPayment = 0;
  $commissionOnRoyaltyPayment[$month] = 0;
  $totalCommissionOnRoyaltyPayment = 0;
  $totalPaymentAwardedAcrossMonths = 0;
  $totalPaymentAcrossMonths = 0;
}  

# Get task payments

$taskSelectQuery = "select year(completion_date) as year,month(completion_date) as month, coalesce(sum(payment), 0) as payment from tasks group by year(completion_date), month(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $taskPayment[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $totalTaskPayment += $row['payment'];
}

# Get commission on task payments
$commissionOnTaskSelectQuery = "select year(completion_date) as year, month(completion_date) as month, coalesce(sum(payment), 0) as payment from (select completion_date, (commission * payment) as payment from commissions left join tasks on commissions.earner = tasks.worker where (commission_validity_start is null or tasks.completion_date >= commission_validity_start) and (commission_validity_end is null or tasks.completion_date <= commission_validity_end)) t1 group by year(completion_date), month(completion_date);";
$commissionOnTaskSelectResult = $mysqli -> query($commissionOnTaskSelectQuery);
for ($i = 0; $i < $commissionOnTaskSelectResult -> num_rows; $i++) {
  $row = $commissionOnTaskSelectResult -> fetch_assoc();
  $commissionOnTaskPayment[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $totalCommissionOnTaskPayment += $row['payment'];
}

# Get stipend payments

$stipendSelectQuery = "select year(stipend_award_date) as awardYear, month(stipend_award_date) as awardMonth, year(stipend_end_date) as year, month(stipend_end_date) as month, (stipend_award_date is not null) as awarded, coalesce(sum(payment), 0) as payment  from stipends group by year(stipend_award_date), month(stipend_award_date), year(stipend_end_date), month(stipend_end_date), (stipend_award_date is not null);";
$stipendSelectResult = $mysqli -> query($stipendSelectQuery);
for ($i = 0; $i < $stipendSelectResult -> num_rows; $i++) {
  $row = $stipendSelectResult -> fetch_assoc();
  if ($row['awarded'] == 1 and $row['awardYear'] == $row['year'] and $row['awardMonth'] == $row['month']) {
    $stipendPaymentAwardedInSameMonth[$row['year'] . '-' . sprintf('%02d', $row['month'])] += $row['payment'];
    $totalStipendPaymentAwardedInSameMonth += $row['payment'];
  } else if ($row['awarded'] == 1) {
    $stipendPaymentAwardedInLaterMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] += $row['payment'];
    $stipendPaymentAwardedFromEarlierMonth[$row['awardYear'] . '-' . sprintf('%02d',$row['awardMonth'])] += $row['payment'];
    $totalStipendPaymentStraddlingMonths += $row['payment'];
  } else {
    $unawardedStipendPayment[$row['year'] . '-' . sprintf('%02d',$row['month'])] += $row['payment'];
    $totalUnawardedStipendPayment += $row['payment'];
  }
}

# Get royalty payments
$royaltySelectQuery = "select year(royalty_end_date) as year, month(royalty_end_date) as month, coalesce(sum(payment), 0) as payment from royalties group by year(royalty_end_date), month(royalty_end_date);";
$royaltySelectResult = $mysqli -> query($royaltySelectQuery);
for ($i = 0; $i < $royaltySelectResult -> num_rows; $i++) {
  $row = $royaltySelectResult -> fetch_assoc();
  $royaltyPayment[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $totalRoyaltyPayment += $row['payment'];
}

# Get commission on royalty payments
$commissionOnRoyaltySelectQuery = "select year(royalty_end_date) as year, month(royalty_end_date) as month, coalesce(sum(payment), 0) as payment from (select royalty_end_date, (commission * payment) as payment from commissions left join royalties on commissions.earner = royalties.payee where (commission_validity_start is null or royalties.royalty_start_date >= commission_validity_start) and (commission_validity_end is null or royalties.royalty_end_date <= commission_validity_end)) t1 group by year(royalty_end_date), month(royalty_end_date);";
$commissionOnRoyaltySelectResult = $mysqli -> query($commissionOnRoyaltySelectQuery);
for ($i = 0; $i < $commissionOnRoyaltySelectResult -> num_rows; $i++) {
  $row = $commissionOnRoyaltySelectResult -> fetch_assoc();
  $commissionOnRoyaltyPayment[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $totalCommissionOnRoyaltyPayment  += $row['payment'];
}

foreach($monthList as $month) {
  $totalPaymentAwarded[$month] = 0;
  $totalPayment[$month] = 0;
  $totalPaymentAwarded[$month] = $taskPayment[$month] + $commissionOnTaskPayment[$month]  + $stipendPaymentAwardedInSameMonth[$month] + $stipendPaymentAwardedFromEarlierMonth[$month] + $royaltyPayment[$month] + $commissionOnRoyaltyPayment[$month];
  $totalPaymentAwardedAcrossMonths += $totalPaymentAwarded[$month];
  $totalPayment[$month] = $totalPaymentAwarded[$month] + $stipendPaymentAwardedInLaterMonth[$month] - $stipendPaymentAwardedFromEarlierMonth[$month] + $unawardedStipendPayment[$month];
  $totalPaymentAcrossMonths += $totalPayment[$month];
}

# Print table
print "\n";
print '<table id="myTablePaymentsDueByTypeAndMonth" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Month</th>';
print '<th>Task payments</th>';
print '<th>Commissions on task payments</th>';
print '<th>Stipend payments (awarded same month)</th>';
if ($totalStipendPaymentStraddlingMonths > 0) {
  print '<th>Stipend payments (awarded from earlier)</th>';
}
print '<th>Royalty payments</th>';
print '<th>Commissions on royalty payments</th>';
print '<th>Total payment awarded</th>';
print '<th>Stipend payments (deferred)</th>';
if ($totalStipendPaymentStraddlingMonths > 0) {
  print '<th>Stipend payments (awarded later)</th>';
}
print '<th>Total payment</th>';
print '</tr>';
print "</thead>\n<tbody>\n";

foreach (array_reverse($monthList) as $month) {
  print "<tr><td>$month</td>";
  print '<td align="right">'.sprintf('%.2f',$taskPayment[$month]).'</td>';
  print '<td align="right">'.sprintf('%.2f',$commissionOnTaskPayment[$month]).'</td>';
  print '<td align="right">'.sprintf('%.2f',$stipendPaymentAwardedInSameMonth[$month]).'</td>';
  if ($totalStipendPaymentStraddlingMonths > 0) {
    print '<td align="right">'.sprintf('%.2f',$stipendPaymentAwardedFromEarlierMonth[$month]).'</td>';
  }
  print '<td align="right">'.sprintf('%.2f',$royaltyPayment[$month]).'</td>';
  print '<td align="right">'.sprintf('%.2f',$commissionOnRoyaltyPayment[$month]).'</td>';
  print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentAwarded[$month]).'</strong></td>';
  print '<td align="right">'.sprintf('%.2f',$unawardedStipendPayment[$month]).'</td>';
  if ($totalStipendPaymentStraddlingMonths > 0) {
    print '<td align="right">'.sprintf('%.2f',$stipendPaymentAwardedInLaterMonth[$month]).'</td>';
  }
  print '<td align="right"><strong>'.sprintf('%.2f',$totalPayment[$month]).'</strong></td>';
  print '</tr>';
}

print "</tbody>\n<tfoot>\n";
print '<tr><td><strong>Total across months</strong></td>';
print '<td align="right"><strong>'.sprintf('%.2f',$totalTaskPayment).'</td>';
print '<td align="right"><strong>'.sprintf('%.2f',$totalCommissionOnTaskPayment).'</td>';
print '<td align="right"><strong>'.sprintf('%.2f',$totalStipendPaymentAwardedInSameMonth).'</td>';
if ($totalStipendPaymentStraddlingMonths > 0) {
  print '<td align="right"><strong>'.sprintf('%.2f',$totalStipendPaymentStraddlingMonths).'</td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$totalRoyaltyPayment).'</td>';
print '<td align="right"><strong>'.sprintf('%.2f',$totalCommissionOnRoyaltyPayment).'</td>';
print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentAwardedAcrossMonths).'</td>';
print '<td align="right"><strong>'.sprintf('%.2f',$totalUnawardedStipendPayment).'</td>';
if ($totalStipendPaymentStraddlingMonths > 0) {
  print '<td align="right"><strong>'.sprintf('%.2f',$totalStipendPaymentStraddlingMonths).'</td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentAcrossMonths).'</td>';
print "</tr>\n";
print "</tfoot>\n</table>\n";
?>