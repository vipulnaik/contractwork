<?php
print '<h4 id="payerPaymentsDueByTypeAndYear">Payer payments due by type and year</h4>';

$totalCommissionOnTaskPayment = 0;
$totalStipendPaymentAwardedInSameYear = 0;
$totalStipendPaymentStraddlingYears = 0;
$totalUnawardedStipendPayment = 0;
$totalRoyaltyPayment = 0;
$totalPaymentAcrossYears = 0;
$totalTaskPayment = 0;

# Initialize values to zero
foreach ($yearList as $year) {
  $taskPayment[$year] = 0;
  $commissionOnTaskPayment[$year] = 0;
  $stipendPaymentAwardedInSameYear[$year] = 0;
  $stipendPaymentAwardedFromEarlierYear[$year] = 0;
  $stipendPaymentAwardedInLaterYear[$year] = 0;
  $unawardedStipendPayment[$year] = 0;
  $royaltyPayment[$year] = 0;
  $commissionOnRoyaltyPayment[$year] = 0;
  $totalCommissionOnRoyaltyPayment = 0;
  $totalPaymentAwardedAcrossYears = 0;
}  

# Get task payments

$taskSelectQuery = "select year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks where payer=? group by year(completion_date);";
$stmt = $mysqli->prepare($taskSelectQuery);
$stmt->bind_param("s", $payer);
$stmt->execute();
$taskSelectResult = $stmt->get_result();
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $taskPayment[$row['year']] = $row['payment'];
  $totalTaskPayment += $row['payment'];
}

# Get commission on task payments
if ($payer == "Vipul Naik") {
  $commissionOnTaskSelectQuery = "select year(completion_date) as year, coalesce(sum(payment), 0) as payment from (select completion_date, (commission * payment) as payment from commissions left join tasks on commissions.earner = tasks.worker where (commission_validity_start is null or tasks.completion_date >= commission_validity_start) and (commission_validity_end is null or tasks.completion_date <= commission_validity_end)) t1 group by year(completion_date);";
  $commissionOnTaskSelectResult = $mysqli -> query($commissionOnTaskSelectQuery);
  for ($i = 0; $i < $commissionOnTaskSelectResult -> num_rows; $i++) {
    $row = $commissionOnTaskSelectResult -> fetch_assoc();
    $commissionOnTaskPayment[$row['year']] = $row['payment'];
    $totalCommissionOnTaskPayment += $row['payment'];
  }
}

# Get stipend payments

$stipendSelectQuery = "select year(stipend_award_date) as awardYear, year(stipend_end_date) as year, (stipend_award_date is not null) as awarded, coalesce(sum(payment), 0) as payment  from stipends where payer=? group by year(stipend_award_date), year(stipend_end_date), (stipend_award_date is not null);";
$stmt = $mysqli->prepare($stipendSelectQuery);
$stmt->bind_param("s", $payer);
$stmt->execute();
$stipendSelectResult = $stmt->get_result();
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

if ($payer == "Vipul Naik") {
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
  $stmt = $mysqli->prepare($commissionOnRoyaltySelectQuery);
  $stmt->bind_param("s", $payer);
  $stmt->execute();
  $commissionOnRoyaltySelectResult = $stmt->get_result();
  for ($i = 0; $i < $commissionOnRoyaltySelectResult -> num_rows; $i++) {
    $row = $commissionOnRoyaltySelectResult -> fetch_assoc();
    $commissionOnRoyaltyPayment[$row['year']] = $row['payment'];
    $totalCommissionOnRoyaltyPayment += $row['payment'];
  }
}

foreach($yearList as $year) {
  $totalPaymentAwarded[$year] = $taskPayment[$year] + $commissionOnTaskPayment[$year]  + $stipendPaymentAwardedInSameYear[$year] + $stipendPaymentAwardedFromEarlierYear[$year] + $royaltyPayment[$year] + $commissionOnRoyaltyPayment[$year];
  $totalPaymentAwardedAcrossYears += $totalPaymentAwarded[$year];
  $totalPayment[$year] = $totalPaymentAwarded[$year] + $stipendPaymentAwardedInLaterYear[$year] - $stipendPaymentAwardedFromEarlierYear[$year] + $unawardedStipendPayment[$year];
  $totalPaymentAcrossYears += $totalPayment[$year];
}

