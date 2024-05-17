<?php
include_once('doctype.inc');
print '<script src="change-theme.js"></script>';
include_once("backend/globalVariables/passwordFile.inc");
include_once("backend/globalVariables/lists.inc");
include_once("backend/globalVariables/taxVariables.inc");
$worker = 'Issa Rice';
if (!empty($_REQUEST['worker'])) {
  $worker = $_REQUEST['worker'];
}
print "<title>$worker tax details: Contract work for Vipul Naik</title>";
print '<link href="style.css" rel="stylesheet" type="text/css" />'."\n";
include_once('style.inc');
include_once('analytics.inc');
print '</head>';
print '<body>';
print "<h3>$worker tax details: Contract work for Vipul Naik</h3>";
?>

<p><span id="changeThemeMenu" style="display: none;">Set color scheme to:
         <span id="auto-menu-option" style="cursor: pointer;" class="unselectable" onclick="change_theme.set_color('auto')">auto</span>,
         <span id="light-menu-option" style="cursor: pointer;" class="unselectable" onclick="change_theme.set_color('light')">light</span>,
         <span id="dark-menu-option" style="cursor: pointer;" class="unselectable" onclick="change_theme.set_color('dark')">dark</span>
</span>&thinsp;<!-- blank space to prevent cumulative layout shift --></p>

<?php
$workerSelectQuery = "select * from workers where worker=? and private = false;";
$stmt = $mysqli->prepare($workerSelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$workerSelectResult = $stmt->get_result();
if ($workerSelectResult -> num_rows == 0) {
  print '<p>Sorry, we did not find a worker with this name in our public list of workers. Go back to the <a href="/">home page</a> for a full list of workers.</p>';
} else {
  $row = $workerSelectResult -> fetch_assoc();
  $country = $row['country'];
  if ($country != "United States") {
    print "<p>Sorry! Since this worker is not based in the United States, we cannot offer information on the worker's tax situation or obligations.</p>";
  } else {
    print "<p>All payment amounts are listed in current (i.e., nominal, without inflation adjustment) United States dollars (USD).</p>";
    $printTables = false;
    include("backend/workerPaymentsDueByTypeAndYear.inc");
    include("backend/workerPaymentsMadeByMethodAndYear.inc");
    include("backend/taxAdvice.inc");
  }
}
include_once('anchorjs.inc');
print '<script>change_theme.set_theme_from_local_storage();</script>';
print '</body>';
?>
