<?php
print '<h4>Payments due by type and year</h4>';

# Initialize values to zero
foreach ($yearList as $year) {
  $taskPayment[$year] = 0;
  $commissionOnTaskPayment[$year] = 0;
  $stipendPayment[$year][0] = 0;
  $stipendPayment[$year][1] = 0;
  $royaltyPayment[$year] = 0;
  $commissionOnRoyaltyPayment[$year] = 0;
}  

# Get task payments

$taskSelectQuery = "select year(completion_date) as year, coalesce(sum(payment), 0) as payment from tasks group by year(completion_date);";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $taskPayment[$row['year']] = $row['payment'];
}

# Get commission on task payments
$commissionOnTaskSelectQuery = "select year(completion_date) as year, coalesce(sum(payment), 0) as payment from (select completion_date, (commission * payment) as payment from commissions left join tasks on commissions.earner = tasks.worker where (commission_validity_start is null or tasks.completion_date >= commission_validity_start) and (commission_validity_end is null or tasks.completion_date <= commission_validity_end)) t1 group by year(completion_date);";
$commissionOnTaskSelectResult = $mysqli -> query($commissionOnTaskSelectQuery);
for ($i = 0; $i < $commissionOnTaskSelectResult -> num_rows; $i++) {
  $row = $commissionOnTaskSelectResult -> fetch_assoc();
  $commissionOnTaskPayment[$row['year']] = $row['payment'];
}

# Get stipend payments

$stipendSelectQuery = "select year(stipend_end_date) as year, (stipend_award_date is not null) as awarded, coalesce(sum(payment), 0) as payment  from stipends group by year(stipend_end_date), (stipend_award_date is not null);";
$stipendSelectResult = $mysqli -> query($stipendSelectQuery);
for ($i = 0; $i < $stipendSelectResult -> num_rows; $i++) {
  $row = $stipendSelectResult -> fetch_assoc();
  $stipendPayment[$row['year']][$row['awarded']] = $row['payment'];
}

# Get royalty payments
$royaltySelectQuery = "select year(royalty_end_date) as year, coalesce(sum(payment), 0) as payment from royalties group by year(royalty_end_date);";
$royaltySelectResult = $mysqli -> query($royaltySelectQuery);
for ($i = 0; $i < $royaltySelectResult -> num_rows; $i++) {
  $row = $royaltySelectResult -> fetch_assoc();
  $royaltyPayment[$row['year']] = $row['payment'];
}

# Get commission on royalty payments
$commissionOnRoyaltySelectQuery = "select year(royalty_end_date) as year, coalesce(sum(payment), 0) as payment from (select royalty_end_date, (commission * payment) as payment from commissions left join royalties on commissions.earner = royalties.payee where (commission_validity_start is null or royalties.royalty_start_date >= commission_validity_start) and (commission_validity_end is null or royalties.royalty_end_date <= commission_validity_end)) t1 group by year(royalty_end_date);";
$commissionOnRoyaltySelectResult = $mysqli -> query($commissionOnRoyaltySelectQuery);
for ($i = 0; $i < $commissionOnRoyaltySelectResult -> num_rows; $i++) {
  $row = $commissionOnRoyaltySelectResult -> fetch_assoc();
  $commissionOnRoyaltyPayment[$row['year']] = $row['payment'];
}

foreach($yearList as $year) {
  $totalPaymentAwarded[$year] = 0;
  $totalPayment[$year] = 0;
  $totalPaymentAwarded[$year] = $taskPayment[$year] + $commissionOnTaskPayment[$year]  + $stipendPayment[$year][0] + $royaltyPayment[$year] + $commissionOnRoyaltyPayment[$year];
  $totalPayment[$year] = $totalPaymentAwarded[$year] + $stipendPayment[$year][0];
}

# Print table
print '<table border="1">';
print '<tr><th>Type of payment due</th>';
foreach ($yearList as $year) {
  print "<th>Total in year $year</th>";
}
print '</tr>';
print '<tr><td>Tasks</td>';
foreach ($yearList as $year) {
  print '<td align="right">'.$taskPayment[$year].'</td>';
}
print '</tr>';
print '<tr><td>Commissions on tasks</td>';
foreach ($yearList as $year) {
  print '<td align="right">'.$commissionOnTaskPayment[$year].'</td>';
}
print '</tr>';
print '</tr>';
print '<tr><td>Stipends (awarded)</td>';
foreach ($yearList as $year) {
  print '<td align="right">'.$stipendPayment[$year][1].'</td>';
}
print '</tr>';
print '<tr><td>Royalties</td>';
foreach ($yearList as $year) {
  print '<td align="right">'.$royaltyPayment[$year].'</td>';
}
print '</tr>';
print '<tr><td>Commissions on royalties</td>';
foreach ($yearList as $year) {
  print '<td align="right">'.$commissionOnRoyaltyPayment[$year].'</td>';
}
print '</tr>';
print '<tr><td><strong>Total payment awarded</strong></td>';
foreach ($yearList as $year) {
  print '<td align="right"><strong>'.$totalPaymentAwarded[$year].'</strong></td>';
}
print '</tr>';
print '<tr><td>Stipends (deferred)</td>';
foreach ($yearList as $year) {
  print '<td align="right">'.$stipendPayment[$year][0].'</td>';
}
print '</tr>';
print '<tr><td><strong>Total payment</strong></td>';
foreach ($yearList as $year) {
  print '<td align="right"><strong>'.$totalPayment[$year].'</strong></td>';
}
print '</tr>';

print '</table>';
?>