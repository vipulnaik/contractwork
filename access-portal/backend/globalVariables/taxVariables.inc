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

function computeTax($taxableIncome) {
  if ($taxableIncome < 9325) {
    return 0.1 * $taxableIncome;
  } else if ($taxableIncome < 37950) {
    return (932.5 + 0.15 * ($taxableIncome - 9325));
  } else if ($taxableIncome < 91900) {
    return (5226.25 + 0.25 * ($taxableIncome - 37950));
  } else if ($taxableIncome < 191650) {
    return (18713.75 + 0.28 * ($taxableIncome - 91900));
  } else if ($taxableIncome < 416700) {
    return (46643.75 + 0.33 * ($taxableIncome - 191650));
  } else if ($taxableIncome < 418400) {
    return (120910.25 + 0.35 * ($taxableIncome - 416700));
  } else {
    return (121505.25 + 0.396 * ($taxableIncome - 418400));
  }
}
?>
