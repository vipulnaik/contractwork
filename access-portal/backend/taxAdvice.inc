<?php

$reimbursementSelectQuery = "select year(receipt_date) as year, coalesce(sum(sent_payment), 0) as payment from payments where intermediary=".'"'.str_replace('"','\"',$worker).'"'." and receipt_date is not null group by year(receipt_date) order by year(receipt_date);";
$reimbursementSelectResult = $mysqli -> query($reimbursementSelectQuery);
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
  print "Recording adjustment: ".$row['year'].",".$row['adjustment']."\n";
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
  $downwardTaxAdjustmentForYear[$row['year']] = $row['adjustment'];
}

print '<p>For more information on taxes, learn about <a href="https://en.wikipedia.org/wiki/Form_1040">Form 1040</a> and <a href="https://en.wikipedia.org/wiki/Form_1099-MISC">Form 1099-MISC</a>.</p>'."\n";

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
    $incomeForTaxPurposes = $income + $upwardTaxAdjustmentForYear[$year] - $downwardTaxAdjustmentForYear[$year];
    $receivedIncome = $totalPaymentMadeByYear[$year] - $reimbursementDueInYear[$year];
    $selfEmploymentTax = 0.1413 * $incomeForTaxPurposes;
    if (0.9235 * $incomeForTaxPurposes < $selfEmploymentFilingThreshold[$year]) {
      $selfEmploymentTax = 0;
    }
    $taxableIncomeAssumingNoExemption = max(0, $incomeForTaxPurposes - 0.5 * $selfEmploymentTax - $standardDeduction[$year]);
    $incomeTaxAssumingNoExemption = computeTax($taxableIncomeAssumingNoExemption, $year);
    $taxableIncomeAssumingExemption = max(0, $incomeForTaxPurposes - 0.5 * $selfEmploymentTax - $standardDeduction[$year] - $basicExemption[$year]);
    $incomeTaxAssumingExemption = computeTax($taxableIncomeAssumingExemption, $year);
    $totalTaxAssumingNoExemption = $selfEmploymentTax + $incomeTaxAssumingNoExemption;
    $totalTaxAssumingExemption = $selfEmploymentTax + $incomeTaxAssumingExemption;
    print "<p>In the year $year, the total payment awarded to you (your income) was $".number_format($incomeForTaxPurposes,2)." USD, and the total money paid to you was $".number_format($receivedIncome,2)." USD. Your upward adjustment to income (for payments from tasks completed in previous years, that was finalized in $year) was $".number_format($upwardTaxAdjustmentForYear[$year],2)." and the downward adjustment to income (for payments for completed tasks in that year, but finalized in later years) was $".number_format($downwardTaxAdjustmentForYear[$year],2).". <strong>Thus, the effective income for tax purposes from contract work is $".number_format($incomeForTaxPurposes,2).".</strong></p>\n";
    print "<p>Here is a rough estimate for how much tax you would need to pay assuming all your income was from contract work for Vipul Naik:</p>\n";
    print "<ul>\n";
    print "    <li>Assuming you are single and cannot take a personal exemption: $".number_format($selfEmploymentTax,2)." self-employment tax and $".number_format($incomeTaxAssumingNoExemption,2)." income tax totaling to $".number_format($totalTaxAssumingNoExemption,2).".</li>\n";
    print "    <li>Assuming you are single and can take a personal exemption: $".number_format($selfEmploymentTax,2)." self-employment tax and $".number_format($incomeTaxAssumingExemption,2)." income tax, totaling to $".number_format($totalTaxAssumingExemption,2).".</li>\n";
    print "</ul>\n";
    print "<p>More details of your tax situation and how to fill your tax forms are below.</p>\n";
    if (0.9235 * $incomeForTaxPurposes < $selfEmploymentFilingThreshold[$year]) {
      print "<p>You had self-employment income for the year $year. However, assuming that all your self-employment income was through contract work for Vipul Naik, you do not pass the threshold for filing and paying taxes. Specifically, 92.35% of your income was less than the threshold of $$selfEmploymentFilingThreshold[$year].".' For more information, see <a href="https://www.irs.gov/businesses/small-businesses-self-employed/self-employed-individuals-tax-center">Self-Employed Individuals Tax Center</a> and <a href="https://www.irs.gov/pub/irs-pdf/f1040sse.pdf">Form 1040, Schedule SE</a> (Page 2, Line 4c). You are also below the minimum threshold for paying income tax.</p>'."\n";
    } else {
      print "<p>If you are a United States citizen or resident for tax purposes, you <strong>need to file your tax return and pay self-employment tax (Social Security and Medicare taxes)</strong> on the income earned. You are above the filing threshold (92.35% of your income exceeds the filing threshold of $".$selfEmploymentFilingThreshold[$year].'). For more information on the filing threshold, see <a href="https://www.irs.gov/businesses/small-businesses-self-employed/self-employed-individuals-tax-center">Self-Employed Individuals Tax Center</a> and <a href="https://www.irs.gov/pub/irs-pdf/f1040sse.pdf">Form 1040, Schedule SE</a> (Page 2, Line 4c).'." The reason is that income earned through contract work is classified under self-employment income, and the responsibility for paying Social Security and Medicare taxes on such income falls on the worker rather than the payer. Approximate, highly conservative, guidance on what to do follows. This is just to give you a sense of how things should look; you should read through the forms and instructions competely to make sure it is correct for your situation.</p>";    
      print '<p><strong>Fill in the forms electronically (using your PDF reader) rather than by hand to make it easier to edit the forms and easier for the IRS to process your forms</strong>.</p>';
      print '<p>Start by filling <a href="https://www.irs.gov/pub/irs-pdf/f1040sc.pdf">Form 1040, Schedule C, Page 1</a>. In Part I and II, enter all your contract work income on Lines 1, 3, 5, 7, 29, and 31. If all your contract work income was from Vipul Naik, the amount will be $'.number_format($incomeForTaxPurposes,2).'. The remaining entries in both parts should be zero or blank. Do not fill in Page 2. Attach only Page 1 to your tax filing.</p>';
      print '<p>Now go to <a href="https://www.irs.gov/pub/irs-pdf/f1040.pdf">the main Form 1040</a>. Enter the data for Lines 1 through 6 based on your knowledge. If you are single and nobody is claiming you as a dependent, you should have 1 total exemption claimed in Line 6d. For Line 7, enter your total income from regular employment. Enter your contract work income on Line 12 (which equals '.number_format($incomeForTaxPurposes,2).' if contract work for Vipul Naik was your only contract work).';
      print '<p>Now switch to <a href="https://www.irs.gov/pub/irs-pdf/f1040-sse.pdf">Form 1040, Schedule SE</a>'.". Fill Page 2, Part I (leave Page 1 and Page 2, Part II blank). Your contract work income will go in Lines 2 and 3. Follow the instructions carefully. The end result on Line 12 should be about 14.13% of your contract work income, which should work out to $".number_format($selfEmploymentTax,2)." (there are some edge cases where it's less, but these probably don't apply to you).</p>";
      print '<p>Return to Form 1040. Fill the rest of the form, till Line 56. For Line 27, reference Schedule SE. ';
      if ($incomeForTaxPurposes < $standardDeduction[$year]/(1 - 0.5 * 0.1413)) {
        print "Assuming you had no other income in $year, since your income minus the deductible part of self-employment tax was less than the standard deduction of $".$standardDeduction[$year]." USD, you do not need to pay income tax, and line 56 should be 0.</p>";
      } else if ($incomeForTaxPurposes < ($standardDeduction[$year] + $basicExemption[$year])/(1 - 0.5 * 0.1413)) {
        print "Assuming you had no other income in $year, since your income minus the deductible part of self-employment tax was less than the sum of the standard deduction of $".$standardDeduction[$year]." USD and the basic personal exemption of $".$basicExemption[$year].", you do not need to pay income tax if you are a United States citizen or resident for tax purposes, <em>and</em> if nobody else claimed you as a dependent. Under these circumstances, line 56 should be 0. However, if somebody claimed you as a dependent, you cannot take the personal exemption and may have a positive income tax obligation. Crude guess: your taxable income in this case will be $".number_format($taxableIncomeAssumingNoExemption,2)." USD and your income tax will be approximately $".number_format($incomeTaxAssumingNoExemption,2)." USD.".' The computation of tax from taxable income is done using the <a href="https://taxfoundation.org/'.$year.'-tax-brackets">'.$year." tax brackets</a>.</p>\n";
      } else {
        print "You probably need to pay some taxes, so Line 56 is likely to be positive (though it may not be, depending on all the deductions and credits you get). Crude guess: assuming you are not being claimed as a dependent, your taxable income will be $".number_format($taxableIncomeAssumingExemption,2)." USD and your income tax will be approximately $".number_format($incomeTaxAssumingExemption,2)." USD. If somebody claimed you as a dependent, your taxable income will be $".number_format($taxableIncomeAssumingNoExemption,2)." USD and your income tax will be approximately $".number_format($incomeTaxAssumingNoExemption,2)." USD.".' The computation of tax from taxable income is done using the <a href="https://taxfoundation.org/'.$year.'-tax-brackets">'.$year." tax brackets</a>.</p>\n";
      }
      print '<p>Now return to Form 1040. Fill in Line 57 and then complete the rest of the form.</p>';
      print "<p>If you are using a tax compliance software instead of filling the forms yourself, then check if it gives you an option to add in income for self-employment or contract work. Some softwares may not allow you to enter the numbers directly. To get around this problem, you may need to enter it in as if it is a Form 1099-MISC, even though you will not receive a Form 1099-MISC. That is because Vipul Naik is paying you personally rather than in the course of a trade or business, but tax compliance softwares may not have personal payments as a prominent enough use case to cover.</p>";
    }
  }
}
?>
