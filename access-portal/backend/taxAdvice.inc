<?php

$reimbursementSelectQuery = "select year(receipt_date) as year, coalesce(sum(sent_payment), 0) as payment from payments where intermediary=? and receipt_date is not null group by year(receipt_date) order by year(receipt_date);";
$stmt = $mysqli->prepare($reimbursementSelectQuery);
$stmt->bind_param("s", $worker);
$stmt->execute();
$reimbursementSelectResult = $stmt->get_result();
$reimbursementDueInYear = array();
foreach($yearList as $year) {
  $reimbursementDueInYear[$year] = 0;
}

for($i = 0;$i < $reimbursementSelectResult -> num_rows;$i++) {
  $row = $reimbursementSelectResult -> fetch_assoc();
  $reimbursementDueInYear[$row['year']] = $row['payment'];
}

$upwardTaxAdjustmentsQuery = "select payment_finalization_year as year, coalesce(sum(adjustment), 0) as adjustment from tax_adjustments group by payment_finalization_year;";
$upwardTaxAdjustmentsResult = $mysqli -> query($upwardTaxAdjustmentsQuery);
$upwardTaxAdjustmentForYear = array();
foreach($yearList as $year) {
  $upwardTaxAdjustmentForYear[$year] = 0;
}

for($i = 0;$i < $upwardTaxAdjustmentsResult -> num_rows;$i++) {
  $row = $upwardTaxAdjustmentsResult -> fetch_assoc();
  print "<p>Upward recording adjustment: ".$row['year'].",".$row['adjustment']."</p>\n";
  $upwardTaxAdjustmentForYear[$row['year']] = $row['adjustment'];
}

$downwardTaxAdjustmentsQuery = "select completion_year as year, coalesce(sum(adjustment), 0) as adjustment from tax_adjustments group by completion_year;";
$downwardTaxAdjustmentsResult = $mysqli -> query($downwardTaxAdjustmentsQuery);
$downwardTaxAdjustmentForYear = array();
foreach($yearList as $year) {
  $downwardTaxAdjustmentForYear[$year] = 0;
}

for($i = 0;$i < $downwardTaxAdjustmentsResult -> num_rows;$i++) {
  $row = $downwardTaxAdjustmentsResult -> fetch_assoc();
  print "<p>Downward recording adjustment: ".$row['year'].",".$row['adjustment']."</p>\n";
  $downwardTaxAdjustmentForYear[$row['year']] = $row['adjustment'];
}

function hyperlinkedTaxForm($year, $slug, $anchorText) {
  global $mostRecentCompletedTaxYear, $currentTaxYear;
  if ($year == $mostRecentCompletedTaxYear or $year == $currentTaxYear) {
    return '<a href="https://www.irs.gov/pub/irs-pdf/'.$slug.'.pdf">'.$anchorText.' (PDF)</a>';
  } else {
    return '<a href="https://www.irs.gov/pub/irs-prior/'.$slug.'--'.$year.'.pdf">'.$anchorText.' (PDF)</a>';
  }
}

print '<p>For more information on taxes, learn about <a href="https://en.wikipedia.org/wiki/Form_1040">Form 1040</a> and <a href="https://en.wikipedia.org/wiki/Form_1099-MISC">Form 1099-MISC</a>.</p>'."\n";

print 'Pass the parameter <code>contractWorkIncome</code> in the URL to change the income used below to an arbitrary amount (<a href="/taxes.php?worker=Issa+Rice&amp;contractWorkIncome=10000.05">example</a>); this will use the same amount for all years. You can also pass the parameters <code>interestIncome</code>, <code>totalOrdinaryDividend</code>, and <code>qualifiedDividend</code> to set those values (they all default to 0.00 if you don’t enter them). Click <a href="/taxes.php?worker=Issa+Rice&amp;contractWorkIncome=10000.05&amp;interestIncome=100&amp;totalOrdinaryDividend=100&amp;qualifiedDividend=100">here</a> for a link to this page with all the parameters filled out.';

print '<p><a href="/worker.php?worker='.urlencode($worker).'">Back to worker page</a>'."\n";

