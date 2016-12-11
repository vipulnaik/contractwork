create table royalties(
  royalty_id int(11) not null auto_increment primary key,
  payee varchar(40),
  payment float(7,2) not null,
  royalty_basis enum('Wikipedia pageviews','Quora views') not null,
  royalty_scope varchar(40) not null,
  royalty_rate float(5,3),
  royalty_start_date date NOT NULL,
  royalty_end_date date NOT NULL,
  notes varchar(2000)
) ENGINE=InnoDB AUTO_INCREMENT=15239276 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

insert into royalties(payee, payment, royalty_basis, royalty_scope, royalty_rate, royalty_start_date, royalty_end_date, notes) values
  ('Alex K. Chen',4096,'Quora views','All Quora questions and answers to date',null,'2015-04-01','2015-12-31','Separate rates for questions and answers. See https://exp.issarice.com/akc_views.txt for data and http://exp.issarice.com/calc.py for processing code'),
  ('Alex K. Chen',38.54,'Wikipedia pageviews','Pages created before 2015',0.001,'2015-04-01','2015-04-30',NULL),
  ('Alex K. Chen',3.09,'Wikipedia pageviews','Pages created in 2015',0.002,'2015-04-01','2015-04-30',NULL),
  ('Alex K. Chen',47.77,'Wikipedia pageviews','Pages created before 2015',0.001,'2015-05-01','2015-05-31',NULL),
  ('Alex K. Chen',249.60,'Wikipedia pageviews','Pages created in 2015',0.002,'2015-05-01','2015-05-31',NULL),
  ('Alex K. Chen',30.62,'Wikipedia pageviews','Pages created before 2015',0.001,'2015-06-01','2015-06-30',NULL),
  ('Alex K. Chen',226.29,'Wikipedia pageviews','Pages created in 2015',0.002,'2015-06-01','2015-06-30',NULL),
  ('Alex K. Chen',31.59,'Wikipedia pageviews','Pages created before 2015',0.001,'2015-07-01','2015-07-31',NULL),
  ('Alex K. Chen',142.15,'Wikipedia pageviews','Pages created in 2015',0.002,'2015-07-01','2015-07-31',NULL),
  ('Alex K. Chen',27.29,'Wikipedia pageviews','Pages created before 2015',0.001,'2015-08-01','2015-08-31',NULL),
  ('Alex K. Chen',121.91,'Wikipedia pageviews','Pages created in 2015',0.002,'2015-08-01','2015-08-31',NULL),
  ('Alex K. Chen',29.83,'Wikipedia pageviews','Pages created before 2015',0.001,'2015-09-01','2015-09-30',NULL),
  ('Alex K. Chen',126.18,'Wikipedia pageviews','Pages created in 2015',0.002,'2015-09-01','2015-09-30',NULL),
  ('Alex K. Chen',35.47,'Wikipedia pageviews','Pages created before 2015',0.001,'2015-10-01','2015-10-31',NULL),
  ('Alex K. Chen',122.52,'Wikipedia pageviews','Pages created in 2015',0.002,'2015-10-01','2015-10-31',NULL),
  ('Alex K. Chen',31.39,'Wikipedia pageviews','Pages created before 2015',0.001,'2015-11-01','2015-11-30',NULL),
  ('Alex K. Chen',114.00,'Wikipedia pageviews','Pages created in 2015',0.002,'2015-11-01','2015-11-30',NULL),
  ('Alex K. Chen',32.32,'Wikipedia pageviews','Pages created before 2015',0.001,'2015-12-01','2015-12-31',NULL),
  ('Alex K. Chen',129.82,'Wikipedia pageviews','Pages created in 2015',0.002,'2015-12-01','2015-12-31',NULL);
