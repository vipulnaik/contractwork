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
  ('Issa Rice',419.12,'2018-11-01','2018-11-30','2018-11-30','Below full monthly quota, so scaled full month pay of $1200 (for 17 days = 136 hours) based on fraction of month worked',47.50,136);
  
insert into stipends(payee, payment, stipend_start_date, stipend_end_date, stipend_award_date, notes, hours_logged) values
  ('Sebastian Sanchez',100,'2017-05-01','2017-05-31','2017-05-31',NULL,NULL),
  ('Sebastian Sanchez',250,'2017-06-01','2017-06-30','2017-06-30',NULL,NULL),
  ('Sebastian Sanchez',250,'2017-07-01','2017-07-31','2017-07-31',NULL,NULL),
  ('Sebastian Sanchez',250,'2017-08-01','2017-08-31','2017-08-31',NULL,NULL),
  ('Sebastian Sanchez',250,'2017-09-01','2017-09-30','2017-09-30',NULL,NULL),
  ('Sebastian Sanchez',400,'2017-10-01','2017-10-31','2017-10-31','Moved to full time work, so stipend increase from $250 to $400',NULL),
  ('Sebastian Sanchez',500,'2017-11-01','2017-11-30','2017-11-30','Increased amount of work, so stipend increased correspondingly. Average of 5.5 hours of work per day all days, totaling to 165 hours. This is based on estimation, not actual time tracking',165),
  ('Sebastian Sanchez',500,'2017-12-01','2017-12-31','2017-12-31','The work hours estimate is very rough and not based on time tracking. Using the same average of 5.5 hours per day as we did the previous month',171),
  ('Sebastian Sanchez',150,'2018-01-01','2018-01-31','2018-01-31','The work hours estimate is rough, assuming 5.5 hours per day for 30% of days. Worker was away on vacation from approximately the 10th to the 31st of the month',50),
  ('Sebastian Sanchez',500,'2018-02-01','2018-02-28','2018-02-28','Time estimate includes time spent in general research and writing, not just on Timelines Wiki. The writing tasks outside Timelines Wiki are not paid for as individual tasks',160),
  ('Sebastian Sanchez',500,'2018-03-01','2018-03-31','2018-03-31','Time estimate includes time spent in general research and writing, not just on Timelines Wiki. The writing tasks outside Timelines Wiki are not paid for as individual tasks',175),
  ('Sebastian Sanchez',500,'2018-04-01','2018-04-30','2018-04-30','Time estimate includes time spent in general research and writing, not just on Timelines Wiki. The writing tasks outside Timelines Wiki are not paid for as individual tasks',165),
  ('Sebastian Sanchez',625,'2018-05-01','2018-05-31','2018-05-31','Time estimate includes time spent in general research and writing, not just on Timelines Wiki. The writing tasks outside Timelines Wiki are not paid for as individual tasks',190),
  ('Sebastian Sanchez',625,'2018-06-01','2018-06-30','2018-06-30','Time estimate includes time spent in general research and writing, not just on Timelines Wiki. The writing tasks outside Timelines Wiki are not paid for as individual tasks',175),
  ('Sebastian Sanchez',700,'2018-07-01','2018-07-31','2018-07-31','Time estimate includes time spent in general research and writing, not just on Timelines Wiki. The writing tasks outside Timelines Wiki are not paid for as individual tasks',215),
  ('Sebastian Sanchez',625,'2018-08-01','2018-08-31','2018-08-31','Time estimate includes time spent in general research and writing, not just on Timelines Wiki. The writing tasks outside Timelines Wiki are not paid for as individual tasks',170),
  ('Sebastian Sanchez',625,'2018-09-01','2018-09-30','2018-09-30','Time estimate includes time spent in general research and writing, not just on Timelines Wiki. The writing tasks outside Timelines Wiki are not paid for as individual tasks',170),
  ('Sebastian Sanchez',650,'2018-10-01','2018-10-31','2018-10-31','Time estimate includes time spent in general research and writing, not just on Timelines Wiki. The writing tasks outside Timelines Wiki are not paid for as individual tasks',180),
  ('Sebastian Sanchez',75,'2018-11-01','2018-11-30','2018-11-30','Time estimate includes time spent in general research and writing, not just on Timelines Wiki. The writing tasks outside Timelines Wiki are not paid for as individual tasks',20);

insert into stipends(payee, payment, stipend_start_date, stipend_end_date, stipend_award_date, notes) values
  ('Alex K. Chen',0.02,'2015-04-01','2015-12-31','2015-12-31','Fudge factor correction');

insert into stipends(payee, payment, stipend_start_date, stipend_end_date, stipend_award_date, notes) values
  ('Issa Rice',100,'2016-01-01','2016-12-31','2016-12-31','Stipend for managing AKC');
