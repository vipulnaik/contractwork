<?php
print '<h4>Payments due and payments made by month</h4>';

print '<p>For completed months, the row for the month gives the data at the end of the month. For the current month, the row for the month gives the data as of now.</p>';

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

$paymentSelectQuery = "select year(receipt_date) as year, month(receipt_date) as month, coalesce(sum(payment), 0) as payment from payments where payee='$worker' and receipt_date is not null group by year(receipt_date), month(receipt_date) order by year(receipt_date), month(receipt_date);";
$paymentSelectResult = $mysqli -> query($paymentSelectQuery);
for ($i=0; $i < $paymentSelectResult -> num_rows; $i++) {
  $row = $paymentSelectResult -> fetch_assoc();
  $paymentMadeInMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $cumulativePaymentMadeSoFar += $row['payment'];
  $cumulativePaymentMadeTillMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $cumulativePaymentMadeSoFar;
}

$reimbursementSelectQuery = "select year(receipt_date) as year, month(receipt_date) as month, coalesce(sum(sent_payment), 0) as payment from payments where intermediary='$worker' and receipt_date is not null group by year(receipt_date), month(receipt_date) order by year(receipt_date), month(receipt_date);";
$reimbursementSelectResult = $mysqli -> query($reimbursementSelectQuery);
for ($i=0; $i < $reimbursementSelectResult -> num_rows; $i++) {
  $row = $reimbursementSelectResult -> fetch_assoc();
  $reimbursementDueInMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $cumulativeReimbursementDueSoFar += $row['payment'];
  $cumulativeReimbursementDueTillMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $cumulativeReimbursementDueSoFar;
}

$mostRecentlySeenCumulativePaymentDue = 0;
$mostRecentlySeenCumulativeReimbursementDue = 0;
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

# Print table
print '<table border="1">';
print '<tr><th>Month</th>';
print '<th>Payment awarded in month</th>';
print '<th>Cumulative payment awarded in month</th>';
if ($cumulativeReimbursementDueSoFar > 0) {
  print '<th>Reimbursement due in month</th>';
  print '<th>Cumulative reimbursement due</th>';
}
print '<th>Payment made in month</th>';
print '<th>Cumulative payment made till month</th>';
print '<th>Pending payment increase in month</th>';
print '<th>Cumulative pending payment</th>';
print '</tr>';

foreach ($monthList as $month) {
  if ($paymentMadeInMonth[$month] > 0 or $totalPaymentAwarded[$month] > 0) {
    print "<tr><td>$month</td>";
    print '<td align="right">'.sprintf('%.2f',$totalPaymentAwarded[$month]).'</td>';
    print '<td align="right">'.sprintf('%.2f',$cumulativePaymentAwardedTillMonth[$month]).'</td>';
    if ($cumulativeReimbursementDueSoFar > 0) {
      print '<td align="right">'.sprintf('%.2f',$reimbursementDueInMonth[$month]).'</td>';
      print '<td align="right">'.sprintf('%.2f',$cumulativeReimbursementDueTillMonth[$month]).'</td>';
    }

    print '<td align="right">'.sprintf('%.2f',$paymentMadeInMonth[$month]).'</td>';
    print '<td align="right">'.sprintf('%.2f',$cumulativePaymentMadeTillMonth[$month]).'</td>';
    print '<td align="right">'.sprintf('%.2f',$totalPaymentAwarded[$month] + $reimbursementDueInMonth[$month] - $paymentMadeInMonth[$month]).'</td>';
    print '<td align="right">'.sprintf('%.2f',$cumulativePaymentAwardedTillMonth[$month] + $cumulativeReimbursementDueTillMonth[$month] - $cumulativePaymentMadeTillMonth[$month]).'</td>';
    print '</tr>';
  }
}

print '</table>';
?>