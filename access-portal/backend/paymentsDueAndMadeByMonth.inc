<?php
print '<h4>Payments due and payments made by month</h4>';

print '<p>For completed months, the row for the month gives the data at the end of the month. For the current month, the row for the month gives the data as of now.</p>';

# Initialize values to zero
$cumulativePaymentAwardedSoFar = 0;
$cumulativePaymentMadeSoFar = 0;
foreach ($monthList as $month) {
  $paymentMadeInMonth[$month] = 0;
  $cumulativePaymentMadeTillMonth[$month] = 0;
  $cumulativePaymentAwardedSoFar += $totalPaymentAwarded[$month];
  $cumulativePaymentAwardedTillMonth[$month] = $cumulativePaymentAwardedSoFar;
}  

# Get payments

$paymentSelectQuery = "select year(receipt_date) as year, month(receipt_date) as month, coalesce(sum(payment), 0) as payment from payments where receipt_date is not null group by year(receipt_date), month(receipt_date) order by year(receipt_date), month(receipt_date);";
$paymentSelectResult = $mysqli -> query($paymentSelectQuery);
for ($i=0; $i < $paymentSelectResult -> num_rows; $i++) {
  $row = $paymentSelectResult -> fetch_assoc();
  $paymentMadeInMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $cumulativePaymentMadeSoFar += $row['payment'];
  $cumulativePaymentMadeTillMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $cumulativePaymentMadeSoFar;
}

$mostRecentlySeenCumulativePayment = 0;
foreach($monthList as $month) {
  if ($cumulativePaymentMadeTillMonth[$month] > 0) {
    $mostRecentlySeenCumulativePayment = $cumulativePaymentMadeTillMonth[$month];
  } else {
    $cumulativePaymentMadeTillMonth[$month] = $mostRecentlySeenCumulativePayment;
  }
}

# Print table
print '<table border="1">';
print '<tr><th>Month</th>';
print '<th>Payment awarded in month</th>';
print '<th>Cumulative payment awarded in month</th>';
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
    print '<td align="right">'.sprintf('%.2f',$paymentMadeInMonth[$month]).'</td>';
    print '<td align="right">'.sprintf('%.2f',$cumulativePaymentMadeTillMonth[$month]).'</td>';
    print '<td align="right">'.sprintf('%.2f',$totalPaymentAwarded[$month] - $paymentMadeInMonth[$month]).'</td>';
    print '<td align="right">'.sprintf('%.2f',$cumulativePaymentAwardedTillMonth[$month] - $cumulativePaymentMadeTillMonth[$month]).'</td>';
    print '</tr>';
  }
}

print '</table>';
?>