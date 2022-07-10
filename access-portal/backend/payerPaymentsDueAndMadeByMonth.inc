<?php
if ($printTables == true) {
  print '<h4 id="payerPaymentsDueAndMadeByMonth">Payer payments due and payments made by month</h4>';
}
print '<p>For completed months, the row for the month gives the data at the end of the month. For the current month, the row for the month gives the data from the beginning of the month till now. The bold amounts are the cumulative numbers so far, across all time.</p>';

# Initialize values to zero
$cumulativePaymentAwardedSoFar = 0;
$cumulativePaymentMadeSoFar = 0;
$cumulativeReimbursementDueSoFar = 0;
foreach ($monthList as $month) {
  $paymentMadeInMonth[$month] = 0;
  $cumulativePaymentMadeTillMonth[$month] = 0;
  $reimbursementDueInMonth[$month] = 0;
  $cumulativeReimbursementDueTillMonth[$month] = 0;
  $cumulativePaymentAwardedSoFar += $totalPaymentAwarded[$month];
  $cumulativePaymentAwardedTillMonth[$month] = $cumulativePaymentAwardedSoFar;
}  

# Get payments

$paymentSelectQuery = "select year(receipt_date) as year, month(receipt_date) as month, coalesce(sum(payment), 0) as payment from payer_payments where payer=? and receipt_date is not null group by year(receipt_date), month(receipt_date) order by year(receipt_date), month(receipt_date);";
if ($payer == "Vipul Naik") {
  # All the stuff in the payments table over and above what's in payer_payments table is payments by Vipul Naik
  $paymentCalc = "coalesce(total_payment, 0) - coalesce(other_payer_payment, 0) as payment";
  $totalPaymentsQuery = "select year(receipt_date) as year, month(receipt_date) as month, coalesce(sum(payment), 0) as total_payment from payments where intermediary is null and receipt_date is not null group by year(receipt_date), month(receipt_date) order by year(receipt_date), month(receipt_date)";
  $otherPaymentsQuery = "select year(receipt_date) as year, month(receipt_date) as month, coalesce(sum(payment), 0) as other_payer_payment from payer_payments where receipt_date is not null group by year(receipt_date), month(receipt_date) order by year(receipt_date), month(receipt_date)";
  $paymentSelectQuery = "select * from (select t1.year as year, t1.month as month, $paymentCalc from ($totalPaymentsQuery) t1 left join ($otherPaymentsQuery) t2 on t1.year = t2.year and t1.month = t2.month union select t4.year as year, t4.month as month, $paymentCalc from ($totalPaymentsQuery) t3 right join ($otherPaymentsQuery) t4 on t3.year = t4.year and t3.month = t4.month) t5 order by year, month;";
}
$stmt = $mysqli->prepare($paymentSelectQuery);
if ($payer != "Vipul Naik") {
  $stmt->bind_param("s", $payer);
}
$stmt->execute();
$paymentSelectResult = $stmt->get_result();
for ($i=0; $i < $paymentSelectResult -> num_rows; $i++) {
  $row = $paymentSelectResult -> fetch_assoc();
  $paymentMadeInMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $cumulativePaymentMadeSoFar += $row['payment'];
  $cumulativePaymentMadeTillMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $cumulativePaymentMadeSoFar;
}

