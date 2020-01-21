<?php
$workerSelectQuery = "select * from workers where worker=? and private = false;";
$stmt = $mysqli->prepare($workerSelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$workerSelectResult = $stmt->get_result();
$row = $workerSelectResult -> fetch_assoc();

print '<h4 id="workerInfo">Basic worker information</h4>';
print "\n";
print '<table id="myTableWorkerInfo" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Item</th><th>Value</th></tr>';
print "</thead>\n<tbody>\n";
print '<tr><td>Country</td><td>'.$row['country'];
if ($row['country'] == "United States") {
  print ' (<a href="/taxes.php?worker='.urlencode($worker).'">tax information</a>)';
}
print '</td>';
if (isset($row['wikipedia_username']) and $row['wikipedia_username'] != "") {
  print '<tr><td>Wikipedia username</td><td>'.$row['wikipedia_username'].' (<a href="https://en.wikipedia.org/wiki/User:'.$row['wikipedia_username'].'">user page</a>, <a href="https://en.wikipedia.org/wiki/User_talk:'.$row['wikipedia_username'].'">user talk page</a>, <a href="https://en.wikipedia.org/wiki/Special:Contributions/'.$row['wikipedia_username'].'">contributions page</a>, <a href="https://tools.wmflabs.org/xtools-ec/?user='.$row['wikipedia_username'].'&project=en.wikipedia.org">WMF Labs X! Tools page</a>, <a href="http://wikipediaviews.org/displayviewsformultipletagsandmonths.php?tag=Pages+created+by+'.urlencode($row['worker']).'&allmonths=allmonths&drilldown=all">Wikipedia Views</a>)</td></tr>';
}
if (isset($row['timelines_wiki_username']) and $row['timelines_wiki_username'] != "") {
  print "<tr><td>Timelines wiki username</td><td>".$row['timelines_wiki_username'].' (<a href="https://timelines.issarice.com/wiki/User:'.$row['timelines_wiki_username'].'">user page</a>, <a href="https://timelines.issarice.com/wiki/User_talk:'.$row['timelines_wiki_username'].'">user talk page</a>, <a href="https://timelines.issarice.com/wiki/Special:Contributions/'.$row['timelines_wiki_username'].'">contributions page</a>)</td></tr>';
}
$facebook_username = $row['facebook_username'];
$facebook_url = 'https://www.facebook.com/'.$facebook_username;
if (substr($facebook_username, 0, 4) == "http") {
  $facebook_url = $facebook_username;
}
print '<tr><td>Facebook username</td><td><a href="'.$facebook_url.'">'.$facebook_username.'</a></td></tr>';
print '<tr><td>Email ID</td><td>'.$row['email_id'].'</td></tr>';
if ($row['website'] != '') {
  print '<tr><td>Website</td><td><a href="'.$row['website'].'">'.$row['website'].'</a></td></tr>';
}
if ($row['twitter_username'] != '') {
  print '<tr><td>Twitter username</td><td><a href="https://twitter.com/'.$row['twitter_username'].'">'.$row['twitter_username'].'</a></td></tr>';
}
if ($row['github_username'] != '') {
  print '<tr><td>GitHub username</td><td><a href="https://github.com/'.$row['github_username'].'">'.$row['github_username'].'</a></td></tr>';
}
if ($row['linkedin_username'] != '') {
  print '<tr><td>LinkedIn username</td><td><a href="https://www.linkedin.com/in/'.$row['linkedin_username'].'/">'.$row['linkedin_username'].'</a></td></tr>';
}

if ($row['lesswrong_username'] != '') {
  print '<tr><td>LessWrong username</td><td><a href="http://lesswrong.com/user/'.$row['lesswrong_username'].'">'.$row['lesswrong_username'].'</a></td></tr>';
}
if ($row['eaf_username'] != '') {
  print '<tr><td>Effective Altruism Forum username</td><td><a href="http://effective-altruism.com/user/'.$row['eaf_username'].'">'.$row['eaf_username'].'</a></td></tr>';
}

print '<tr><td>Preferred payment method</td><td>'.$row['preferred_payment_method'].'</td></tr>';
print '<tr><td>Recruiter</td>';
if ($row['recruiter'] == "Vipul Naik") {
  print '<td>'.$row['recruiter'].'</td></tr>';
} else {
  print '<td><a href="https://contractwork.vipulnaik.com/worker.php?worker='.urlencode($row['recruiter']).'">'.$row['recruiter'].'</a></td></tr>';
}
print '<tr><td>Contact method (initial contact)</td><td>'.$row['contact_method'].'</td></tr>';
print '<tr><td>Worker file (on GitHub, with revision history)</td><td><a href="https://github.com/vipulnaik/contractwork/blob/master/contributor-lists/'.$row['worker_file'].'">'.$row['worker_file'].'</a> (this file includes a list of partial or completed tasks for which pay has not yet been added, if applicable; look for TODO in the file)</td></tr>';
if ($row['notes'] != '') {
  print '<tr><td>Notes</td><td>'.$row['notes'].'</td></tr>';
}
print "</tbody>\n</table>\n";

?>
