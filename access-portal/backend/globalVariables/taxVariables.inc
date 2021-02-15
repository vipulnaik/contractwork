<?php

$currentTaxYear = '2021';
$mostRecentCompletedTaxYear = '2020';

$s1scLineNumber['2018'] = 12;
$s1TotalIncomeLineNumber['2018'] = 22;
$s1sseLineNumber['2018'] = 27;
$s1TotalDeductionLineNumber['2018'] = 36;

$s1scLineNumber['2019'] = 3;
$s1TotalIncomeLineNumber['2019'] = 9;
$s1sseLineNumber['2019'] = 14;
$s1TotalDeductionLineNumber['2019'] = 22;

$s1scLineNumber['2020'] = 3;
$s1TotalIncomeLineNumber['2020'] = 9;
$s1sseLineNumber['2020'] = 14;
$s1TotalDeductionLineNumber['2020'] = 22;

$s1scLineNumber['2021'] = 3;
$s1TotalIncomeLineNumber['2021'] = 9;
$s1sseLineNumber['2021'] = 14;
$s1TotalDeductionLineNumber['2021'] = 22;

$s1InMainFormLineNumber['2018'] = '6 (inner blank)';
$totalIncomeLineNumber['2018'] = 6;
$agiLineNumber['2018'] = 7;
$standardOrItemizedDeductionLineNumber['2018'] = 8;
$taxableIncomeLineNumber['2018'] = 10;
$taxLineNumber['2018'] = 11;
$setInMainFormLineNumber['2018'] = 14;
$totalTaxLineNumber['2018'] = 15;
$totalPaymentsLineNumber['2018'] = 18;

$s1InMainFormLineNumber['2019'] = '7a';
$totalIncomeLineNumber['2019'] = '7b';
$adjustmentsToIncomeLineNumber['2019'] = '8a';
$agiLineNumber['2019'] = '8b';
$standardOrItemizedDeductionLineNumber['2019'] = 9;
$totalDeductionLineNumber['2019'] = '11a';
$taxableIncomeLineNumber['2019'] = '11b';
$taxLineNumber['2019'] = '12a';
$setInMainFormLineNumber['2019'] = 15;
$totalTaxLineNumber['2019'] = 16;
$totalPaymentsLineNumber['2019'] = 19;

$s1InMainFormLineNumber['2020'] = 8;
$totalIncomeLineNumber['2020'] = 9;
$adjustmentsToIncomeLineNumber['2020'] = '10a and 10c';
$agiLineNumber['2020'] = 11;
$standardOrItemizedDeductionLineNumber['2020'] = 12;
$totalDeductionLineNumber['2020'] = 14;
$taxableIncomeLineNumber['2020'] = 15;
$taxLineNumber['2020'] = 16;
$setInMainFormLineNumber['2020'] = 23;
$totalTaxLineNumber['2020'] = 24;
$totalPaymentsLineNumber['2020'] = 33;

$s1InMainFormLineNumber['2021'] = 8;
$totalIncomeLineNumber['2021'] = 9;
$adjustmentsToIncomeLineNumber['2021'] = '10a and 10c';
$agiLineNumber['2021'] = 11;
$standardOrItemizedDeductionLineNumber['2021'] = 12;
$totalDeductionLineNumber['2021'] = 14;
$taxableIncomeLineNumber['2021'] = 15;
$taxLineNumber['2021'] = 16;
$setInMainFormLineNumber['2021'] = 23;
$totalTaxLineNumber['2021'] = 24;
$totalPaymentsLineNumber['2021'] = 33;


