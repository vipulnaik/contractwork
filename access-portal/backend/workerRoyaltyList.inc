<?php

$royaltySelectQuery = "select * from royalties where payee=? order by royalty_end_date desc";

$stmt = $mysqli->prepare($royaltySelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$royaltySelectResult = $stmt->get_result();

print '<h4 id="workerRoyaltyList">Full list of royalties in reverse chronological order ('.($royaltySelectResult -> num_rows).' entries)</h4>'."\n";
print "\n";
print '<table id="myTableWorkerRoyaltyList" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr>';
print '<th>Basis for royalty</th>';
print '<th>Scope of royalty</th>';
print '<th>Rate per unit</th>';
print '<th>Period</th>';
print '<th>Payment</th>';
print '<th>Notes</th>';
print '</tr>';
print "</thead>\n<tbody>\n";
for ($i = 0; $i < $royaltySelectResult -> num_rows; $i++) {
  $row = $royaltySelectResult -> fetch_assoc();
  print '<tr>';
  print '<td>'.$row['royalty_basis'].'</td>';
  print '<td>'.$row['royalty_scope'].'</td>';
  print '<td align="right">'.sprintf('%.5f',$row['royalty_rate']).'</td>';
  print '<td>'.$row['royalty_start_date'];
  if ($row['royalty_end_date'] == '') {
    print ' onward';
  } else {
    print '–'.$row['royalty_end_date'].'</td>';
  }
  print '<td align="right">'.number_format($row['payment'],2).'</td>';
  print '<td>'.cleanNotes($row['notes']).'</td>';
  print '</tr>';
}
print "</tbody>\n</table>\n";
?>
