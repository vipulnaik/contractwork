<?php

$currentTaxYear = '2017';
$standardDeduction['2015'] = 6200;
$standardDeduction['2016'] = 6300;
$standardDeduction['2017'] = 6350;
$basicExemption['2015'] = 3950;
$basicExemption['2016'] = 4050;
$basicExemption['2017'] = 4050;
$selfEmploymentFilingThreshold['2015'] = 400;
$selfEmploymentFilingThreshold['2016'] = 400;
$selfEmploymentFilingThreshold['2017'] = 400;
$minimumPayableBalance = 1;
$minimumCollectionBalance = 5;


function computeTax($taxableIncome, $year) {
  $bracket10Top['2015'] = 9225;
  $bracket15Top['2015'] = 37450;
  $bracket25Top['2015'] = 90750;
  $bracket28Top['2015'] = 189300;
  $bracket33Top['2015'] = 411500;
  $bracket35Top['2015'] = 413200;

  $bracket10Top['2016'] = 9275;
  $bracket15Top['2016'] = 37650;
  $bracket25Top['2016'] = 91150;
  $bracket28Top['2016'] = 190150;
  $bracket33Top['2016'] = 413350;
  $bracket35Top['2016'] = 415050;

  $bracket10Top['2017'] = 9325;
  $bracket15Top['2017'] = 37950;
  $bracket25Top['2017'] = 91900;
  $bracket28Top['2017'] = 191650;
  $bracket33Top['2017'] = 416700;
  $bracket35Top['2017'] = 418400;
  if ($taxableIncome < 0) {
    return 0;
  } else if ($taxableIncome < $bracket10Top[$year]) {
    return 0.1 * $taxableIncome;
  } else if ($taxableIncome < $bracket15Top[$year]) {
    return (0.1 * $bracket10Top[$year] + 0.15 * ($taxableIncome - $bracket10Top[$year]));
  } else if ($taxableIncome < $bracket25Top[$year]) {
    return (0.1 * $bracket10Top[$year] + 0.15 * ($bracket15Top[$year] - $bracket10Top[$year]) + 0.25 * ($taxableIncome - $bracket15Top[$year]));
  } else if ($taxableIncome < $bracket28Top[$year]) {
    return (0.1 * $bracket10Top[$year] + 0.15 * ($bracket15Top[$year] - $bracket10Top[$year]) + 0.25 * ($bracket25Top[$year] - $bracket15Top[$year]) + 0.28 * ($taxableIncome - $bracket25Top[$year]));
  } else if ($taxableIncome < $bracket33Top[$year]) {
    return (0.1 * $bracket10Top[$year] + 0.15 * ($bracket15Top[$year] - $bracket10Top[$year]) + 0.25 * ($bracket25Top[$year] - $bracket15Top[$year]) + 0.28 * ($bracket28Top[$year] - $bracket25Top[$year]) + 0.33 * ($taxableIncome - $bracket28Top[$year]));
  } else if ($taxableIncome < $bracket35Top[$year]) {
    return (0.1 * $bracket10Top[$year] + 0.15 * ($bracket15Top[$year] - $bracket10Top[$year]) + 0.25 * ($bracket25Top[$year] - $bracket15Top[$year]) + 0.28 * ($bracket28Top[$year] - $bracket25Top[$year]) + 0.33 * ($bracket35Top[$year] - $bracket28Top[$year]) + 0.35 * ($taxableIncome - $bracket33Top[$year]));
  } else {
    return (0.1 * $bracket10Top[$year] + 0.15 * ($bracket15Top[$year] - $bracket10Top[$year]) + 0.25 * ($bracket25Top[$year] - $bracket15Top[$year]) + 0.28 * ($bracket28Top[$year] - $bracket25Top[$year]) + 0.33 * ($bracket35Top[$year] - $bracket28Top[$year]) + 0.35 * ($bracket35Top[$year] - $bracket33Top[$year]) + 0.396 * ($taxableIncome - $bracket35Top[$year]));
  }
}
?>
