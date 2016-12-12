<?php
$workerSelectQuery = "select * from workers where worker='$worker' and private = false;";
$workerSelectResult = $mysqli -> query($workerSelectQuery);
$row = $workerSelectResult -> fetch_assoc();

print '<h4>Basic worker information</h4>';
print '<table border="1">';
print '<tr><th>Item</th><th>Value</th></tr>';
print '<tr><td>Country</td><td>'.$row['country'].'</td>';
print '<tr><td>Wikipedia username</td><td>'.$row['wikipedia_username'].' (<a href="https://en.wikipedia.org/wiki/User:'.$row['wikipedia_username'].'">user page</a>, <a href="https://en.wikipedia.org/wiki/User_talk:'.$row['wikipedia_username'].'">user talk page</a>, <a href="https://en.wikipedia.org/wiki/Special:Contributions/'.$row['wikipedia_username'].'">contributions page</a>, <a href="https://tools.wmflabs.org/xtools-ec/?user='.$row['wikipedia_username'].'&project=en.wikipedia.org">WMF Labs X! Tools page</a>)</td></tr>';
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
print '<tr><td>Preferred payment method</td><td>'.$row['preferred_payment_method'].'</td></tr>';
print '<tr><td>Recruiter</td><td>'.$row['recruiter'].'</td></tr>';
print '<tr><td>Contact method (initial contact)</td><td>'.$row['contact_method'].'</td></tr>';
if ($row['notes'] != '') {
  print '<tr><td>Notes</td><td>'.$row['notes'].'</td></tr>';
}
print '</table>';

?>