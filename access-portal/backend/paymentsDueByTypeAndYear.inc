<?php
print '<h4 id="paymentsDueByTypeAndYear">Payments due by type and year</h4>';

# Initialize values to zero
foreach ($yearList as $year) {
  $taskPayment[$year]["Vipul Naik"] = 0;
  $taskPayment[$year]["Peter Hurford"] = 0;
  $totalTaskPayment["Vipul Naik"] = 0;
  $totalTaskPayment["Peter Hurford"] = 0;
  $commissionOnTaskPayment[$year] = 0;
  $totalCommissionOnTaskPayment = 0;
  $stipendPaymentAwardedInSameYear[$year] = 0;
  $totalStipendPaymentAwardedInSameYear = 0;
  $stipendPaymentAwardedFromEarlierYear[$year] = 0;
  $stipendPaymentAwardedInLaterYear[$year] = 0;
  $totalStipendPaymentStraddlingYears = 0;
  $unawardedStipendPayment[$year] = 0;
  $totalUnawardedStipendPayment = 0;
  $royaltyPayment[$year] = 0;
  $totalRoyaltyPayment = 0;
  $commissionOnRoyaltyPayment[$year] = 0;
  $totalCommissionOnRoyaltyPayment = 0;
  $totalPaymentAwardedAcrossYears = 0;
  $totalPaymentAcrossYears = 0;
}  

# Get task payments

$taskSelectQuery = "select payer, year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks group by payer, year(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $taskPayment[$row['year']][$row['payer']] = $row['payment'];
  $totalTaskPayment[$row['payer']] += $row['payment'];
}

# Get commission on task payments
$commissionOnTaskSelectQuery = "select year(completion_date) as year, coalesce(sum(payment), 0) as payment from (select completion_date, (commission * payment) as payment from commissions left join tasks on commissions.earner = tasks.worker where (commission_validity_start is null or tasks.completion_date >= commission_validity_start) and (commission_validity_end is null or tasks.completion_date <= commission_validity_end)) t1 group by year(completion_date);";
$commissionOnTaskSelectResult = $mysqli -> query($commissionOnTaskSelectQuery);
for ($i = 0; $i < $commissionOnTaskSelectResult -> num_rows; $i++) {
  $row = $commissionOnTaskSelectResult -> fetch_assoc();
  $commissionOnTaskPayment[$row['year']] = $row['payment'];
  $totalCommissionOnTaskPayment += $row['payment'];
}

# Get stipend payments

$stipendSelectQuery = "select year(stipend_award_date) as awardYear, year(stipend_end_date) as year, (stipend_award_date is not null) as awarded, coalesce(sum(payment), 0) as payment  from stipends group by year(stipend_award_date), year(stipend_end_date), (stipend_award_date is not null);";
$stipendSelectResult = $mysqli -> query($stipendSelectQuery);
for ($i = 0; $i < $stipendSelectResult -> num_rows; $i++) {
  $row = $stipendSelectResult -> fetch_assoc();
  if ($row['awarded'] == 1 and $row['awardYear'] == $row['year']) {
    $stipendPaymentAwardedInSameYear[$row['year']] += $row['payment'];
    $totalStipendPaymentAwardedInSameYear += $row['payment'];
  } else if ($row['awarded'] == 1) {
    $stipendPaymentAwardedInLaterYear[$row['year']] += $row['payment'];
    $stipendPaymentAwardedFromEarlierYear[$row['awardYear']] += $row['payment'];
    $totalStipendPaymentStraddlingYears += $row['payment'];
  } else {
    $unawardedStipendPayment[$row['year']] += $row['payment'];
    $totalUnawardedStipendPayment += $row['payment'];
  }
}

# Get royalty payments
$royaltySelectQuery = "select year(royalty_end_date) as year, coalesce(sum(payment), 0) as payment from royalties group by year(royalty_end_date);";
$royaltySelectResult = $mysqli -> query($royaltySelectQuery);
for ($i = 0; $i < $royaltySelectResult -> num_rows; $i++) {
  $row = $royaltySelectResult -> fetch_assoc();
  $royaltyPayment[$row['year']] = $row['payment'];
  $totalRoyaltyPayment += $row['payment'];
}

# Get commission on royalty payments
$commissionOnRoyaltySelectQuery = "select year(royalty_end_date) as year, coalesce(sum(payment), 0) as payment from (select royalty_end_date, (commission * payment) as payment from commissions left join royalties on commissions.earner = royalties.payee where (commission_validity_start is null or royalties.royalty_start_date >= commission_validity_start) and (commission_validity_end is null or royalties.royalty_end_date <= commission_validity_end)) t1 group by year(royalty_end_date);";
$commissionOnRoyaltySelectResult = $mysqli -> query($commissionOnRoyaltySelectQuery);
for ($i = 0; $i < $commissionOnRoyaltySelectResult -> num_rows; $i++) {
  $row = $commissionOnRoyaltySelectResult -> fetch_assoc();
  $commissionOnRoyaltyPayment[$row['year']] = $row['payment'];
  $totalCommissionOnRoyaltyPayment += $row['payment'];
}

