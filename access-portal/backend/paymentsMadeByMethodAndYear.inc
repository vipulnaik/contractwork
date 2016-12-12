<?php
print '<h4>Payments made by type and year</h4>';

# Initialize values to zero
$grandTotal = 0;
foreach ($paymentMethods as $paymentMethod) {
  $totalPaymentByMethod[$paymentMethod] = 0;
  foreach ($yearList as $year) {
    $payment[$paymethMethod][$year] = 0;
    $totalPaymentByYear[$year] = 0;
  }
}  

# Get payments

$paymentSelectQuery = "select payment_method, year(receipt_date) as year, coalesce(sum(payment), 0) as payment from payments where receipt_date is not null group by payment_method, year(receipt_date);";
$paymentSelectResult = $mysqli -> query($paymentSelectQuery);
for ($i=0; $i < $paymentSelectResult -> num_rows; $i++) {
  $row = $paymentSelectResult -> fetch_assoc();
  $payment[$row['payment_method']][$row['year']] = $row['payment'];
  $totalPaymentByMethod[$row['payment_method']] += $row['payment'];
  $totalPaymentByYear[$row['year']] = $row['payment'];
  $grandTotal += $row['payment'];
}

# Print table
print '<table border="1">';
print '<tr><th>Payment method</th>';
foreach ($yearList as $year) {
  print "<th>Total in year $year</th>";
}
print '<th>Total across years</th></tr>';
foreach ($paymentMethods as $paymentMethod) {
  print "<tr><td>$paymentMethod</td></tr>";
  foreach ($yearList as $year) {
    print '<td align="right">'.sprintf('%.2f',$payment[$paymentMethod][$year]).'</td>';
  }
  print '<td align="right">'.sprintf('%.2f',$totalPaymentByMethod[$paymentMethod]).'</td>';
}
print '<tr><td><strong>Total across payment methods</strong></td>'
foreach ($yearList as $year) {
  print '<td align="right"><strong>'.sprintf('%.2f',$totalPaymentByYear[$year]).'</strong></td>';
}
print '<td align="right"><strong>'.sprintf('%.2f',$grandTotal).'</strong></td>';
print '</tr>';

print '</table>';
?>