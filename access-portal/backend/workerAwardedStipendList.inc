<?php

$stipendSelectQuery = "select * from stipends where payee='$worker' and stipend_award_date is not null order by stipend_award_date desc";

$stipendSelectResult = $mysqli -> query($stipendSelectQuery);

print '<h4>Full list of awarded stipends in reverse chronological order ('.($stipendSelectResult -> num_rows).' entries)</h4>';
print '<table border="1">';
print '<tr>';
print '<th>Stipend period</th>';
print '<th>Stipend award date</th>';
print '<th>Payment</th>';
print '<th>Notes</th>';
print '</tr>';
for ($i = 0; $i < $stipendSelectResult -> num_rows; $i++) {
  $row = $stipendSelectResult -> fetch_assoc();
  array_push($earnerList, $row['earner']);
  print '<tr>';
  print '<td>'.$row['stipend_start_date'];
  if ($row['stipend_end_date'] == '') {
    print ' onward';
  } else {
    print '–'.$row['stipend_end_date'].'</td>';
  }
  print '<td>'.$row['stipend_award_date'].'</td>';
  print '<td align="right">'.sprintf('%.2f',$row['payment']).'</td>';
  print '<td>'.$row['notes'].'</td>';
  print '</tr>';
}
print '</table>';
?>