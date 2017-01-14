<?php
print '<!doctype html public "-//W3C//DTD HTML 4.01 Transitional//EN"><html><head><meta http-equiv="Content-Type" content="text/html;charset=utf-8" >';
print '<title>Contract work for Vipul Naik</title>';
include_once('analytics.inc');
print '<link href="style.css" rel="stylesheet" type="text/css" />'."\n";
print '<script type="text/javascript" src="./jquery-3.1.1.min.js"></script>'."\n";
print '<script type="text/javascript" src="./jquery.tablesorter.js"></script>'."\n";
print '</head>';
include_once("backend/globalVariables/passwordFile.inc");
include_once("backend/globalVariables/lists.inc");
print '<body>';
print '<script>$(document).ready(function()
    {
        $("#myTablePaymentsDueByTypeAndYear").tablesorter();
        $("#myTablePaymentsMadeByMethodAndYear").tablesorter();
        $("#myTableTaskPaymentsDueByTypeAndYear").tablesorter();
        $("#myTableTaskPaymentsDueByTopicAndYear").tablesorter();
        $("#myTableTaskPaymentsDueByVenueAndYear").tablesorter();
        $("#myTableTaskPaymentsDueByWorkerAndType").tablesorter();
        $("#myTableTaskPaymentsMadeByWorkerAndMethod").tablesorter();
    }
); </script>'."\n";
print '<h3>Contract work for Vipul Naik</h3>';
include_once('preamble.inc');
print '<h4>Table of contents</h4>';
print '<ul>';
print '<li><a href="#paymentsDueByTypeAndYear">Payments due by type and year</a></li>';
print '<li><a href="#paymentsMadeByMethodAndYear">Payments made by method and year</a></li>';
print '<li><a href="#taskPaymentsDueByTypeAndYear">Task payments due by type and year</a></li>';
print '<li><a href="#taskPaymentsDueByTopicAndYear">Task payments due by topic and year</a></li>';
print '<li><a href="#taskPaymentsDueByVenueAndYear">Task payments due by venue and year</a></li>';
print '<li><a href="#paymentsDueByWorkerAndType">Payments due by worker and type</a></li>';
print '<li><a href="#paymentsMadeByWorkerAndMethod">Payments made by worker and method</a></li>';
print '<li><a href="#paymentsDueAndMadeByWorker">Payments due and made by worker</a></li>';
print '<li><a href="#paymentsDueByTypeAndMonth">Payments due by type and month</a></li>';
print '<li><a href="#taskPaymentsDueByTypeAndMonth">Task payments due by type and month</a></li>';
print '<li><a href="#taskPaymentsDueByTopicAndMonth">Task payments due by topic and month</a></li>';
print '<li><a href="#taskPaymentsDueByVenueAndMonth">Task payments due by venue and month</a></li>';
print '<li><a href="#paymentsDueAndMadeByMonth">Payments due and made by month</a></li>';
print '</ul>';

include ("backend/paymentsDueByTypeAndYear.inc");
include ("backend/paymentsMadeByMethodAndYear.inc");
include ("backend/taskPaymentsDueByTypeAndYear.inc");
include ("backend/taskPaymentsDueByTopicAndYear.inc");
include ("backend/taskPaymentsDueByVenueAndYear.inc");
include ("backend/paymentsDueByWorkerAndType.inc");
include ("backend/paymentsMadeByWorkerAndMethod.inc");
include ("backend/paymentsDueAndMadeByWorker.inc");
include ("backend/paymentsDueByTypeAndMonth.inc");
include ("backend/taskPaymentsDueByTypeAndMonth.inc");
include ("backend/taskPaymentsDueByTopicAndMonth.inc");
include ("backend/taskPaymentsDueByVenueAndMonth.inc");
include ("backend/paymentsDueAndMadeByMonth.inc");
print '</body>';
?>