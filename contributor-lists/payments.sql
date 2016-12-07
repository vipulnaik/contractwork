create table payments(
  payment_id int(11) not null auto_increment primary key,
  payment_method enum('Cash','Check','PayPal','Wire transfer','Western Union') not null,
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
  ('Western Union','Sebastian Sanchez',NULL,fillin,fillin,fillin,fillin,108,108,8,100),
  ('Western Union','Sebastian Sanchez',NULL,fillin,fillin,fillin,fillin,508,508,8,500),
  ('Western Union','Sebastian Sanchez',NULL,fillin,fillin,fillin,fillin,708,708,8,700),
  ('Western Union','Sebastian Sanchez',NULL,'2016-07-23','2016-07-23','2016-07-25','2016-07-25',678,678,8,670),
  ('Western Union','Sebastian Sanchez',NULL,'2016-08-20','2016-08-20','2016-08-22','2016-08-22',678,678,8,670),
  ('Western Union','Sebastian Sanchez',NULL,'2016-10-01','2016-10-01','2016-10-03','2016-10-03',669,669,8,661),
  ('Western Union','Sebastian Sanchez',NULL,'2016-11-05','2016-11-05','2016-11-07','2016-10-03',677,677,8,669),

  # --Ethan Bashkansky payments
  # -- put in $44 payment to Issa
  ('PayPal','Ethan Bashkansky',NULL,'2016-04-30','2016-04-30','2016-04-30','2016-04-30',44,44,0,44),
  ('PayPal','Ethan Bashkansky',NULL,'2016-08-30','2016-08-30','2016-08-30','2016-08-30',196.90,196.90,0,196.90),
  ('PayPal','Ethan Bashkansky',NULL,'2016-11-09','2016-11-09','2016-11-09','2016-11-09',257.30,257.30,0,257.30),

  # --Issa Rice payments
  # -- Put in early year payments
  ('Check','Issa Rice',NULL,'2016-05-14',(insert date),(insert date),'2016-05-23',4000,4000,0,4000),
  ('Check','Issa Rice',NULL,'2016-10-01',(insert date),(insert date),NULL,4000,4000,0,4000),

  # -- Insert PayPal payments for all the other workers



