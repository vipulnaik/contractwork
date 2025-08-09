<?php
include_once('doctype.inc');
print '<script src="change-theme.js"></script>';
include_once("backend/globalVariables/passwordFile.inc");
include_once("backend/globalVariables/lists.inc");
include_once("backend/functions.inc");
include_once('backend/graphing.inc');
include_once('analytics.inc');
include_once('strip-commas.inc');
print '<link href="style.css" rel="stylesheet" type="text/css" />'."\n";
include_once('style.inc');
print '<script type="text/javascript" src="./jquery-3.7.1.min.js"></script>'."\n";
print '<script type="text/javascript" src="./jquery.tablesorter.js"></script>'."\n";
$venue = '';
$matchingMethod = "REGEXP";
if (!empty($_REQUEST['venue'])) {
  $venue = $_REQUEST['venue'];
}
if (!empty($_REQUEST['matching'])) {
  $matching = $_REQUEST['matching'];
  if ($matching == "exact") {
    $matchingMethod = "=";
  }
}
$venueRegexMatcherParamStr = "";
$venueRegexMatcherParams = array();
if ($venue != '') {
  $venueRegexMatcher = "`task_venue` $matchingMethod ?";
  $venueRegexMatcherParamStr .= "s";
  $venueRegexMatcherParams[] = $venue;
  print "<title>" . htmlspecialchars($venue) . " venue work details: Contract work for Vipul Naik</title>";
  print '</head>';
  print '<body>';
  print '<script>$(document).ready(function(){$("table").tablesorter({textExtraction: stripCommas});});</script>'."\n";
  print "<h3>Contract work related to venue " . htmlspecialchars($venue) . " for Vipul Naik</h3>";
} else {
  $venueRegexMatcher = '1 = 1';
  print "<title>All task details: Contract work for Vipul Naik</title>";
  print '</head>';
  print '<body>';
  print '<script>$(document).ready(function(){$("table").tablesorter({textExtraction: stripCommas});});</script>'."\n";
  print "<h3>Contract work (all tasks) for Vipul Naik</h3>";
}
?>

<p><span id="changeThemeMenu" style="display: none;">Set color scheme to:
         <span id="auto-menu-option" style="cursor: pointer;" class="unselectable" onclick="change_theme.set_color('auto')">auto</span>,
         <span id="light-menu-option" style="cursor: pointer;" class="unselectable" onclick="change_theme.set_color('light')">light</span>,
         <span id="dark-menu-option" style="cursor: pointer;" class="unselectable" onclick="change_theme.set_color('dark')">dark</span>
</span>&thinsp;<!-- blank space to prevent cumulative layout shift --></p>
<script>change_theme.set_theme_from_local_storage();</script>

<?php
$taskSelectQuery = "select * from tasks where $venueRegexMatcher and private = false;";
$stmt = $mysqli->prepare($taskSelectQuery);
if ($venueRegexMatcherParams) {
  $stmt->bind_param($venueRegexMatcherParamStr, ...$venueRegexMatcherParams);
}
$stmt->execute();
$taskSelectResult = $stmt->get_result();
if ($taskSelectResult -> num_rows == 0) {
  print "<p>We could not find any tasks with a matching venue.</p>";
} else {
  print '<h4>Table of contents</h4>';
  print '<ul>';
  print '<li><a href="#venueTaskPaymentsDueByTypeAndYear">Venue task payments due by type and year</a></li>';
  print '<li><a href="#venueTaskPaymentsDueByPayerAndYear">Venue task payments due by payer and year</a></li>';
  print '<li><a href="#venueTaskPaymentsDueByWorkerAndYear">Venue task payments due by worker and year</a></li>';
  print '<li><a href="#venueTaskPaymentsDueByTypeAndMonth">Venue task payments due by type and month</a></li>';
  print '<li><a href="#venueTaskPaymentsDueByPayerAndMonth">Venue task payments due by payer and month</a></li>';
  print '<li><a href="#venueTaskPaymentsDueByWorkerAndMonth">Venue task payments due by worker and month</a></li>';
  print '<li><a href="#venueTaskList">Venue task list</a></li>';
  print '</ul>';
  include("backend/venueTaskPaymentsDueByTypeAndYear.inc");
  include("backend/venueTaskPaymentsDueByPayerAndYear.inc");
  include("backend/venueTaskPaymentsDueByWorkerAndYear.inc");
  include("backend/venueTaskPaymentsDueByTypeAndMonth.inc");
  include("backend/venueTaskPaymentsDueByPayerAndMonth.inc");
  include("backend/venueTaskPaymentsDueByWorkerAndMonth.inc");
  include("backend/venueTaskList.inc");
}
include_once('anchorjs.inc');
print '</body>';
?>
