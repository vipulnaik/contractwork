create table commissions(
  commission_id int(11) not null auto_increment primary key,
  earner varchar(40) not null,
  commission_receiver varchar(40) not null,
  commission float(2,2) not null,
  commission_reason enum('Recruiter','Guide') not null,
  commission_validity_start date,
  commission_validity_end date,
  notes varchar(2000)
  constraint earner_is_worker foreign key (earner) references workers (worker),
  constraint commission_receiver_is_worker foreign key (commission_receiver) references workers (worker)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

insert into commissions(earner,commission_receiver,commission,commission_validity_start,commission_validity_end,commission_reason) values 
  ('Adrian Ulloa','Issa Rice',0.10,'2016-08-16',NULL,'Guide'),
  ('Amy Zhang','Issa Rice',0.15,'2016-06-26',NULL,'Guide'),
  ('Avi Glozman','Issa Rice',0.10,'2016-06-05',NULL,'Guide'),
  ('Charlie Corner','Issa Rice',0.15,'2016-07-10',NULL,'Guide'),
  ('Christopher Kunin','Issa Rice',0.10,'2016-06-16',NULL,'Guide'),
  ('Devansh Dwivedy','Issa Rice',0.10,'2016-06-29',NULL,'Guide'),
  ('Eddy Su','Issa Rice',0.10,'2016-06-12',NULL,'Guide'),
  ('Michael Royzen','Issa Rice',0.10,'2016-06-21',NULL,'Guide'),
  ('Sean Yu','Issa Rice',0.10,'2016-06-24',NULL,'Guide'),
  ('Sergey Yegorov','Issa Rice',0.10,'2016-09-20',NULL,'Guide'),
  ('Thomas Foster','Issa Rice',0.10,'2016-06-16',NULL,'Guide'),
  ('Joey Malandra','Issa Rice',0.10,'2016-12-13',NULL,'Guide'),
  ('Alex K. Chen','Issa Rice',0.03,'2016-01-01','2016-12-31','Guide'),
  ('Alex K. Chen','Issa Rice',0.10,'2015-04-01','2015-12-31','Guide'),
  ('Orpheus Lummis','Issa Rice',0.15,'2018-09-30','2020-12-31','Guide'),
  ('Mati Roy','Issa Rice',0.15,'2019-02-17','2019-02-17','Guide'),
  ('Amana Rice','Issa Rice',0.15,'2020-12-01','2020-12-31','Guide'),

  ('Amy Zhang','Ethan Bashkansky',0.15,'2016-06-26',NULL,'Recruiter'),
  ('Avi Glozman','Ethan Bashkansky',0.10,'2016-06-05',NULL,'Recruiter'),
  ('Christopher Kunin','Ethan Bashkansky',0.10,'2016-06-16',NULL,'Recruiter'),
  ('Devansh Dwivedy','Ethan Bashkansky',0.10,'2016-06-29',NULL,'Recruiter'),
  ('Eddy Su','Ethan Bashkansky',0.10,'2016-06-12',NULL,'Recruiter'),
  ('Michael Royzen','Ethan Bashkansky',0.10,'2016-06-21',NULL,'Recruiter'),
  ('Sean Yu','Ethan Bashkansky',0.10,'2016-06-24',NULL,'Recruiter'),
  ('Joey Malandra','Ethan Bashkansky',0.10,'2016-12-13',NULL,'Recruiter'),

  ('Charlie Corner','Linchuan Zhang',0.15,'2016-07-10',NULL,'Recruiter'),

  ('Thomas Foster','Alex K. Chen',0.10,'2016-06-16',NULL,'Recruiter');