foreach($yearList as $year) {
  $totalPaymentAwarded[$year] = 0;
  $totalPayment[$year] = 0;
  $totalPaymentAwarded[$year] = $taskPayment[$year]["Vipul Naik"] + $taskPayment[$year]["Peter Hurford"] + $commissionOnTaskPayment[$year]  + $stipendPaymentAwardedInSameYear[$year] + $stipendPaymentAwardedFromEarlierYear[$year] + $royaltyPayment[$year] + $commissionOnRoyaltyPayment[$year];
  $totalPaymentAwardedAcrossYears += $totalPaymentAwarded[$year];
  $totalPayment[$year] = $totalPaymentAwarded[$year] + $stipendPaymentAwardedInLaterYear[$year] - $stipendPaymentAwardedFromEarlierYear[$year] + $unawardedStipendPayment[$year];
  $totalPaymentAcrossYears += $totalPayment[$year];
}

# Print table
print "\n";
print '<table id="myTablePaymentsDueByTypeAndYear" class="tablesorter">'."\n";
print "<thead>\n<tr>\n	<th>Type of payment due</th>\n";
foreach (array_reverse($yearList) as $year) {
  print "	<th>Total in year $year</th>\n";
}
print "	<th>Total across years</th>\n</tr>\n";
print "</thead>\n<tbody>\n";
foreach (array("Vipul Naik", "Peter Hurford") as $payer) {
  if ($totalTaskPayment[$payer] > 0) {
    print "<tr>\n	<td>Tasks for $payer</td>\n";
    foreach (array_reverse($yearList) as $year) {
      print '	<td align="right">'.sprintf('%.2f',$taskPayment[$year][$payer])."</td>\n";
    }
    print '	<td align="right"><strong>'.sprintf('%.2f',$totalTaskPayment[$payer])."</strong></td>\n";
    print "</tr>\n";
  }
}
print "<tr>\n	<td>Commissions on tasks</td>\n";
foreach (array_reverse($yearList) as $year) {
  print '	<td align="right">'.sprintf('%.2f',$commissionOnTaskPayment[$year])."</td>\n";
}
print '	<td align="right"><strong>'.sprintf('%.2f',$totalCommissionOnTaskPayment)."</strong></td>\n";
print "</tr>\n";
print "<tr>\n	<td>Stipends (awarded same year)</td>\n";
foreach (array_reverse($yearList) as $year) {
  print '	<td align="right">'.sprintf('%.2f',$stipendPaymentAwardedInSameYear[$year])."</td>\n";
}
print '	<td align="right"><strong>'.sprintf('%.2f',$totalStipendPaymentAwardedInSameYear)."</strong></td>\n";
print "</tr>\n";
if ($totalStipendPaymentStraddlingYears > 0) {
  print "<tr>\n	<td>Stipends (awarded from earlier year)</td>\n";
  foreach (array_reverse($yearList) as $year) {
    print '	<td align="right">'.sprintf('%.2f',$stipendPaymentAwardedFromEarlierYear[$year])."</td>\n";
  }
  print '	<td align="right"><strong>'.sprintf('%.2f',$totalStipendPaymentStraddlingYears)."</strong></td>\n";
  print "</tr>\n";
}
print '<tr><td>Royalties</td>';
foreach (array_reverse($yearList) as $year) {
  print '	<td align="right">'.sprintf('%.2f',$royaltyPayment[$year])."</td>\n";
}
print '	<td align="right"><strong>'.sprintf('%.2f',$totalRoyaltyPayment)."</strong></td>\n";
print "</tr>\n";
print "<tr>\n	<td>Commissions on royalties</td>\n";
foreach (array_reverse($yearList) as $year) {
  print '	<td align="right">'.sprintf('%.2f',$commissionOnRoyaltyPayment[$year])."</td>\n";
}
print '	<td align="right"><strong>'.sprintf('%.2f',$totalCommissionOnRoyaltyPayment)."</strong></td>\n";
print "</tr>\n";
print "<tr>\n	<td><strong>Total payment awarded</strong></td>\n";
foreach (array_reverse($yearList) as $year) {
  print '	<td align="right"><strong>'.sprintf('%.2f',$totalPaymentAwarded[$year])."</strong></td>\n";
}
print '	<td align="right"><strong>'.sprintf('%.2f',$totalPaymentAwardedAcrossYears)."</strong></td>\n";
print "</tr>\n";
print "<tr>\n	<td>Stipends (unawarded)</td>\n";
foreach (array_reverse($yearList) as $year) {
  print '	<td align="right">'.sprintf('%.2f',$unawardedStipendPayment[$year])."</td>\n";
}
print '	<td align="right"><strong>'.sprintf('%.2f',$totalUnawardedStipendPayment)."</strong></td>\n";
print "</tr>\n";
if ($totalStipendPaymentStraddlingYears > 0) {
  print "<tr>\n	<td>Stipends (deferred to later year)</td>\n";
  foreach (array_reverse($yearList) as $year) {
    print '	<td align="right">'.sprintf('%.2f',$stipendPaymentAwardedInLaterYear[$year])."</td>\n";
  }
  print '	<td align="right"><strong>'.sprintf('%.2f',$totalStipendPaymentStraddlingYears)."</strong></td>\n";
  print "</tr>\n";
}
print "</tbody>\n<tfoot>\n";
print "<tr>\n	<td><strong>Total payment</strong></td>\n";
foreach (array_reverse($yearList) as $year) {
  print '	<td align="right"><strong>'.sprintf('%.2f',$totalPayment[$year])."</strong></td>\n";
}
print '	<td align="right"><strong>'.sprintf('%.2f',$totalPaymentAcrossYears)."</strong></td>\n";
print "</tr>\n";
print "</tfoot>\n";
print "</table>\n";
?>