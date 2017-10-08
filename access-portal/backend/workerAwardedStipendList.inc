<?php

$stipendSelectQuery = "select * from stipends where payee=".'"'.str_replace('"','\"',$worker).'"'." and stipend_award_date is not null order by stipend_award_date desc, stipend_end_date desc";

$stipendSelectResult = $mysqli -> query($stipendSelectQuery);

print '<h4 id="workerAwardedStipendList">Full list of awarded stipends in reverse chronological order ('.($stipendSelectResult -> num_rows).' entries)</h4>';
print "\n";
print '<table id="myTableWorkerAwardedStipendList" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr>';
print '<th>Stipend period</th>';
print '<th>Stipend award date</th>';
print '<th>Payment</th>';
print '<th>Notes</th>';
print '</tr>';
print "</thead>\n<tbody>\n";
for ($i = 0; $i < $stipendSelectResult -> num_rows; $i++) {
  $row = $stipendSelectResult -> fetch_assoc();
  print '<tr>';
  print '<td>'.$row['stipend_start_date'];
  if ($row['stipend_end_date'] == '') {
    print ' onward';
  } else {
    print '–'.$row['stipend_end_date'].'</td>';
  }
  print '<td>'.$row['stipend_award_date'].'</td>';
  print '<td align="right">'.number_format($row['payment'],2).'</td>';
  print '<td>'.$row['notes'].'</td>';
  print '</tr>';
}
print "</tbody>\n</table>\n";
?>
