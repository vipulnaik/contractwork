<?php

foreach($yearList as $year) {
  if ($totalPaymentAwarded[$year] > 0 or $totalPaymentMadeByYear[$year] > 0) {
    print "<h4>Tax situation for year $year";
    if ($totalPaymentAwarded[$year] == $totalpaymentMadeByYear[$year]) {
      $income = $totalPaymentAwarded[$year];
      print "<p>During this year, you earned an income of $income from contract work for Vipul Naik using both accrual basis accounting (including only awarded income) and cash basis accounting (including only received income.</p>";
      if ($income < 4000) {
        print "<p>If this was your sole income source for the year, here is approximate guidance on filing your taxes. File Form 1040 along with Schedules C and SE.</p>";
        print "<p>First fill Schedule C. Enter the amount $income in Part I, lines 1, 3, 5, and 7, and enter 0 in (or leave blank) lines 2, 4, and 6. For Part II, enter 0 (or leave blank) lines 8 through 27 in Part II. Enter 0 for lines 28 and 30, and enter $income for lines 29 and 31. You can skip entering Part III and IV, and therefore do not need to attach those sheets.</p>";
}