<?php

print '<h4 id="workerImpact">Worker impact: Wikipedia</h4>';

$totalViewsQuery = "select sum(viewcount) as totalViews from wikipediaviews.viewcountsbymonth where (pagename, language) in (select distinct pagename, language from wikipediaviews.pagetags where tag = 'Pages created by $worker') and drilldown in ('desktop','mobile-web','mobile-app');";

$totalViewsResult = $mysqli -> query($totalViewsQuery);

$totalViewCount = 0;
if ($totalViewsResult -> num_rows > 0) {
  $row = $totalViewsResult -> fetch_assoc();
  $totalViewCount = $row['totalViews'];
}

$createdOrEditedPageViewsQuery = "select sum(viewcount) as totalViews from wikipediaviews.viewcountsbymonth where (pagename, language) in (select distinct pagename, language from wikipediaviews.pagetags where tag = 'Pages edited significantly but not created by $worker' or tag = 'Pages created by $worker') and drilldown in ('desktop','mobile-web','mobile-app') and language = 'en'";

$createdOrEditedPageViewsResult = $mysqli -> query($createdOrEditedPageViewsQuery);

$createdOrEditedPageViewCount = 0;
if ($createdOrEditedPageViewsResult -> num_rows > 0) {
  $row = $createdOrEditedPageViewsResult -> fetch_assoc();
  $createdOrEditedPageViewCount = $row['totalViews'];
}

$paidViewsQuery = "select sum(viewcount) as totalViews from wikipediaviews.viewcountsbymonth where pagename in (select distinct task_receptacle from tasks where worker='$worker' and task_type = 'Wikipedia page creation') and drilldown in ('desktop','mobile-web','mobile-app') and language = 'en';"; # Needs to be fixed to handle cross-language views
 
$paidViewsResult = $mysqli -> query($paidViewsQuery);

$paidViewCount = 0;
if ($paidViewsResult -> num_rows > 0) {
  $row = $paidViewsResult -> fetch_assoc();
  $paidViewCount = $row['totalViews'];
}

$paidCreatedOrEditedPageViewsQuery = "select sum(viewcount) as totalViews from wikipediaviews.viewcountsbymonth where pagename in (select distinct task_receptacle from tasks where worker='$worker' and task_type in ('Wikipedia page creation','Wikipedia page update')) and drilldown in ('desktop', 'mobile-web', 'mobile-app') and language = 'en';"; # Needs to be fixed to handle cross-language views

$paidCreatedOrEditedPageViewsResult = $mysqli -> query($paidCreatedOrEditedPageViewsQuery);

$paidCreatedOrEditedPageViewCount = 0;
if ($paidCreatedOrEditedPageViewsResult -> num_rows > 0) {
  $row = $paidCreatedOrEditedPageViewsResult -> fetch_assoc();
  $paidCreatedOrEditedPageViewCount = $row['totalViews'];
}

$costPerThousandViews = 0;
$blendedCostPerThousandViews = 0;
if ($paidViewCount > 0) {
  $costPerThousandViews = 1000 * $totalPaymentForTaskType['Wikipedia page creation']/$paidViewCount;
  $blendedCostPerThousandViews = 1000 * $totalPaymentAcrossYears/$paidViewCount;
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
print '<tr><td>Cost per thousand views (including only explicit costs for page creation)</td><td align="right">'.sprintf('%.2f',$costPerThousandViews).'</td></tr>';
print '<tr><td>Cost per thousand views (including pay for everything)</td><td align="right">'.sprintf('%.2f',$blendedCostPerThousandViews).'</td></tr>';
print "</tbody>\n</table>\n";
?>