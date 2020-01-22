<?php

print '<h4 id="workerImpact">Worker impact: Wikipedia</h4>';

$totalViewsQuery = "select sum(viewcount) as totalViews from wikipediaviews.viewcountsbymonth where (pagename, language) in (select distinct pagename, language from wikipediaviews.pagetags where tag = ?) and drilldown in ('desktop','mobile-web','mobile-app');";
$stmt = $mysqli->prepare($totalViewsQuery);
$stmt->bind_param("s", "Pages created by $worker");
$stmt->execute();
$totalViewsResult = $stmt->get_result();

$totalViewCount = 0;
if ($totalViewsResult -> num_rows > 0) {
  $row = $totalViewsResult -> fetch_assoc();
  $totalViewCount = $row['totalViews'];
}

$createdOrEditedPageViewsQuery = "select sum(viewcount) as totalViews from wikipediaviews.viewcountsbymonth where (pagename, language) in (select distinct pagename, language from wikipediaviews.pagetags where tag = ? or tag = ?) and drilldown in ('desktop','mobile-web','mobile-app')";
$stmt = $mysqli->prepare($createdOrEditedPageViewsQuery);
$stmt->bind_param("ss", "Pages edited significantly but not created by $worker", "Pages created by $worker");
$createdOrEditedPageViewsResult = $stmt->get_result();

$createdOrEditedPageViewCount = 0;
if ($createdOrEditedPageViewsResult -> num_rows > 0) {
  $row = $createdOrEditedPageViewsResult -> fetch_assoc();
  $createdOrEditedPageViewCount = $row['totalViews'];
}

$paidViewsQuery = "select sum(viewcount) as totalViews from wikipediaviews.viewcountsbymonth where (pagename,language) in (select distinct task_receptacle,language from tasks where worker=? and task_type in ('Wikipedia page creation','Wikipedia page translation')) and drilldown in ('desktop','mobile-web','mobile-app');";
$stmt = $mysqli->prepare($paidViewsQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$paidViewsResult = $stmt->get_result();

$paidViewCount = 0;
if ($paidViewsResult -> num_rows > 0) {
  $row = $paidViewsResult -> fetch_assoc();
  $paidViewCount = $row['totalViews'];
}

$paidCreatedOrEditedPageViewsQuery = "select sum(viewcount) as totalViews from wikipediaviews.viewcountsbymonth where (pagename,language) in (select distinct task_receptacle,language from tasks where worker=? and task_type in ('Wikipedia page creation','Wikipedia page translation','Wikipedia page update')) and drilldown in ('desktop', 'mobile-web', 'mobile-app');";
$stmt = $mysqli->prepare($paidCreatedOrEditedPageViewsQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$paidCreatedOrEditedPageViewsResult = $stmt->get_result();

$paidCreatedOrEditedPageViewCount = 0;
if ($paidCreatedOrEditedPageViewsResult -> num_rows > 0) {
  $row = $paidCreatedOrEditedPageViewsResult -> fetch_assoc();
  $paidCreatedOrEditedPageViewCount = $row['totalViews'];
}

$costPerThousandViews = 0;
$blendedCostPerThousandViews = 0;
if ($paidViewCount > 0) {
  $costPerThousandViews = 1000 * ($totalPaymentForTaskType['Wikipedia page creation'] + $totalPaymentForTaskType['Wikipedia page translation'])/$paidViewCount;
  $blendedCostPerThousandViews = 1000 * $totalPaymentAcrossYears/$paidViewCount;
}
$costPerThousandViewsCreatedOrEdited = 0;
$blendedCostPerThousandViewsCreatedOrEdited = 0;
if ($paidCreatedOrEditedPageViewCount > 0) {
  $costPerThousandViewsCreatedOrEdited = 1000 * ($totalPaymentForTaskType['Wikipedia page creation'] + $totalPaymentForTaskType['Wikipedia page translation'] + $totalPaymentForTaskType['Wikipedia page update'])/$paidCreatedOrEditedPageViewCount;
  $blendedCostPerThousandViewsCreatedOrEdited = 1000 * $totalPaymentAcrossYears/$paidCreatedOrEditedPageViewCount;
}

print "\n";
print '<table id="myTableWorkerImpact" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Item</th><th>Value</th></tr>';
print "</thead>\n<tbody>\n";
print '<tr><td>Total pageviews of all Wikipedia pages created</td><td align="right">'.number_format($totalViewCount,2).'</td></tr>';
print '<tr><td>Total pageviews of all Wikipedia pages created or edited significantly</td><td align="right">'.number_format($createdOrEditedPageViewCount,2).'</td></tr>';
print '<tr><td>Total pageviews of Wikipedia pages created as contract work</td><td align="right">'.number_format($paidViewCount,2).'</td></tr>';
print '<tr><td>Total pageviews of Wikipedia pages created or edited (not necessarily significantly) as contract work</td><td align="right">'.number_format($paidCreatedOrEditedPageViewCount,2).'</td></tr>';
print '<tr><td>Cost per thousand views of pages created (including only explicit costs for page creation)</td><td align="right">'.number_format($costPerThousandViews,2).'</td></tr>';
print '<tr><td>Cost per thousand views of pages created (including pay for everything)</td><td align="right">'.number_format($blendedCostPerThousandViews,2).'</td></tr>';
print '<tr><td>Cost per thousand views of pages created or edited (including only explicit costs for page creation and editing)</td><td align="right">'.number_format($costPerThousandViewsCreatedOrEdited,2).'</td></tr>';
print '<tr><td>Cost per thousand views of pages created or edited (including pay for everything)</td><td align="right">'.number_format($blendedCostPerThousandViewsCreatedOrEdited,2).'</td></tr>';
print "</tbody>\n</table>\n";
?>
