<?php

$workerPaymentSelectQuery = "select * from tasks where payee='$worker' and receipt_date is not null order by receipt_date desc";
$workerPaymentSelectResult = $mysqli -> query($workerPaymentSelectQuery);
print '<h4>Full list of received payments in chronological order ('.($workerPaymentSelectResult -> num_rows).' tasks)</h4>';
print '<table border="1">';
print '<tr>';
print '<th>Payment method</th>';
print '<th>Intermediary (empty if none)</th>';
print '<th>Sent date</th>';
print '<th>Receipt date</th>';
print '<th>Payment</th>';
print '<th>Amount sent</th>';
print '<th>Overhead</th>';
print '<th>Amount received</th>';
print '</tr>';

for($i = 0; $i < $workerPaymentSelectResult -> num_rows; $i++) {
  $row = $workerPaymentSelectResult -> fetch_assoc();
  print '<tr>';
  print '<td>'.$row['payment_method'].'</td>';
  print '<td>'.$row['intermediary'].'</td>';
  print '<td>'.$row['sent_date'].'</td>';
  print '<td>'.$row['receipt_date'].'</td>';
  print '<td align="right">'.sprintf("%.2f",$row['payment']).'</td>';
  print '<td align="right">'.sprintf("%.2f",$row['sent_payment']).'</td>';
  print '<td align="right">'.sprintf("%.2f",$row['overhead']).'</td>';
  print '<td align="right">'.sprintf("%.2f",$row['received_payment']).'</td>';
  print '</tr>';
}

print '</table>';
?>
