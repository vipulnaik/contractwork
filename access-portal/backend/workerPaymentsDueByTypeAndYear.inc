<?php
if ($printTables == true) {
  print '<h4 id="workerPaymentsDueByTypeAndYear">Worker payments due by type and year</h4>';
}

# Initialize values to zero
foreach ($yearList as $year) {
  foreach ($payers as $payer) {
    $taskPayment[$year][$payer] = 0;
    $totalTaskPayment[$payer] = 0;
  }
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

$taskSelectQuery = "select payer, year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks where worker=? group by payer, year(completion_date);";
$stmt = $mysqli->prepare($taskSelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$taskSelectResult = $stmt->get_result();
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $taskPayment[$row['year']][$row['payer']] = $row['payment'];
  $totalTaskPayment[$row['payer']] += $row['payment'];
}

# Get commission on task payments
$commissionOnTaskSelectQuery = "select year(completion_date) as year, coalesce(sum(payment), 0) as payment from (select commission_receiver, completion_date, (commission * payment) as payment from commissions left join tasks on commissions.earner = tasks.worker where (commission_validity_start is null or tasks.completion_date >= commission_validity_start) and (commission_validity_end is null or tasks.completion_date <= commission_validity_end)) t1 where commission_receiver=? group by year(completion_date);";
$stmt = $mysqli->prepare($commissionOnTaskSelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$commissionOnTaskSelectResult = $stmt->get_result();
for ($i = 0; $i < $commissionOnTaskSelectResult -> num_rows; $i++) {
  $row = $commissionOnTaskSelectResult -> fetch_assoc();
  $commissionOnTaskPayment[$row['year']] = $row['payment'];
  $totalCommissionOnTaskPayment += $row['payment'];
}

# Get stipend payments

$stipendSelectQuery = "select year(stipend_award_date) as awardYear, year(stipend_end_date) as year, (stipend_award_date is not null) as awarded, coalesce(sum(payment), 0) as payment from stipends where payee=? group by year(stipend_award_date), year(stipend_end_date), (stipend_award_date is not null);";
$stmt = $mysqli->prepare($stipendSelectQuery);
$stmt->bind_param("s", $worker);
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

# Get royalty payments
$royaltySelectQuery = "select year(royalty_end_date) as year, coalesce(sum(payment), 0) as payment from royalties where payee=? group by year(royalty_end_date);";
$stmt = $mysqli->prepare($royaltySelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$royaltySelectResult = $stmt->get_result();
for ($i = 0; $i < $royaltySelectResult -> num_rows; $i++) {
  $row = $royaltySelectResult -> fetch_assoc();
  $royaltyPayment[$row['year']] = $row['payment'];
  $totalRoyaltyPayment += $row['payment'];
}

# Get commission on royalty payments
$commissionOnRoyaltySelectQuery = "select year(royalty_end_date) as year, coalesce(sum(payment), 0) as payment from (select commission_receiver, royalty_end_date, (commission * payment) as payment from commissions left join royalties on commissions.earner = royalties.payee where (commission_validity_start is null or royalties.royalty_start_date >= commission_validity_start) and (commission_validity_end is null or royalties.royalty_end_date <= commission_validity_end)) t1 where commission_receiver=? group by year(royalty_end_date);";
$stmt = $mysqli->prepare($commissionOnRoyaltySelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$commissionOnRoyaltySelectResult = $stmt->get_result();
for ($i = 0; $i < $commissionOnRoyaltySelectResult -> num_rows; $i++) {
  $row = $commissionOnRoyaltySelectResult -> fetch_assoc();
  $commissionOnRoyaltyPayment[$row['year']] = $row['payment'];
  $totalCommissionOnRoyaltyPayment += $row['payment'];
}

foreach($yearList as $year) {
  $totalPaymentAwarded[$year] = 0;
  $totalPayment[$year] = 0;
  $taskPaymentAcrossPayers[$year] = 0;
  foreach ($payers as $payer) {
    $taskPaymentAcrossPayers[$year] += $taskPayment[$year][$payer];
  }
  $totalPaymentAwarded[$year] = $taskPaymentAcrossPayers[$year] + $commissionOnTaskPayment[$year]  + $stipendPaymentAwardedInSameYear[$year] + $stipendPaymentAwardedFromEarlierYear[$year] + $royaltyPayment[$year] + $commissionOnRoyaltyPayment[$year];
  $totalPaymentAwardedAcrossYears += $totalPaymentAwarded[$year];
  $totalPayment[$year] = $totalPaymentAwarded[$year] + $stipendPaymentAwardedInLaterYear[$year] - $stipendPaymentAwardedFromEarlierYear[$year] + $unawardedStipendPayment[$year];
  $totalPaymentAcrossYears += $totalPayment[$year];
}

# Print table
if ($printTables == true) {
  print "\n";
  print '<table id="myTableWorkerPaymentsDueByTypeAndYear" class="tablesorter">'."\n";
  print "<thead>\n";
  print '<tr><th>Type of payment due</th>';
  print '<th>Total across years</th>';
  foreach (array_reverse($yearList) as $year) {
    if ($totalPayment[$year] != 0 or $totalPaymentAwarded[$year] != 0) {
      print "<th>Total in year $year</th>";
    }
  }
  print "</tr>\n</thead>\n<tbody>\n";
  foreach($payers as $payer) {
    if ($totalTaskPayment[$payer] > 0) {
      print "<tr>\n	<td>Tasks for <a href=\"/payer.php?payer=".urlencode($payer)."\">$payer</td>\n";
      print '<td align="right"><strong>'.number_format($totalTaskPayment[$payer],2).'</strong></td>';
      foreach (array_reverse($yearList) as $year) {
        if ($totalPayment[$year] != 0 or $totalPaymentAwarded[$year] != 0) {
          print '<td align="right">'.number_format($taskPayment[$year][$payer],2).'</td>';
        }
      }
      print '</tr>';
    }
  }
  print '<tr><td>Commissions on tasks</td>';
  print '<td align="right"><strong>'.number_format($totalCommissionOnTaskPayment,2).'</strong></td>';
  foreach (array_reverse($yearList) as $year) {
    if ($totalPayment[$year] != 0 or $totalPaymentAwarded[$year] != 0) {
      print '<td align="right">'.number_format($commissionOnTaskPayment[$year],2).'</td>';
    }
  }
  print '</tr>';
  print '<tr><td>Stipends (awarded same year)</td>';
  print '<td align="right"><strong>'.number_format($totalStipendPaymentAwardedInSameYear,2).'</strong></td>';
  foreach (array_reverse($yearList) as $year) {
    if ($totalPayment[$year] != 0 or $totalPaymentAwarded[$year] != 0) {
      print '<td align="right">'.number_format($stipendPaymentAwardedInSameYear[$year],2).'</td>';
    }
  }
  print '</tr>';
  if ($totalStipendPaymentStraddlingYears > 0) {
    print '<tr><td>Stipends (awarded from earlier year)</td>';
    print '<td align="right"><strong>'.number_format($totalStipendPaymentStraddlingYears,2).'</strong></td>';
    foreach (array_reverse($yearList) as $year) {
      if ($totalPayment[$year] != 0 or $totalPaymentAwarded[$year] != 0) {
        print '<td align="right">'.number_format($stipendPaymentAwardedFromEarlierYear[$year],2).'</td>';
      }
    }
    print '</tr>';
  }
  print '<tr><td>Royalties</td>';
  print '<td align="right"><strong>'.number_format($totalRoyaltyPayment,2).'</strong></td>';
  foreach (array_reverse($yearList) as $year) {
    if ($totalPayment[$year] != 0 or $totalPaymentAwarded[$year] != 0) {
      print '<td align="right">'.number_format($royaltyPayment[$year],2).'</td>';
    }
  }
  print '</tr>';
  print '<tr><td>Commissions on royalties</td>';
  print '<td align="right"><strong>'.number_format($totalCommissionOnRoyaltyPayment,2).'</strong></td>';
  foreach (array_reverse($yearList) as $year) {
    if ($totalPayment[$year] != 0 or $totalPaymentAwarded[$year] != 0) {
      print '<td align="right">'.number_format($commissionOnRoyaltyPayment[$year],2).'</td>';
    }
  }
  print '</tr>';
  print '<tr><td><strong>Total payment awarded</strong></td>';
  print '<td align="right"><strong>'.number_format($totalPaymentAwardedAcrossYears,2).'</strong></td>';
  foreach (array_reverse($yearList) as $year) {
    if ($totalPayment[$year] != 0 or $totalPaymentAwarded[$year] != 0) {
      print '<td align="right"><strong>'.number_format($totalPaymentAwarded[$year],2).'</strong></td>';
    }
  }
  print '</tr>';
  print '<tr><td>Stipends (unawarded)</td>';
  print '<td align="right"><strong>'.number_format($totalUnawardedStipendPayment,2).'</strong></td>';
  foreach (array_reverse($yearList) as $year) {
    if ($totalPayment[$year] != 0 or $totalPaymentAwarded[$year] != 0) {
      print '<td align="right">'.number_format($unawardedStipendPayment[$year],2).'</td>';
    }
  }
  print '</tr>';
  if ($totalStipendPaymentStraddlingYears > 0) {
    print '<tr><td>Stipends (deferred to later year)</td>';
    print '<td align="right"><strong>'.number_format($totalStipendPaymentStraddlingYears,2).'</strong></td>';
    foreach (array_reverse($yearList) as $year) {
      if ($totalPayment[$year] != 0 or $totalPaymentAwarded[$year] != 0) {
        print '<td align="right">'.number_format($stipendPaymentAwardedInLaterYear[$year],2).'</td>';
      }
    }
    print '</tr>';
  }
  if ($totalStipendPaymentStraddlingYears > 0) {
    print '<tr><td>Stipends (awarded from earlier year; subtract)</td>';
    print '<td align="right"><strong>'.number_format(-$totalStipendPaymentStraddlingYears,2).'</strong></td>';
    foreach (array_reverse($yearList) as $year) {
      if ($totalPayment[$year] != 0 or $totalPaymentAwarded[$year] != 0) {
        print '<td align="right">'.number_format(-$stipendPaymentAwardedFromEarlierYear[$year],2).'</td>';
      }
    }
    print '</tr>';
  }
  print "</tbody>\n<tfoot>\n";
  print '<tr><td><strong>Total payment</strong></td>';
  print '<td align="right"><strong>'.number_format($totalPaymentAcrossYears,2).'</strong></td>';
  foreach (array_reverse($yearList) as $year) {
    if ($totalPayment[$year] != 0 or $totalPaymentAwarded[$year] != 0) {
      print '<td align="right"><strong>'.number_format($totalPayment[$year],2).'</strong></td>';
    }
  }
  print '</tr>';  
  print "</tfoot>\n</table>\n";
}
?>
