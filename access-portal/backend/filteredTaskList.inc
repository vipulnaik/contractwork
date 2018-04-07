<?php

$taskSelectQuery = "select * from tasks where $filterQuery and private = false order by completion_date desc";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
print '<h4 id="filteredTaskList">Full list of tasks in reverse chronological order ('.($taskSelectResult -> num_rows).' tasks)</h4>';
print "\n";
print '<table id="myTableFilteredTaskList" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr>';
print '<th>Task venue</th>';
print '<th>Task type</th>';
print '<th>Task receptacle</th>';
print '<th>Completion date</th>';
print '<th>Worker</th>';
print '<th>Payer</th>';
print '<th>Payment</th>';
print '<th>Topic</th>';
print '<th>Format</th>';
print '<th>Time spent (hours:minutes)</th>';
print '<th>Effective pay per hour</th>';
print '<th>Notes</th>';
print '</tr>';
print "</thead>\n<tbody>\n";
for($i = 0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  print '<tr>';
  print '<td><a href="/venue.php?venue='.urlencode($row['task_venue']).'&matching=exact">'.$row['task_venue'].'</a></td>';
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
  print '<td><a href="/worker.php?worker='.urlencode($row['worker']).'">'.$row['worker'].'</a></td>';
  print '<td><a href="/payer.php?payer='.urlencode($row['payer']).'">'.$row['payer'].'</a></td>';
  print '<td align="right">'.number_format($row['payment'],2).'</td>';
  print '<td>'.$row['topic'].'</td>';
  print '<td><a href="/format.php?venue='.urlencode($row['format']).'&matching=exact">'.$row['format'].'</a></td>';
  if (isset($row['minutes_spent']) && $row['minutes_spent'] != '') {
    $hoursSpent = floor($row['minutes_spent']/60);
    $residualMinutesSpent = $row['minutes_spent'] - ($hoursSpent * 60);
    print '<td align="right">'.$hoursSpent.":".sprintf("%02d",$residualMinutesSpent).'</td>';
    print '<td align="right">'.number_format($row['payment'] * 60/ $row['minutes_spent'], 2).'</td>';
  } else {
    print '<td align="right"></td>';
    print '<td align="right"></td>';
  }
  print '<td>'.cleanNotes($row['notes']).'</td>';
  print '</tr>';
}

print "</tbody>\n</table>\n";
?>
