<?php
print '<!doctype html public "-//W3C//DTD HTML 4.01 Transitional//EN"><html><head><meta http-equiv="Content-Type" content="text/html;charset=utf-8" >';
print '<title>Contract work for Vipul Naik</title>';
print '</head>';
include_once("backend/globalvariables/passwordFile.inc");
include_once("backend/globalvariables/lists.inc");
print '<body>';
print '<h3>Contract work for Vipul Naik</h3>';
print '<p>This is an online portal with a summary and various exploration options for contract work done for <a href="http://vipulnaik.com">Vipul Naik</a>. The git repository with the code for this portal, as well as all the underlying data, is <a href="https://github.com/vipulnaik/contractwork">available on GitHub</a>. All payment amounts are in current United States dollars (USD).</p>';

print '<h4>Table of contents</h4>';
print '<ul>';
print '<li><a href="#paymentsDueByTypeAndYear">Payments due by type and year</a></li>';
print '<li><a href="#paymentsMadeByMethodAndYear">Payments made by method and year</a></li>';
print '<li><a href="#taskPaymentsDueByTypeAndYear">Task payments due by type and year</a></li>';
print '<li><a href="#taskPaymentsDueByVenueAndYear">Task payments due by venue and year</a></li>';
print '<li><a href="#paymentsDueByWorkerAndType">Payments due by worker and type</a></li>';
print '<li><a href="#paymentsMadeByWorkerAndMethod">Payments made by worker and method</a></li>';
print '<li><a href="#paymentsDueAndMadeByWorker">Payments due and made by worker</a></li>';
print '<li><a href="#paymentsDueByTypeAndMonth">Payments due by type and month</a></li>';
print '<li><a href="#taskPaymentsDueByTypeAndMonth">Task payments due by type and month</a></li>';
print '<li><a href="#paymentsDueAndMadeByMonth">Payments due and made by month</a></li>';
print '</ul>';

include ("backend/paymentsDueByTypeAndYear.inc");
include ("backend/paymentsMadeByMethodAndYear.inc");
include ("backend/taskPaymentsDueByTypeAndYear.inc");
include ("backend/taskPaymentsDueByVenueAndYear.inc");
include ("backend/taskPaymentsDueByTopicAndYear.inc");
include ("backend/paymentsDueByWorkerAndType.inc");
include ("backend/paymentsMadeByWorkerAndMethod.inc");
include ("backend/paymentsDueAndMadeByWorker.inc");
include ("backend/paymentsDueByTypeAndMonth.inc");
include ("backend/taskPaymentsDueByTypeAndMonth.inc");
include ("backend/paymentsDueAndMadeByMonth.inc");
print '</body>';
?>