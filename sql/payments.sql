create table payments(
  payment_id int(11) not null auto_increment primary key,
  payment_method enum('Cash','Check','PayPal','Wire transfer','Western Union','Debit card via Facebook','Venmo', 'Ethereum', 'Bitcoin','Direct deposit via Gusto', 'Direct deposit') not null,
  payee varchar(40) not null,
  intermediary varchar(40) default null,
  sent_date date NOT NULL,
  payment_notice_receipt_date date NOT NULL,
  cashout_request_date date,
  receipt_date date,
  payment float(7,2) not null,
  sent_payment float(7,2) not null,
  overhead float(7,2) not null,
  received_payment float(7,2) not null,
  private tinyint(1) default 0,
  notes varchar(2000)
) ENGINE=InnoDB AUTO_INCREMENT=15239276 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

insert into payments(payment_method, payee, intermediary, sent_date, payment_notice_receipt_date, cashout_request_date, receipt_date, payment, sent_payment, overhead, received_payment,notes) values
  /* Sebastian Sanchez payments */
  ('Western Union','Sebastian Sanchez',NULL,'2016-05-07','2016-05-07','2016-05-09','2016-05-09',108,108,8,100,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2016-05-09','2016-05-09','2016-05-10','2016-05-10',508,508,8,500,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2016-05-14','2016-05-14','2016-05-16','2016-05-16',708,708,8,700,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2016-07-23','2016-07-23','2016-07-25','2016-07-25',678,678,8,670,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2016-08-20','2016-08-20','2016-08-22','2016-08-22',678,678,8,670,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2016-10-01','2016-10-01','2016-10-03','2016-10-03',669,669,8,661,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2016-11-05','2016-11-05','2016-11-07','2016-11-07',677,677,8,669,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2016-12-21','2016-12-21','2016-12-22','2016-12-22',642.37,642.37,8,634.37,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2017-01-18','2017-01-18','2017-01-19','2017-01-19',640.78,640.78,8,632.78,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2017-03-04','2017-03-04','2017-03-07','2017-03-07',661.62,661.62,8,653.62,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2017-05-06','2017-05-06','2017-05-09','2017-05-09',659.71,659.71,8,651.71,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2017-05-13','2017-05-13','2017-05-15','2017-05-15',659.61,659.61,8,651.61,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2017-06-03','2017-06-03','2017-06-06','2017-06-06',636.39,636.39,8,628.39,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2017-06-10','2017-06-10','2017-06-12','2017-06-12',641.91,641.91,8,633.91,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2017-06-24','2017-06-24','2017-06-26','2017-06-26',633.28,633.28,8,625.28,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2017-07-08','2017-07-08','2017-07-10','2017-07-10',3011.61,3011.61,30,2981.61,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2017-10-04','2017-10-04','2017-10-05','2017-10-05',4744.33,4744.33,30,4714.33,NULL),
  ('PayPal','Sebastian Sanchez',NULL,'2017-12-10','2017-12-10','2017-12-11','2017-12-11',94.30,100,5.70,94.30,NULL),
  ('Western Union','Sebastian Sanchez',NULL,'2017-12-30','2017-12-30','2018-01-02','2018-01-02',4175,4477.81,30,4447.81,'Payee gets 80000 ARS. $4175 is calculated as 80000 ARS at the exchange rate at the time of transfer.'),
  ('Western Union','Sebastian Sanchez',NULL,'2018-03-11','2018-03-11','2018-03-12','2018-03-12',3960, 4065.73, 30, 4035.73,'Payee gets 80010 ARS. $3960 is calculated as 80010 ARS at the exchange rate at the time of transfer.'),
  ('Western Union','Sebastian Sanchez',NULL,'2018-06-02','2018-06-02','2018-06-04','2018-06-04',3950.32, 4030, 30, 4000,'Payee gets 98763.17 ARS. $3950.52 is calculated as 98763.17 ARS at the exchange rate at the time of transfer (1 ARS = 0.040 USD).'),
  ('Western Union','Sebastian Sanchez',NULL,'2018-08-04','2018-08-04','2018-08-13','2018-08-13',4253,4530,30,4500,'Payee gets 121517 ARS. $4253 is calculated as 121517 ARS at the exchange rate at the time of transfer of 1 ARS = 0.035 USD (the exchange rate around the middle of the time between sending and receiving).'),
  ('Western Union','Sebastian Sanchez',NULL,'2018-10-13','2018-10-13','2018-10-16','2018-10-16',4218.60,4330,30,4300,'Payee gets 153599.22 ARS. $4218.60 is calculated as 152599.22 ARS at the exchange rate at the time of transfer (1 ARS = 0.027 USD).'),
  ('Western Union','Sebastian Sanchez',NULL,'2019-03-09','2019-03-09','2019-03-11','2019-03-11',4145,4330,30,4300,'Payee gets 172717 ARS. $4145 is calculated as 172717 ARS at the exchange rate at the time of transfer of 1 ARS = 0.024 USD. This payment is happening after a long gap since the previous payment (of about five months) due to reduced volume of work in the interim due to vacation and sickness.'),
  ('Western Union','Sebastian Sanchez',NULL,'2019-05-19','2019-05-19','2019-05-20','2019-05-20',4705,4770,20,4750,'Payee gets 212918.23 ARS. $4705 is calculated as 212918.23 ARS at the exchange rate at the time of transfer (1 ARS = 0.0221 USD).'),
  ('PayPal','Sebastian Sanchez',NULL,'2019-08-02','2019-08-02','2019-08-02','2019-08-02',50,50,3,47,'Small experimental payment via PayPal to test out this transfer method. It would turn out that the PayPal transaction fees of 5.4% + 30 cents, along with additional overhead, would lead us to consider this experiment a failure.'),
  ('PayPal','Sebastian Sanchez',NULL,'2019-08-03','2019-08-03','2019-08-03','2019-08-03',-33.45,-35.30,-1.85,-33.45,'Payee returns money via PayPal after we determined that the PayPal transaction fees were too high for the PayPal transfer to be cost-effective.'),
  ('Western Union','Sebastian Sanchez',NULL,'2019-08-11','2019-08-11','2019-08-12','2019-08-12',692.92,708,8,700,'Payee gets 31496.46 ARS. $692.92 is calculated as 31496.46 ARS at the exchange rate at the time of transfer (1 ARS = 0.022 USD).'),
  ('Western Union','Sebastian Sanchez',NULL,'2019-08-25','2019-08-25','2019-08-26','2019-08-26',4950,4970,20,4950,'Payee gets 271770.03 ARS. The exchange rate used by Western Union matches the market exchange rate at the time of transfer (1 USD = 54.63 ARS).'),
  ('Western Union','Sebastian Sanchez',NULL,'2019-12-14','2019-12-14','2019-12-16','2019-12-16',4950,4990,40,4950,'Payee gets 354370.50 ARS. The exchange rate used by Western Union matches the "true" market exchange rate at the time of transfer (1 USD = 71.59 ARS).'),
  ('Western Union','Sebastian Sanchez',NULL,'2020-02-08','2020-02-08','2020-02-10','2020-02-10',4950,4990,40,4950,'Payee gets 413424 ARS. The exchange rate used by Western Union matches the "true" market exchange rate at the time of transfer (1 USD = 83.52 ARS).'),
  ('Bitcoin','Sebastian Sanchez',NULL,'2020-06-02','2020-06-02','2020-06-02','2020-06-02',190.13,190.13,0,190.13,'Transaction in Bitcoin for 0.02 BTC (and calculated in terms of USD value at time of transaction), with a very small transaction fee of 0.00002820 BTC. Transaction available online at https://www.blockchain.com/btc/tx/c2c3141e13437ff181cee7caceda69913d3715fc1af7a6bab0b3a8250a497413 (note that the transaction as shown in Blockchain appears to bundle this transaction with others that Coinbase may have executed simultaneously, so its details are a bit misleading). Sebastian received 22746 ARS for the 0.02 BTC.'),
  ('Bitcoin','Sebastian Sanchez',NULL,'2020-06-10','2020-06-10','2020-06-10','2020-06-10',1484.19,1484.19,0,1484.19,'Transaction in Bitcoin for 0.15 BTC (and calculated in terms of USD value at time of transaction), with a very small transaction fee of 0.00026640 BTC. Transaction available online at https://www.blockchain.com/btc/tx/8ac25795213e7032d055994f77b8163a74c345522f1dfb7c7899b47125f88ecf Sebastian received 171351.46 ARS for the 0.15 BTC.'),
  ('Bitcoin','Sebastian Sanchez',NULL,'2020-07-08','2020-07-08','2020-07-08','2020-07-08',4704.64,4704.64,0,4704.64,'Transaction in Bitcoin for 0.50 BTC (and calculated in terms of USD value at time of transaction), with a very small transaction fee of 0.00056663 BTC. Transaction available online at https://www.blockchain.com/btc/tx/53a5687a3c0f4f277f43f303c88fb127e603781cdc31221fc8fa9bb350fc3cd7 Sebastian received 526911.24 ARS for the 0.50 BTC.'),
  ('Bitcoin','Sebastian Sanchez',NULL,'2020-10-07','2020-10-07','2020-10-07','2020-10-07',5327.32,5327.32,0,5327.32,'Transaction in Bitcoin for 0.50 BTC (and calculated in terms of USD value at time of transaction), with a very small transaction fee of 0.00003696 BTC. Transaction available online at https://www.blockchain.com/btc/tx/8a7e84f79eee973b379ee8bf61688f5249564427130999d255d83c37955fc02b Sebastian received 764353.88 ARS for the 0.50 BTC.'),
  ('Bitcoin','Sebastian Sanchez',NULL,'2020-11-05','2020-11-05','2020-11-05','2020-11-05',2377.12,2377.12,0,2377.12,'Transaction in Bitcoin for 0.15 BTC (and calculated in terms of USD value at time of transaction), with a very small transaction fee of 0.00009758 BTC. Transaction available online at https://www.blockchain.com/btc/tx/69a3321d6d4b0517ab7ec971bc17dd4a7e16d0fce2ac530bdde5aed31b156542 Sebastian received 344105.07 ARS for the 0.15 BTC when he sold it the next day (Friday, November 6, 2020).'),
  ('Bitcoin','Sebastian Sanchez',NULL,'2020-12-17','2020-12-17','2020-12-17','2020-12-17',69.64,69.64,0,69.64,'Transaction in Bitcoin for 0.003 BTC (and calculated in terms of USD value at timme of transaction), with a very small transaction fee of 0.00004023 BTC. Transaction available online at https://www.blockchain.com/btc/tx/b83a5d053dec8bd1540b5087d481b66d1c4107fb7c55adcda20ef0f2886b4970'),
  ('Bitcoin','Sebastian Sanchez',NULL,'2020-12-17','2020-12-17','2020-12-17','2020-12-17',707.12,707.12,0,707.12,'Transaction in Bitcoin for 0.03 BTC (and calculated in terms of USD value at timme of transaction), with a very small transaction fee of 0.00004209 BTC. Transaction available online at https://www.blockchain.com/btc/tx/ba7235c0e3f236cb7fbe7fa2900530be3400c03c9c715a7210231cc739d870e3'),
  ('Bitcoin','Sebastian Sanchez',NULL,'2021-01-02','2021-01-02','2021-01-02','2021-01-02',649.12,649.12,0,649.12,'Transaction in Bitcoin for 0.02 BTC (and calculated in terms of USD value at time of transaction), with a very small transaction fee of 0.00000754 BTC. Transaction available online at https://blockchain.info/tx/b02de5ccd5a2c951e9b1970d0c35611c6cce64f30a2d161f85c6621448a66810 (note that the transaction as shown in Blockchain appears to bundle this transaction with others that Coinbase may have executed simultaneously, so its details are a bit misleading).'),

  /* Ethan Bashkansky payments */
  ('Cash','Ethan Bashkansky','Issa Rice','2016-02-17','2016-02-17','2016-02-17','2016-02-17',115,115,0,115,NULL),
  ('PayPal','Ethan Bashkansky',NULL,'2016-04-30','2016-04-30','2016-04-30','2016-04-30',44,44,0,44,NULL),
  ('PayPal','Ethan Bashkansky',NULL,'2016-08-30','2016-08-30','2016-08-30','2016-08-30',196.90,196.90,0,196.90,NULL),
  ('PayPal','Ethan Bashkansky',NULL,'2016-11-09','2016-11-09','2016-11-09','2016-11-09',257.30,257.30,0,257.30,NULL),
  ('PayPal','Ethan Bashkansky',NULL,'2018-01-07','2018-01-07','2018-01-07','2018-01-07',545.52,545.52,0,545.52,NULL),

  /* Issa Rice payments */
  /* Payments for 2015 tax year */
  ('PayPal','Issa Rice',NULL,'2015-06-13','2015-06-13','2015-06-13','2015-06-13',218,220,0,220,NULL),
  ('PayPal','Issa Rice',NULL,'2015-08-05','2015-08-05','2015-08-05','2015-08-05',62,62,0,62,NULL),
  ('PayPal','Issa Rice',NULL,'2015-08-08','2015-08-08','2015-08-08','2015-08-08',135,135,0,135,NULL),
  ('PayPal','Issa Rice',NULL,'2015-09-22','2015-09-22','2015-09-22','2015-09-22',300,300,0,300,NULL),
  ('PayPal','Issa Rice',NULL,'2015-11-07','2015-11-07','2015-11-07','2015-11-07',250,250,0,250,NULL),
  ('PayPal','Issa Rice',NULL,'2015-11-22','2015-11-22','2015-11-22','2015-11-22',50,50,0,50,NULL),
  ('PayPal','Issa Rice',NULL,'2015-12-31','2015-12-31','2015-12-31','2015-12-31',50,50,0,50,NULL),
  ('PayPal','Issa Rice',NULL,'2016-01-01','2016-01-01','2016-01-01','2016-01-01',5,5,0,5,NULL),
  ('PayPal','Issa Rice',NULL,'2016-01-01','2016-01-01','2016-01-01','2016-01-01',5,5,0,5,NULL),
  ('PayPal','Issa Rice',NULL,'2016-01-01','2016-01-01','2016-01-01','2016-01-01',5,5,0,5,NULL),
  ('PayPal','Issa Rice',NULL,'2016-01-01','2016-01-01','2016-01-01','2016-01-01',5,5,0,5,NULL),
  ('PayPal','Issa Rice',NULL,'2016-01-01','2016-01-01','2016-01-01','2016-01-01',5,5,0,5,NULL),
  ('PayPal','Issa Rice',NULL,'2016-01-01','2016-01-01','2016-01-01','2016-01-01',5,5,0,5,NULL),
  ('PayPal','Issa Rice',NULL,'2016-01-01','2016-01-01','2016-01-01','2016-01-01',1,1,0,1,NULL),
  /* Possibly mixed payment */
  ('PayPal','Issa Rice',NULL,'2016-01-16','2016-01-16','2016-01-16','2016-01-16',1342,1342,0,1342,NULL),

  /* Payments for 2016 tax year */
  ('PayPal','Issa Rice',NULL,'2016-01-21','2016-01-21','2016-01-21','2016-01-21',50,50,0,50,NULL),
  ('PayPal','Issa Rice',NULL,'2016-01-23','2016-01-23','2016-01-23','2016-01-23',50,50,0,50,NULL),
  ('PayPal','Issa Rice',NULL,'2016-01-24','2016-01-24','2016-01-24','2016-01-24',25,25,0,25,NULL),
  ('PayPal','Issa Rice',NULL,'2016-01-28','2016-01-28','2016-01-28','2016-01-28',100,100,0,100,NULL),
  ('PayPal','Issa Rice',NULL,'2016-01-31','2016-01-31','2016-01-31','2016-01-31',80,80,0,80,NULL),
  ('PayPal','Issa Rice',NULL,'2016-02-03','2016-02-03','2016-02-03','2016-02-03',100,100,0,100,NULL),
  ('PayPal','Issa Rice',NULL,'2016-02-17','2016-02-17','2016-02-17','2016-02-17',115,115,0,115,NULL),
  ('PayPal','Issa Rice',NULL,'2016-03-04','2016-03-04','2016-03-04','2016-03-04',193,193,0,193,NULL),
  ('PayPal','Issa Rice',NULL,'2016-04-22','2016-04-22','2016-04-22','2016-04-22',296,296,0,296,NULL),
  ('Check','Issa Rice',NULL,'2016-05-14','2016-05-18','2016-05-23','2016-05-23',4000,4000,0,4000,'This is the first payment made by check to Issa Rice; we switched to check because PayPal was not reliable at processing large payments'),
  ('Check','Issa Rice',NULL,'2016-10-01','2016-10-06','2017-01-03','2017-01-04',4000,4000,0,4000,NULL),
  
  /* Payments for 2017 tax year */
  ('Check','Issa Rice',NULL,'2017-03-25','2017-04-10','2017-04-15','2017-04-17',12000,12000,0,12000,'This is the biggest contract work payment ever so far; the payment also begins to pay off Issa for the stipends from 2016 the award of which had been deferred till March 2017'),
  ('Check','Issa Rice',NULL,'2017-09-27','2017-09-30','2017-10-02','2017-10-12',15000,15000,0,15000,'This is the biggest contract work payment ever so far; the payment completes the paying off of deferred stipends from previous years'),

  /* Payments for 2018 tax year */
  ('Check','Issa Rice',NULL,'2018-04-02','2018-04-05','2018-04-09','2018-04-18',18000,18000,0,18000,'This is the biggest contract work payment ever so far; we decided to hold out till the amount reached $18,000 to reduce the proportional effort overhead of money transfer'),
  ('Check','Issa Rice',NULL,'2018-11-22','2018-11-30','2018-12-11','2018-12-12',10000,10000,0,10000,'We decided to make the transfer at a smaller amount threshold than last time''s $18,000, because the monthly amount of work had declined, and waiting till we get to $18,000 would take a lot of time'),

  /* Payments for 2019 tax year */
  ('PayPal','Issa Rice',NULL,'2019-08-02','2019-08-02','2019-08-02','2019-08-02',4263.02,4263.02,0,4263.02,'We decided to try out PayPal to clear out the existing amount due, because the amount was large enough to be worth a transfer, but too small to be worth the overhead of a check. Fortunately, PayPal worked'),
  ('Direct deposit via Gusto','Issa Rice',NULL,'2019-08-13','2019-08-13','2019-08-13','2019-08-13',498.75,498.75,0,498.75,'Payment from Berkeley Existential Risk Initiative (BERI) for work done by Issa Rice in July 2019'),
  ('Direct deposit via Gusto','Issa Rice',NULL,'2019-09-11','2019-09-11','2019-09-11','2019-09-11',95.10,95.10,0,95.10,'Payment from Berkeley Existential Risk Initiative (BERI) for work done by Issa Rice in August 2019'),
  ('Direct deposit','Issa Rice',NULL,'2019-11-15','2019-11-15','2019-11-15','2019-11-15',50,50,0,50,'Payment from Centre for Effective Altruism (CEA) for an EA Forum comment prize'),

  /* Payment sent in 2020 to wrap up pending amount due from 2019 tax year */
  ('PayPal','Issa Rice',NULL,'2020-01-01','2020-01-01','2020-01-01','2020-01-01',1460.13,1460.13,0,1460.13,'We decided to try out PayPal to clear out the existing amount due, because the amount was large enough to be worth a transfer, but too small to be worth the overhead of a check. Fortunately, PayPal worked.'),

  /* Payments for 2020 tax year sent in 2020 */
  ('PayPal','Issa Rice',NULL,'2020-02-06','2020-02-06','2020-02-06','2020-02-06',570.16,570.16,0,570.16,'Since the amount due was over $300, we decided to clear it via PayPal.'),
  ('PayPal','Issa Rice',NULL,'2020-05-01','2020-05-01','2020-05-01','2020-05-01',371.07,371.07,0,371.07,'Since the amount due was over $300, we decided to clear it via PayPal.'),
  ('PayPal','Issa Rice',NULL,'2020-07-10','2020-07-10','2020-07-10','2020-07-10',354.03,354.03,0,354.03,'Since the amount due was over $300, we decided to clear it via PayPal.'),
  ('PayPal','Issa Rice',NULL,'2020-08-01','2020-08-01','2020-08-01','2020-08-01',306.63,306.63,0,306.03,'Since the amount due was over $300, we decided to clear it via PayPal.'),
  ('PayPal','Issa Rice',NULL,'2020-11-07','2020-11-07','2020-11-07','2020-11-07',334.62,334.62,0,334.62,'Since the amount due was over $300, we decided to clear it via PayPal.'),

  /* Payment sent in 2021 to wrap up pending amount due from 2020 tax year */
  ('PayPal','Issa Rice',NULL,'2021-01-03','2021-01-03','2021-01-03','2021-01-03',835.57,835.57,0,835.57,NULL),
  ('PayPal','Issa Rice',NULL,'2021-01-03','2021-01-03','2021-01-03','2021-01-03',40.61,40.61,0,40.61,NULL),

  /* Payment sent in 2021 for 2020 work by Amana Rice */
  ('PayPal','Amana Rice',NULL,'2021-01-03','2021-01-03','2021-01-03','2021-01-03',270.72,270.72,0,270.72,NULL),
  /* Orpheus Lummis */
  ('Ethereum','Orpheus Lummis',NULL,'2018-10-06','2018-10-06','2018-10-06','2018-10-06',160,160.01,0.01,160,NULL),

  /* Mati Roy */
  ('PayPal','Mati Roy',NULL,'2019-02-17','2019-02-17','2019-02-17','2019-02-17',500,500,18.82,481.18,NULL),
  ('Bitcoin','Mati Roy',NULL,'2019-08-17','2019-08-17','2019-08-17','2019-08-17',100,100.69,0.69,100,'Transaction in Bitcoin for 0.00981355 BTC (and calculated in terms of USD value at time of transaction) with a very small transaction fee of 0.00006799 BTC. Transaction available online at https://www.blockchain.com/btc/tx/c84d76588c3f8819dabe5c9f4d8eaac5d670f87f0d1de21d8efa7f44247dd820 (note that the transaction as shown in Blockchain appears to additionally allocate 0.00225072 BTC to another account, and that should be ignored)'),

  /* Adrian Ulloa payment */
  ('PayPal','Adrian Ulloa','Issa Rice','2016-08-26','2016-08-26','2016-08-26','2016-08-26',105,105.53,0.53,105,NULL),
  ('PayPal','Adrian Ulloa','Issa Rice','2016-12-14','2016-12-14','2016-12-20','2016-12-20',100,100.50,0.50,100,NULL),

  /* Amy Zhang */
  ('PayPal','Amy Zhang','Issa Rice','2016-06-26','2016-06-26','2016-06-26','2016-06-26',80,80,0,80,NULL),

  /* Avi Glozman */
  ('PayPal','Avi Glozman',NULL,'2016-06-04','2016-06-04','2016-06-04','2016-06-04',33,33,0,33,NULL),
  ('PayPal','Avi Glozman',NULL,'2016-07-28','2016-07-28','2016-07-28','2016-07-28',193,193,0,193,NULL),
  ('PayPal','Avi Glozman',NULL,'2016-08-28','2016-08-28','2016-08-28','2016-08-28',190,190,0,190,NULL),
  ('PayPal','Avi Glozman',NULL,'2016-12-13','2016-12-13','2016-12-14','2016-12-14',60,60,0,60,NULL),
  ('PayPal','Avi Glozman',NULL,'2017-03-08','2017-03-08','2017-03-08','2017-03-08',110,110,0,110,NULL),

  /* Charlie Corner */
  ('PayPal','Charlie Corner',NULL,'2016-07-09','2016-07-09','2016-07-09','2016-07-09',50,50,0,50,NULL),
  ('PayPal','Charlie Corner',NULL,'2016-09-18','2016-09-18','2016-09-18','2016-09-18',102,102,0,102,NULL),
  ('PayPal','Charlie Corner',NULL,'2020-03-15','2020-03-15','2020-03-15','2020-03-15',50,50,0,50,'A much delayed payment to clear pending balance'),

  /* Christopher Kunin */
  ('PayPal','Christopher Kunin',NULL,'2016-06-18','2016-06-18','2016-06-18','2016-06-18',30,30,0,30,NULL),
  ('PayPal','Christopher Kunin',NULL,'2016-08-01','2016-08-01','2016-08-01','2016-08-01',112,112,0,112,NULL),
  ('PayPal','Christopher Kunin',NULL,'2016-10-12','2016-10-12','2016-10-12','2016-10-12',120,120,0,120,NULL),

  /* Devansh Dwivedy */
  ('PayPal','Devansh Dwivedy',NULL,'2016-06-29','2016-06-29','2016-06-29','2016-06-29',50,50,0,50,NULL),
  ('PayPal','Devansh Dwivedy',NULL,'2017-01-31','2017-01-31','2017-01-31','2017-01-31',103,103,0,103,NULL),

  /* Eddy Su */
  ('PayPal','Eddy Su',NULL,'2016-06-11','2016-06-11','2016-06-11','2016-06-11',38,38,0,38,NULL),
  ('PayPal','Eddy Su',NULL,'2016-12-13','2016-12-13','2016-12-13','2016-12-13',33,33,0,33,NULL),

  /* Jesse Clifton */
  ('Check','Jesse Clifton',NULL,'2016-08-15','2016-08-18','2016-08-24','2016-08-27',2000,2000,0,2000,NULL),
  ('PayPal','Jesse Clifton',NULL,'2017-03-18','2017-03-18','2017-03-18','2017-03-18',234,234,0,234,NULL),

  /* Michael Royzen */
  ('PayPal','Michael Royzen',NULL,'2016-06-21','2016-06-21','2016-06-21','2016-06-21',50,50,0,50,NULL),

  /* Sean Yu */
  ('PayPal','Sean Yu',NULL,'2016-06-23','2016-06-23','2016-06-23','2016-06-23',50,50,0,50,NULL),
  ('Venmo','Sean Yu',NULL,'2020-03-14','2020-03-14','2020-03-14','2020-03-14',5,5,0,5,'A much delayed payment to clear pending balance'),

  /* Sergey Yegorov */
  ('PayPal','Sergey Yegorov',NULL,'2016-10-17','2016-10-17','2016-10-17','2016-10-17',175,175.88,0.88,175,NULL),

  /* Thomas Foster */
  ('PayPal','Thomas Foster',NULL,'2016-06-16','2016-06-16','2016-06-16','2016-06-16',80,79.99,0.79,79,NULL),
  ('PayPal','Thomas Foster',NULL,'2017-02-07','2017-02-07','2017-02-07','2017-02-07',50,50.51,0.51,50,NULL),

  /* Linchuan Zhang */
  ('PayPal','Linchuan Zhang',NULL,'2020-03-14','2020-03-14','2020-03-14','2020-03-14',30.30,30.30,0,30.30,'A much delayed payment to clear pending balance'),

  /* Alex K. Chen */
  ('Check','Alex K. Chen',NULL,'2015-12-26','2015-12-31','2016-01-06','2016-01-06',7100,7100,0,7100,NULL),
  ('Check','Alex K. Chen',NULL,'2017-01-07','2017-01-13','2017-01-19','2017-01-19',4000,4000,0,4000,NULL),
  ('Venmo','Alex K. Chen',NULL,'2017-11-06','2017-11-06','2017-11-06','2017-11-06',-624.50,-624.50,0,-624.50,NULL),
  
  /* Milo King */
  ('Debit card via Facebook','Milo King',NULL,'2016-12-13','2016-12-13','2016-12-13','2016-12-13',205,205,0,205,NULL),

  /* Joey Malandra */
  ('PayPal','Joey Malandra',NULL,'2016-12-25','2016-12-25','2016-12-25','2016-12-25',64,64,0,64,NULL),
  ('PayPal','Joey Malandra',NULL,'2017-03-18','2017-03-18','2017-03-18','2017-03-18',73,73,0,73,NULL),

  /* Daniel Alejandro Maidana */
  ('Cash','Daniel Alejandro Maidana','Sebastian Sanchez','2016-12-31','2016-12-31','2016-12-31','2016-12-31',30,30,0,30,'Sebastian Sanchez paid Daniel Alejandro Maidana in pesos at the exchange rate of that date');
