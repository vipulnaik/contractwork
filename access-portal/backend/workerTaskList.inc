<?php

$workerTaskSelectQuery = "select * from tasks where worker='$worker' and private = false order by completion_date desc";
$workerTaskSelectResult = $mysqli -> query($workerTaskSelectQuery);
print '<h4 id="workerTaskList">Full list of tasks in reverse chronological order ('.($workerTaskSelectResult -> num_rows).' tasks)</h4>';
print "\n";
print '<table id="myTableWorkerTaskList" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr>';
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
for($i = 0; $i < $workerTaskSelectResult -> num_rows; $i++) {
  $row = $workerTaskSelectResult -> fetch_assoc();
  print '<tr>';
  print '<td>'.$row['task_venue'].'</td>';
  print '<td>'.$row['task_type'].'</td>';
  if (substr($row['task_receptacle_url'],0,4) == "http" and strpos($row['task_receptacle_url'],',http') == false) {
    print '<td><a href="'.$row['task_receptacle_url'].'">'.$row['task_receptacle'].'</a>';
    if ($row['task_type'] == "Wikipedia page creation" or $row['task_type'] == "Wikipedia page update") {
      print ' (<a href="http://wikipediaviews.org/displayviewsformultiplemonths.php?page='.urlencode($row['task_receptacle']).'&language=en&drilldown=all&allmonths=allmonths">Wikipedia Views</a>)';
    }
    print '</td>';
  } else {
    print '<td>'.$row['task_receptacle'].'</td>';
  }
  print '<td>'.$row['completion_date'].'</td>';
  print '<td>'.$row['payer'].'</td>';
  print '<td align="right">'.sprintf("%.2f",$row['payment']).'</td>';
  print '<td>'.$row['topic'].'</td>';
  print '<td>'.$row['format'].'</td>';
  print '<td>'.cleanNotes($row['notes']).'</td>';
  print '</tr>';
}

print "</tbody>\n</table>\n";
?>
