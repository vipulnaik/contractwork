<?php

print '<h4 id="workerImpact">Worker impact: Wikipedia</h4>';

$totalViewsQuery = "select sum(viewcount) as totalViews from wikipediaviews.viewcountsbymonth where (pagename, language) in (select distinct pagename, language from wikipediaviews.pagetags where tag = ".'"'."Pages created by ".str_replace('"','\"',$worker).'"'.") and drilldown in ('desktop','mobile-web','mobile-app');";

$totalViewsResult = $mysqli -> query($totalViewsQuery);

$totalViewCount = 0;
if ($totalViewsResult -> num_rows > 0) {
  $row = $totalViewsResult -> fetch_assoc();
  $totalViewCount = $row['totalViews'];
}

$createdOrEditedPageViewsQuery = "select sum(viewcount) as totalViews from wikipediaviews.viewcountsbymonth where (pagename, language) in (select distinct pagename, language from wikipediaviews.pagetags where tag = ".'"'."Pages edited significantly but not created by ".str_replace('"','\"',$worker).'"'." or tag = ".'"'."Pages created by ".str_replace('"','\"',$worker).'"'.") and drilldown in ('desktop','mobile-web','mobile-app')";

$createdOrEditedPageViewsResult = $mysqli -> query($createdOrEditedPageViewsQuery);

$createdOrEditedPageViewCount = 0;
if ($createdOrEditedPageViewsResult -> num_rows > 0) {
  $row = $createdOrEditedPageViewsResult -> fetch_assoc();
  $createdOrEditedPageViewCount = $row['totalViews'];
}

$paidViewsQuery = "select sum(viewcount) as totalViews from wikipediaviews.viewcountsbymonth where (pagename,language) in (select distinct task_receptacle,language from tasks where worker=".'"'.str_replace('"','\"',$worker).'"'." and task_type in ('Wikipedia page creation','Wikipedia page translation')) and drilldown in ('desktop','mobile-web','mobile-app');";
 
$paidViewsResult = $mysqli -> query($paidViewsQuery);

$paidViewCount = 0;
if ($paidViewsResult -> num_rows > 0) {
  $row = $paidViewsResult -> fetch_assoc();
  $paidViewCount = $row['totalViews'];
}

$paidCreatedOrEditedPageViewsQuery = "select sum(viewcount) as totalViews from wikipediaviews.viewcountsbymonth where (pagename,language) in (select distinct task_receptacle,language from tasks where worker=".'"'.str_replace('"','\"',$worker).'"'." and task_type in ('Wikipedia page creation','Wikipedia page translation','Wikipedia page update')) and drilldown in ('desktop', 'mobile-web', 'mobile-app');";

$paidCreatedOrEditedPageViewsResult = $mysqli -> query($paidCreatedOrEditedPageViewsQuery);

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
print '<tr><td>Total pageviews of all Wikipedia pages created</td><td align="right">'.sprintf('%.2f',$totalViewCount).'</td></tr>';
print '<tr><td>Total pageviews of all Wikipedia pages created or edited significantly</td><td align="right">'.sprintf('%.2f',$createdOrEditedPageViewCount).'</td></tr>';
print '<tr><td>Total pageviews of Wikipedia pages created as contract work</td><td align="right">'.sprintf('%.2f',$paidViewCount).'</td></tr>';
print '<tr><td>Total pageviews of Wikipedia pages created or edited (not necessarily significantly) as contract work</td><td align="right">'.sprintf('%.2f',$paidCreatedOrEditedPageViewCount).'</td></tr>';
print '<tr><td>Cost per thousand views of pages created (including only explicit costs for page creation)</td><td align="right">'.sprintf('%.2f',$costPerThousandViews).'</td></tr>';
print '<tr><td>Cost per thousand views of pages created (including pay for everything)</td><td align="right">'.sprintf('%.2f',$blendedCostPerThousandViews).'</td></tr>';
print '<tr><td>Cost per thousand views of pages created or edited (including only explicit costs for page creation and editing)</td><td align="right">'.sprintf('%.2f',$costPerThousandViewsCreatedOrEdited).'</td></tr>';
print '<tr><td>Cost per thousand views of pages created or edited (including pay for everything)</td><td align="right">'.sprintf('%.2f',$blendedCostPerThousandViewsCreatedOrEdited).'</td></tr>';
print "</tbody>\n</table>\n";
?>