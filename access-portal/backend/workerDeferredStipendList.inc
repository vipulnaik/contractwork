<?php

$stipendSelectQuery = "select * from stipends where payee='$worker' and stipend_award_date is null order by stipend_end_date desc";

$stipendSelectResult = $mysqli -> query($stipendSelectQuery);

print '<h4>Full list of deferred stipends in reverse chronological order ('.($stipendSelectResult -> num_rows).' entries)</h4>';
print "\n";
print '<table id="myTableWorkerDeferredStipendList" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr>';
print '<th>Stipend period</th>';
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
  print '<td align="right">'.sprintf('%.2f',$row['payment']).'</td>';
  print '<td>'.$row['notes'].'</td>';
  print '</tr>';
}
print "</tbody>\n</table>\n";
?>