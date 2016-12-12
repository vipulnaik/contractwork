<?php
print '<h4>Worker payments made by month</h4>';

# Initialize values to zero
foreach ($monthList as $month) {
  $paymentInMonth[$month] = 0;
  $cumulativePaymentTillMonth[$month] = 0;
}  
$cumulativePaymentSoFar = 0;

# Get payments

$paymentSelectQuery = "select year(receipt_date) as year, month(receipt_date) as month, coalesce(sum(payment), 0) as payment from payments where payee='$worker' and receipt_date is not null group by year(receipt_date), month(receipt_date) order by year(receipt_date), month(receipt_date);";
$paymentSelectResult = $mysqli -> query($paymentSelectQuery);
for ($i=0; $i < $paymentSelectResult -> num_rows; $i++) {
  $row = $paymentSelectResult -> fetch_assoc();
  $paymentInMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $row['payment'];
  $cumulativePaymentSoFar += $row['payment'];
  $cumulativePaymentTillMonth[$row['year'] . '-' . sprintf('%02d',$row['month'])] = $cumulativePaymentSoFar;
}

# Print table
print '<table border="1">';
print '<tr><th>Month</th>';
print '<th>Payment made in month</th>';
print '<th>Cumulative payment made till month</th>';
print '</tr>';

foreach ($monthList as $month) {
  if ($paymentInMonth[$month] > 0) {
    print "<tr><td>$month</td>";
    print '<td align="right">'.sprintf('%.2f',$paymentInMonth[$month]).'</td>';
    print '<td align="right">'.sprintf('%.2f',$cumulativePaymentTillMonth[$month]).'</td>';
    print '</tr>';
  }
}

print '</table>';
?>