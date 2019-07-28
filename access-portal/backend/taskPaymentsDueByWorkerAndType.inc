<?php
print '<h4 id="taskPaymentsDueByWorkerAndType">Task payments due by worker and type</h4>';

$workerSelectQuery = "select distinct worker from workers where private = false and worker != 'Linchuan Zhang';";
$workerSelectResult = $mysqli -> query($workerSelectQuery);

$workers = array();

for ($i = 0; $i < $workerSelectResult -> num_rows; $i++) {
  $workerRow = $workerSelectResult -> fetch_assoc();
  array_push($workers, $workerRow['worker']);
}

# Initialize values to zero
global $totalPaymentForTaskType;
global $totalTaskPaymentForWorker;

foreach($taskTypes as $taskType) {
  $totalPaymentForTaskType[$taskType] = 0; 
  foreach ($workers as $worker) {
    $paymentForTaskTypeAndWorker[$taskType][$worker] = 0;
  }
}  

foreach($workers as $worker) {
  $totalTaskPaymentForWorker[$worker] = 0;
}

$totalTaskPayment = 0;

# Get task payments

$taskSelectQuery = "select task_type, worker, coalesce(sum(payment), 0) as payment from tasks where worker not in ($workerSelectQuery) group by task_type, worker;";
$taskSelectResult = $mysqli -> query($taskSelectQuery);
for ($i=0; $i < $taskSelectResult -> num_rows; $i++) {
  $row = $taskSelectResult -> fetch_assoc();
  $paymentForTaskTypeAndWorker[$row['task_type']][$row['worker']] = $row['payment'];
  $totalTaskPaymentForWorker[$row['worker']] += $row['payment'];
  $totalPaymentForTaskType[$row['task_type']] += $row['payment'];
  $totalTaskPayment += $row['payment'];
}
# Sort task types

function cmpTaskTypesForWorker($firstTaskType, $secondTaskType) {
  global $totalPaymentForTaskType;
  if (intval($totalPaymentForTaskType[$firstTaskType]) == intval($totalPaymentForTaskType[$secondTaskType])) {
      return 0;
  }
  return (intval($totalPaymentForTaskType[$firstTaskType]) > intval($totalPaymentForTaskType[$secondTaskType])) ? -1 : 1;
}

function cmpWorkersForTaskType ($firstWorker, $secondWorker) {
  global $totalTaskPaymentForWorker;
  if (intval($totalTaskPaymentForWorker[$firstWorker]) == intval($totalTaskPaymentForWorker[$secondWorker])) {
      return 0;
  }
  return (intval($totalTaskPaymentForWorker[$firstWorker]) > intval($totalTaskPaymentForWorker[$secondWorker])) ? -1 : 1;
}

usort($taskTypes,"cmpTaskTypesForWorker");
usort($workers,"cmpWorkersForTaskType");

# Then print data by worker

# Print table
print "\n";
print '<table id="myTableTaskPaymentsDueByWorkerAndType" class="tablesorter">'."\n";
print "<thead>\n";
print '<tr><th>Worker</th>';
print "<th>Total across task types</th>";
foreach ($taskTypes as $taskType) {
  if ($totalPaymentForTaskType[$taskType] > 0) {
    print "<th>$taskType</th>";
  }
}
print '</tr>';
print "</thead>\n<tbody>\n";
foreach ($workers as $worker) {
  if ($totalTaskPaymentForWorker[$worker] > 0) {
    print '<tr><td><a href="/worker.php?worker='.urlencode($worker).'">'.$worker.'</a></td>';
    print '<td align="right"><strong>'.number_format($totalTaskPaymentForWorker[$worker],2).'</strong></td>';
    foreach ($taskTypes as $taskType) {
      if ($totalPaymentForTaskType[$taskType] > 0) {
        print '<td align="right">'.number_format($paymentForTaskTypeAndWorker[$taskType][$worker],2).'</td>';
      }
    }
    print '</tr>';
  }
}

print "</tbody>\n<tfoot>\n";
print '<tr><td><strong>Total across workers</strong></td>';
print '<td align="right"><strong>'.number_format($totalTaskPayment,2).'</strong></td>';
foreach($taskTypes as $taskType) {
  if ($totalPaymentForTaskType[$taskType] > 0) {
    print '<td align="right"><strong>'.number_format($totalPaymentForTaskType[$taskType],2).'</strong></td>';
  }
}
print '</tr>';

print "</tfoot>\n</table>\n";

?>
