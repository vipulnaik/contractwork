create database contractwork;

use contractwork;

create table tasks(
  task_id int(11) not null auto_increment,
  worker varchar(40),
  task_venue enum('Wikipedia','Wikipedia Views','Effective Altruism Forum','LessWrong','Personal website') default 'Wikipedia',
  task_type enum('Wikipedia page creation','Wikipedia page update','Wikipedia page translation','Attemped Wikipedia work','Miscellaneous Wikipedia work','Preliminary research','Blog post or article','Survey creation','Surey recruitment','Coding','Consulting','Review'),
  task_receptacle varchar(100) NOT NULL,
  task_receptacle_url varchar(100) NOT NULL,
  completion_date date NOT NULL,
  payment float(7,2) NOT NULL,
  topic varchar(100) NOT NULL,
  format varchar(100) NOT NULL,
  notes varchar(2000) DEFAULT NULL,
  primary key (`task_id`)
) ENGINE=InnoDB AUTO_INCREMENT=15239276 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

# -- Ethan Bashkansky's Wikipedia page creation work

insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Form W-4','https://en.wikipedia.org/wiki/Form_W-4','2016-02-12',30,'United States taxation','Prose', NULL),
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Form 1095','https://en.wikipedia.org/wiki/Form_1095','2016-02-13',30,'United States taxation','Prose', NULL),
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Individual shared responsibility provision','https://en.wikipedia.org/wiki/Individual_shared_responsibility_provision','2016-02-14',40,'United States taxation','Prose',NULL),
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Form 1042','https://en.wikipedia.org/wiki/Form_1042','2016-02-15',25,'United States taxation','Prose',NULL),
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Equal Pay Day','https://en.wikipedia.org/wiki/Equal_Pay_Day','2016-04-26',24,'Feminism','Prose',NULL),
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Form 1099-K','https://en.wikipedia.org/wiki/Form_1099-K','2016-08-23',50,'United States taxation','Prose',NULL),
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Form 1099-R','https://en.wikipedia.org/wiki/Form_1099-R','2016-08-29',50,'United States taxation','Prose',NULL),
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Vote pairing in the United States presidential election, 2016','https://en.wikipedia.org/wiki/Vote_pairing_in_the_United_States_presidential_election,_2016','2016-11-02',105,'United States politics','Prose',NULL);

insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of cholera', 'https://en.wikipedia.org/wiki/Timeline_of_cholera','2016-04-23',100,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of malaria', 'https://en.wikipedia.org/wiki/Timeline_of_malaria','2016-04-27',200,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of senescence research', 'https://en.wikipedia.org/wiki/Timeline_of_senescence_research','2016-05-09',100,'Frontier health/speculative','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Rockefeller Sanitary Commission', 'https://en.wikipedia.org/wiki/Rockefeller_Sanitary_Commission','2016-05-11',30,'Global health/oranizations','Prose', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in China', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_China','2016-05-17',160,'Country healthcare','Timeline',NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in India', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_India', '2016-05-22',131,'Country healthcare','Timeline',NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of influenza', 'https://en.wikipedia.org/wiki/Timeline_of_influenza','2016-05-26',125,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Japan', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Japan','2016-05-28',135,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Cuba', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Cuba','2016-07-10',105,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Kenya', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Kenya','2016-07-18',80,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Kenya', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Kenya','2016-07-18',80,'Country healthcare','Timeline', NULL),

# -- Ethan Bashkansky's other work
  ('Ethan Bashkansky', 'Wikipedia', 'Miscellaneous Wikipedia work', 'N/A', 'N/A', '2016-09-07', 120, 'Miscellaneous', 'Prose','Ethan went on a page creation spree and sought rewards for creatin broadly relevant pages'),
  ('Ethan Bashkansky', 'Wikipedia', 'Attempted Wikipedia work', 'De minimis fringe benefit', 'https://en.wikipedia.org/wiki/De_minimis_fringe_benefit',5,'United States taxation','Prose','The page already existed')
