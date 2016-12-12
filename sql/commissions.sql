create table commissions(
  commission_id int(11) not null auto_increment primary key,
  earner varchar(40) not null,
  commission_receiver varchar(40) not null,
  commission float(2,2) not null,
  commission_reason enum('Recruiter','Guide') not null,
  commission_validity_start date,
  commission_validity_end date,
  notes varchar(2000)
) ENGINE=InnoDB AUTO_INCREMENT=15239276 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

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
  ('Alex K. Chen','Issa Rice',0.03,'2016-01-01','2016-12-31','Guide'),
  ('Alex K. Chen','Issa Rice',0.10,'2015-04-01','2015-12-31','Guide'),
 
  ('Amy Zhang','Ethan Bashkansky',0.15,'2016-06-26',NULL,'Recruiter'),
  ('Avi Glozman','Ethan Bashkansky',0.10,'2016-06-05',NULL,'Guide'),
  ('Christopher Kunin','Ethan Bashkansky',0.10,'2016-06-16',NULL,'Guide'),
  ('Devansh Dwivedy','Ethan Bashkansky',0.10,'2016-06-29',NULL,'Guide'),
  ('Eddy Su','Ethan Bashkansky',0.10,'2016-06-12',NULL,'Guide'),
  ('Michael Royzen','Ethan Bashkansky',0.10,'2016-06-21',NULL,'Guide'),
  ('Sean Yu','Ethan Bashkansky',0.10,'2016-06-24',NULL,'Guide'),

  ('Charlie Corner','Linchuan Zhang',0.15,'2016-07-10',NULL,'Guide'),

  ('Thomas Foster','Alex K. Chen',0.10,'2016-06-16',NULL,'Guide');


