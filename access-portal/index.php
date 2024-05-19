<?php
include_once('doctype.inc');
print '<script src="change-theme.js"></script>';
print '<title>Contract work for Vipul Naik</title>';
include_once('analytics.inc');
include_once('strip-commas.inc');
include_once('backend/functions.inc');
include_once('backend/graphing.inc');
print '<link href="style.css" rel="stylesheet" type="text/css" />'."\n";
include_once('style.inc');
print '<script type="text/javascript" src="./jquery-3.7.1.min.js"></script>'."\n";
print '<script type="text/javascript" src="./jquery.tablesorter.js"></script>'."\n";
print '</head>';
include_once("backend/globalVariables/passwordFile.inc");
include_once("backend/globalVariables/lists.inc");
print "<body>\n";
print '<script>$(document).ready(function(){$("table").tablesorter({textExtraction: stripCommas});});</script>'."\n";
print '<h3>Contract work for Vipul Naik</h3>';
?>

<p><span id="changeThemeMenu" style="display: none;">Set color scheme to:
         <span id="auto-menu-option" style="cursor: pointer;" class="unselectable" onclick="change_theme.set_color('auto')">auto</span>,
         <span id="light-menu-option" style="cursor: pointer;" class="unselectable" onclick="change_theme.set_color('light')">light</span>,
         <span id="dark-menu-option" style="cursor: pointer;" class="unselectable" onclick="change_theme.set_color('dark')">dark</span>
</span>&thinsp;<!-- blank space to prevent cumulative layout shift --></p>
<script>change_theme.set_theme_from_local_storage();</script>

<?php
include('preamble.inc');
print '<h4>Table of contents</h4>';
print '<ul>';
print '<li><a href="#paymentsDueByTypeAndYear">Payments due by type and year</a></li>';
print '<li><a href="#paymentsMadeByMethodAndYear">Payments made by method and year</a></li>';
print '<li><a href="#taskPaymentsDueByTypeAndYear">Task payments due by type and year</a></li>';
print '<li><a href="#taskPaymentsDueByTopicAndYear">Task payments due by topic and year</a></li>';
print '<li><a href="#taskPaymentsDueByVenueAndYear">Task payments due by venue and year</a></li>';
print '<li><a href="#taskPaymentsDueByFormatAndYear">Task payments due by format and year</a></li>';
print '<li><a href="#taskPaymentsDueByWorkerAndYear">Task payments due by worker and year</a></li>';
print '<li><a href="#paymentsDueByWorkerAndType">Payments due by worker and type</a></li>';
print '<li><a href="#taskPaymentsDueByWorkerAndType">Task payments due by worker and type</a></li>';
print '<li><a href="#paymentsMadeByWorkerAndMethod">Payments made by worker and method</a></li>';
print '<li><a href="#paymentsDueAndMadeByWorker">Payments due and made by worker</a></li>';
print '<li><a href="#paymentsDueByTypeAndMonth">Payments due by type and month</a></li>';
print '<li><a href="#taskPaymentsDueByTypeAndMonth">Task payments due by type and month</a></li>';
print '<li><a href="#taskPaymentsDueByTopicAndMonth">Task payments due by topic and month</a></li>';
print '<li><a href="#taskPaymentsDueByVenueAndMonth">Task payments due by venue and month</a></li>';
print '<li><a href="#taskPaymentsDueByFormatAndMonth">Task payments due by format and month</a></li>';
print '<li><a href="#taskPaymentsDueByWorkerAndMonth">Task payments due by worker and month</a></li>';
print '<li><a href="#paymentsDueAndMadeByMonth">Payments due and made by month</a></li>';
print '<li><a href="#additionalNotes">Additional notes</a></li>';
print '</ul>';

include ("backend/paymentsDueByTypeAndYear.inc");
include ("backend/paymentsMadeByMethodAndYear.inc");
include ("backend/taskPaymentsDueByTypeAndYear.inc");
include ("backend/taskPaymentsDueByTopicAndYear.inc");
include ("backend/taskPaymentsDueByVenueAndYear.inc");
include ("backend/taskPaymentsDueByFormatAndYear.inc");
include ("backend/taskPaymentsDueByWorkerAndYear.inc");
include ("backend/paymentsDueByWorkerAndType.inc");
include ("backend/taskPaymentsDueByWorkerAndType.inc");
include ("backend/paymentsMadeByWorkerAndMethod.inc");
include ("backend/paymentsDueAndMadeByWorker.inc");
include ("backend/paymentsDueByTypeAndMonth.inc");
include ("backend/taskPaymentsDueByTypeAndMonth.inc");
include ("backend/taskPaymentsDueByTopicAndMonth.inc");
include ("backend/taskPaymentsDueByVenueAndMonth.inc");
include ("backend/taskPaymentsDueByFormatAndMonth.inc");
include ("backend/taskPaymentsDueByWorkerAndMonth.inc");
include ("backend/paymentsDueAndMadeByMonth.inc");
include ("additionalNotes.inc");

include_once('anchorjs.inc');
print '</body>';
?>
