<?php

$reimbursementSelectQuery = "select year(receipt_date) as year, coalesce(sum(sent_payment), 0) as payment from payments where intermediary='$worker' and receipt_date is not null group by year(receipt_date) order by year(receipt_date);";
$reimbursementSelectResult = $mysqli -> query($reimbursementSelectQuery);
foreach($yearList as $year) {
  $reimbursementDueInYear[$year] = 0;
}

for($i = 0;$i < $reimbursementSelectResult -> num_rows;$i++) {
  $row = $reimbursementSelectResult -> fetch_assoc();
  $reimbursementDueInYear[$row['year']] = $row['payment'];
}

print '<p>For more information on taxes, learn about <a href="https://en.wikipedia.org/wiki/Form_1040">Form 1040</a> and <a href="https://en.wikipedia.org/wiki/Form_1099-MISC">Form 1099-MISC</a>.</p>';

print '<p><a href="/worker.php?worker='.urlencode($worker).'">Back to worker page</a>';

foreach(array_reverse($yearList) as $year) {
  if ($totalPaymentAwarded[$year] > 0 or $totalPaymentMadeByYear[$year] > 0) {
    print "<h4>Tax situation for year $year</h4>";
    $income = $totalPaymentAwarded[$year];
    $receivedIncome = $totalPaymentMadeByYear[$year] - $reimbursementDueInYear[$year];
    $selfEmploymentTax = 0.1412 * $income;
    $taxableIncomeAssumingNoExemption = max(0, $income - 0.5 * $selfEmploymentTax - $standardDeduction[$year]);
    $incomeTaxAssumingNoExemption = 0.1 * $taxableIncomeAssumingNoExemption;
    $taxableIncomeAssumingExemption = max(0, $income - 0.5 * $selfEmploymentTax - $standardDeduction[$year] - $basicExemption[$year]);
    $incomeTaxAssumingExemption = 0.1 * $taxableIncomeAssumingExemption;
    $totalTaxAssumingNoExemption = $selfEmploymentTax + $incomeTaxAssumingNoExemption;
    $totalTaxAssumingExemption = $selfEmploymentTax + $incomeTaxAssumingExemption;
    print "<p>In the year $year, the total payment awarded to you (your income) was $".sprintf('%.2f',$income)." USD, and the total money paid to you was $".sprintf('%.2f',$receivedIncome)." USD.</p>";
    print "<p>Here is a rough estimate for how much tax you would need to pay assuming all your income was from contract work for Vipul Naik: (a) assuming you cannot take a personal exemption: $".sprintf('%.2f',$selfEmploymentTax)." self-employment tax and $".sprintf('%.2f',$incomeTaxAssumingNoExemption)." income tax totaling to $".sprintf('%.2f',$totalTaxAssumingNoExemption).", (b) assuming you can take a personal exemption: $".sprintf('%.2f',$selfEmploymentTax)." self-employment tax and $".sprintf('%.2f',$incomeTaxAssumingExemption)." income tax, totaling to $".sprintf('%.2f',$totalTaxAssumingExemption).". More details of your tax situation and how to fill your tax forms are below.</p>";
    if ($income > 0) {
      print "<p>If you are a United States citizen or resident for tax purposes, you <strong>need to pay self-employment tax (Social Security and Medicare taxes)</strong> on the income earned. The reason is that income earned through contract work is classified under self-employment income, and the responsibility for paying Social Security and Medicare taxes on such income falls on the worker rather than the payer. Approximate, highly conservative, guidance on what to do follows. This is just to give you a sense of how things should look; you should read through the forms and instructions competely to make sure it is correct for your situation.</p>";
      if ($income < $selfEmploymentFilingThreshold[$year]) {
        print '<p>Assuming all your income was self-employment income and all of it was earned through contract work for Vipul Naik: since your income is less than the self-employment filing threshold of $'.$selfEmploymentFilingThreshold[$year].', you probably do not need to file your tax return. For more, see <a href="https://www.irs.gov/businesses/small-businesses-self-employed/self-employed-individuals-tax-center">here</a>. However, <strong>you still have a legal obligation to pay your taxes</strong>, so the below filing guidance can help you better understand how to calculate the amount that you need to pay.</p>';
      } else {
        print '<p>Since your self-employment income exceeds the self-employment filing threshold of $'.$selfEmploymentFilingThreshold[$year].', <strong>you need to file your tax return</strong>. For more, see <a href="https://www.irs.gov/businesses/small-businesses-self-employed/self-employed-individuals-tax-center">here</a>.</p>';
      }
      print '<p><strong>Fill in the forms electronically (using your PDF reader) rather than by hand to make it easier to edit the forms and easier for the IRS to process your forms</strong>.</p>';
      print '<p>Start by filling <a href="https://www.irs.gov/pub/irs-pdf/f1040sc.pdf">Form 1040, Schedule C, Page 1</a>. In Part I and II, enter all your contract work income on Lines 1, 3, 5, 7, 29, and 31. If all your contract work income was from Vipul Naik, the amount will be '.$income.'. The remaining entries in both parts should be zero or blank. Do not fill in Page 2. Attach only Page 1 to your tax filing.</p>';
      print '<p>Now go to <a href="https://www.irs.gov/pub/irs-pdf/f1040.pdf">the main Form 1040</a>. Enter the data for Lines 1 through 6 based on your knowledge. If you are single and nobody is claiming you as a dependent, you should have 1 total exemption claimed in Line 6d. For Line 7, enter your total income from regular employment. Enter your contract work income on Line 12 (which equals '.$income.' if contract work for Vipul Naik was your only contract work).';
      print '<p>Now switch to <a href="https://www.irs.gov/pub/irs-pdf/f1040-sse.pdf">Form 1040, Schedule SE</a>'.". Fill Page 2, Part I (leave Page 1 and Page 2, Part II blank). Your contract work income will go in Lines 2 and 3. Follow the instructions carefully. The end result on Line 12 should be about 14.12% of your contract work income, which should work out to $".sprintf('%.2f',$selfEmploymentTax)." (there are some edge cases where it's less, but these probably don't apply to you).</p>";
      print '<p>Return to Form 1040. Fill the rest of the form, till Line 56. For Line 27, reference Schedule SE. ';
      if ($income < $standardDeduction[$year]/(1 - 0.5 * 0.1412)) {
        print "Assuming you had no other income in $year, since your income minus the deductible part of self-employment tax was less than the standard deduction of $".$standardDeduction[$year]." USD, you do not need to pay income tax, and line 56 should be 0.</p>";
      } else if ($income < ($standardDeduction[$year] + $basicExemption[$year])/(1 - 0.5 * 0.1412)) {
        print "Assuming you had no other income in $year, since your income minus the deductible part of self-employment tax was less than the sum of the standard deduction of $".$standardDeduction[$year]." USD and the basic personal exemption of $".$basicExemption[$year].", you do not need to pay income tax if you are a United States citizen or resident for tax purposes, <em>and</em> if nobody else claimed you as a dependent. Under these circumstances, line 56 should be 0. However, if somebody claimed you as a dependent, you cannot take the personal exemption and may have a positive income tax obligation. Crude guess: your taxable income in this case will be $$taxableIncomeAssumingNoExemption USD and your income tax will be approximately $".sprintf('%.2f',$incomeTaxAssumingNoExemption)." USD.</p>";
      } else {
        print "You probably need to pay some taxes, so Line 56 is likely to be positive (though it may not be, depending on all the deductions and credits you get). Crude guess: assuming you are not being claimed as a dependent, your taxable income will be approximately $$taxableIncomeAssumingNoExemption USD and your income tax will be approximately $".sprintf('%.2f',$incomeTaxAssumingExemption)." USD. If somebody claimed you as a dependent, your taxable income will be $$taxableIncomeAssumingExemption USD and your tax will be $".sprintf('%.2f',$incomeTaxAssumingNoExemption)." USD.</p>";
      }
      print '<p>Now return to Form 1040. Fill in Line 57 and then complete the rest of the form.</p>';
      print "<p>If you are using a tax compliance software instead of filling the forms yourself, then check if it gives you an option to add in income for self-employment or contract work. Some softwares may not allow you to enter the numbers directly. To get around this problem, you may need to enter it in as if it is a Form 1099-MISC, even though you will not receive a Form 1099-MISC. That is because Vipul Naik is paying you personally rather than in the course of a trade or business, but tax compliance softwares may not have personal payments as a prominent enough use case to cover.</p>";
    }
  }
}
?>