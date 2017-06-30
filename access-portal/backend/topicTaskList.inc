<?php

$topicTaskSelectQuery = "select * from tasks where $topicRegexMatcher and private = false order by completion_date desc";
$topicTaskSelectResult = $mysqli -> query($topicTaskSelectQuery);
print '<h4 id="topicTaskList">Full list of tasks in reverse chronological order ('.($topicTaskSelectResult -> num_rows).' tasks)</h4>';
print "\n";
print '<table id="myTableTopicTaskList" class="tablesorter">'."\n";
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
for($i = 0; $i < $topicTaskSelectResult -> num_rows; $i++) {
  $row = $topicTaskSelectResult -> fetch_assoc();
  print '<tr><td><a href="/worker.php?worker='.urlencode($row['worker']).'">'.$row['worker'].'</a></td>';
  print '<td>'.$row['task_venue'].'</td>';
  print '<td>'.$row['task_type'].'</td>';
  if (substr($row['task_receptacle_url'],0,4) == "http" and strpos($row['task_receptacle_url'],',http') == false) {
    print '<td><a href="'.$row['task_receptacle_url'].'">'.$row['task_receptacle'].'</a></td>';
  } else {
    print '<td>'.$row['task_receptacle'].'</td>';
  }
  print '<td>'.$row['completion_date'].'</td>';
  print '<td><a href="/payer.php?payer='.urlencode($row['payer']).'">$row['payer'].'</a></td>';
  print '<td align="right">'.sprintf("%.2f",$row['payment']).'</td>';
  print '<td>'.$row['topic'].'</td>';
  print '<td>'.$row['format'].'</td>';
  print '<td>'.cleanNotes($row['notes']).'</td>';
  print '</tr>';
}

print "</tbody>\n</table>\n";
?>
