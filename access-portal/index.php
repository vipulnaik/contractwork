<?php
print '<!doctype html public "-//W3C//DTD HTML 4.01 Transitional//EN"><html><head><meta http-equiv="Content-Type" content="text/html;charset=utf-8" >';
print '<title>Contract work for Vipul Naik</title>';
print '</head>';
include_once("backend/globalvariables/passwordfile.inc");
print '<body>';
print '<h3>Contract work for Vipul Naik</h3>';
print '<p>This is an online portal with a summary and various exploration options for contract work done for <a href="http://vipulnaik.com">Vipul Naik</a>. The git repository with the code for this portal, as well as all the underlying data, is <a href="https://github.com/vipulnaik/contractwork">available on GitHub</a>. All payment amounts are in current United States dollars (USD).</p>';

$yearList = array("2015", "2016");

$monthList = array("2015-04","2015-05","2015-06","2015-07","2015-08","2015-09","2015-10","2015-11","2015-12","2016-01","2016-02","2016-03","2016-04","2016-05","2016-05","2016-06","2016-07","2016-08","2016-09","2016-10","2016-11","2016-12");

include ("backend/paymentsDueByTypeAndYear.inc");
include ("backend/taskPaymentsDueByTypeAndYear.inc");
include ("backend/taskPaymentsDueByVenueAndYear.inc");
include ("backend/taskPaymentsDueByTopicAndYear.inc");
include ("backend/paymentsDueByTypeAndMonth.inc");
print '</body>';
?>