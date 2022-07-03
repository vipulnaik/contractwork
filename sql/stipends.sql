create table stipends(
  stipend_id int(11) not null auto_increment primary key,
  payee varchar(40),
  payment float(7,2) not null,
  stipend_start_date date not null,
  stipend_end_date date not null,
  stipend_award_date date,
  notes varchar(2000),
  hours_logged float(13,2) default null,
  total_work_hours int(11) default null,
  payer varchar(40) default 'Vipul Naik',
  constraint stipend_payee_is_worker foreign key (payee) references workers (worker),
  constraint stipend_payer_is_payer foreign key (payer) references payers (payer)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

insert into stipends(payee, payment, stipend_start_date, stipend_end_date, stipend_award_date, notes, hours_logged, total_work_hours) values
  ('Issa Rice',700,'2016-02-01','2016-02-28','2016-12-28','Paid after long deferral as end-of-year award. Constitutes 100% of stipend for that month',NULL,NULL),
  ('Issa Rice',900,'2016-03-01','2016-03-31','2016-12-28','Paid after long deferral as end-of-year award. Constitutes 100% of stipend for that month',NULL,NULL),
  ('Issa Rice',900,'2016-04-01','2016-04-30','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes 100% of stipend for that month',NULL,NULL),
  ('Issa Rice',1000,'2016-05-01','2016-05-31','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $300 was awarded at end of original month',NULL,NULL),
  ('Issa Rice',1250,'2016-06-01','2016-06-30','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $250 was awarded at end of original month',NULL,NULL),
  ('Issa Rice',1250,'2016-07-01','2016-07-31','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $250 was awarded at end of original month',NULL,NULL),
  ('Issa Rice',960,'2016-08-01','2016-08-31','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone; pay less than usual 1250 because of reduced work while in Japan. Constitutes deferred part of stipend for that month; remaining $190 was awarded at end of original month',NULL,NULL),
  ('Issa Rice',1250,'2016-09-01','2016-09-30','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $250 was awarded at end of original month',NULL,NULL),
  ('Issa Rice',1250,'2016-10-01','2016-10-31','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $250 was awarded at end of original month',NULL,NULL),
  ('Issa Rice',750,'2016-11-01','2016-11-30','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $250 was awarded at end of original month. The amount was reduced from the standard $1250 because part of the time was spent on https://issarice.com/digital-preservation (a personal project)',NULL,NULL),
  ('Issa Rice',750,'2016-12-01','2016-12-31','2017-03-24','Awarded after delay, due to achievement of LiftIgniter milestone. Constitutes deferred part of stipend for that month; remaining $250 was awarded at end of original month. The amount was reduced from the standard $1250 because part of the time was spent on researcher profiles (a personal project)',NULL,NULL),
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
  ('Issa Rice',200.97,'2020-01-01','2020-01-31','2020-01-31','Rate of $9/hour effective December 2019',22.33,150),
  ('Issa Rice',6.30,'2020-02-01','2020-02-29','2020-02-29','Rate of $9/hour effective December 2019',0.70,150),
  ('Issa Rice',65.07,'2020-03-01','2020-03-31','2020-03-31','Rate of $9/hour effective December 2019',7.23,150),
  ('Issa Rice',161.28,'2020-04-01','2020-04-30','2020-04-30','Rate of $9/hour effective December 2019',17.92,150),
  ('Issa Rice',154.17,'2020-05-01','2020-05-31','2020-05-31','Rate of $9/hour effective December 2019',17.13,150),
  ('Issa Rice',98.37,'2020-06-01','2020-06-30','2020-06-30','Rate of $9/hour effective December 2019',10.93,150),
  ('Issa Rice',162.18,'2020-07-01','2020-07-31','2020-07-31','Rate of $9/hour effective December 2019',18.02,150),
  ('Issa Rice',49.68,'2020-08-01','2020-08-31','2020-08-31','Rate of $9/hour effective December 2019',5.52,150),
  ('Issa Rice',47.07,'2020-09-01','2020-09-30','2020-09-30','Rate of $9/hour effective December 2019',5.23,150),
  ('Issa Rice',56.25,'2020-10-01','2020-10-31','2020-10-31','Rate of $9/hour effective December 2019',6.25,150),
  ('Issa Rice',55.35,'2020-11-01','2020-11-30','2020-11-30','Rate of $9/hour effective December 2019',6.15,150),
  ('Issa Rice',176.58,'2020-12-01','2020-12-31','2020-12-31','Rate of $9/hour effective December 2019',19.62,150),
  ('Issa Rice',52.92,'2021-01-01','2021-01-31','2021-01-31','Rate of $9/hour effective December 2019',5.88,150),
  ('Issa Rice',38.88,'2021-02-01','2021-02-28','2021-02-28','Rate of $9/hour effective December 2019',4.32,150),
  ('Issa Rice',31.32,'2021-03-01','2021-03-31','2021-03-31','Rate of $9/hour effective December 2019',3.48,150),
  ('Issa Rice',21.60,'2021-04-01','2021-04-30','2021-04-30','Rate of $9/hour effective December 2019',2.4,150),
  ('Issa Rice',29.07,'2021-05-01','2021-05-31','2021-05-31','Rate of $9/hour effective December 2019',3.23,150),
  ('Issa Rice',35.55,'2021-06-01','2021-06-30','2021-06-30','Rate of $9/hour effective December 2019',3.95,150),
  ('Issa Rice',16.20,'2021-07-01','2021-07-31','2021-07-31','Rate of $9/hour effective December 2019',1.8,150),
  ('Issa Rice',28.35,'2021-08-01','2021-08-31','2021-08-31','Rate of $9/hour effective December 2019',3.15,150),
  ('Issa Rice',53.55,'2021-09-01','2021-09-30','2021-09-30','Rate of $9/hour effective December 2019',5.95,150),
  ('Issa Rice',43.92,'2021-10-01','2021-10-31','2021-10-31','Rate of $9/hour effective December 2019',4.88,150),
  ('Issa Rice',33.48,'2021-11-01','2021-11-30','2021-11-30','Rate of $9/hour effective December 2019',3.72,150),
  ('Issa Rice',63.90,'2021-12-01','2021-12-31','2021-12-31','Rate of $9/hour effective December 2019',7.10,150),
  ('Issa Rice',22.95,'2022-01-01','2022-01-31','2022-01-31','Rate of $9/hour effective December 2019',2.55,150),
  ('Issa Rice',4.77,'2022-02-01','2022-02-28','2022-02-28','Rate of $9/hour effective December 2019',0.53,150),
  ('Issa Rice',38.25,'2022-03-01','2022-03-31','2022-03-31','Rate of $9/hour effective December 2019',4.25,150),
  ('Issa Rice',43.20,'2022-04-01','2022-04-30','2022-04-30','Rate of $9/hour effective December 2019',4.80,150),
  ('Issa Rice',47.07,'2022-05-01','2022-05-31','2022-05-31','Rate of $9/hour effective December 2019',5.23,150),
  ('Issa Rice',73.80,'2022-06-01','2022-06-30','2022-06-30','Rate of $9/hour effective December 2019',8.20,150);

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
  ('Sebastian Sanchez',720,'2020-01-01','2020-01-31','2020-01-31','The time and payment are only for time spent on Timelines wiki.',180),
  ('Sebastian Sanchez',712,'2020-02-01','2020-02-29','2020-02-29','The payment is at $4/hour for a total of 178 hours: 170 spent on Timelines wiki and 8 spent on initial exploration of the Machinelearning subwiki.',178),
  ('Sebastian Sanchez',830,'2020-03-01','2020-03-31','2020-03-31','The payment is at $4/hour for the first 200 hours and $30 for the additional 12 hours; 195 hours spent on Timelines wiki, 16 hours spent on Machinelearning subwiki, and 1 hour spent on wikiHow work.',212),
  ('Sebastian Sanchez',806,'2020-04-01','2020-04-30','2020-04-30','The payment is at $4/hour for all hours, plus an additional $6/hour for 9 hours for which the output is not directly compensated for. Breakdown of time: 177 hours on Timelines wiki, 1 hour on Machinelearning subwiki, 1 hour on wikiHow work, and 9 hours on other projects.',188),
  ('Sebastian Sanchez',808,'2020-05-01','2020-05-31','2020-05-31','The payment is at $4/hour for all hours, plus an additional $5/hour for 20 hours for which the output is not directly compensated for. Worked 177 hours, including 157 on Timelines wiki.',177),
  ('Sebastian Sanchez',735,'2020-06-01','2020-06-30','2020-06-30','The payment is at $4/hour for all hours, plus an additional $5/hour for 15 hours for which the output is not directly compensated for. Worked 165 hours, including 150 on Timelines wiki.',165),
  ('Sebastian Sanchez',740,'2020-07-01','2020-07-31','2020-07-31','The payment is at $4/hour for all hours, plus an additional $5/hour for 12 hours for which output is noot directly compensated for. Worked 170 hours, including 130 on Timelines wiki and 28 on Org Watch.',170),
  ('Sebastian Sanchez',612,'2020-08-01','2020-08-31','2020-08-31','The payment is at $4/hour for all 153 hours eligible for stipend. Total time spent was as follows: 139 hours on Timelines wiki, 24 hours on Org Watch, and 9 hours on other activities. For Timelines wiki, the number of hours was in excess of the cap of 120 hours, so only the first 120 hours were eligible for stipend.',172),
  ('Sebastian Sanchez',700,'2020-09-01','2020-09-30','2020-09-30','The payment is at $4/hour for all 160 hours eligible for stipend, plus 15 of 19 excess hours accumulated from last month. Total time spent was follows: 105 hours on Timelines wiki, 17 hours on Timelines wiki promotion, 38 hours on Org Watch, and 15 hours overage on Timelines wiki applied from the previous month. The reason only 15 hours rather than the full 19 hours of the past overage were applied is that with 15 hours, we already hit the cap of 120 hours on Timelines wiki for September.',160),
  ('Sebastian Sanchez',688,'2020-10-01','2020-10-31','2020-10-31','The payment is at $4/hour for all 172 hours eligible for stipend. Total time spent was as follows: 126 hours on Timelines wiki, 8 hours on Timelines wiki promotion, and 44 hours on Org Watch. For Timelines wiki, the number of hours was in excess of the cap of 120 hours, so only the first 120 hours were eligible for stipend. As of now, we have a total overage of 10 hours on Timelines wiki (4 hours carried over, and 6 more hours this month).',178),
  ('Sebastian Sanchez',564,'2020-11-01','2020-11-30','2020-11-30','The payment is at $4/hour for all 131 hours eligible for stipend, plus all 10 excess hours accumulated from earlier. Total time spent was as follows: 98.5 hours on Timelines wiki, 1.5 hours on Timelines wiki SEO research, and 31 hours on Org Watch.',131),
  ('Sebastian Sanchez',656,'2020-12-01','2020-12-31','2020-12-31','The payment is at $4/hour for all 164 hours eligible for stipend. Total time spent was as follows: 83 hours on Timelines Wiki and 81 hours on Org Watch.',164),
  /* 2021 */
  ('Sebastian Sanchez',560,'2021-01-01','2021-01-31','2021-01-31','The payment is at $4/hour for all 140 hours eligible for stipend. Total time spent was as follows: 115 hours on Timelines Wiki and 25 hours on Org Watch.',140),
  ('Sebastian Sanchez',726,'2021-02-01','2021-02-28','2021-02-28','The payment is at $4/hour for all 181.5 hours eligible for stipend. Total time spent was as follows: 150 hours on Timelines Wiki and 31.5 hours on Org Watch.',181.5),
  ('Sebastian Sanchez',808,'2021-03-01','2021-03-31','2021-03-31','The payment is at $4/hour for all 202 hours eligible for stipend. Total time spent was as follows: 169 hours on Timelines Wiki and 33 hours on Org Watch.',202),
  ('Sebastian Sanchez',760,'2021-04-01','2021-04-30','2021-04-30','The payment is at $4/hour for all 190 hours eligible for stipend. Total time spent was as follows: 155 hours on Timelines Wiki and 35 hours on Org Watch.',190),
  ('Sebastian Sanchez',680,'2021-05-01','2021-05-31','2021-05-31','The payment is at $4/hour for all 170 hours eligible for stipend. Total time spent was as follows: all 170 hours on Timelines Wiki.',170),
  ('Sebastian Sanchez',608,'2021-06-01','2021-06-30','2021-06-30','The payment is at $4/hour for all 152 hours eligible for stipend. Total time spent was as follows: 130 hours on Timelines Wiki and 22 hours on Org Watch.',152),
  ('Sebastian Sanchez',740,'2021-07-01','2021-07-31','2021-07-31','The payment is at $4/hour for all 185 hours eligible for stipend. Total time spent was as follows: 155 hours on Timelines Wiki and 30 hours on Org Watch.',185),
  ('Sebastian Sanchez',608,'2021-08-01','2021-08-31','2021-08-31','The payment is at $4/hour for all 152 hours eligible for stipend. Total time spent was as follows: 142 hours on Timelines Wiki and and 10 hours on Org Watch.',152),
  ('Sebastian Sanchez',648,'2021-09-01','2021-09-30','2021-09-30','The payment is at $4/hour for 162 hours eligible for stipend out of a total of 167 hours worked. Total time spent was as follows: 155 hours on Timelines Wiki (of which stipend-eligible hours were capped at 150) and and 12 hours on Org Watch.',167),
  ('Sebastian Sanchez',680,'2021-10-01','2021-10-31','2021-10-31','The payment is at $4/hour for 170 hours eligible for stipend out of a total of 178 hours worked. Total time spent was as follows: 158 hours on Timelines Wiki (of which stipend-eligible hours were capped at 150) and 20 hours on Org Watch.',178),
  ('Sebastian Sanchez',672,'2021-11-01','2021-11-30','2021-11-30','The payment is at $4/hour for 168 hours eligible for stipend out of a total of 178 hours worked. Total time spent was as follows: 160 hours on Timelines Wiki (of which stipend-eligible hours were capped at 150) and 18 hours on Org Watch.',178),
  ('Sebastian Sanchez',692,'2021-12-01','2021-12-31','2021-12-31','The payment is at $4/hour for 173 hours eligible for stipend out of a total of 181 hours worked. Total time spent was as follows: 158 hours on Timelines Wiki (of which stipend-eligible hours were capped at 150) and 23 hours on Org Watch.',181),
  /* 2022 */
  ('Sebastian Sanchez',708,'2022-01-01','2022-01-31','2022-01-31','The payment is at $4/hour for all 177 hours worked. Total time spent was as follows: 150 hours on Timelines Wiki and 27 hours on Org Watch.',177),
  ('Sebastian Sanchez',636,'2022-02-01','2022-02-28','2022-02-28','The payment is at $4/hour for 159 hours eligible for stipend. Total time spent was as follows: 165 hours on Timelines Wiki (including 5 hours exempt on timeline of GiveDirectly that are exempt from monthly cap, and 150 hours per the monthly cap), and 4 hours on Org Watch.',169),
  ('Sebastian Sanchez',700,'2022-03-01','2022-03-31','2022-03-31','The payment is at $4/hour for 175 hours eligible for stipend. Total time spent was as follows: 161 hours on Timelines Wiki (of which 150 are eligible per the monthly cap) and 25 hours on Org Watch.',186),
  ('Sebastian Sanchez',696,'2022-04-01','2022-04-30','2022-04-30','The payment is at $4/hour for 174 hours eligible for stipend. Total time spent was as follows: 159 hours on Timelines Wiki (of which 150 are eligible per the monthly cap) and 24 hours on Org Watch.',183),
  ('Sebastian Sanchez',700,'2022-05-01','2022-05-31','2022-05-31','The payment is at $4/hour for 175 hours eligible for stipend. Total time spent was as follows: 155 hours on Timelines Wiki (of which 150 are eligible per the monthly cap) and 25 hours on Org Watch.',180),
  ('Sebastian Sanchez',696,'2022-06-01','2022-06-30','2022-06-30','The payment is at $4/hour for 174 hours eligible for stipend, compared to 146 hours worked. Total time spent was as follows: 122 hours on Timelines Wiki and 24 hours on Org Watch. Since the time on Timelines Wiki was less than the cap of 150 hours by 28 hours, 28 of the past accumulated excess of 66 hours were applied.',146);

insert into stipends(payee, payment, stipend_start_date, stipend_end_date, stipend_award_date, notes, hours_logged, payer) values
  ('Sebastian Sanchez',120,'2022-06-01','2022-06-30','2022-06-30','The payment is at $4/hour for all 30 hours worked on Timelines Wiki.',30,'Future Fund Regranting Program');

insert into stipends(payee, payment, stipend_start_date, stipend_end_date, stipend_award_date, notes, hours_logged) values
  ('Amana Rice',120.32,'2020-12-01','2020-12-31','2020-12-31','30.08 hours at $4/hour',30.08);

insert into stipends(payee, payment, stipend_start_date, stipend_end_date, stipend_award_date, notes) values
  ('Alex K. Chen',0.02,'2015-04-01','2015-12-31','2015-12-31','Fudge factor correction');

insert into stipends(payee, payment, stipend_start_date, stipend_end_date, stipend_award_date, notes) values
  ('Issa Rice',100,'2016-01-01','2016-12-31','2016-12-31','Stipend for managing AKC');
