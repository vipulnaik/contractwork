<?php
include_once('doctype.inc');
print '<script src="change-theme.js"></script>';
include_once("backend/globalVariables/passwordFile.inc");
include_once("backend/globalVariables/lists.inc");
include_once("backend/stringFunctions.inc");
include_once('analytics.inc');
print '<link href="style.css" rel="stylesheet" type="text/css" />'."\n";
include_once('style.inc');
print '<script type="text/javascript" src="./jquery-3.1.1.min.js"></script>'."\n";
print '<script type="text/javascript" src="./jquery.tablesorter.js"></script>'."\n";
print "<title>Wikipedia work summary</title></head><body>";
$pageSelectQuery = "select distinct task_receptacle from tasks where task_type REGEXP 'Wikipedia' and task_type != 'Attempted Wikipedia work' order by task_receptacle;";
$pageSelectResult = $mysqli -> query($pageSelectQuery);

print '{| class="sortable wikitable" border="1"';
print "\n! Page !! Creator (if paid) !! Contributors (if paid) !! Connected contributor disclosure added to talk page yet? !! Notes";

function getWikipediaUsername($worker) {
  global $mysqli;
  $sqlQuery = "select wikipedia_username from workers where worker=?";
  $stmt = $mysqli->prepare($sqlQuery);
  $stmt->bind_param("s", $worker);
  $stmt->execute();
  $sqlResult = $stmt->get_result();
  for ($i = 0; $i < $sqlResult -> num_rows; $i++) {
    $sqlRow = $sqlResult -> fetch_assoc();
    return $sqlRow['wikipedia_username'];
  }
}

function displayWithLinks($worker) {
  $wikipediaUsername = getWikipediaUsername($worker);
  return "[[User:$wikipediaUsername|$wikipediaUsername]] ([[User talk:$wikipediaUsername|talk]], [[Special:Contributions/$wikipediaUsername|contribs]]) ";
}

for($i = 0; $i < $pageSelectResult -> num_rows; $i++) {
  $pageRow = $pageSelectResult -> fetch_assoc();
  $page = $pageRow["task_receptacle"];
  print "\n|-\n| [[$page]] ";
  $pageDataQuery = "select * from tasks where task_receptacle=? and task_type REGEXP 'Wikipedia' and task_type != 'Attempted Wikipedia work';";
  $stmt = $mysqli->prepare($pageDataQuery);
  $stmt->bind_param("s", $page);
  $stmt->execute();
  $pageDataResult = $stmt->get_result();
  $creator = '';
  $contributors = array();
  for($j = 0; $j < $pageDataResult -> num_rows; $j++) {
    $dataRow = $pageDataResult -> fetch_assoc();
    $worker = $dataRow['worker'];
    if ($dataRow['task_type'] == "Wikipedia page creation" or $dataRow['task_type'] == "Wikipedia page translation") {
      $creator = $worker;
    } else {
      array_push($contributors, $worker);
    }
  }
  if ($creator == '') {
    print " || || ";
  } else {
    print " || ".displayWithLinks($creator)." || ";
  }
  foreach($contributors as $contributor) {
    print(displayWithLinks($contributor));
  }
  print " || No || ";
}
print "\n|}";
print "</body></html>";

?>
