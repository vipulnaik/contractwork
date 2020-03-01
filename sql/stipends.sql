create table stipends(
  stipend_id int(11) not null auto_increment primary key,
  payee varchar(40),
  payment float(7,2) not null,
  stipend_start_date date NOT NULL,
  stipend_end_date date NOT NULL,
  stipend_award_date date,
  notes varchar(2000),
  hours_logged float(13,2) DEFAULT NULL,
  total_work_hours int(11) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=15239276 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

insert into stipends(payee, payment, stipend_start_date, stipend_end_date, stipend_award_date, notes, hours_logged, total_work_hours) values
  ('Issa Rice',700,'2016-02-01','2016-02-28','2016-12-28','Paid after long deferral as end-of-year award. Constitutes 100% of stipend for that month', NULL, NULL),
  ('Issa Rice',900,'2016-03-01','2016-03-31','2016-12-28','Paid after long deferral as end-of-year award. Constitutes 100% of stipend for that month', NULL, NULL),
  ('Issa Rice',900,'2016-04-01','2016-04-30','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes 100% of stipend for that month', NULL, NULL),
  ('Issa Rice',1000,'2016-05-01','2016-05-31','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $300 was awarded at end of original month', NULL, NULL),
  ('Issa Rice',1250,'2016-06-01','2016-06-30','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $250 was awarded at end of original month', NULL, NULL),
  ('Issa Rice',1250,'2016-07-01','2016-07-31','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $250 was awarded at end of original month', NULL, NULL),
  ('Issa Rice',960,'2016-08-01','2016-08-31','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone; pay less than usual 1250 because of reduced work while in Japan. Constitutes deferred part of stipend for that month; remaining $190 was awarded at end of original month', NULL, NULL),
  ('Issa Rice',1250,'2016-09-01','2016-09-30','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $250 was awarded at end of original month', NULL, NULL),
  ('Issa Rice',1250,'2016-10-01','2016-10-31','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $250 was awarded at end of original month', NULL, NULL),
  ('Issa Rice',750,'2016-11-01','2016-11-30','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $250 was awarded at end of original month. The amount was reduced from the standard $1250 because part of the time was spent on https://issarice.com/digital-preservation (a personal project)', NULL, NULL),
  ('Issa Rice',750,'2016-12-01','2016-12-31','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $250 was awarded at end of original month. The amount was reduced from the standard $1250 because part of the time was spent on researcher profiles (a personal project)', NULL, NULL),
  ('Issa Rice',1200,'2017-01-01','2017-01-31','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $250 was awarded at end of original month. The amount was reduced from the full $1250 because of a few days off', 74, 176),
  ('Issa Rice',1150,'2017-02-01','2017-02-28','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $250 was awarded at end of original month. The amount was reduced from the standard $1250 because of time spent on https://issarice.com/amazon-mechanical-turk (a personal project)', 161, 160);

insert into stipends(payee, payment, stipend_start_date, stipend_end_date, stipend_award_date, notes, hours_logged, total_work_hours) values
  ('Issa Rice',300,'2016-05-01','2016-05-31','2016-05-31',NULL,NULL,NULL),
  ('Issa Rice',250,'2016-06-01','2016-06-30','2016-06-30','Distribution changed from 300 + 1000 to 250 + 1250 to conserve cash',NULL,NULL),
  ('Issa Rice',250,'2016-07-01','2016-07-31','2016-07-31',NULL,NULL,NULL),
  ('Issa Rice',190,'2016-08-01','2016-08-31','2016-08-31','Pay less than usual 250 because of reduced work while in Japan',NULL,NULL),
  ('Issa Rice',250,'2016-09-01','2016-09-30','2016-09-30',NULL,NULL,NULL),
  ('Issa Rice',250,'2016-10-01','2016-10-31','2016-10-31',NULL,NULL,NULL),
  ('Issa Rice',250,'2016-11-01','2016-11-30','2016-11-30',NULL,NULL,NULL),
  ('Issa Rice',250,'2016-12-01','2016-12-31','2016-12-31',NULL,NULL,NULL),
  ('Issa Rice',250,'2017-01-01','2017-01-31','2017-01-31',NULL,74,176),
  ('Issa Rice',250,'2017-02-01','2017-02-28','2017-02-28',NULL,161,160),
  ('Issa Rice',1500,'2017-03-01','2017-03-31','2017-03-31',NULL,104,184),
  ('Issa Rice',1500,'2017-04-01','2017-04-30','2017-04-30',NULL,157,160),
  ('Issa Rice',1304,'2017-05-01','2017-05-31','2017-05-31','Stipend for month of May. Took last week of May (Monday 2017-05-29 to Wednesday 2017-05-31) off to recover from burnout after work on timeline of electricity adoption',145,160),
  ('Issa Rice',1500,'2017-06-01','2017-06-30','2017-06-30',NULL,159,176),
  ('Issa Rice',1500,'2017-07-01','2017-07-31','2017-07-31',NULL,190,168),
  ('Issa Rice',1500,'2017-08-01','2017-08-31','2017-08-31',NULL,197,184),
  ('Issa Rice',1500,'2017-09-01','2017-09-30','2017-09-30',NULL,173,176),
  ('Issa Rice',1500,'2017-10-01','2017-10-31','2017-10-31',NULL,170,168),
  ('Issa Rice',1500,'2017-11-01','2017-11-30','2017-11-30',NULL,178,176),
  ('Issa Rice',1500,'2017-12-01','2017-12-31','2017-12-31',NULL,176,176),
  ('Issa Rice',1500,'2018-01-01','2018-01-31','2018-01-31',NULL,179,176),
  ('Issa Rice',1500,'2018-02-01','2018-02-28','2018-02-28','Accumulated 1.6 hours of overtime work to be adjusted against a later month',161.6,160),
  ('Issa Rice',1500,'2018-03-01','2018-03-31','2018-03-31',NULL,184,184),
  ('Issa Rice',1500,'2018-04-01','2018-04-30','2018-04-30',NULL,160.78,160),
  ('Issa Rice',540,'2018-05-01','2018-05-31','2018-05-31','Used up 2.38 accumulated overtime hours from previous months. Still below full monthly quota, so scaled pay based on fraction of month worked',63.9,184),
  ('Issa Rice',659,'2018-06-01','2018-06-30','2018-06-30','Below full monthly quota, so scaled full month pay of $1500 based on fraction of month worked',77.28,176),
  ('Issa Rice',791,'2018-07-01','2018-07-31','2018-07-31','Below full monthly quota, so scaled full month pay of $1500 based on fraction of month worked',97.07,184),
  ('Issa Rice',528,'2018-08-01','2018-08-31','2018-08-31','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',59.82,136),
  ('Issa Rice',643.67,'2018-09-01','2018-09-30','2018-09-30','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',72.95,136),
  ('Issa Rice',585,'2018-10-01','2018-10-31','2018-10-31','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',66.30,136),
  ('Issa Rice',419.12,'2018-11-01','2018-11-30','2018-11-30','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',47.50,136),
  ('Issa Rice',231.18,'2018-12-01','2018-12-31','2018-12-31','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',26.20,136),
  ('Issa Rice',194.38,'2019-01-01','2019-01-31','2019-01-31','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',22.03,136),
  ('Issa Rice',112.50,'2019-02-01','2019-02-28','2019-02-28','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',12.75,136),
  ('Issa Rice',159.88,'2019-03-01','2019-03-31','2019-03-31','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',18.12,136),
  ('Issa Rice',267.35,'2019-04-01','2019-04-30','2019-04-30','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',30.3,136),
  ('Issa Rice',275.56,'2019-05-01','2019-05-31','2019-05-31','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',31.23,136),
  ('Issa Rice',265.76,'2019-06-01','2019-06-30','2019-06-30','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',30.12,136),
  ('Issa Rice',120.44,'2019-07-01','2019-07-31','2019-07-31','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',13.65,136),
  ('Issa Rice',93.79,'2019-08-01','2019-08-31','2019-08-31','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',10.63,136),
  ('Issa Rice',32.21,'2019-09-01','2019-09-30','2019-09-30','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',3.65,136),
  ('Issa Rice',88.06,'2019-10-01','2019-10-31','2019-10-31','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',9.98,136),
  ('Issa Rice',94.24,'2019-11-01','2019-11-30','2019-11-30','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',10.68,136),
  ('Issa Rice',88.02,'2019-12-01','2019-12-31','2019-12-31','Rate of $9/hour effective December 2019. This new rate applies to the first 150 hours of work in each month',9.78,150),
  ('Issa Rice',200.97,'2020-01-01','2020-01-31','2020-01-31','Rate of $9/hour effective December 2019',22.33,150);

insert into stipends(payee, payment, stipend_start_date, stipend_end_date, stipend_award_date, notes, hours_logged) values
  ('Sebastian Sanchez',100,'2017-05-01','2017-05-31','2017-05-31',NULL,NULL),
  ('Sebastian Sanchez',250,'2017-06-01','2017-06-30','2017-06-30',NULL,NULL),
  ('Sebastian Sanchez',250,'2017-07-01','2017-07-31','2017-07-31',NULL,NULL),
  ('Sebastian Sanchez',250,'2017-08-01','2017-08-31','2017-08-31',NULL,NULL),
  ('Sebastian Sanchez',250,'2017-09-01','2017-09-30','2017-09-30',NULL,NULL),
  ('Sebastian Sanchez',400,'2017-10-01','2017-10-31','2017-10-31','Moved to full time work, so stipend increase from $250 to $400',NULL),
  ('Sebastian Sanchez',500,'2017-11-01','2017-11-30','2017-11-30','Increased amount of work, so stipend increased correspondingly. Average of 5.5 hours of work per day all days, totaling to 165 hours. This is based on estimation, not actual time tracking',165),
  ('Sebastian Sanchez',500,'2017-12-01','2017-12-31','2017-12-31','The work hours estimate is very rough and not based on time tracking. Using the same average of 5.5 hours per day as we did the previous month',171),
  /* 2018 */
  ('Sebastian Sanchez',150,'2018-01-01','2018-01-31','2018-01-31','The work hours estimate is rough, assuming 5.5 hours per day for 30% of days. Worker was away on vacation from approximately the 10th to the 31st of the month',50),
  ('Sebastian Sanchez',500,'2018-02-01','2018-02-28','2018-02-28','Time estimate includes time spent in general research and writing, not just on Timelines wiki. The writing tasks outside Timelines wiki are not paid for as individual tasks',160),
  ('Sebastian Sanchez',500,'2018-03-01','2018-03-31','2018-03-31','Time estimate includes time spent in general research and writing, not just on Timelines wiki. The writing tasks outside Timelines wiki are not paid for as individual tasks',175),
  ('Sebastian Sanchez',500,'2018-04-01','2018-04-30','2018-04-30','Time estimate includes time spent in general research and writing, not just on Timelines wiki. The writing tasks outside Timelines wiki are not paid for as individual tasks',165),
  ('Sebastian Sanchez',625,'2018-05-01','2018-05-31','2018-05-31','Time estimate includes time spent in general research and writing, not just on Timelines wiki. The writing tasks outside Timelines wiki are not paid for as individual tasks',190),
  ('Sebastian Sanchez',625,'2018-06-01','2018-06-30','2018-06-30','Time estimate includes time spent in general research and writing, not just on Timelines wiki. The writing tasks outside Timelines wiki are not paid for as individual tasks',175),
  ('Sebastian Sanchez',700,'2018-07-01','2018-07-31','2018-07-31','Time estimate includes time spent in general research and writing, not just on Timelines wiki. The writing tasks outside Timelines wiki are not paid for as individual tasks',215),
  ('Sebastian Sanchez',625,'2018-08-01','2018-08-31','2018-08-31','Time estimate includes time spent in general research and writing, not just on Timelines wiki. The writing tasks outside Timelines wiki are not paid for as individual tasks',170),
  ('Sebastian Sanchez',625,'2018-09-01','2018-09-30','2018-09-30','Time estimate includes time spent in general research and writing, not just on Timelines wiki. The writing tasks outside Timelines wiki are not paid for as individual tasks',170),
  ('Sebastian Sanchez',650,'2018-10-01','2018-10-31','2018-10-31','Time estimate includes time spent in general research and writing, not just on Timelines wiki. The writing tasks outside Timelines wiki are not paid for as individual tasks',180),
  ('Sebastian Sanchez',75,'2018-11-01','2018-11-30','2018-11-30','Time estimate includes time spent in general research and writing, not just on Timelines wiki. The writing tasks outside Timelines wiki are not paid for as individual tasks. Total work hours logged in this month were low because of vacation travel to Europe',20),
  ('Sebastian Sanchez',120,'2018-12-01','2018-12-31','2018-12-31','Time estimate includes time spent in general research and writing, not just on Timelines wiki. The writing tasks outside Timelines wiki are not paid for as individual tasks. Total work hours logged in this month were low because of sickness',30),
  /* 2019 */
  ('Sebastian Sanchez',450,'2019-01-01','2019-01-31','2019-01-31','Time estimate includes time spent in general research and writing, not just on Timelines wiki. The writing tasks outside Timelines wiki are not paid for as individual tasks. Total work hours logged in this month were low due to time spent resting and recovering from sickness',100),
  ('Sebastian Sanchez',650,'2019-02-01','2019-02-28','2019-02-28','There was no time spent outside Timelines wiki in this month, so all time is on Timelines wiki',160),
  ('Sebastian Sanchez',550,'2019-03-01','2019-03-31','2019-03-31','Time estimate includes time spent in general research and writing, not just on Timelines wiki. The writing tasks outside Timelines wiki are not paid for as individual tasks',125),
  ('Sebastian Sanchez',660,'2019-04-01','2019-04-30','2019-04-30','There was no time spent outside Timelines wiki in this month, so all time is on Timelines wiki',165),
  ('Sebastian Sanchez',680,'2019-05-01','2019-05-31','2019-05-31','There was no significant time spent outside Timelines wiki in this month, so we will treat all time as having been on Timelines wiki',170),
  ('Sebastian Sanchez',770,'2019-06-01','2019-06-30','2019-06-30','Of the 185 hours spent this month, 5 were spent outside Timelines wiki, and the remaining 180 were sent on Timelines wiki',185),
  ('Sebastian Sanchez',780,'2019-07-01','2019-07-31','2019-07-31','There was no time spent outside Timelines wiki in this month, so all time is on Timelines wiki',195),
  ('Sebastian Sanchez',580,'2019-08-01','2019-08-31','2019-08-31','There was no time spent outside Timelines wiki in this month, so all time is on Timelines wiki. Number of hours this month is lower than the typical monthly amount, due to a vacation of about one week',145),
  ('Sebastian Sanchez',740,'2019-09-01','2019-09-30','2019-09-30','There was no time spent outside Timelines wiki in this month, so all time is on Timelines wiki',185),
  ('Sebastian Sanchez',700,'2019-10-01','2019-10-31','2019-10-31','There was no time spent outside Timelines wiki in this month, so all time is on Timelines wiki',175),
  ('Sebastian Sanchez',780,'2019-11-01','2019-11-30','2019-11-30','This includes some time spent outside Timelines wiki',185),
  ('Sebastian Sanchez',700,'2019-12-01','2019-12-01','2019-12-31','The listed amount of time (165 hours) is only on Timelines wiki. However, some time was spent on preparing for projects in 2020 as well, which is not counted in the 165 hours, but is reflected in an extra 40 USD added to the stipend',165),
  /* 2020 */
  ('Sebastian Sanchez',720,'2020-01-01','2020-01-31','2020-01-31','The time and payment are only for time spent on Timelines wiki',180),
  ('Sebastian Sanchez',712,'2020-02-01','2020-02-29','2020-02-29','The payment is at $4/hour for a total of 178 hours: 170 spent on Timelines wiki and 8 spent on initial exploration of the Machinelearning subwiki',178);

insert into stipends(payee, payment, stipend_start_date, stipend_end_date, stipend_award_date, notes) values
  ('Alex K. Chen',0.02,'2015-04-01','2015-12-31','2015-12-31','Fudge factor correction');

insert into stipends(payee, payment, stipend_start_date, stipend_end_date, stipend_award_date, notes) values
  ('Issa Rice',100,'2016-01-01','2016-12-31','2016-12-31','Stipend for managing AKC');
