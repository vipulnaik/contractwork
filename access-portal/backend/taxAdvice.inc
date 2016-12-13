<?php

$reimbursementSelectQuery = "select year(receipt_date) as year, coalesce(sum(sent_payment), 0) as payment from payments where intermediary='$worker' and receipt_date is not null group by year(receipt_date), order by year(receipt_date);";
$reimbursementSelectResult = $mysqli -> query($reimbursementSelectQuery);
foreach($yearList as $year) {
  $reimbursementDueInYear[$year] = 0;
}

for($i = 0;$i < $reimbursementSelectResult -> num_rows;$i++) {
  $row = $reimbursementSelectResult -> fetch_assoc();
  $reimbursementDueInYear[$row['year']] = $row['payment'];
}

print '<p>For more information on taxes, learn about <a href="https://en.wikipedia.org/wiki/Form_1040">Form 1040</a> and <a href="https://en.wikipedia.org/wiki/Form_1099-MISC">Form 1099-MISC</a>.</p>';

foreach(array_reverse($yearList) as $year) {
  if ($totalPaymentAwarded[$year] > 0 or $totalPaymentMadeByYear[$year] > 0) {
    print "<h4>Tax situation for year $year</h4>";
    $accrualIncome = $totalPaymentAwarded[$year];
    $cashIncome = $totalPaymentMadeByYear[$year] - $reimbursementDueInYear[$year];
    print "<p>In the year $year, the total payment awarded to you (your accrual income) was $accrualIncome, and the total money paid to you (your cash income) was $cashIncome. The rest of the instructions here assume you are using accrual income for your calculations.</p>";
    if ($accrualIncome < $standardDeduction[$year]) {
      print "<p>Assuming you had no other income in $year, since your accrual income was less than the standard deduction of $".$standardDeduction[$year]." USD, you do not need to pay income tax if you are a United States citizen or resident for tax purposes.</p>";
    } else if ($accrualIncome < $standardDeduction[$year] + $basicExemption[$year]) {
      print "<p>Assuming you had no other income in $year, since your accrual income was less than the sum of the standard deduction of ".$standardDeduction[$year]." and the basic personal exemption of ".$basicExemption[$year].", you do not need to pay income tax if you are a United States citizen or resident for tax purposes, <em>and</em> if nobody else claimed you as a dependent.</p>";
    } else {
      print "<p>You probably need to pay taxes on the income $accrualIncome earned in year $year, even if it was your only income for the year.</p>";
    }
    if ($accrualIncome > 0) {
      print "<p>If you are a United States citizen or resident for tax purposes, you <strong>need to pay self-employment tax (Social Security and Medicare taxes)</strong> on the income earned. You also need to file your income tax return. The reason is that for contract work, the responsibility for paying these taxes falls on the worker rather than the employer. Approximate, highly conservative, guidance on what to do follows. This is just to give you a sense of how things should look; you should read through the forms and instructions competely to make sure it is correct for your situation.</p>";
      print '<p><strong>Fill in the forms electronically (using your PDF reader) rather than by hand to make it easier to edit the forms and easier for the IRS to process your forms</strong>.</p>';
      print '<p>Start by filling <a href="https://www.irs.gov/pub/irs-pdf/f1040sc.pdf">Form 1040, Schedule C, Page 1</a>. In Part I and II, enter all your contract work income on Lines 1, 3, 5, 7, 29, and 31. If all your contract work income was from Vipul Naik, the amount will be '.$accrualIncome.'. The remaining entries in both parts should be zero or blank. Do not fill in Page 2. Attach only Page 1 to your tax filing.</p>';
      print '<p>Now go to <a href="https://www.irs.gov/pub/irs-pdf/f1040.pdf">the main Form 1040</a>. Enter the data for Lines 1 through 6 based on your knowledge. If you are single and nobody is claiming you as a dependent, you should have 1 total exemption claimed in Line 6d. For Line 7, enter your total income from regular employment. Enter your contract work income on Line 12 (which equals '.$accrualIncome.' if contract work for Vipul Naik was your only contract work). Fill the rest of the form, till Line 56. Leave Line 27 blank; circle back to it later. ';
      if ($accrualIncome < $standardDeduction[$year]) {
        print "Assuming you had no other income in $year, since your accrual income was less than the standard deduction of $".$standardDeduction[$year]." USD, you do not need to pay income tax, and line 56 should be 0.</p>";
      } else if ($accrualIncome < $standardDeduction[$year] + $basicExemption[$year]) {
        print "Assuming you had no other income in $year, since your accrual income was less than the sum of the standard deduction of $".$standardDeduction[$year]." USD and the basic personal exemption of $".$basicExemption[$year].", you do not need to pay income tax if you are a United States citizen or resident for tax purposes, <em>and</em> if nobody else claimed you as a dependent. Under these circumstances, line 56 should be 0.</p>";
      } else {
        print "You probably need to pay some taxes, so Line 56 is likely to be positive (though it may not be, depending on all the deductions and credits you get).</p>";
      }
      print '<p>For <a href="https://www.irs.gov/pub/irs-pdf/f1040-sse.pdf">Form 1040, Schedule SE</a>'.", fill Page 2, Part I (leave Page 1 and Page 2, Part II blank). Your contract work income will go in Lines 2 and 3. Follow the instructions carefully. The end result on Line 12 should be about 14.12% of your contract work income (there are some edge cases where it's less, but these probably don't apply to you).</p>";
      print '<p>Now return to Form 1040. Fill in Line 57 and then complete the rest of the form.</p>';
      print "<p>If you are using a tax compliance software instead of filling the forms yourself, then check if it gives you an option to add in income for self-employment or contract work. Some softwares may not allow you to enter the numbers directly. To get around this problem, you may need to enter it in as if it is a Form 1099-MISC, even though you will not receive a Form 1099-MISC. That is because Vipul Naik is paying you personally rather than in the course of a trade or business.</p>";
    }
  }
}
?>