<?php

print '<h4 id="workerImpact">Worker impact: Wikipedia</h4>';

$totalViewsQuery = "select sum(viewcount) as totalViews from wikipediaviews.viewcountsbymonth_all where pagename in (select distinct pagename from wikipediaviews.pagetags where tag = 'Pages created by $worker') and drilldown in ('desktop','mobile-web','mobile-app') and language = 'en';";

$totalViewsResult = $mysqli -> query($totalViewsQuery);

$totalViewCount = 0;
if ($totalViewsResult -> num_rows > 0) {
  $row = $totalViewsResult -> fetch_assoc();
  $totalViewCount = $row['totalViews'];
}

$paidViewsQuery = "select sum(viewcount) as totalViews from wikipediaviews.viewcountsbymonth_all where pagename in (select distinct task_receptacle from tasks where worker='$worker' and task_type = 'Wikipedia page creation') and drilldown in ('desktop','mobile-web','mobile-app') and language = 'en';";

$paidViewsResult = $mysqli -> query($paidViewsQuery);

$paidViewCount = 0;
if ($paidViewsResult -> num_rows > 0) {
  $row = $paidViewsResult -> fetch_assoc();
  $paidViewCount = $row['totalViews'];
}

$costPerThousandViews = 0;
$blendedCostPerThousandViews = 0;
if ($paidViewCount > 0) {
  $costPerThousandViews = 1000 * $totalPaymentForTaskType['Wikipedia page creation']/$paidViewCount;
  $blendedCostPerThousandViews = 1000 * $totalPaymentAcrossYears/$paidViewCount;
}
print '<table border="1">';
print '<tr><th>Item</th><th>Value</th></tr>';
print '<tr><td>Total pageviews of all Wikipedia pages created</td><td align="right">'.sprintf('%.2f',$totalViewCount).'</td></tr>';
print '<tr><td>Total pageviews of Wikipedia pages created as contract work</td><td align="right">'.sprintf('%.2f',$paidViewCount).'</td></tr>';
print '<tr><td>Cost per thousand views (including only explicit costs for page creation)</td><td align="right">'.sprintf('%.2f',$costPerThousandViews).'</td></tr>';
print '<tr><td>Cost per thousand views (including pay for everything)</td><td align="right">'.sprintf('%.2f',$blendedCostPerThousandViews).'</td></tr>';
print '</table>';
?>