create table payer_payments(
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
