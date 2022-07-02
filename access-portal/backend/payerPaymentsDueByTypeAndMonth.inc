<?php
if ($printTables == true) {
  print '<h4 id="payerPaymentsDueByTypeAndMonth">Payer payments due by type and month</h4>';
}

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

$taskSelectQuery = "select year(completion_date) as year,month(completion_date) as month, coalesce(sum(payment), 0) as payment from tasks where payer=? group by year(completion_date), month(completion_date);";
$stmt = $mysqli->prepare($taskSelectQuery);
$stmt->bind_param("s", $payer);
$stmt->execute();
$taskSelectResult = $stmt->get_result();
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $taskPayment[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $totalTaskPayment += $row['payment'];
}

# Get commission on task payments (only supported for Vipul Naik)
if ($payer == "Vipul Naik") {
  $commissionOnTaskSelectQuery = "select year(completion_date) as year, month(completion_date) as month, coalesce(sum(payment), 0) as payment from (select commission_receiver, completion_date, (commission * payment) as payment from commissions left join tasks on commissions.earner = tasks.worker where (commission_validity_start is null or tasks.completion_date >= commission_validity_start) and (commission_validity_end is null or tasks.completion_date <= commission_validity_end)) t1 group by year(completion_date), month(completion_date);";
  # Note: we're using statement execution rather than query because it seems to give more precision and will be consistent with other pages (for this particular query, sub-cent precision is relevant)
  $stmt = $mysqli->prepare($commissionOnTaskSelectQuery);
  $stmt->execute();
  $commissionOnTaskSelectResult = $stmt->get_result();
  for ($i = 0; $i < $commissionOnTaskSelectResult -> num_rows; $i++) {
    $row = $commissionOnTaskSelectResult -> fetch_assoc();
    $commissionOnTaskPayment[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
    $totalCommissionOnTaskPayment += $row['payment'];
  }
}

# Get stipend payments
$stipendSelectQuery = "select year(stipend_award_date) as awardYear, month(stipend_award_date) as awardMonth, year(stipend_end_date) as year, month(stipend_end_date) as month, (stipend_award_date is not null) as awarded, coalesce(sum(payment), 0) as payment from stipends where payer=? group by year(stipend_award_date), month(stipend_award_date), year(stipend_end_date), month(stipend_end_date), (stipend_award_date is not null);";
$stmt = $mysqli->prepare($stipendSelectQuery);
$stmt->bind_param("s", $payer);
$stmt->execute();
$stipendSelectResult = $stmt->get_result();
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

# Get royalty payments (only supported for Vipul Naik)
if ($payer == "Vipul Naik") {
  $royaltySelectQuery = "select year(royalty_end_date) as year, month(royalty_end_date) as month, coalesce(sum(payment), 0) as payment from royalties group by year(royalty_end_date), month(royalty_end_date);";
  $royaltySelectResult = $mysqli -> query($royaltySelectQuery);
  for ($i = 0; $i < $royaltySelectResult -> num_rows; $i++) {
    $row = $royaltySelectResult -> fetch_assoc();
    $royaltyPayment[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
    $totalRoyaltyPayment += $row['payment'];
  }
}

# Get commission on royalty payments (only supported for Vipul Naik)
if ($payer == "Vipul Naik") {
  $commissionOnRoyaltySelectQuery = "select year(royalty_end_date) as year, month(royalty_end_date) as month, coalesce(sum(payment), 0) as payment from (select royalty_end_date, (commission * payment) as payment from commissions left join royalties on commissions.earner = royalties.payee where (commission_validity_start is null or royalties.royalty_start_date >= commission_validity_start) and (commission_validity_end is null or royalties.royalty_end_date <= commission_validity_end)) t1 group by year(royalty_end_date), month(royalty_end_date);";
  # Note: we're using statement execution rather than query because it seems to give more precision and will be consistent with other pages (for this particular query, sub-cent precision is relevant)
  $stmt=$mysqli->prepare($commissionOnRoyaltySelectQuery);
  $stmt->execute();
  $commissionOnRoyaltySelectResult = $stmt->get_result();
  for ($i = 0; $i < $commissionOnRoyaltySelectResult -> num_rows; $i++) {
    $row = $commissionOnRoyaltySelectResult -> fetch_assoc();
    $commissionOnRoyaltyPayment[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
    $totalCommissionOnRoyaltyPayment += $row['payment'];
  }
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
if ($printTables == true) {
  print "\n";
  print '<table id="myTablePayerPaymentsDueByTypeAndMonth" class="tablesorter">'."\n";
  print "<thead>\n";
  print '<tr><th>Month</th>';
  print '<th>Task payments</th>';
  if ($payer == "Vipul Naik") {
    print '<th>Commissions on task payments</th>';
  }
  print '<th>Stipend payments (awarded same month)</th>';
  if ($totalStipendPaymentStraddlingMonths > 0) {
    print '<th>Stipend payments (awarded from earlier)</th>';
  }
  if ($payer == "Vipul Naik") {
    print '<th>Royalty payments</th>';
    print '<th>Commissions on royalty payments</th>';
  }
  print '<th>Total payment awarded</th>';
  print '<th>Stipend payments (deferred)</th>';
  if ($totalStipendPaymentStraddlingMonths > 0) {
    print '<th>Stipend payments (awarded later)</th>';
  }
  if ($totalStipendPaymentStraddlingMonths > 0) {
    print '<th>Stipend payments (awarded from earlier; subtract)</th>';
  }
  print '<th>Total payment</th>';
  print '</tr>';
  print "</thead>\n<tbody>\n";
  foreach (array_reverse($monthList) as $month) {
    if ($totalPayment[$month] > 0) {
      print "<tr><td>$month</td>";
      print '<td align="right">'.number_format($taskPayment[$month],2).'</td>';
      if ($payer == "Vipul Naik") {
        print '<td align="right">'.number_format($commissionOnTaskPayment[$month],2).'</td>';
      }
      print '<td align="right">'.number_format($stipendPaymentAwardedInSameMonth[$month],2).'</td>';
      if ($totalStipendPaymentStraddlingMonths > 0) {
        print '<td align="right">'.number_format($stipendPaymentAwardedFromEarlierMonth[$month],2).'</td>';
      }
      if ($payer == "Vipul Naik") {
        print '<td align="right">'.number_format($royaltyPayment[$month],2).'</td>';
        print '<td align="right">'.number_format($commissionOnRoyaltyPayment[$month],2).'</td>';
      }
      print '<td align="right"><strong>'.number_format($totalPaymentAwarded[$month],2).'</strong></td>';
      print '<td align="right">'.number_format($unawardedStipendPayment[$month],2).'</td>';
      if ($totalStipendPaymentStraddlingMonths > 0) {
        print '<td align="right">'.number_format($stipendPaymentAwardedInLaterMonth[$month],2).'</td>';
      }
      if ($totalStipendPaymentStraddlingMonths > 0) {
        print '<td align="right">'.number_format(-$stipendPaymentAwardedFromEarlierMonth[$month],2).'</td>';
      }
      print '<td align="right"><strong>'.number_format($totalPayment[$month],2).'</strong></td>';
      print '</tr>';
    }
  }

  print "</tbody>\n<tfoot>\n";
  print '<tr><td><strong>Total across months</strong></td>';
  print '<td align="right"><strong>'.number_format($totalTaskPayment,2).'</td>';
  if ($payer == "Vipul Naik") {
    print '<td align="right"><strong>'.number_format($totalCommissionOnTaskPayment,2).'</td>';
  }
  print '<td align="right"><strong>'.number_format($totalStipendPaymentAwardedInSameMonth,2).'</td>';
  if ($totalStipendPaymentStraddlingMonths > 0) {
    print '<td align="right"><strong>'.number_format($totalStipendPaymentStraddlingMonths,2).'</strong></td>';
  }
  if ($payer == "Vipul Naik") {
    print '<td align="right"><strong>'.number_format($totalRoyaltyPayment,2).'</td>';
    print '<td align="right"><strong>'.number_format($totalCommissionOnRoyaltyPayment,2).'</td>';
  }
  print '<td align="right"><strong>'.number_format($totalPaymentAwardedAcrossMonths,2).'</td>';
  print '<td align="right"><strong>'.number_format($totalUnawardedStipendPayment,2).'</td>';
  if ($totalStipendPaymentStraddlingMonths > 0) {
    print '<td align="right"><strong>'.number_format($totalStipendPaymentStraddlingMonths,2).'</strong></td>';
  }
  if ($totalStipendPaymentStraddlingMonths > 0) {
    print '<td align="right"><strong>'.number_format(-$totalStipendPaymentStraddlingMonths,2).'</strong></td>';
  }
  print '<td align="right"><strong>'.number_format($totalPaymentAcrossMonths,2).'</td>';
  print '</tr>';
  
  print "</tfoot>\n</table>\n";
}
?>
