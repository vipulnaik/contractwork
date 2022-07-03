<?php

$payerPaymentSelectQuery = "select * from payer_payments where payer=? and receipt_date is not null order by receipt_date desc";
$stmt = $mysqli->prepare($payerPaymentSelectQuery);
$stmt->bind_param("s", $payer);
$stmt->execute();
$payerPaymentSelectResult = $stmt->get_result();
print '<h4 id="payerPaymentList">Full list of sent payments in reverse chronological order ('.($payerPaymentSelectResult -> num_rows).' payments)</h4>';
print "\n";
print '<table id="myTablePayerPaymentList" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr>';
print '<th>Payment method</th>';
print '<th>Sent date</th>';
print '<th>Receipt date</th>';
print '<th>Payment</th>';
print '<th>Amount sent</th>';
print '<th>Overhead</th>';
print '<th>Amount received</th>';
print '<th>Intermediary (empty if none)</th>';
print '</tr>';
print "</thead>\n<tbody>\n";
for($i = 0; $i < $payerPaymentSelectResult -> num_rows; $i++) {
  $row = $payerPaymentSelectResult -> fetch_assoc();
  print '<tr>';
  print '<td>'.$row['payment_method'].'</td>';
  print '<td>'.$row['sent_date'].'</td>';
  print '<td>'.$row['receipt_date'].'</td>';
  print '<td align="right">'.number_format($row['payment'],2).'</td>';
  print '<td align="right">'.number_format($row['sent_payment'],2).'</td>';
  print '<td align="right">'.number_format($row['overhead'],2).'</td>';
  print '<td align="right">'.number_format($row['received_payment'],2).'</td>';
  print '<td>'.$row['intermediary'].'</td>';
  print '</tr>';
}

print "</tbody>\n</table>\n";
?>
