<?php

function timeSeriesGraphs($timePeriods, $group, $timePeriodAmount,
    $amountByGroupAndTimePeriod, $generateGraphCmdBase, $imagesPath,
    $permalinkUrlBase, $graphIdentifier) {
  $cumulativeTotal = 0;
  $cumulativeForGroup = array();

  // If a dash is present in the first time period, like "2010-01", then
  // consider the graph to be monthly, otherwise default to yearly
  if (strpos($timePeriods[0], "-") === false) {
    $dataForGraph = "Year";
    $dataForCumulativeGraph = "Year";
  } else {
    $dataForGraph = "Month";
    $dataForCumulativeGraph = "Month";
  }

  $timePeriodsCopy = $timePeriods;
  $groupCopy = $group;
  sort($timePeriodsCopy);

  // Remove group elements that are zero across all time periods
  foreach ($groupCopy as $g) {
    if (array_sum($amountByGroupAndTimePeriod[$g]) == 0) {
      $group = array_diff($group, array($g));
    }
  }

  foreach ($group as $i) {
    $dataForGraph .= "|$i";
    $dataForCumulativeGraph .= "|$i";
  }
  $dataForGraph .= "|Total\n";
  $dataForCumulativeGraph .= "|Total\n";

  /* Populate all the rows for each time period */
  foreach ($timePeriodsCopy as $p) {
    if (($timePeriodAmount[$p] ?? 0) != 0) {
      $dataForGraph .= "$p";
      $dataForCumulativeGraph .= "$p";
      foreach ($group as $i) {
        if (!isset($cumulativeForGroup[$i])) {
          $cumulativeForGroup[$i] = 0;
        }
        $cumulativeForGroup[$i] += ($amountByGroupAndTimePeriod[$i][$p] ?? 0);
        $dataForGraph .= "|" .
          sprintf("%d", $amountByGroupAndTimePeriod[$i][$p] ?? 0);
        $dataForCumulativeGraph .= "|" .
          sprintf("%d", $cumulativeForGroup[$i] ?? 0);
      }
      $cumulativeTotal += $timePeriodAmount[$p];
      $dataForGraph .= "|" . sprintf("%d", $timePeriodAmount[$p]) . "\n";
      $dataForCumulativeGraph .= "|" . sprintf("%d", $cumulativeTotal) . "\n";
    }
  }

  /* Populate the totals row */
  $dataForGraph .= "Total";
  $dataForCumulativeGraph .= "Total";
  foreach ($group as $i) {
    if (!isset($cumulativeForGroup[$i])) {
      $cumulativeForGroup[$i] = 0;
    }
    $dataForGraph .= "|" . sprintf("%d", $cumulativeForGroup[$i]);
    $dataForCumulativeGraph .= "|" . sprintf("%d", $cumulativeForGroup[$i]);
  }
  $dataForGraph .= "|" . sprintf("%d", $cumulativeTotal) . "\n";
  $dataForCumulativeGraph .= "|" . sprintf("%d", $cumulativeTotal) . "\n";

  $permalinkUrl = $permalinkUrlBase . $graphIdentifier;
  $fileName = hash("md5", $permalinkUrl);
  $filePathBase = $imagesPath . $fileName;
  $dataHasChanged= false;
  if (file_exists(! $filePathBase . ".csv")) {
    file_put_contents($filePathBase . ".csv", $dataForGraph);
    $dataHasChanged = true;
  } else {
    $previousOutput = file_get_contents($filePathBase . ".csv");
    if ($previousOutput != $dataForGraph) {
      $dataHasChanged = true;
      file_put_contents($filePathBase . ".csv", $dataForGraph);
    }
  }

  /* Incremental graph */
  $cmdToExecute = $generateGraphCmdBase . " " . $filePathBase . ".csv " .
    $filePathBase . "-timeseries.png";
  if ($dataHasChanged or ! file_exists($filePathBase . "-timeseries.png")) {
    if (file_exists($filePathBase . "-timeseries.png")) {
      exec("rm " . $filePathBase . "-timeseries.png");
    }
    exec($cmdToExecute);
  }

  /* Cumulative graph */
  $fileNameCumulative = hash("md5", $permalinkUrl . "-cumulative");
  $filePathBaseCumulative = $imagesPath . $fileNameCumulative;
  $dataHasChangedCumulative = false;
  if (! file_exists($filePathBaseCumulative . ".csv")) {
    file_put_contents($filePathBaseCumulative . ".csv",
      $dataForCumulativeGraph);
    $dataHasChangedCumulative = true;
  } else {
    $previousOutput = file_get_contents($filePathBaseCumulative . ".csv");
    if ($previousOutput != $dataForCumulativeGraph) {
      $dataHasChangedCumulative = true;
      file_put_contents($filePathBaseCumulative . ".csv",
        $dataForCumulativeGraph);
    }
  }
  $cmdToExecuteCumulative = $generateGraphCmdBase . " " .
    $filePathBaseCumulative . ".csv " . $filePathBaseCumulative .
    "-timeseries.png";
  if ($dataHasChangedCumulative or ! file_exists($filePathBaseCumulative .
      "-timeseries.png")) {
    if (file_exists($filePathBaseCumulative . "-timeseries.png")) {
      exec("rm ".$filePathBaseCumulative . "-timeseries.png");
    }
    exec($cmdToExecuteCumulative);
  }

  return array($fileName, $fileNameCumulative);
}

?>
