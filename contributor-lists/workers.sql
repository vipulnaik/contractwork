create table workers(
  worker_id int(11) not null auto_increment,
  worker varchar(40) not null,
  country varchar(20) not null,
  wikipedia_username varchar(20),
  facebook_username varchar(20),
  email_id varchar(40),
  preferred_payment_method enum('Cash','Check','PayPal','Wire transfer','Western Union') not null,
  recruiter enum('Vipul Naik','Issa Rice','Ethan Bashkansky','Linchuan Zhang','Alex K. Chen') not null,
  contact_method enum('inbound email','inbound Facebook','outbound email','outbound Facebook','outbound in-person') not null,
  notes varchar(2000) default null
  unique worker(`worker`)
) ENGINE=InnoDB AUTO_INCREMENT=15239276 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

insert into workers(worker, country, wikipedia_username, facebook_username, email_id, preferred_payment_method, recruiter, notes) values (
  ('Sebastian Sanchez','Argentina','Wikisanchez','seba.sanchez.3998',NULL,'Western Union','Vipul Naik','inbound Facebook','Started work in April 2016. Took break in June 2016 for Japan visit. Worked on disease timelines, country healthcare timelines, and miscellaneous global health Wikipedia articles.'),
  ('Ethan Bashkansky','United States','Ethanbas','ethan.bashkansky',NULL,'PayPal','Issa Rice','outbound in-person','Did sporadic work in February, and has done sporadic work a few times since. Also recruits other workers and stays in touch.'),
  ('Adrian Ulloa','Peru','Physikite','physikite',NULL,'PayPal','Vipul Naik','inbound email','Did sporadic work in September of 2016.'),
  ('Avi Glozman','United States','Avigl','avi.glozman',NULL,'PayPal','Ethan Bashkansky','outbound Facebook','Sporadic work since June 2016')
