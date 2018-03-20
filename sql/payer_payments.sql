create table payer_payments(
  payment_id int(11) not null auto_increment primary key,
  payment_method enum('Cash','Check','PayPal','Wire transfer','Western Union','Debit card via Facebook','Venmo') not null,
  payer varchar(40) not null,
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

insert into payer_payments(payment_method, payer, sent_date, payment_notice_receipt_date, cashout_request_date, receipt_date, payment, sent_payment, overhead, received_payment) values
  ('PayPal', 'Peter Hurford', '2017-10-05', '2017-10-05', '2017-10-05', '2017-10-05', 2115, 2115, 0, 2115),
  ('PayPal', 'Alex Flint', '2018-03-09', '2018-03-09', '2018-03-09', '2018-03-09', 150, 150, 0, 150);


