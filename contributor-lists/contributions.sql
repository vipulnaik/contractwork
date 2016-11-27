create database contractwork;

use contractwork;

create table tasks(
  task_id not null auto_increment,
  worker varchar(40),
  task_venue enum('Wikipedia','Wikipedia Views','Effective Altruism Forum','LessWrong','Personal website') default 'Wikipedia',
  task_type enum('Wikipedia page creation','Wikipedia page update','Wikipedia pge translation','attemped Wikipedia work','miscellaneous Wikipedia work','Preliminary research','Blog post or article','Survey creation','Surey recruitment','Coding','Consulting','Review'),
  task_receptacle varchar(100) NOT NULL,
  task_receptacle_url varchar(100) NOT NULL,
  completion_date date NOT NULL,
  payment float(7,2) NOT NULL,
  topic varchar(100) NOT NULL,
  format varchar(100) NOT NULL,
  notes varchar(2000) DEFAULT NULL
) ENGINE=InnoDB AUTO_INCREMENT=15239276 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

# -- Ethan Bashkansky's Wikipedia work

insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptable_url, completion_date, payment, topic, format) values
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Form W-4','https://en.wikipedia.org/wiki/Form_W-4','2016-02-12',30,'United States taxation','Prose'),
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Form 1095','https://en.wikipedia.org/wiki/Form_1095','2016-02-13',30,'United States taxation','Prose'),
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Individual shared responsibility provision','https://en.wikipedia.org/wiki/Individual_shared_responsibility_provision','2016-02-14',40,'United States taxation','Prose'),
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Form 1042','https://en.wikipedia.org/wiki/Form_1042','2016-02-15',25,'United States taxation','Prose'),
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Equal Pay Day','https://en.wikipedia.org/wiki/Equal_Pay_Day','2016-04-26',24,'Feminism','Prose'),
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Form 1099-K','https://en.wikipedia.org/wiki/Form_1099-K','2016-08-23',50,'United States taxation','Prose'),
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Form 1099-R','https://en.wikipedia.org/wiki/Form_1099-R','2016-08-29',50,'United States taxation','Prose'),
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Vote pairing in the United States presidential election, 2016','https://en.wikipedia.org/wiki/Vote_pairing_in_the_United_States_presidential_election,_2016','2016-11-02',105,'United States politics','Prose');
