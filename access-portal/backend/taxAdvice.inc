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
    if ($year <= '2017') {
      print "    <li>Assuming you are single and can take a personal exemption: $".number_format($selfEmploymentTax,2)." self-employment tax (computed as 14.13% of your income) and $".number_format($incomeTaxAssumingExemption,2)." income tax (computed using tax rates after subtracting standard deduction, personal exemption, and half of self-employment tax from your income), totaling to $".number_format($totalTaxAssumingExemption,2).".</li>\n";
      print "    <li>Assuming you are single and cannot take a personal exemption: $".number_format($selfEmploymentTax,2)." self-employment tax (computed as 14.13% of your income) and $".number_format($incomeTaxAssumingNoExemption,2)." income tax (computed using tax rates after subtracting standard deduction and half of self-employment tax from your income) totaling to $".number_format($totalTaxAssumingNoExemption,2).".</li>\n";
    } else {
      print "    <li>Assuming you are single: $".number_format($selfEmploymentTax,2)." self-employment tax (computed as 14.13% of your income) and $".number_format($incomeTaxAssumingNoExemption,2)." income tax (computed using tax rates after subtracting standard deduction and half of self-employment tax from your income) totaling to $".number_format($totalTaxAssumingNoExemption,2).".</li>\n";
    }
    print "</ul>\n";
    print "<p>More details of your tax situation and how to fill your tax forms are below.</p>\n";
    if ($incomeForTaxPurposes == 0) {
      print "<p>You had no income for tax purposes for the year $year from contract work for Vipul Naik. If you had no other income in the year, you do not need to file a tax return.</p>";
    } else if (0.9235 * $incomeForTaxPurposes < $selfEmploymentFilingThreshold[$year]) {
      print "<p>You had self-employment income for the year $year. However, assuming that all your self-employment income was through contract work for Vipul Naik, you do not pass the threshold for filing and paying taxes. Specifically, 92.35% of your income was less than the threshold of $$selfEmploymentFilingThreshold[$year].".' For more information, see <a href="https://www.irs.gov/businesses/small-businesses-self-employed/self-employed-individuals-tax-center">Self-Employed Individuals Tax Center</a> and <a href="https://www.irs.gov/pub/irs-pdf/f1040sse.pdf">Form 1040, Schedule SE</a> (Page 2, line 4c). You are also below the minimum threshold for paying income tax.</p>'."\n";
    } else {
      print "<p>If you are a United States citizen or resident for tax purposes, you <strong>need to file your tax return and pay self-employment tax (Social Security and Medicare taxes)</strong> on the income earned. You are above the filing threshold (92.35% of your income exceeds the filing threshold of $".$selfEmploymentFilingThreshold[$year].'). For more information on the filing threshold, see <a href="https://www.irs.gov/businesses/small-businesses-self-employed/self-employed-individuals-tax-center">Self-Employed Individuals Tax Center</a> and <a href="https://www.irs.gov/pub/irs-pdf/f1040sse.pdf">Form 1040, Schedule SE</a> (Page 2, line 4c).'." The reason is that income earned through contract work is classified under self-employment income, and the responsibility for paying Social Security and Medicare taxes on such income falls on the worker rather than the payer. Approximate, highly conservative, guidance on what to do follows. This is just to give you a sense of how things should look; you should read through the forms and instructions competely to make sure it is correct for your situation.</p>";    
      print '<p><strong>Fill in the forms electronically (using your PDF reader) rather than by hand to make it easier to edit the forms and easier for the IRS to process your forms</strong>.</p>';
      print '<p>Start by filling <a href="https://www.irs.gov/pub/irs-pdf/f1040sc.pdf">Form 1040, Schedule C, Page 1</a>. In Part I and II, enter all your contract work income on lines 1, 3, 5, 7, 29, and 31. If all your contract work income was from Vipul Naik, the amount will be $'.number_format($incomeForTaxPurposes,2).' USD. The remaining entries in both parts should be zero or blank. Do not fill in Page 2. Attach only Page 1 to your tax filing.</p>';
      if ($year <= '2017') {
        print '<p>Now go to <a href="https://www.irs.gov/pub/irs-prior/f1040--'.$year.'.pdf">the main Form 1040</a>. Enter the data for lines 1 through 6 based on your knowledge. If you are single and nobody is claiming you as a dependent, you should have 1 total exemption claimed in line 6d. For line 7, enter your total income from regular employment. Enter your contract work income on line 12 (which equals $'.number_format($incomeForTaxPurposes,2).' if contract work for Vipul Naik was your only contract work).';
      } else if ($year == '2018') {
        print '<p>Now go to <a href="https://www.irs.gov/pub/irs-pdf/f1040s1.pdf">Form 1040, Schedule 1</a>. Enter the total contract work income (which equals $'.number_format($incomeForTaxPurposes,2).') on line 12 and line 22. For now, do not fill beyond line 22 (we shall return to line 27 later).</p>';
        print '<p>Now go to <a href="https://www.irs.gov/pub/irs-pdf/f1040.pdf">the main Form 1040</a>. Fill in the first page of the form based on your own knowledge. On the second page, in the inner blank for line 6 (which asks you to enter the amount from Schedule 1, line 22), re-enter the contract work income (which equals $'.number_format($incomeForTaxPurposes,2).').</p>';
      } else {
        print '<p>Now go to <a href="https://www.irs.gov/pub/irs-pdf/f1040s1.pdf">Form 1040, Schedule 1</a>. Enter the total contract work income (which equals $'.number_format($incomeForTaxPurposes,2).') on line 3 and line 9. For now, do not fill beyond line 9 (we shall return to line 14 later).</p>';
        print '<p>Now go to <a href="https://www.irs.gov/pub/irs-pdf/f1040.pdf">the main Form 1040</a>. Fill in the top of the first page (the personal information prior to numbered lines). On line 7a (which asks you to enter the amount from Schedule 1, line 9), re-enter the contract work income (which equals $'.number_format($incomeForTaxPurposes,2).'). Assuming that you have no other sources of income, enter the same value on line 7b.</p>';
      }
      print '<p>Now switch to <a href="https://www.irs.gov/pub/irs-pdf/f1040sse.pdf">Form 1040, Schedule SE</a>'.". If using Free File Fillable Forms, select Schedule SE - Self-Employment Tax Part B - Taxpayer. Fill Page 2, Part I (leave Page 1 and Page 2, Part II blank). Your contract work income will go in lines 2 and 3. Follow the instructions carefully. The end result on line 12 should be about 14.13% of your contract work income, which should work out to $".number_format($selfEmploymentTax,2)." (there are some edge cases where it's less, but these probably don't apply to you). The value on line 13 should be half of the value on line 12, which should work out to $".number_format(0.5*$selfEmploymentTax,2).".</p>";
      if ($year <= '2017') {
        print "<p>Return to Form 1040. For line 27, enter the same value as on line 13 of Form 1040, Schedule SE, which in turn is half of the value on line 12, and should work out to $".number_format(0.5*$selfEmploymentTax,2).". The same value will likely go into line 36, assuming none of the rest of the adjustments apply to you.</p>";
      } else if ($year == '2018') {
        print "<p>Return to Form 1040, Schedule 1. For line 27, enter the same value as on line 13 of Form 1040, Schedule SE, which in turn is half of the value on line 12, and should work out to $".number_format(0.5*$selfEmploymentTax,2).". The same value will likely go into line 36, assuming none of the rest of the adjustments apply to you.</p>";
        print "<p>Now return to Form 1040 and focus on filling in line 7. You will enter the value of line 6, which is $".number_format($incomeForTaxPurposes, 2).", minus the amount from Schedule 1, line 36, which is $".number_format(0.5*$selfEmploymentTax,2).". The difference should work out to $".number_format($incomeForTaxPurposes - 0.5 * $selfEmploymentTax, 2).", or approximately (100 - 0.5 * 14.13)% of your income.</p>";
      } else {
        print "<p>Return to Form 1040, Schedule 1. For line 14, enter the same value as on line 13 of Form 1040, Schedule SE, which in turn is half of the value on line 12, and should work out to $".number_format(0.5*$selfEmploymentTax,2).". The same value will likely go into line 22, assuming none of the rest of the adjustments apply to you.</p>";
        print "<p>Now return to Form 1040 and focus on filling in lines 8a and 8b. On line 8a, you will re-enter the value you entered on Schedule 1, line 22, namely $".number_format(0.5*$selfEmploymentTax,2).". On line 8b, you should enter the value obtained by subtracting line 8a from line 7b, i.e., the value $(".number_format($incomeForTaxPurposes, 2)." - $".number_format(0.5*$selfEmploymentTax,2)."). The difference should work out to $".number_format($incomeForTaxPurposes - 0.5 * $selfEmploymentTax, 2).", or approximately (100 - 0.5 * 14.13)% of your income.</p>";
      }
      if ($incomeForTaxPurposes < $standardDeduction[$year]/(1 - 0.5 * 0.1413)) {
        if ($year <= '2017') {
          print "Assuming you had no other income in $year, since your income minus the deductible part of self-employment tax was less than the standard deduction of $".number_format($standardDeduction[$year], 2)." USD, you do not need to pay income tax, and line 56 should be 0.</p>";
        } else if ($year == '2018') {
          print "<p>On line 8, enter the standard deduction for the year, which is $".number_format($standardDeduction[$year]).". The value you entered on line 7, namely $".number_format($incomeForTaxPurses - 0.5 * $selfEmploymentTax, 2).", is less than the standard deduction you entered on line 8. Thus, on line 10, you will enter 0. You do not owe any income tax.</p>";
        } else {
          print "<p>On lines 9 and 11a, enter the standard deduction for the year, which is $".number_format($standardDeduction[$year]).". The value you entered on line 8b, namely $".number_format($incomeForTaxPurposes - 0.5 * $selfEmploymentTax, 2).", is less than the standard deduction you entered on line 11a. Thus, on line 11b, you will enter 0. You do not owe any income tax.</p>";
        }
      } else if ($incomeForTaxPurposes < ($standardDeduction[$year] + $basicExemption[$year])/(1 - 0.5 * 0.1413) and $year <= "2017") {
        print "Assuming you had no other income in $year, since your income minus the deductible part of self-employment tax was less than the sum of the standard deduction of $".number_format($standardDeduction[$year], 2)." USD and the basic personal exemption of $".number_format($basicExemption[$year], 2).", you do not need to pay income tax if you are a United States citizen or resident for tax purposes, <em>and</em> if nobody else claimed you as a dependent. Under these circumstances, line 56 should be 0. However, if somebody claimed you as a dependent, you cannot take the personal exemption and may have a positive income tax obligation. Crude guess: your taxable income in this case will be $".number_format($taxableIncomeAssumingNoExemption,2)." USD and your income tax will be approximately $".number_format($incomeTaxAssumingNoExemption,2)." USD.".' The computation of tax from taxable income is done using the <a href="https://taxfoundation.org/'.$year.'-tax-brackets">'.$year." tax brackets</a>.</p>\n";
      } else {
        if ($year <= "2017") {
          print "You probably need to pay some taxes, so line 56 is likely to be positive (though it may not be, depending on all the deductions and credits you get). Crude guess: assuming you are not being claimed as a dependent, your taxable income will be $".number_format($taxableIncomeAssumingExemption,2)." USD and your income tax will be approximately $".number_format($incomeTaxAssumingExemption,2)." USD. If somebody claimed you as a dependent, your taxable income will be $".number_format($taxableIncomeAssumingNoExemption,2)." USD and your income tax will be approximately $".number_format($incomeTaxAssumingNoExemption,2)." USD.".' The computation of tax from taxable income is done using the <a href="https://taxfoundation.org/'.$year.'-tax-brackets">'.$year." tax brackets</a>.</p>\n";
        } else {
          print "On line 8, enter your standard deduction for the year, namely $".number_format($standardDeduction[$year], 2).". On line 10, enter the value obtained by subtracting line 8 from line 7. This should yield $".number_format($taxableIncomeAssumingNoExemption, 2)." USD and your income tax (to be entered on line 11) will be approximately $".number_format($incomeTaxAssumingNoExemption,2)." USD.".' The computation of tax from taxable income is done using the <a href="https://taxfoundation.org/'.$year.'-tax-brackets">'.$year." tax brackets</a>.</p>\n";
        }
      }
      if ($year <= "2017") {
        print '<p>Now return to Form 1040. Fill in line 57; this should match line 12 of Schedule SE, which is $'.number_format($selfEmploymentTax, 2).'. The total on line 63 should be the sum of your income tax (as calculated on line 56) and your self-employment tax (as calculated on line 57). This total will be $'.number_format($totalTaxAssumingExemption, 2).' if you are taking a personal exemption (i.e., you are not being claimed as a dependent), and $'.number_format($totalTaxAssumingNoExemption, 2).' if you are not taking a personal exemption (i.e., somebody else is claiming you as a dependent).</p>';
        print '<p>If you have made estimated tax payments (using Form 1040-ES by mail or through EFTPS) you need to enter the total amount of your estimated tax payments on line 65. If you paid an additional amount with your request for extension to file, enter that on line 70. Enter the total on line 74.</p>';
        print "<p>Now follow the instructions to fill in the rest of the form. Depending on which of line 63 and line 74 is bigger, you are either owed a refund or need to make a payment. If you are owed a refund, you can either ask for it right away or have it apply to next year's taxes. If you owe money, there is a possibility that you may also need to pay an estimated tax penalty, but if you aren't sure how to calculate this penalty, you can leave it blank and let the IRS reach out to you if they need you to pay a penalty.</p>";
      } else if ($year == "2018") {
        print '<p>Now go to <a href="https://www.irs.gov/pub/irs-pdf/f1040s4.pdf">Form 1040, Schedule 4</a>. Fill in line 57; this should match line 12 of Schedule SE, which is $'.number_format($selfEmploymentTax, 2).'. Enter the same amount on line 64.</p>';
        print '<p>Now return to Form 1040. On line 14, enter the same value as entered in Schedule 4, namely $'.number_format($selfEmploymentTax, 2).'. On line 15, enter the totals of lines 11 and 14, which should work out to $'.number_format($totalTaxAssumingNoExemption, 2).'. This is the total amount of tax you owe.</p>';
        print '<p>If you have made estimated tax payments (using Form 1040-ES by mail or through EFTPS) you need to enter the total amount of your estimated tax payments in <a href="https://www.irs.gov/pub/irs-pdf/f1040s5.pdf">Form 1040, Schedule 5</a> on line 66. If you paid an additional amount with your request for extension to file, enter that on line 71. Enter the total on line 75.</p>';
        print '<p>Return to Form 1040 and on line 17, enter the amount you just entered on line 75 in the inner blank that says "Add any amount from Schedule 5" and then also on the main line 17 (on the right) and on line 18.</p>';
        print "<p>Now follow the instructions to fill in the rest of the form. Depending on which of line 15 and line 18 is bigger, you are either owed a refund or need to make a payment. If you are owed a refund, you can either ask for it right away or have it apply to next year's taxes. If you owe money, there is a possibility that you may also need to pay an estimated tax penalty, but if you aren't sure how to calculate this penalty, you can leave it blank and let the IRS reach out to you if they need you to pay a penalty.</p>";
      } else {
        print 'Now go to <a href="https://www.irs.gov/pub/irs-pdf/f1040s2.pdf">Form 1040, Schedule 2</a>. Fill in line 4; this should match line 12 of Schedule SE, which is $'.number_format($selfEmploymentTax, 2).'. Enter the same amount on line 10.</p>';
        print '<p>Now return to Form 1040. On line 15, enter the value as entered in Schedule 2, namely $'.number_format($selfEmploymentTax, 2).'. On line 16, enter the totals of lines 11 and 14, which should work out to $'.number_format($totalTaxAssumingNoExemption, 2).'. This is the total amount of tax you owe.</p>';
        print '<p>If you have made estimated tax payments (using Form 1040-ES by mail or through EFTPS) or if you chose a credit elect last year, you need to enter the total amount applied from last year plus your estimated tax payments in <a href="https://www.irs.gov/pub/irs-pdf/f1040s3.pdf">Form 1040, Schedule 3</a> on line 8. If you paid an additional amount with your request for extension to file, enter that on line 10. Enter the total on line 14.</p>';
        print '<p>Return to Form 1040 and copy the total you just entered (on Schedule 3 line 14) to Form 1040, lines 18d, 18e, and 19.</p>';
        print "<p>Now follow the instructions to fill in the rest of the form. Depending on which of line 16 and line 19 is bigger, you are either owed a refund or need to make a payment. If you are owed a refund, you can either ask for it right away or have it apply to next year's taxes. If you owe money, there is a possibility that you may also need to pay an estimated tax penalty, but if you aren't sure how to calculate this penalty, you can leave it blank and let the IRS reach out to you if they need you to pay a penalty.</p>";
      }
      print "<p>If you are using a tax compliance software instead of filling the forms yourself, then check if it gives you an option to add in income for self-employment or contract work. Some softwares may not allow you to enter the numbers directly. To get around this problem, you may need to enter it in as if it is a Form 1099-MISC, even though you will not receive a Form 1099-MISC. That is because Vipul Naik is paying you personally rather than in the course of a trade or business, but tax compliance softwares may not have personal payments as a prominent enough use case to cover.</p>";
    }
  }
}
?>