# Print table
print "\n";
print '<table id="myTablePayerPaymentsDueByTypeAndYear" class="tablesorter">'."\n";
print "<thead>\n<tr>\n	<th>Type of payment due</th>\n";
print "	<th>Total across years</th>\n";
foreach (array_reverse($yearList) as $year) {
  print "	<th>Total in year $year</th>\n";
}
print "</tr>\n</thead>\n<tbody>\n";
if ($totalTaskPayment > 0) {
  print "<tr>\n	<td>Tasks</td>\n";
  print '	<td align="right"><strong>'.number_format($totalTaskPayment,2)."</strong></td>\n";
  foreach (array_reverse($yearList) as $year) {
    print '	<td align="right">'.number_format($taskPayment[$year],2)."</td>\n";
  }
  print "</tr>\n";
}
if ($payer == "Vipul Naik") {
  print "<tr>\n	<td>Commissions on tasks</td>\n";
  print '	<td align="right"><strong>'.number_format($totalCommissionOnTaskPayment,2)."</strong></td>\n";
  foreach (array_reverse($yearList) as $year) {
    print '	<td align="right">'.number_format($commissionOnTaskPayment[$year],2)."</td>\n";
  }
  print "</tr>\n";
}
print "<tr>\n	<td>Stipends (awarded same year)</td>\n";
print '	<td align="right"><strong>'.number_format($totalStipendPaymentAwardedInSameYear,2)."</strong></td>\n";
foreach (array_reverse($yearList) as $year) {
  print '	<td align="right">'.number_format($stipendPaymentAwardedInSameYear[$year],2)."</td>\n";
}
print "</tr>\n";
if ($totalStipendPaymentStraddlingYears > 0) {
  print "<tr>\n	<td>Stipends (awarded from earlier year)</td>\n";
  print '	<td align="right"><strong>'.number_format($totalStipendPaymentStraddlingYears,2)."</strong></td>\n";
  foreach (array_reverse($yearList) as $year) {
    print '	<td align="right">'.number_format($stipendPaymentAwardedFromEarlierYear[$year],2)."</td>\n";
  }
  print "</tr>\n";
}
if ($payer == "Vipul Naik") {
  print '<tr><td>Royalties</td>';
  print '	<td align="right"><strong>'.number_format($totalRoyaltyPayment,2)."</strong></td>\n";
  foreach (array_reverse($yearList) as $year) {
    print '	<td align="right">'.number_format($royaltyPayment[$year],2)."</td>\n";
  }
  print "</tr>\n";
  print "<tr>\n	<td>Commissions on royalties</td>\n";
  print '	<td align="right"><strong>'.number_format($totalCommissionOnRoyaltyPayment,2)."</strong></td>\n";
  foreach (array_reverse($yearList) as $year) {
    print '	<td align="right">'.number_format($commissionOnRoyaltyPayment[$year],2)."</td>\n";
  }
  print "</tr>\n";
}
print "<tr>\n	<td><strong>Total payment awarded</strong></td>\n";
print '	<td align="right"><strong>'.number_format($totalPaymentAwardedAcrossYears,2)."</strong></td>\n";
foreach (array_reverse($yearList) as $year) {
  print '	<td align="right"><strong>'.number_format($totalPaymentAwarded[$year],2)."</strong></td>\n";
}
print "</tr>\n";
if ($totalUnawardedStipendPayment > 0) {
  print "<tr>\n	<td>Stipends (unawarded)</td>\n";
  print '	<td align="right"><strong>'.number_format($totalUnawardedStipendPayment,2)."</strong></td>\n";
  foreach (array_reverse($yearList) as $year) {
    print '	<td align="right">'.number_format($unawardedStipendPayment[$year],2)."</td>\n";
  }
}
print "</tr>\n";
if ($totalStipendPaymentStraddlingYears > 0) {
  print "<tr>\n	<td>Stipends (deferred to later year)</td>\n";
  print '	<td align="right"><strong>'.number_format($totalStipendPaymentStraddlingYears,2)."</strong></td>\n";
  foreach (array_reverse($yearList) as $year) {
    print '	<td align="right">'.number_format($stipendPaymentAwardedInLaterYear[$year],2)."</td>\n";
  }
  print "</tr>\n";
}
if ($totalStipendPaymentStraddlingYears > 0) {
  print "<tr>\n	<td>Stipends (awarded from earlier year; subtract)</td>\n";
  print '	<td align="right"><strong>'.number_format(-$totalStipendPaymentStraddlingYears,2)."</strong></td>\n";
  foreach (array_reverse($yearList) as $year) {
    print '	<td align="right">'.number_format(-$stipendPaymentAwardedFromEarlierYear[$year],2)."</td>\n";
  }
  print "</tr>\n";
}
print "</tbody>\n<tfoot>\n";
print "<tr>\n	<td><strong>Total payment</strong></td>\n";
print '	<td align="right"><strong>'.number_format($totalPaymentAcrossYears,2)."</strong></td>\n";
foreach (array_reverse($yearList) as $year) {
  print '	<td align="right"><strong>'.number_format($totalPayment[$year],2)."</strong></td>\n";
}
print "</tr>\n";
print "</tfoot>\n";
print "</table>\n";
?>
