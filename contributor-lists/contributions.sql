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
  ('Sebastian Sanchez','Wikipedia','Wikipedia page translation', 'Dolor en los animales', 'https://es.wikipedia.org/wiki/Dolor_en_los_animales','2016-04-21',100,'Animal welfare','Translation', 'Source: Pain in animals (English Wikipedia)'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of cholera', 'https://en.wikipedia.org/wiki/Timeline_of_cholera','2016-04-23',100,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of malaria', 'https://en.wikipedia.org/wiki/Timeline_of_malaria','2016-04-27',200,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of senescence research', 'https://en.wikipedia.org/wiki/Timeline_of_senescence_research','2016-05-09',100,'Frontier health/speculative','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Rockefeller Sanitary Commission', 'https://en.wikipedia.org/wiki/Rockefeller_Sanitary_Commission','2016-05-11',30,'Global health/oranizations','Prose', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in China', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_China','2016-05-17',160,'Country healthcare','Timeline','85 for original article, 75 for updates'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in India', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_India', '2016-05-22',131,'Country healthcare','Timeline','95 for original article, 30 for updates in late May 2016, 6 for updates 2016-09-26'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of influenza', 'https://en.wikipedia.org/wiki/Timeline_of_influenza','2016-05-26',125,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Japan', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Japan','2016-05-28',135,'Country healthcare','Timeline', '100 for original article, 35 for updates'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Cuba', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Cuba','2016-07-10',105,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Kenya', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Kenya','2016-07-18',80,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Germany', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Germany','2016-07-21',110,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Egypt', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Egypt','2016-07-22',80,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Nigeria', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Nigeria','2016-07-27',80,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of cardiovascular disease', 'https://en.wikipedia.org/wiki/Timeline_ocardiovascular_disease','2016-08-01',140,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of stroke', 'https://en.wikipedia.org/wiki/Timeline_of_stroke','2016-08-05',75,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', "Timeline of Alzheimer's disease",#-- '
  'https://en.wikipedia.org/wiki/Timeline_of_Alzheimer%27s_disease','2016-08-13',75,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of melanoma', 'https://en.wikipedia.org/wiki/Timeline_of_melanoma','2016-08-16',60,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of leukemia', 'https://en.wikipedia.org/wiki/Timeline_of_leukemia','2016-08-20',70,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Klerokinesis', 'https://en.wikipedia.org/wiki/Klerokinesis','2016-08-20',20,'Biology','Prose', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of lymphoma', 'https://en.wikipedia.org/wiki/Timeline_of_lymphoma','2016-08-27',70,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of lung cancer', 'https://en.wikipedia.org/wiki/Timeline_of_lung_cancer','2016-08-28',65,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of brain cancer', 'https://en.wikipedia.org/wiki/Timeline_of_brain_cancer','2016-09-01',82,'Global health/diseases','Timeline', '65 for original work, 17 for updates finished 2016-09-12'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of tuberculosis', 'https://en.wikipedia.org/wiki/Timeline_of_tuberculosis','2016-09-08',90,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of kidney cancer', 'https://en.wikipedia.org/wiki/Timeline_of_kidney_cancer','2016-09-11',55,'Global health/diseases','Timeline', '50 for initial version, 5 for updates published 2016-09-26'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of colorectal cancer', 'https://en.wikipedia.org/wiki/Timeline_of_colorectal_cancer','2016-09-12',58,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of pancreatic cancer', 'https://en.wikipedia.org/wiki/Timeline_of_pancreatic_cancer','2016-09-18',60,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of cervical cancer', 'https://en.wikipedia.org/wiki/Timeline_of_cervical_cancer','2016-09-19',45,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of hospitals', 'https://en.wikipedia.org/wiki/Timeline_of_hospitals','2016-09-25',160,'Health systems','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of liver cancer', 'https://en.wikipedia.org/wiki/Timeline_of_liver_cancer','2016-10-01',49,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of bladder cancer', 'https://en.wikipedia.org/wiki/Timeline_of_bladder_cancer','2016-10-01',45,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in South Africa', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_South_Africa','2016-10-10',75,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Ethiopia', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Ethiopia','2016-10-17',55,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in France', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_France','2016-10-22',110,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Italy', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Italy','2016-10-26',110,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Russia', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Russia','2016-11-07',110,'Country healthcare','Timeline', 'Published to main space 2016-10-31, finalized and payment added 2016-11-07'),

# -- Adrian Ulloa page creation
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Adrian Ulloa','Wikipedia', 'Wikipedia page creation', 'Waitlist Zero', )
# -- Avi Glozman page creation
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Avi Glozman', 'Wikipedia', 'Wikipedia page creation', 'Silicon Valley Education Foundation', 'https://en.wikipedia.org/wiki/Silicon_Valley_Education_Foundation', '2016-06-05', 33, 'Philanthropy/foundations/education', 'Prose', NULL),
  ('Avi Glozman', 'Wikipedia', 'Wikipedia page creation', 'Screening Partnership Program', 'https://en.wikipedia.org/wiki/Screening_Partnership_Program', '2016-06-29', 53, 'United States government programs/Air travel', 'Prose', NULL),
  ('Avi Glozman', 'Wikipedia', 'Wikipedia page creation', 'Timeline of social media', 'https://en.wikipedia.org/wiki/Timeline_of_social_media', '2016-07-27', 155, 'Teechnology/general', 'Timeline', '140 for original, extra 15 for additions 2016-08-28'),
  ('Avi Glozman', 'Wikipedia', 'Wikipedia page creation', 'Timeline of e-commerce', 'https://en.wikipedia.org/wiki/Timeline_of_e-commerce', '2016-08-28', 175, 'Teechnology/general', 'Timeline', NULL),
  ('Avi Glozman', 'Wikipedia', 'Wikipedia page creation', 'Chicago Community Trust', 'https://en.wikipedia.org/wiki/Chicago_Community_Trust', '2016-10-21', 33, 'Philanthropy/foundations', 'Prose', NULL);

# -- Charlie Corner page creation
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Charlie Corner','Wikipedia','Wikipedia page creation','Form 1098-T','https://en.wikipedia.org/wiki/Form_1098-T','2016-07-10',50,'United States taxation','Prose',NULL),
  ('Charlie Corner','Wikipedia','Wikipedia page creation','Adora Cheung','https://en.wikipedia.org/wiki/Adora_Cheung','2016-08-04',32,'Technology/influential people','Prose',NULL),
  ('Charlie Corner','Wikipedia','Wikipedia page creation','Fresh Fruit and Vegetable Program','https:/en.wikipedia.org/wiki/Fresh_Fruit_and_Vegetable_Program','2016-09-14',70,'United States welfare state','Prose',NULL),
  
# -- Christopher Kunin page creation
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Christopher Kunin', 'Wikipedia','Wikipedia page creation','The Ethics of Voting','https://en.wikipedia.org/wiki/The_Ethics_of_Voting','2016-06-16',30,'Political philosophy/political science','Prose',NULL),
  ('Christopher Kunin', 'Wikipedia','Wikipedia page creation','Global Polio Eradication Initiative','https://en.wikipedia.org/wiki/Global_Polio_Eradication_Initiative','2016-06-21',35,'Global health/programs','Prose',NULL),
  ('Christopher Kunin', 'Wikipedia','Wikipedia page creation','The Entrepreneurial State','https://en.wikipedia.org/wiki/The_Entrepreneurial_State','2016-07-05',32,'Political philosophy/political science','Prose',NULL),
  ('Christopher Kunin', 'Wikipedia','Wikipedia page creation','Illiberal Reformers','https://en.wikipedia.org/wiki/Illiberal_Reformers','2016-08-17',35,'Political philosophy/political science','Prose',NULL),
  ('Christopher Kunin', 'Wikipedia','Wikipedia page creation','Stokes interview','https://en.wikipedia.org/wiki/Stokes_interview','2016-09-04',50,'United States migration','Prose',NULL),
  ('Christopher Kunin', 'Wikipedia','Wikipedia page creation','Scientific Charity Movement','https://en.wikipedia.org/wiki/Scientific_Charity_Movement','2016-10-10',35,'Philanthropy/philosophy','Prose',NULL);
  
# -- Devansh Dwivedy page creation
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Devansh Dwivedy','Wikipedia','Wikipedia page creation','Richard W. Boone','https://en.wikipedia.org/wiki/Richard_W._Boone','2016-06-29', 50, 'Philanthropy/influential people', 'Prose', NULL),
  ('Devansh Dwivedy','Wikipedia','Wikipedia page creation','Field Foundation of New York','https://en.wikipedia.org/wiki/Field_Foundation_of_New_York','2016-07-15', 30, 'Philanthropy/foundations', 'Prose', NULL),
  ('Devansh Dwivedy','Wikipedia','Wikipedia page creation','Global Outbreak Alert and Response Network','https://en.wikipedia.org/wiki/Global_Outbreak_Alert_and_Response_Network', 'Global health/organizations', 'Prose', NULL);
  
# -- Eddy Su page creation
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Eddy Su','Wikipedia','Wikipedia page creation','H-1C visa','https://en.wikipedia.org/wiki/H-1C_visa','2016-06-12',38,'United States migration', 'prose', NULL),
  ('Eddy Su','Wikipedia','Wikipedia page creation','H-1A visa','https://en.wikipedia.org/wiki/H-1A_visa','2016-06-13',33,'United States migration', 'prose', NULL),
  
  
# -- Ethan Bashkansky's other work
  ('Ethan Bashkansky', 'Wikipedia', 'Miscellaneous Wikipedia work', 'N/A', 'N/A', '2016-09-07', 120, 'Miscellaneous', 'Prose','Ethan went on a page creation spree and sought rewards for creatin broadly relevant pages'),
  ('Ethan Bashkansky', 'Wikipedia', 'Attempted Wikipedia work', 'De minimis fringe benefit', 'https://en.wikipedia.org/wiki/De_minimis_fringe_benefit',5,'United States taxation','Prose','The page already existed')
