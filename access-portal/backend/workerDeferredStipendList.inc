<?php

$stipendSelectQuery = "select * from stipends where payee=? and stipend_award_date is null order by stipend_end_date desc";

$stmt = $mysqli->prepare($stipendSelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$stipendSelectResult = $stmt->get_result();

print '<h4 id="workerDeferredStipendList">Full list of deferred stipends in reverse chronological order ('.($stipendSelectResult -> num_rows).' entries)</h4>';
print "\n";
print '<table id="myTableWorkerDeferredStipendList" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr>';
print '<th>Stipend period</th>';
print '<th>Payment</th>';
print '<th>Payer</th>';
print '<th>Hours logged</th>';
print '<th>Total work hours</th>';
print '<th>Effective hourly pay using hours logged</th>';
print '<th>Effective hourly pay using total work hours</th>';
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
  print '<td><a href="/payer.php?payer='.urlencode($row['payer']).'">'.$row['payer'].'</a></td>';
  print '<td align="right">'.number_format($row['payment'],2).'</td>';
  if (isset($row['hours_logged']) && $row['hours_logged'] != '') {
    print '<td align="right">'.$row['hours_logged'].'</td>';
  } else {
    print '<td align="right"></td>';
  }
  if (isset($row['total_work_hours']) && $row['total_work_hours'] != '') {
    print '<td align="right">'.$row['total_work_hours'].'</td>';
  } else {
    print '<td align="right"></td>';
  }
  if (isset($row['hours_logged']) && $row['hours_logged'] != '') {
    print '<td align="right">'.number_format($row['payment'] / $row['hours_logged'], 2).'</td>';
  } else {
    print '<td align="right"></td>';
  }
  if (isset($row['total_work_hours']) && $row['total_work_hours'] != '') {
    print '<td align="right">'.number_format($row['payment'] / $row['total_work_hours'], 2).'</td>';
  } else {
    print '<td align="right"></td>';
  }
  print '<td>'.$row['notes'].'</td>';
  print '</tr>';
}
print "</tbody>\n</table>\n";
?>
