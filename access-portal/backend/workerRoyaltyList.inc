<?php

$royaltySelectQuery = "select * from royalties where payee=".'"'.str_replace('"','\"',$worker).'"'." order by royalty_end_date desc";

$royaltySelectResult = $mysqli -> query($royaltySelectQuery);

print '<h4>Full list of royalties in reverse chronological order ('.($royaltySelectResult -> num_rows).' entries)</h4>'."\n";
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
  print '<td align="right">'.sprintf('%.2f',$row['payment']).'</td>';
  print '<td>'.$row['notes'].'</td>';
  print '</tr>';
}
print "</tbody>\n</table>\n";
?>