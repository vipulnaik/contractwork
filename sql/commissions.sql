create table commissions(
  commission_id int(11) not null auto_increment primary key,
  earner varchar(40) not null,
  commission_receiver varchar(40) not null,
  commission decimal(2,2) not null,
  commission_reason enum('Recruiter','Guide') not null,
  commission_validity_start date,
  commission_validity_end date,
  notes varchar(2000),
  constraint earner_is_worker foreign key (earner) references workers (worker),
  constraint commission_receiver_is_worker foreign key (commission_receiver) references workers (worker)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

insert into commissions(earner,commission_receiver,commission,commission_validity_start,commission_validity_end,commission_reason) values 
  ('Adrian Ulloa','Issa Rice',0.10,'2016-08-16',null,'Guide'),
  ('Amy Zhang','Issa Rice',0.15,'2016-06-26',null,'Guide'),
  ('Avi Glozman','Issa Rice',0.10,'2016-06-05',null,'Guide'),
  ('Charlie Corner','Issa Rice',0.15,'2016-07-10',null,'Guide'),
  ('Christopher Kunin','Issa Rice',0.10,'2016-06-16',null,'Guide'),
  ('Devansh Dwivedy','Issa Rice',0.10,'2016-06-29',null,'Guide'),
  ('Eddy Su','Issa Rice',0.10,'2016-06-12',null,'Guide'),
  ('Michael Royzen','Issa Rice',0.10,'2016-06-21',null,'Guide'),
  ('Sean Yu','Issa Rice',0.10,'2016-06-24',null,'Guide'),
  ('Sergey Yegorov','Issa Rice',0.10,'2016-09-20',null,'Guide'),
  ('Thomas Foster','Issa Rice',0.10,'2016-06-16',null,'Guide'),
  ('Joey Malandra','Issa Rice',0.10,'2016-12-13',null,'Guide'),
  ('Alex K. Chen','Issa Rice',0.03,'2016-01-01','2016-12-31','Guide'),
  ('Alex K. Chen','Issa Rice',0.10,'2015-04-01','2015-12-31','Guide'),
  ('Orpheus Lummis','Issa Rice',0.15,'2018-09-30','2020-12-31','Guide'),
  ('Mati Roy','Issa Rice',0.15,'2019-02-17','2019-02-17','Guide'),
  ('Amana Rice','Issa Rice',0.15,'2020-12-01','2020-12-31','Guide'),

  ('Amy Zhang','Ethan Bashkansky',0.15,'2016-06-26',null,'Recruiter'),
  ('Avi Glozman','Ethan Bashkansky',0.10,'2016-06-05',null,'Recruiter'),
  ('Christopher Kunin','Ethan Bashkansky',0.10,'2016-06-16',null,'Recruiter'),
  ('Devansh Dwivedy','Ethan Bashkansky',0.10,'2016-06-29',null,'Recruiter'),
  ('Eddy Su','Ethan Bashkansky',0.10,'2016-06-12',null,'Recruiter'),
  ('Michael Royzen','Ethan Bashkansky',0.10,'2016-06-21',null,'Recruiter'),
  ('Sean Yu','Ethan Bashkansky',0.10,'2016-06-24',null,'Recruiter'),
  ('Joey Malandra','Ethan Bashkansky',0.10,'2016-12-13',null,'Recruiter'),

  ('Charlie Corner','Linchuan Zhang',0.15,'2016-07-10',null,'Recruiter'),

  ('Thomas Foster','Alex K. Chen',0.10,'2016-06-16',null,'Recruiter');