if ($payer == "Vipul Naik") {
  $mostRecentlySeenCumulativePaymentDue = 0;
  $mostRecentlySeenCumulativeReimbursementDue = 0;
  $reimbursementSelectQuery = "select year(receipt_date) as year, month(receipt_date) as month, coalesce(sum(sent_payment - payment), 0) as payment from payments where intermediary is not null and receipt_date is not null group by year(receipt_date), month(receipt_date) order by year(receipt_date), month(receipt_date);";
  $reimbursementSelectResult = $mysqli -> query($reimbursementSelectQuery);
  for ($i=0; $i < $reimbursementSelectResult -> num_rows; $i++) {
    $row = $reimbursementSelectResult -> fetch_assoc();
    $reimbursementDueInMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
    $cumulativeReimbursementDueSoFar += $row['payment'];
    $cumulativeReimbursementDueTillMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $cumulativeReimbursementDueSoFar;
    if ($payer == "Vipul Naik") {
      if ($cumulativeReimbursementDueTillMonth[$month] > 0) {
        $mostRecentlySeenCumulativeReimbursementDue = $cumulativeReimbursementDueTillMonth[$month];
      } else {
        $cumulativeReimbursementDueTillMonth[$month] = $mostRecentlySeenCumulativeReimbursementDue;
      }
    }
  }

  foreach($monthList as $month) {
    if ($cumulativePaymentMadeTillMonth[$month] > 0) {
      $mostRecentlySeenCumulativePaymentDue = $cumulativePaymentMadeTillMonth[$month];
    } else {
      $cumulativePaymentMadeTillMonth[$month] = $mostRecentlySeenCumulativePaymentDue;
    }
    if ($cumulativeReimbursementDueTillMonth[$month] > 0) {
      $mostRecentlySeenCumulativeReimbursementDue = $cumulativeReimbursementDueTillMonth[$month];
    } else {
      $cumulativeReimbursementDueTillMonth[$month] = $mostRecentlySeenCumulativeReimbursementDue;
    }
  }
}

$mostRecentlySeenCumulativePaymentDue = 0;
foreach($monthList as $month) {
  if ($cumulativePaymentMadeTillMonth[$month] > 0) {
    $mostRecentlySeenCumulativePaymentDue = $cumulativePaymentMadeTillMonth[$month];
  } else {
    $cumulativePaymentMadeTillMonth[$month] = $mostRecentlySeenCumulativePaymentDue;
  }
}

# Print table
if ($printTables == true) {
  print "\n";
  print '<table id="myTablePayerPaymentsDueAndMadeByMonth" class="tablesorter">'."\n";
  print "<thead>\n";
  print '<tr><th>Month</th>';
  print '<th>Payment awarded in month</th>';
  print '<th>Cumulative payment awarded till month</th>';
  if ($cumulativeReimbursementDueSoFar > 0) {
    print '<th>Reimbursement due in month</th>';
    print '<th>Cumulative reimbursement due</th>';
  }
  print '<th>Payment made in month</th>';
  print '<th>Cumulative payment made till month</th>';
  print '<th>Pending payment increase in month</th>';
  print '<th>Cumulative pending payment</th>';
  print '</tr>';
  print "</thead>\n<tbody>\n";
  $starting = true;
  foreach (array_reverse($monthList) as $month) {
    if ($paymentMadeInMonth[$month] > 0 or $totalPaymentAwarded[$month] > 0) {
      print "<tr>";
      $opener = "";
      $closer = "";
      if ($starting == true) {
        $opener = "<strong>";
        $closer = "</strong>";
      }
      print "<td>$opener$month$closer</td>";
      print '<td align="right">'.number_format($totalPaymentAwarded[$month],2).'</td>';
      print '<td align="right">'.$opener.number_format($cumulativePaymentAwardedTillMonth[$month],2).$closer.'</td>';
      if ($cumulativeReimbursementDueSoFar > 0) {
        print '<td align="right">'.number_format($reimbursementDueInMonth[$month],2).'</td>';
        print '<td align="right">'.$opener.number_format($cumulativeReimbursementDueTillMonth[$month],2).$closer.'</td>';
      }
      print '<td align="right">'.number_format($paymentMadeInMonth[$month],2).'</td>';
      print '<td align="right">'.$opener.number_format($cumulativePaymentMadeTillMonth[$month],2).$closer.'</td>';
      print '<td align="right">'.number_format($totalPaymentAwarded[$month] + $reimbursementDueInMonth[$month] - $paymentMadeInMonth[$month],2).'</td>';
      print '<td align="right">'.$opener.number_format($cumulativePaymentAwardedTillMonth[$month] + $cumulativeReimbursementDueTillMonth[$month] - $cumulativePaymentMadeTillMonth[$month],2).$closer.'</td>';
      $starting = false;
      print "</tr>\n";
    }
  }
  
  print "</tbody>\n</table>\n";
}
?>