print "<ul>\n";
foreach(array_reverse($yearList) as $year) {
  if ($totalPaymentAwarded[$year] > 0 or $totalPaymentMadeByYear[$year] > 0) {
    print '    <li><a href="#'.$year.'">Tax situation for year '.$year.'</a></li>'."\n";
  }
}
print "</ul>\n";

foreach(array_reverse($yearList) as $year) {
  if ($totalPaymentAwarded[$year] > 0 or $totalPaymentMadeByYear[$year] > 0) {
    print '<h4 id="'.$year.'">Tax situation for year '.$year;
    if ($year == $currentTaxYear) {
      print ' (current year, so information not final)';
    }
    print "</h4>\n";
    $income = $totalPaymentAwarded[$year];
    $contractWorkIncome = $income + $upwardTaxAdjustmentForYear[$year] - $downwardTaxAdjustmentForYear[$year];
    $receivedIncome = $totalPaymentMadeByYear[$year] - $reimbursementDueInYear[$year];
    if ($_REQUEST['contractWorkIncome'] ?? '') {
      $contractWorkIncome = floatval($_REQUEST['contractWorkIncome']);
      $receivedIncome = $contractWorkIncome;
    }
    if ($_REQUEST['interestIncome'] ?? '' ) {
      $interestIncome = floatval($_REQUEST['interestIncome']);
    } else {
      $interestIncome = 0.0;
    }
    if ($_REQUEST['totalOrdinaryDividend'] ?? '' ) {
      $totalOrdinaryDividend = floatval($_REQUEST['totalOrdinaryDividend']);
    } else {
      $totalOrdinaryDividend = 0.0;
    }
    if ($_REQUEST['qualifiedDividend'] ?? '' ) {
      $qualifiedDividend = floatval($_REQUEST['qualifiedDividend']);
    } else {
      $qualifiedDividend = 0.0;
    }
    $selfEmploymentTax = 0.1413 * $contractWorkIncome;
    if (0.9235 * $contractWorkIncome < $selfEmploymentFilingThreshold[$year]) {
      $selfEmploymentTax = 0;
    }
    $taxableIncomeAssumingNoExemption = max(0, $contractWorkIncome - 0.5 * $selfEmploymentTax - $standardDeduction[$year]);
    $incomeTaxAssumingNoExemption = computeTax($taxableIncomeAssumingNoExemption, $year);
    $taxableIncomeAssumingExemption = max(0, $contractWorkIncome - 0.5 * $selfEmploymentTax - $standardDeduction[$year] - $basicExemption[$year]);
    $incomeTaxAssumingExemption = computeTax($taxableIncomeAssumingExemption, $year);
    $totalTaxAssumingNoExemption = $selfEmploymentTax + $incomeTaxAssumingNoExemption;
    $totalTaxAssumingExemption = $selfEmploymentTax + $incomeTaxAssumingExemption;
    print "<p>In the year $year, the total payment awarded to you (your income) was $".number_format($contractWorkIncome,2)." USD, and the total money paid to you was $".number_format($receivedIncome,2)." USD. Your upward adjustment to income (for payments from tasks completed in previous years, that was finalized in $year) was $".number_format($upwardTaxAdjustmentForYear[$year],2)." and the downward adjustment to income (for payments for completed tasks in that year, but finalized in later years) was $".number_format($downwardTaxAdjustmentForYear[$year],2).". <strong>Thus, the effective income for tax purposes from contract work is $".number_format($contractWorkIncome,2).".</strong></p>\n";
    print "<p>Also, your interest income was $" . number_format($interestIncome, 2) . ", and your dividend income was $" . number_format($totalOrdinaryDividend, 2) . ". </p>\n";
    print "<p>Here is a rough estimate for how much tax you would need to pay assuming all your income was from contract work for Vipul Naik and your interest income was $".number_format($interestIncome, 2)." and your dividend income was (total: $$totalOrdinaryDividend, qualified: $$qualifiedDividend):</p>\n";
    print "<ul>\n";
    if ($year <= '2017') {
      print "    <li>Assuming you are single and can take a personal exemption: $".number_format($selfEmploymentTax,2)." self-employment tax (computed as 14.13% of your income) and $".number_format($incomeTaxAssumingExemption,2)." income tax (computed using tax rates after subtracting standard deduction, personal exemption, and half of self-employment tax from your income), totaling to $".number_format($totalTaxAssumingExemption,2).".</li>\n";
      print "    <li>Assuming you are single and cannot take a personal exemption: $".number_format($selfEmploymentTax,2)." self-employment tax (computed as 14.13% of your income) and $".number_format($incomeTaxAssumingNoExemption,2)." income tax (computed using tax rates after subtracting standard deduction and half of self-employment tax from your income) totaling to $".number_format($totalTaxAssumingNoExemption,2).".</li>\n";
    } else {
      print "    <li>Assuming you are single: $".number_format($selfEmploymentTax,2)." self-employment tax (computed as 14.13% of your contract work income) and $".number_format($incomeTaxAssumingNoExemption,2)." income tax (computed using tax rates after subtracting standard deduction and half of self-employment tax from your income) totaling to $".number_format($totalTaxAssumingNoExemption,2).".</li>\n";
    }
    print "</ul>\n";
    print "<p>More details of your tax situation and how to fill your tax forms are below.</p>\n";
    if ($contractWorkIncome == 0) {
      print "<p>You had no income for tax purposes for the year $year from contract work for Vipul Naik. If you had no other income in the year, you do not need to file a tax return.</p>";
    } else if (0.9235 * $contractWorkIncome < $selfEmploymentFilingThreshold[$year]) {
      print "<p>You had self-employment income for the year $year. However, assuming that all your self-employment income was through contract work for Vipul Naik, you do not pass the threshold for filing and paying taxes. Specifically, 92.35% of your income was less than the threshold of $$selfEmploymentFilingThreshold[$year].".' For more information, see <a href="https://www.irs.gov/businesses/small-businesses-self-employed/self-employed-individuals-tax-center">Self-Employed Individuals Tax Center</a> and '.hyperlinkedTaxForm($year, 'f1040sse', 'Form 1040, Schedule SE').' (Page 2, line 4c). You are also below the minimum threshold for paying income tax. However, we provide instructions below just in case you want to file taxes.</p>'."\n";
    } else {
      print "<p>If you are a United States citizen or resident for tax purposes, you <strong>need to file your tax return and pay self-employment tax (Social Security and Medicare taxes)</strong> on the income earned. You are above the filing threshold (92.35% of your income exceeds the filing threshold of $".$selfEmploymentFilingThreshold[$year].'). For more information on the filing threshold, see <a href="https://www.irs.gov/businesses/small-businesses-self-employed/self-employed-individuals-tax-center">Self-Employed Individuals Tax Center</a> and '.hyperlinkedTaxForm($year, 'f1040sse', 'Form 1040, Schedule SE').'. The reason is that income earned through contract work is classified under self-employment income, and the responsibility for paying Social Security and Medicare taxes on such income falls on the worker rather than the payer.</p>';
    }
    print "<p>Approximate, highly conservative, guidance on what to do follows. This is just to give you a sense of how things should look; you should read through the forms and instructions competely to make sure it is correct for your situation.";
    print "<p>Depending on your income and filing status, you may be eligible for an earned income credit (EIC), also known as an earned income tax credit (EITC). <strong>Since the EITC is complex to model, we do not include the value of the EITC in our calculations, and you're responsible for making the adjustments yourself. We do, however, have a gentle reminder when we get to the relevant lines in Form 1040, as well as heuristic guidance on what the value should approximately work out to.</strong></p>";
    print '<p><strong>Fill in the forms electronically (using your PDF reader) rather than by hand to make it easier to edit the forms and easier for the IRS to process your forms.';
    if ($year == $mostRecentCompletedTaxYear) {
      print ' Please also consider e-filing your tax return using <a href="https://www.freefilefillableforms.com/">freefilefillableforms.com</a>.';
    }
    print '</strong></p>';
    print '<p>Start by filling '.hyperlinkedTaxForm($year, 'f1040sc', 'Form 1040, Schedule C, Page 1').'. In row F, select the Accounting method as "Accrual" -- this corresponds to using the "total payment awarded" which is what we use here; if instead you want to use "Cash" you must use the "total payment made" value, in which case you have to replace the number for all your calculations. Also, keep in mind that it is best to keep your accounting method consistent across years and across income sources, otherwise you run the risk of undercounting or double-counting income, and also attracting more IRS scrutiny.</p>';
    print '<p>In Part I and II, enter all your contract work income on lines 1, 3, 5, 7, 29, and 31. If all your contract work income was from Vipul Naik, and you are using the "Accrual" method, the amount will be $'.number_format($contractWorkIncome,2).' USD. The remaining entries in both parts should be zero or blank. Do not fill in Page 2. Attach only Page 1 to your tax filing.</p>';
    if ($year <= '2017') {
      print '<p>Now go to '.hyperlinkedTaxForm($year, 'f1040', 'the main Form 1040').'. the data for lines 1 through 6 based on your knowledge. If you are single and nobody is claiming you as a dependent, you should have 1 total exemption claimed in line 6d. For line 7, enter your total income from regular employment (this should be 0 if all your income was from contract work). Enter your contract work income on line 12 (which equals $'.number_format($contractWorkIncome,2).' if contract work for Vipul Naik was your only contract work).';
    } else if ($year >= '2018') {
      print '<p>Now go to '.hyperlinkedTaxForm($year, 'f1040s1', 'Form 1040, Schedule 1').'. Enter the total contract work income (which equals $'.number_format($contractWorkIncome,2).') on line '.$s1scLineNumber[$year].' and line '.$s1TotalIncomeLineNumber[$year].'. For now, do not fill beyond line '.$s1TotalIncomeLineNumber[$year].' (we shall return to line '.$s1sseLineNumber[$year].' later).</p>';
      print '<p>Now go to '.hyperlinkedTaxForm($year, 'f1040', 'the main Form 1040').'. Fill in the lines prior to '.$s1InMainFormLineNumber[$year].' based on your knowledge. On line '.$s1InMainFormLineNumber[$year].' (which asks you to enter the amount from Schedule 1, the last line (the line for total income), i.e., line '.$s1TotalIncomeLineNumber[$year].'), re-enter the contract work income (which equals $'.number_format($contractWorkIncome,2).'). Copy this value to line '.$totalIncomeLineNumber[$year].' assuming you had no other income.</p>';
    }
    print '<p>Now switch to '.hyperlinkedTaxForm($year, 'f1040sse', 'Schedule SE').'.';
    if ($year >= '2018') {
      print " If using Free File Fillable Forms, select ".$setName[$year].".";
    }
    if ($year <= '2019') {
      print " Fill Page 2, Part I (leave Page 1 and Page 2, Part II blank).";
    } else {
      print " Fill Part I (leave Part II blank).";
    }
    print " Your contract work income will go in lines 2 and 3. Follow the instructions carefully. The end result on line 12 should be about 14.13% of your contract work income (or $0.00 if 92.35% of your income was less than the threshold of $$selfEmploymentFilingThreshold[$year]), which should work out to $".number_format($selfEmploymentTax,2)." (there are some edge cases where it's less, but these probably don't apply to you). The value on line 13 should be half of the value on line 12, which should work out to $".number_format(0.5*$selfEmploymentTax,2).".</p>";
    if ($year <= '2017') {
      print "<p>Return to Form 1040. For line 27, enter the same value as on line 13 of Form 1040, Schedule SE, which in turn is half of the value on line 12, and should work out to $".number_format(0.5*$selfEmploymentTax,2).". The same value will likely go into line 36, assuming none of the rest of the adjustments apply to you.</p>";
    } else if ($year >= '2018') {
      print "<p>Return to Form 1040, Schedule 1. For line ".$s1sseLineNumber[$year].", enter the same value as on line 13 of Form 1040, Schedule SE, which in turn is half of the value on line 12, and should work out to $".number_format(0.5*$selfEmploymentTax,2).". The same value will likely go into line ".$s1TotalDeductionLineNumber[$year].", assuming none of the rest of the adjustments apply to you.</p>";
      print "<p>Now return to Form 1040.</p>";
  if ($year >= "2019") {
        print "<p>On line(s) ".$adjustmentsToIncomeLineNumber[$year]." enter the value that you just filled in in Schedule 1, line ".$s1TotalDeductionLineNumber[$year].", i.e., ".number_format(0.5*$selfEmploymentTax,2).".</p>";
      }
      print "<p>On line ".$agiLineNumber[$year].", enter the value of line $totalIncomeLineNumber[$year], which is $".number_format($contractWorkIncome, 2).", minus the total deduction from Schedule 1, line ".$s1TotalDeductionLineNumber[$year].", which is $".number_format(0.5*$selfEmploymentTax,2).". The difference should work out to $".number_format($contractWorkIncome - 0.5 * $selfEmploymentTax, 2).", or approximately (100 - 0.5 * 14.13)% of your income.</p>";
    }
    if ($contractWorkIncome < $standardDeduction[$year]/(1 - 0.5 * 0.1413)) {
      if ($year <= '2017') {
        print "Assuming you had no other income in $year, since your income minus the deductible part of self-employment tax was less than the standard deduction of $".number_format($standardDeduction[$year], 2)." USD, you do not need to pay income tax, and line 56 should be 0.</p>";
      } else if ($year == '2018') {
        print "<p>On line ".$standardOrItemizedDeductionLineNumber[$year].", enter the standard deduction for the year, which is $".number_format($standardDeduction[$year]).". The value you entered on line ".$agiLineNumber[$year].", namely $".number_format($contractWorkIncome - 0.5 * $selfEmploymentTax, 2).", is less than the standard deduction you entered on line $standardOrItemizedDeductionLineNumber. Thus, on line ".$taxableIncomeLineNumber[$year].", you will enter 0. You do not owe any income tax.</p>";
      } else {
        print "<p>On lines ".$standardOrItemizedDeductionLineNumber[$year]." and ".$totalDeductionLineNumber[$year].", enter the standard deduction for the year, which is $".number_format($standardDeduction[$year]).". The value you entered on line ".$agiLineNumber[$year].", namely $".number_format($contractWorkIncome - 0.5 * $selfEmploymentTax, 2).", is less than the standard deduction you entered on line ".$totalDeductionLineNumber[$year].". Thus, on line ".$taxableIncomeLineNumber[$year].", you will enter 0. You do not owe any income tax.</p>";
      }
    } else if ($contractWorkIncome < ($standardDeduction[$year] + $basicExemption[$year])/(1 - 0.5 * 0.1413) and $year <= "2017") {
      print "Assuming you had no other income in $year, since your income minus the deductible part of self-employment tax was less than the sum of the standard deduction of $".number_format($standardDeduction[$year], 2)." USD and the basic personal exemption of $".number_format($basicExemption[$year], 2).", you do not need to pay income tax if you are a United States citizen or resident for tax purposes, <em>and</em> if nobody else claimed you as a dependent. Under these circumstances, line 56 should be 0. However, if somebody claimed you as a dependent, you cannot take the personal exemption and may have a positive income tax obligation. Crude guess: your taxable income in this case will be $".number_format($taxableIncomeAssumingNoExemption,2)." USD and your income tax will be approximately $".number_format($incomeTaxAssumingNoExemption,2)." USD.".' The computation of tax from taxable income is done using the <a href="https://taxfoundation.org/'.$year.'-tax-brackets">'.$year." tax brackets</a>.</p>\n";
    } else {
      if ($year <= "2017") {
        print "You probably need to pay some taxes, so line 56 is likely to be positive (though it may not be, depending on all the deductions and credits you get). Crude guess: assuming you are not being claimed as a dependent, your taxable income will be $".number_format($taxableIncomeAssumingExemption,2)." USD and your income tax will be approximately $".number_format($incomeTaxAssumingExemption,2)." USD. If somebody claimed you as a dependent, your taxable income will be $".number_format($taxableIncomeAssumingNoExemption,2)." USD and your income tax will be approximately $".number_format($incomeTaxAssumingNoExemption,2)." USD.".' The computation of tax from taxable income is done using the <a href="https://taxfoundation.org/'.$year.'-tax-brackets">'.$year." tax brackets</a>.</p>\n";
      } else if ($year == "2018") {
        print "On line ".$standardOrItemizedDeductionLineNumber[$year].", enter your standard deduction for the year, namely $".number_format($standardDeduction[$year], 2).". On line ".$taxableIncomeLineNumber[$year].", enter the value obtained by subtracting line ".$standardOrItemizedDeductionLineNumber[$year]." from line ".$agiLineNumber[$year].". This should yield $".number_format($taxableIncomeAssumingNoExemption, 2)." USD and your income tax (to be entered on line ".$taxLineNumber[$year].") will be approximately $".number_format($incomeTaxAssumingNoExemption,2)." USD.".' The computation of tax from taxable income is done using the <a href="https://taxfoundation.org/'.$year.'-tax-brackets">'.$year." tax brackets</a>.</p>\n";
      } else {
        print "On lines ".$standardOrItemizedDeductionLineNumber[$year]." and ".$totalDeductionLineNumber[$year].", enter your standard deduction for the year, namely $".number_format($standardDeduction[$year], 2).". On line ".$taxableIncomeLineNumber[$year].", enter the value obtained by subtracting line ".$totalDeductionLineNumber[$year]." from line ".$agiLineNumber[$year].". This should yield $".number_format($taxableIncomeAssumingNoExemption, 2)." USD and your income tax (to be entered on line ".$taxLineNumber[$year].") will be approximately $".number_format($incomeTaxAssumingNoExemption,2)." USD.".' The computation of tax from taxable income is done using the <a href="https://taxfoundation.org/'.$year.'-tax-brackets">'.$year." tax brackets</a>.</p>\n";
      }
    }
    if ($year <= "2017") {
      print '<p>Now return to Form 1040. Fill in line 57; this should match line 12 of Schedule SE, which is $'.number_format($selfEmploymentTax, 2).'. The total on line 63 should be the sum of your income tax (as calculated on line 56) and your self-employment tax (as calculated on line 57). This total will be $'.number_format($totalTaxAssumingExemption, 2).' if you are taking a personal exemption (i.e., you are not being claimed as a dependent), and $'.number_format($totalTaxAssumingNoExemption, 2).' if you are not taking a personal exemption (i.e., somebody else is claiming you as a dependent).</p>';
      print '<p>If you have made estimated tax payments (using Form 1040-ES by mail or through EFTPS), or if you chose a credit elect last year, you need to enter the total amount applied from last year plus your estimated tax payments on line 65. If you paid an additional amount with your request for extension to file, enter that on line 70. Enter the total on line 74.</p>';
      print "<p>Now follow the instructions to fill in the rest of the form. Depending on which of line 63 and line 74 is bigger, you are either owed a refund or need to make a payment. If you are owed a refund, you can either ask for it right away or have it apply to next year's taxes. If you owe money, there is a possibility that you may also need to pay an estimated tax penalty, but if you aren't sure how to calculate this penalty, you can leave it blank and let the IRS reach out to you if they need you to pay a penalty.</p>";
    } else {
      if ($year == "2018") {
        print '<p>Now go to '.hyperlinkedTaxForm('2018', 'f1040s4', 'Form 1040, Schedule 4').'. Fill in line 57; this should match line 12 of Schedule SE, which is $'.number_format($selfEmploymentTax, 2).'. Enter the same amount on line 64.</p>';
      } else {
        print 'Now go to '.hyperlinkedTaxForm($year, 'f1040s2', 'Form 1040, Schedule 2').'. Fill in line 4; this should match line 12 of Schedule SE, which is $'.number_format($selfEmploymentTax, 2).'. Enter the same amount on Schedule 2, the last line (the line for the total), i.e., line '.$s2TotalLineNumber[$year].'.</p>';
      }
      print "<p>Now return to Form 1040. On line ".$setInMainFormLineNumber[$year].", enter the same value, namely $".number_format($selfEmploymentTax, 2).". On line ".$totalTaxLineNumber[$year].", enter the totals of lines ".$setInMainFormLineNumber[$year]." and ".$taxLineNumber[$year].", which should work out to $".number_format($totalTaxAssumingNoExemption, 2).". This is the total amount of tax you owe.</p>";
      if ($year == "2018") {
        print '<p>If you have made estimated tax payments (using Form 1040-ES by mail or through EFTPS)  or if you chose a credit elect last year, you need to enter the total amount applied from last year plus your estimated tax payments in '.hyperlinkedTaxForm('2018', 'f1040s5', 'Form 1040, Schedule 5').' on line 66. If you paid an additional amount with your request for extension to file, enter that on line 71. Enter the total on line 75.</p>';
        print '<p>Return to Form 1040 and on line 17, enter the amount you just entered on line 75 in the inner blank that says "Add any amount from Schedule 5" and then also on the main line 17 (on the right) and on line 18.</p>';
      } else if ($year == "2019") {
         print '<p>If you have made estimated tax payments (using Form 1040-ES by mail or through EFTPS) or if you chose a credit elect last year, you need to enter the total amount applied from last year plus your estimated tax payments in '.hyperlinkedTaxForm($year, 'f1040s3', 'Form 1040, Schedule 3').' on line 8. If you paid an additional amount with your request for extension to file, enter that on line 10. Enter the total on line 14.</p>';
        print '<p>Return to Form 1040 and copy the total you just entered (on Schedule 3 line 14) to Form 1040, lines 18d, 18e, and 19.</p>';
      } else {
         print '<p>If you have made estimated tax payments (using Form 1040-ES by mail or through EFTPS) or if you chose a credit elect last year, you need to enter the total amount applied from last year plus your estimated tax payments on line 26. If you paid any money with your request for extension to file, report it in '.hyperlinkedTaxForm($year, 'f1040s3', 'Form 1040, Schedule 3').' line 10 and copy to line 13, then copy to line 31 of the main Form 1040. Add up the values on lines 26 and 31 and enter this sum on lines 32 and 33.</p>';
      }
      if ($interestIncome + $totalOrdinaryDividend > 0.0) {
        print "<p>Since you had interest and/or dividend income, you will need to fill out Form 1040 Schedule B. On Schedule B, in Part I, list all the sources from which you received interest income as well as the amounts. If you use Free File Fillable Forms, you can just enter the individual amounts on line 1 and it will add them up for you. On lines 2 and 4, you should get $$interestIncome.</p>\n";
        print "<p>Next, still on Schedule B, in Part II, list all the sources from which you received dividends as well as the amounts. Here, you want to enter the <strong>total</strong> dividend amounts, not the qualified dividend amounts. On line 6, you should get the total amount of $$totalOrdinaryDividend.</p>\n";
        print "<p>Now go back to the main Form 1040, and enter the interest income on line 2b (Taxable interest), which should be $$interestIncome. On line 3a, enter the qualified dividend amount, which is $".number_format($qualifiedDividend, 2) .", and on line 3b enter the total dividend amount, which is $".number_format($totalOrdinaryDividend, 2).".</p>\n";
      }
      print '<p>Use the <a href="https://apps.irs.gov/app/eitc">IRS EITC calculator</a> to check if you are eligible for an earned income credit, and enter the calculated earned income credit value in Form 1040 line 27. <strong>Make sure when entering data into the EITC calculator to include the adjustment for 1/2 of self-employment tax when entering self-employment income.</strong> If your earned income is small enough, your earned income credit should approximately match the employee portion of Social Security and Medicare taxes, i.e., about 7.65% of your earned income. For self-employed individuals with small enough self-employment income, it should work out to be in the ballpark of the "half of self-employment tax" that you entered in Form 1040 Schedule SE line 13. The values may not match up exactly due to the use of tax tables rather than schedules for tax calculation, as well as other adjustments, but they should be within a few dollars of each other. As income goes up, the earned income credit becomes smaller, and at sufficiently high incomes, it becomes zero. You can also cross-check your calculations by looking up the EIC table section in the Form 1040 tax tables (HTML or PDF) for your year; however, make sure to subtract the 1/2 of self-employment tax from your self-employment income when plugging into the table to calculate.</p>';
      print "<p>Now follow the instructions to fill in the rest of the form. Depending on which of lines ".$totalTaxLineNumber[$year]." and line ".$totalPaymentsLineNumber[$year]." is bigger, you are either owed a refund or need to make a payment. If you are owed a refund, you can either ask for it right away or have it apply to next year's taxes. If you owe money, there is a possibility that you may also need to pay an estimated tax penalty, but if you aren't sure how to calculate this penalty, you can leave it blank and let the IRS reach out to you if they need you to pay a penalty.</p>";
    }
    print "<p>If you are using a tax compliance software instead of filling the forms yourself, then check if it gives you an option to add in income for self-employment or contract work. Some softwares may not allow you to enter the numbers directly. To get around this problem, you may need to enter it in as if it is a Form 1099-MISC, even though you will not receive a Form 1099-MISC. That is because Vipul Naik is paying you personally rather than in the course of a trade or business, but tax compliance softwares may not have personal payments as a prominent enough use case to cover.</p>";
    }
}
?>