$standardDeduction['2015'] = 6200;
$standardDeduction['2016'] = 6300;
$standardDeduction['2017'] = 6350;
$standardDeduction['2018'] = 12000;
$standardDeduction['2019'] = 12200;
$standardDeduction['2020'] = 12400;
$basicExemption['2015'] = 3950;
$basicExemption['2016'] = 4050;
$basicExemption['2017'] = 4050;
$basicExemption['2018'] = 0;
$basicExemption['2019'] = 0;
$basicExemption['2020'] = 0;
$selfEmploymentFilingThreshold['2015'] = 400;
$selfEmploymentFilingThreshold['2016'] = 400;
$selfEmploymentFilingThreshold['2017'] = 400;
$selfEmploymentFilingThreshold['2018'] = 400;
$selfEmploymentFilingThreshold['2019'] = 400;
$selfEmploymentFilingThreshold['2020'] = 400;
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

  $bracket10Top['2018'] = 9525;
  $bracket12Top['2018'] = 38700;
  $bracket22Top['2018'] = 82500;
  $bracket24Top['2018'] = 157500;
  $bracket32Top['2018'] = 200000;
  $bracket35Top['2018'] = 500000;

  $bracket10Top['2019'] = 9700;
  $bracket12Top['2019'] = 39475;
  $bracket22Top['2019'] = 84200;
  $bracket24Top['2019'] = 160725;
  $bracket32Top['2019'] = 204100;
  $bracket35Top['2019'] = 510300;

  $bracket10Top['2020'] = 9875;
  $bracket12Top['2020'] = 40125;
  $bracket22Top['2019'] = 85525;
  $bracket24Top['2019'] = 163300;
  $bracket32Top['2019'] = 207350;
  $bracket35Top['2019'] = 518400;

  if ($taxableIncome < 0) {
    return 0;
  } else if ($year <= '2017') {
    if ($taxableIncome < $bracket10Top[$year]) {
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
  } else {
    if ($taxableIncome < $bracket10Top[$year]) {
      return 0.1 * $taxableIncome;
    } else if ($taxableIncome < $bracket12Top[$year]) {
      return (0.1 * $bracket10Top[$year] + 0.12 * ($taxableIncome - $bracket10Top[$year]));
    } else if ($taxableIncome < $bracket22Top[$year]) {
      return (0.1 * $bracket10Top[$year] + 0.12 * ($bracket12Top[$year] - $bracket10Top[$year]) + 0.22 * ($taxableIncome - $bracket12Top[$year]));
    } else if ($taxableIncome < $bracket24Top[$year]) {
      return (0.1 * $bracket10Top[$year] + 0.12 * ($bracket12Top[$year] - $bracket10Top[$year]) + 0.22 * ($bracket22Top[$year] - $bracket12Top[$year]) + 0.24 * ($taxableIncome - $bracket22Top[$year]));
    } else if ($taxableIncome < $bracket32Top[$year]) {
      return (0.1 * $bracket10Top[$year] + 0.12 * ($bracket12Top[$year] - $bracket10Top[$year]) + 0.22 * ($bracket22Top[$year] - $bracket12Top[$year]) + 0.24 * ($bracket24Top[$year] - $bracket22Top[$year]) + 0.32 * ($taxableIncome - $bracket24Top[$year]));
    } else if ($taxableIncome < $bracket35Top[$year]) {
      return (0.1 * $bracket10Top[$year] + 0.12 * ($bracket12Top[$year] - $bracket10Top[$year]) + 0.22 * ($bracket22Top[$year] - $bracket12Top[$year]) + 0.24 * ($bracket24Top[$year] - $bracket22Top[$year]) + 0.32 * ($bracket32Top[$year] - $bracket24Top[$year]) + 0.35 * ($taxableIncome - $bracket32Top[$year]));
    } else {
      return (0.1 * $bracket10Top[$year] + 0.12 * ($bracket12Top[$year] - $bracket10Top[$year]) + 0.22 * ($bracket22Top[$year] - $bracket12Top[$year]) + 0.24 * ($bracket24Top[$year] - $bracket22Top[$year]) + 0.32 * ($bracket32Top[$year] - $bracket24Top[$year]) + 0.35 * ($bracket35Top[$year] - $bracket32Top[$year]) + 0.37 * ($taxableIncome - $bracket35Top[$year]));
    }
  }
}
?>
