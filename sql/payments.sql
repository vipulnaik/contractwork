create table payments(
  payment_id int(11) not null auto_increment primary key,
  payment_method enum('Cash','Check','PayPal','Wire transfer','Western Union','Debit card via Facebook') not null,
  payee varchar(40) not null,
  intermediary varchar(40) default null,
  sent_date date NOT NULL,
  payment_notice_receipt_date date NOT NULL,
  cashout_request_date date,
  receipt_date date,
  payment float(7,2) not null,
  sent_payment float(7,2) not null,
  overhead float(7,2) not null,
  received_payment float(7,2) not null
) ENGINE=InnoDB AUTO_INCREMENT=15239276 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

insert into payments(payment_method, payee, intermediary, sent_date, payment_notice_receipt_date, cashout_request_date, receipt_date, payment, sent_payment, overhead, received_payment) values
  # -- Sebastian Sanchez payments
  ('Western Union','Sebastian Sanchez',NULL,'2016-05-07','2016-05-07','2016-05-09','2016-05-09',108,108,8,100),
  ('Western Union','Sebastian Sanchez',NULL,'2016-05-09','2016-05-09','2016-05-10','2016-05-10',508,508,8,500),
  ('Western Union','Sebastian Sanchez',NULL,'2016-05-14','2016-05-14','2016-05-16','2016-05-16',708,708,8,700),
  ('Western Union','Sebastian Sanchez',NULL,'2016-07-23','2016-07-23','2016-07-25','2016-07-25',678,678,8,670),
  ('Western Union','Sebastian Sanchez',NULL,'2016-08-20','2016-08-20','2016-08-22','2016-08-22',678,678,8,670),
  ('Western Union','Sebastian Sanchez',NULL,'2016-10-01','2016-10-01','2016-10-03','2016-10-03',669,669,8,661),
  ('Western Union','Sebastian Sanchez',NULL,'2016-11-05','2016-11-05','2016-11-07','2016-10-03',677,677,8,669),
  ('Western Union','Sebastian Sanchez',NULL,'2016-12-21','2016-12-21','2016-12-22','2016-12-22',642.37,642.37,8,634.37),
  ('Western Union','Sebastian Sanchez',NULL,'2017-01-18','2017-01-18','2017-01-19','2017-01-19',640.78,640.78,8,632.78),
  ('Western Union','Sebastian Sanchez',NULL,'2017-03-04','2017-03-04','2017-03-04','2017-03-07',661.62,661.62,8,653.62),
  # --Ethan Bashkansky payments
  ('Cash','Ethan Bashkansky','Issa Rice','2016-02-17','2016-02-17','2016-02-17','2016-02-17',115,115,0,115),
  ('PayPal','Ethan Bashkansky',NULL,'2016-04-30','2016-04-30','2016-04-30','2016-04-30',44,44,0,44),
  ('PayPal','Ethan Bashkansky',NULL,'2016-08-30','2016-08-30','2016-08-30','2016-08-30',196.90,196.90,0,196.90),
  ('PayPal','Ethan Bashkansky',NULL,'2016-11-09','2016-11-09','2016-11-09','2016-11-09',257.30,257.30,0,257.30),

  # --Issa Rice payments
  # -- Payments for 2015 tax year
  ('PayPal','Issa Rice',NULL,'2015-06-13','2015-06-13','2015-06-13','2015-06-13',218,220,0,220),
  ('PayPal','Issa Rice',NULL,'2015-08-05','2015-08-05','2015-08-05','2015-08-05',62,62,0,62),
  ('PayPal','Issa Rice',NULL,'2015-08-08','2015-08-08','2015-08-08','2015-08-08',135,135,0,135),
  ('PayPal','Issa Rice',NULL,'2015-09-22','2015-09-22','2015-09-22','2015-09-22',300,300,0,300),
  ('PayPal','Issa Rice',NULL,'2015-11-07','2015-11-07','2015-11-07','2015-11-07',250,250,0,250),
  ('PayPal','Issa Rice',NULL,'2015-11-22','2015-11-22','2015-11-22','2015-11-22',50,50,0,50),
  ('PayPal','Issa Rice',NULL,'2015-12-31','2015-12-31','2015-12-31','2015-12-31',50,50,0,50),
  ('PayPal','Issa Rice',NULL,'2016-01-01','2016-01-01','2016-01-01','2016-01-01',5,5,0,5),
  ('PayPal','Issa Rice',NULL,'2016-01-01','2016-01-01','2016-01-01','2016-01-01',5,5,0,5),
  ('PayPal','Issa Rice',NULL,'2016-01-01','2016-01-01','2016-01-01','2016-01-01',5,5,0,5),
  ('PayPal','Issa Rice',NULL,'2016-01-01','2016-01-01','2016-01-01','2016-01-01',5,5,0,5),
  ('PayPal','Issa Rice',NULL,'2016-01-01','2016-01-01','2016-01-01','2016-01-01',5,5,0,5),
  ('PayPal','Issa Rice',NULL,'2016-01-01','2016-01-01','2016-01-01','2016-01-01',5,5,0,5),
  ('PayPal','Issa Rice',NULL,'2016-01-01','2016-01-01','2016-01-01','2016-01-01',1,1,0,1),
  # -- Possibly mixed payment
  ('PayPal','Issa Rice',NULL,'2016-01-16','2016-01-16','2016-01-16','2016-01-16',1342,1342,0,1342),

  # -- Payments for 2016 tax year
  ('PayPal','Issa Rice',NULL,'2016-01-21','2016-01-21','2016-01-21','2016-01-21',50,50,0,50),
  ('PayPal','Issa Rice',NULL,'2016-01-23','2016-01-23','2016-01-23','2016-01-23',50,50,0,50),
  ('PayPal','Issa Rice',NULL,'2016-01-24','2016-01-24','2016-01-24','2016-01-24',25,25,0,25),
  ('PayPal','Issa Rice',NULL,'2016-01-28','2016-01-28','2016-01-28','2016-01-28',100,100,0,100),
  ('PayPal','Issa Rice',NULL,'2016-01-31','2016-01-31','2016-01-31','2016-01-31',80,80,0,80),
  ('PayPal','Issa Rice',NULL,'2016-02-03','2016-02-03','2016-02-03','2016-02-03',100,100,0,100),
  ('PayPal','Issa Rice',NULL,'2016-02-17','2016-02-17','2016-02-17','2016-02-17',115,115,0,115),
  ('PayPal','Issa Rice',NULL,'2016-03-04','2016-03-04','2016-03-04','2016-03-04',193,193,0,193),
  ('PayPal','Issa Rice',NULL,'2016-04-22','2016-04-22','2016-04-22','2016-04-22',296,296,0,296),
  ('Check','Issa Rice',NULL,'2016-05-14','2016-05-18','2016-05-23','2016-05-23',4000,4000,0,4000),
  ('Check','Issa Rice',NULL,'2016-10-01','2016-10-06','2017-01-03','2017-01-04',4000,4000,0,4000),

  # -- Adrian Ulloa payment
  ('PayPal','Adrian Ulloa','Issa Rice','2016-08-26','2016-08-26','2016-08-26','2016-08-26',105,105.53,0.53,105),
  ('PayPal','Adrian Ulloa','Issa Rice','2016-12-14','2016-12-14','2016-12-20','2016-12-20',100,100.50,0.50,100),

  # -- Amy Zhang
  ('PayPal','Amy Zhang','Issa Rice','2016-06-26','2016-06-26','2016-06-26','2016-06-26',80,80,0,80),

  # -- Avi Glozman
  ('PayPal','Avi Glozman',NULL,'2016-06-04','2016-06-04','2016-06-04','2016-06-04',33,33,0,33),
  ('PayPal','Avi Glozman',NULL,'2016-07-28','2016-07-28','2016-07-28','2016-07-28',193,193,0,193),
  ('PayPal','Avi Glozman',NULL,'2016-08-28','2016-08-28','2016-08-28','2016-08-28',190,190,0,190),
  ('PayPal','Avi Glozman',NULL,'2016-12-13','2016-12-13','2016-12-14','2016-12-14',60,60,0,60),
  ('PayPal','Avi Glozman',NULL,'2017-03-08','2017-03-08','2017-03-08','2017-03-08',110,110,0,110),

  # -- Charlie Corner payments
  ('PayPal','Charlie Corner',NULL,'2016-07-09','2016-07-09','2016-07-09','2016-07-09',50,50,0,50),
  ('PayPal','Charlie Corner',NULL,'2016-09-18','2016-09-18','2016-09-18','2016-09-18',102,102,0,102),

  # -- Christopher Kunin payments
  ('PayPal','Christopher Kunin',NULL,'2016-06-18','2016-06-18','2016-06-18','2016-06-18',30,30,0,30),
  ('PayPal','Christopher Kunin',NULL,'2016-08-01','2016-08-01','2016-08-01','2016-08-01',112,112,0,112),
  ('PayPal','Christopher Kunin',NULL,'2016-10-12','2016-10-12','2016-10-12','2016-10-12',120,120,0,120),

  # -- Devansh Dwivedy payments
  ('PayPal','Devansh Dwivedy',NULL,'2016-06-29','2016-06-29','2016-06-29','2016-06-29',50,50,0,50),
  ('PayPal','Devansh Dwivedy',NULL,'2017-01-31','2017-01-31','2017-01-31','2017-01-31',103,103,0,103),

  # -- Eddy Su payments
  ('PayPal','Eddy Su',NULL,'2016-06-11','2016-06-11','2016-06-11','2016-06-11',38,38,0,38),
  ('PayPal','Eddy Su',NULL,'2016-12-13','2016-12-13','2016-12-13','2016-12-13',33,33,0,33),

  # -- Jesse Clifton payments
  ('Check','Jesse Clifton',NULL,'2016-08-15','2016-08-18','2016-08-24','2016-08-27',2000,2000,0,2000),

  # -- Michael Royzen payment
  ('PayPal','Michael Royzen',NULL,'2016-06-21','2016-06-21','2016-06-21','2016-06-21',50,50,0,50),

  # -- Sean Yu payment
  ('PayPal','Sean Yu',NULL,'2016-06-23','2016-06-23','2016-06-23','2016-06-23',50,50,0,50),

  # -- Sergey Yegorov payment
  ('PayPal','Sergey Yegorov',NULL,'2016-10-17','2016-10-17','2016-10-17','2016-10-17',175,175.88,0.88,175),

  # -- Thomas Foster payment
  ('PayPal','Thomas Foster',NULL,'2016-06-16','2016-06-16','2016-06-16','2016-06-16',80,79.99,0.79,79),
  ('PayPal','Thomas Foster',NULL,'2017-02-07','2017-02-07','2017-02-07','2017-02-07',50,50.51,0.51,50),

  # -- Alex K. Chen
  ('Check','Alex K. Chen',NULL,'2015-12-26','2015-12-31','2016-01-06','2016-01-06',7100,7100,0,7100),
  ('Check','Alex K. Chen',NULL,'2017-01-07','2017-01-13','2017-01-19','2017-01-19',4000,4000,0,4000),

  # -- Milo King
  ('Debit card via Facebook','Milo King',NULL,'2016-12-13','2016-12-13','2016-12-13','2016-12-13',205,205,0,205),

  # -- Joey Malandra
  ('PayPal','Joey Malandra',NULL,'2016-12-25','2016-12-25','2016-12-25','2016-12-25',64,64,0,64),

  # -- Daniel Alejandro Maidana
  ('Western Union','Daniel Alejandro Maidana','Sebastian Sanchez','2016-12-31','2016-12-31','2016-12-31','2016-12-31',30,30,0,30);
