<?php

$venueTaskSelectQuery = "select * from tasks where $venueRegexMatcher and private = false order by completion_date desc";
$venueTaskSelectResult = $mysqli -> query($venueTaskSelectQuery);
print '<h4 id="venueTaskList">Full list of tasks in reverse chronological order ('.($venueTaskSelectResult -> num_rows).' tasks)</h4>';
print "\n";
print '<table id="myTableVenueTaskList" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr>';
print '<th>Worker</th>';
print '<th>Task venue</th>';
print '<th>Task type</th>';
print '<th>Task receptacle</th>';
print '<th>Completion date</th>';
print '<th>Payer</th>';
print '<th>Payment</th>';
print '<th>Topic</th>';
print '<th>Format</th>';
print '<th>Notes</th>';
print '</tr>';
print "</thead>\n<tbody>\n";
for($i = 0; $i < $venueTaskSelectResult -> num_rows; $i++) {
  $row = $venueTaskSelectResult -> fetch_assoc();
  print '<tr><td><a href="/worker.php?worker='.urlencode($row['worker']).'">'.$row['worker'].'</a></td>';
  print '<td>'.$row['task_venue'].'</td>';
  print '<td>'.$row['task_type'].'</td>';
  if (substr($row['task_receptacle_url'],0,4) == "http" and strpos($row['task_receptacle_url'],',http') == false) {
    print '<td><a href="'.$row['task_receptacle_url'].'">'.$row['task_receptacle'].'</a></td>';
  } else {
    print '<td>'.$row['task_receptacle'].'</td>';
  }
  print '<td>'.$row['completion_date'].'</td>';
  print '<td><a href="/payer.php?payer='.urlencode($row['payer']).'">'.$row['payer'].'</a></td>';
  print '<td align="right">'.number_format($row['payment'],2).'</td>';
  print '<td>'.$row['topic'].'</td>';
  print '<td>'.$row['format'].'</td>';
  print '<td>'.cleanNotes($row['notes']).'</td>';
  print '</tr>';
}

print "</tbody>\n</table>\n";
?>
