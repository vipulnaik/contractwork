create table tasks(
  task_id int(11) not null auto_increment primary key, 
  worker varchar(40),
  task_venue enum('Wikipedia','Wikipedia Views','Effective Altruism Forum','LessWrong','Personal website','Wikimedia meta','wikiHow','Quora','Market subwiki','Donations list website', 'None') default 'Wikipedia',
  task_type enum('Wikipedia page creation','Wikipedia page update','Wikipedia page translation','Attempted Wikipedia work','Miscellaneous Wikipedia work','Preliminary research','Blog post or article','Survey creation','Survey recruitment','Coding','Consulting','Review','Wiki page creation','Wiki page update','Questions and answers','Contacting people','Data entry'),
  task_receptacle varchar(200) NOT NULL,
  task_receptacle_url varchar(200) NOT NULL,
  completion_date date NOT NULL,
  payment float(7,2) NOT NULL,
  topic varchar(100) NOT NULL,
  format varchar(100) NOT NULL,
  notes varchar(2000) DEFAULT NULL,
  private boolean DEFAULT false
) ENGINE=InnoDB AUTO_INCREMENT=15239276 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

# -- Milo King's Wikipedia page updates
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Milo King', 'Wikipedia', 'Wikipedia page update','Premium Processing Service','https://en.wikipedia.org/wiki/Premium_Processing_Service','2016-03-12',5,'United States migration','Prose','Added section on non-profit ability to use the old system of discretionary expedite requests, with citation');

# -- Milo King's Market work
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Milo King', 'Market subwiki', 'Wiki page update','Multiple pages','http://market.subwiki.org','2016-07-24',200,'Economics','Prose with tables','Summer project to improve coverage of monopoly cases for sales tax, price ceilings, etc. Did not get as far as originally hoped, but provided a good start for Vipul to continue');



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

# -- Sebastian Sanchez's Wikipedia page creation work
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
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of brain cancer', 'https://en.wikipedia.org/wiki/Timeline_of_brain_cancer','2016-09-01',82,'Global health/diseases','Timeline', '55 for original work, 27 for updates finished 2016-09-12'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of tuberculosis', 'https://en.wikipedia.org/wiki/Timeline_of_tuberculosis','2016-09-08',90,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of kidney cancer', 'https://en.wikipedia.org/wiki/Timeline_of_kidney_cancer','2016-09-11',55,'Global health/diseases','Timeline', '50 for initial version, 5 for updates published 2016-09-26'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of colorectal cancer', 'https://en.wikipedia.org/wiki/Timeline_of_colorectal_cancer','2016-09-12',58,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of pancreatic cancer', 'https://en.wikipedia.org/wiki/Timeline_of_pancreatic_cancer','2016-09-18',60,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of cervical cancer', 'https://en.wikipedia.org/wiki/Timeline_of_cervical_cancer','2016-09-19',45,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of hospitals', 'https://en.wikipedia.org/wiki/Timeline_of_hospitals','2016-09-25',160,'Health systems','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of liver cancer', 'https://en.wikipedia.org/wiki/Timeline_of_liver_cancer','2016-10-01',49,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of bladder cancer', 'https://en.wikipedia.org/wiki/Timeline_of_bladder_cancer','2016-10-01',47,'Global health/diseases','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in South Africa', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_South_Africa','2016-10-10',75,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in the Democratic Republic of the Congo', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_the_Democratic_Republic_of_the_Congo','2016-10-13',40,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Ethiopia', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Ethiopia','2016-10-17',55,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in France', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_France','2016-10-22',110,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Italy', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Italy','2016-10-26',110,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in Russia', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Russia','2016-11-07',110,'Country healthcare','Timeline', 'Published to main space 2016-10-31, finalized and payment added 2016-11-07'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Schedula Romana', 'https://en.wikipedia.org/wiki/Schedula_Romana', '2016-11-30', 13, 'History of medicine/health/malaria', 'Prose', 'One of the auxiliary articles for timeline of malaria'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation', 'Timeline of healthcare in the United Kingdom', 'https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_the_United_Kingdom','2016-12-05',140,'Country healthcare','Timeline', NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation','Global Initiative for Traditional Systems of Health', 'https://en.wikipedia.org/wiki/Global_Initiative_for_Traditional_Systems_of_Health','2016-12-05',38,'Miscellaneous global health','Prose','Page created 2016-11-30, finalized pay on 2016-12-05'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation','Mario Pinotti','https://en.wikipedia.org/wiki/Mario_Pinotti','2016-12-09',20,'Miscellaneous global health/malaria','Prose','Part of the malaria-related page cluster'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation','Therapeutice Specialis ad Febres Periodicas Perniciosas','https://en.wikipedia.org/wiki/Therapeutice_Specialis_ad_Febres_Periodicas_Perniciosas','2016-12-28',25,'Miscellaneous global health/malaria','Prose','Part of the malaria-related page cluster'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation','European Virtual Institute for Malaria Research','https://en.wikipedia.org/wiki/European_Virtual_Institute_for_Malaria_Research','2016-12-29',35,'Miscellaneous global health/malaria','Prose','Part of the malaria-related page cluster. Page was originally published on 2016-12-28 and finalized on 2016-12-29'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation','Timeline of measles','https://en.wikipedia.org/wiki/Timeline_of_measles','2017-01-09',125,'Global health/diseases','Timeline',NULL),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page creation','Timeline of poliomyelitis','https://en.wikipedia.org/wiki/Timeline_of_poliomyelitis','2017-01-14',130,'Global health/diseases','Timeline',NULL);

# -- Adrian Ulloa page creation
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Adrian Ulloa','Wikipedia', 'Wikipedia page creation', 'Waitlist Zero', 'https://en.wikipedia.org/wiki/Waitlist_Zero', '2016-08-16', 35, 'Philanthropy/charity/organ donation','Prose', NULL),
  ('Adrian Ulloa','Wikipedia', 'Wikipedia page creation', 'Commodity Supplemental Food Program', 'https://en.wikipedia.org/wiki/Commodity_Suppplemental_Food_Program', '2016-08-24', 70, 'United States welfare state', 'Prose', NULL),
  ('Adrian Ulloa','Wikipedia', 'Wikipedia page creation', 'Robert Wilensky', 'https://en.wikipedia.org/wiki/Robert_Wilensky', '2016-09-06', 20, 'Computer science/Artiicial intelligence/influential people','Prose','Worker-initiated page creation'),
  ('Adrian Ulloa','Wikipedia', 'Wikipedia page creation', 'Timeline of optical character recognition', 'https://en.wikipedia.org/wiki/Timeline_of_optical_character_recognition', '2016-09-22', 60, 'Artificial intelligence/Machine learning','Timeline', NULL),
  ('Adrian Ulloa','Wikipedia', 'Wikipedia page creation', 'Seth Baum', 'https://en.wikipedia.org/wiki/Seth_Baum', '2016-10-19', 20, 'Artificial intelligence/Existential risk/Influential people','Prose','Worker-initiated page creation');
  


  
# -- Avi Glozman page creation
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Avi Glozman', 'Wikipedia', 'Wikipedia page creation', 'Silicon Valley Education Foundation', 'https://en.wikipedia.org/wiki/Silicon_Valley_Education_Foundation', '2016-06-05', 33, 'Philanthropy/foundations/education', 'Prose', NULL),
  ('Avi Glozman', 'Wikipedia', 'Wikipedia page creation', 'Screening Partnership Program', 'https://en.wikipedia.org/wiki/Screening_Partnership_Program', '2016-06-29', 53, 'United States government programs/Air travel', 'Prose', NULL),
  ('Avi Glozman', 'Wikipedia', 'Wikipedia page creation', 'Timeline of social media', 'https://en.wikipedia.org/wiki/Timeline_of_social_media', '2016-07-27', 155, 'Technology/general', 'Timeline', '140 for original, extra 15 for additions 2016-08-28'),
  ('Avi Glozman', 'Wikipedia', 'Wikipedia page creation', 'Timeline of e-commerce', 'https://en.wikipedia.org/wiki/Timeline_of_e-commerce', '2016-08-28', 175, 'Technology/general', 'Timeline', NULL),
  ('Avi Glozman', 'Wikipedia', 'Wikipedia page creation', 'Chicago Community Trust', 'https://en.wikipedia.org/wiki/Chicago_Community_Trust', '2016-10-21', 33, 'Philanthropy/foundations', 'Prose', NULL);

# -- Charlie Corner page creation
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Charlie Corner','Wikipedia','Wikipedia page creation','Form 1098-T','https://en.wikipedia.org/wiki/Form_1098-T','2016-07-10',50,'United States taxation','Prose',NULL),
  ('Charlie Corner','Wikipedia','Wikipedia page creation','Adora Cheung','https://en.wikipedia.org/wiki/Adora_Cheung','2016-08-04',32,'Technology/influential people','Prose',NULL),
  ('Charlie Corner','Wikipedia','Wikipedia page creation','Fresh Fruit and Vegetable Program','https:/en.wikipedia.org/wiki/Fresh_Fruit_and_Vegetable_Program','2016-09-14',70,'United States welfare state','Prose',NULL),
  ('Charlie Corner','Wikipedia','Wikipedia page creation','Form 1023','https://en.wikipedia.org/wiki/Form_1023','2017-01-23',50,'United States taxation/Nonprofit','Prose',NULL);
  
# -- Christopher Kunin page creation
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Christopher Kunin', 'Wikipedia','Wikipedia page creation','The Ethics of Voting','https://en.wikipedia.org/wiki/The_Ethics_of_Voting','2016-06-16',30,'Political philosophy/political science','Prose',NULL),
  ('Christopher Kunin', 'Wikipedia','Wikipedia page creation','Global Polio Eradication Initiative','https://en.wikipedia.org/wiki/Global_Polio_Eradication_Initiative','2016-06-21',35,'Global health/programs','Prose',NULL),
  ('Christopher Kunin', 'Wikipedia','Wikipedia page creation','The Entrepreneurial State','https://en.wikipedia.org/wiki/The_Entrepreneurial_State','2016-07-05',32,'Political philosophy/political science','Prose',NULL),
  ('Christopher Kunin', 'Wikipedia','Wikipedia page creation','Illiberal Reformers','https://en.wikipedia.org/wiki/Illiberal_Reformers','2016-08-17',35,'Political philosophy/political science','Prose',NULL),
  ('Christopher Kunin', 'Wikipedia','Wikipedia page creation','Stokes interview','https://en.wikipedia.org/wiki/Stokes_interview','2016-09-04',50,'United States migration','Prose',NULL),
  ('Christopher Kunin', 'Wikipedia','Wikipedia page creation','Scientific Charity Movement','https://en.wikipedia.org/wiki/Scientific_Charity_Movement','2016-10-10',35,'Philanthropy/philosophy','Prose',NULL);

# -- Daniel Alejandro Maidana page creation

insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Daniel Alejandro Maidana', 'Wikipedia','Wikipedia page creation','Global Programme on AIDS','https://en.wikipedia.org/wiki/User:DanielMB/Global_programme_on_AIDS','2016-10-25',30,'Global health/program','Prose','Daniel finished userspace draft but as of 2016-12-14 the article has not been cleaned and ported to main space. Cleaning and porting is on Vipul.');

# -- Devansh Dwivedy page creation
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Devansh Dwivedy','Wikipedia','Wikipedia page creation','Richard W. Boone','https://en.wikipedia.org/wiki/Richard_W._Boone','2016-06-29', 50, 'Philanthropy/influential people', 'Prose', NULL),
  ('Devansh Dwivedy','Wikipedia','Wikipedia page creation','Field Foundation of New York','https://en.wikipedia.org/wiki/Field_Foundation_of_New_York','2016-07-15', 30, 'Philanthropy/foundations', 'Prose', NULL),
  ('Devansh Dwivedy','Wikipedia','Wikipedia page creation','Global Outbreak Alert and Response Network','https://en.wikipedia.org/wiki/Global_Outbreak_Alert_and_Response_Network', '2016-11-06', 45, 'Global health/organizations', 'Prose', NULL);
  
# -- Eddy Su page creation
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Eddy Su','Wikipedia','Wikipedia page creation','H-1C visa','https://en.wikipedia.org/wiki/H-1C_visa','2016-06-12',38,'United States migration', 'Prose', NULL),
  ('Eddy Su','Wikipedia','Wikipedia page creation','H-1A visa','https://en.wikipedia.org/wiki/H-1A_visa','2016-06-13',33,'United States migration', 'Prose', NULL);

# -- Issa Rice page creation
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  # -- 2015 page creation
  ('Issa Rice','Wikipedia','Wikipedia page creation','Form 1040','https://en.wikipedia.org/wiki/Form_1040','2015-12-31',400,'United States taxation','Prose','Although mostly completed by 2015-12-31, the article was published to main space on 2016-01-01. Payment, however, is considered to be for the 2015 tax year.'),
  # -- 2016 page creation
  ('Issa Rice','Wikipedia','Wikipedia page creation','Green Card Test','https://en.wikipedia.org/wiki/Green_Card_Test','2016-01-05',25,'United States taxation/United States migration', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Triplebyte','https://en.wikipedia.org/wiki/User:Riceissa/Triplebyte','2016-06-04',31,'Technology/company','Prose','25 for initial work in January. 6 for later work in June and publication. Later deleted through AfD, userspace version survives'),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Form 1099','https://en.wikipedia.org/wiki/Form_1099','2016-01-11',50,'United States taxation', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Form 1099-MISC','https://en.wikipedia.org/wiki/Form_1099-MISC','2016-01-21',100,'United States taxation', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Form W-9','https://en.wikipedia.org/wiki/Form_W-9','2016-01-23',50,'United States taxation', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Form 1096','https://en.wikipedia.org/wiki/Form_1096','2016-01-25',25,'United States taxation', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Form W-2','https://en.wikipedia.org/wiki/Form_W-2','2016-01-28',100,'United States taxation', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Form 990','https://en.wikipedia.org/wiki/Form_990','2016-02-03',100,'United States taxation/Philanthropy/Nonprofit evaluation', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Form I-140','https://en.wikipedia.org/wiki/Form_I-140','2016-03-04',168,'United States migration', 'Prose', '150 for original, 18 for miscellaneous improvements'),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Open Philanthropy Project','https://en.wikipedia.org/wiki/Open_Philanthropy_Project','2016-03-22',100,'Philanthropy/Foundations', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Timeline of global health','https://en.wikipedia.org/wiki/Timeline_of_global_health','2016-04-14',190,'Global health', 'Timeline', '170 for work + 20 completion bonus'),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Timeline of deworming','https://en.wikipedia.org/wiki/Timeline_of_deworming','2016-04-24',115,'Global health/diseases', 'Timeline', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Timeline of nonprofit evaluation','https://en.wikipedia.org/wiki/Timeline_of_nonprofit_evaluation','2016-04-30',105,'Philanthropy/Nonprofit evaluation', 'Timeline', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','3 by 5 Initiative','https://en.wikipedia.org/wiki/3_by_5_Initiative','2016-05-02',30,'Global health/organizations', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Innovative Vector Control Consortium','https://en.wikipedia.org/wiki/Innovative_Vector_Control_Consortium','2016-05-04',35,'Global health/organizations', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation',"The State of the World's Children", # -- '
  'https://en.wikipedia.org/wiki/The_State_of_the_World%27s_Children','2016-05-04',30,'Global health/events', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Child survival revolution','https://en.wikipedia.org/wiki/Child_survival_revolution','2016-05-11',101,'Global health/trends', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Participatory poverty assessment','https://en.wikipedia.org/wiki/Participatory_poverty_assessment','2016-05-17',63,'Poverty studies', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Voices of the Poor','https://en.wikipedia.org/wiki/Voices_of_the_Poor','2016-05-18',39,'Poverty studies', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','International Decision Support Initiative','https://en.wikipedia.org/wiki/International_Decision_Support_Initiative','2016-06-07',39,'Global health/organizations', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Amanda Glassman','https://en.wikipedia.org/wiki/Amanda_Glassman','2016-06-08',32,'Global health/influential people', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Health systems strengthening','https://en.wikipedia.org/wiki/Health_systems_strengthening','2016-06-17',43,'Health systems/Global health', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Professional consensus of economics','https://en.wikipedia.org/wiki/Professional_consensus_of_economics', '2016-07-10',67,'Economics', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Priority-setting in global health','https://en.wikipedia.org/wiki/Priority-setting_in_global_health','2016-07-27',155,'Health systems/Global health', 'Prose', NULL),
  ('Issa Rice','Wikipedia','Wikipedia page creation','Initiative on Global Markets','https://en.wikipedia.org/wiki/Initiative_on_Global_Markets', '2016-10-05',30,'Economics', 'Prose', NULL),
  # -- 2017 payments
  ('Issa Rice','Wikipedia','Wikipedia page creation','Timeline of digital preservation','https://en.wikipedia.org/wiki/Timeline_of_digital_preservation', '2017-01-04', 90, 'Digital preservation','Timeline', 'There is still more to port over from https://en.wikipedia.org/wiki/User:Riceissa/Timeline_of_digital_preservation and additional payment will be added when the porting is complete');


# -- Jesse Clifton page creation
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Timeline of animal welfare and rights','https://en.wikipedia.org/wiki/Timeline_of_animal_welfare_and_rights','2016-04-25',150,'Animal welfare','Timeline', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in India','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_India','2016-04-26',100,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Timeline of animal welfare and rights in the United States','https://en.wikipedia.org/wiki/Timeline_of_animal_welfare_and_rights_in_the_United_States','2016-04-29',100,'Animal welfare by country','Timeline', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Timeline of animal welfare and rights in Europe','https://en.wikipedia.org/wiki/Timeline_of_animal_welfare_and_rights_in_Europe','2016-05-05',100,'Animal welfare','Timeline', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Malaysia','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Malaysia','2016-05-06',70,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Japan','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Japan','2016-05-08',60,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in South Korea','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_South_Korea','2016-05-10',60,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Brazil','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Brazil','2016-05-13',90,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Austria','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Austria','2016-06-01',60,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Canada','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Canada','2016-06-05',70,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Timeline of cellular agriculture','https://en.wikipedia.org/wiki/Timeline_of_cellular_agriculture','2016-06-08',50,'Animal welfare/New technology','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Global Animal Partnership','https://en.wikipedia.org/wiki/Global_Animal_Partnership','2016-06-20',30,'Animal welfare/charity','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in South Africa','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_South_Africa','2016-06-23',50,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Ethiopia','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Ethiopia','2016-06-23',55,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Indonesia','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Indonesia','2016-06-24',55,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Russia','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Russia','2016-06-24',60,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Albert Schweitzer Foundation for Our Contemporaries','https://en.wikipedia.org/wiki/Albert_Schweitzer_Foundation_for_Our_Contemporaries','2016-06-27',32,'Animal welfare/charity','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Iran','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Iran','2016-06-28',50,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Australia','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Australia','2016-07-08',70,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Mexico','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Mexico','2016-07-22',50,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Argentina','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Argentina','2016-07-26',45,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Sweden','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Sweden','2016-07-28',50,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Germany','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Germany','2016-07-30',60,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Spain','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Spain','2016-08-23',70,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in France','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_France','2016-09-06',70,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Denmark','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Denmark','2016-09-13',45,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in the Netherlands','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_the_Netherlands','2016-11-20',55,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Animal welfare and rights in Switzerland','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Switzerland','2016-11-20',60,'Animal welfare by country','Prose', NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page creation','Sentience Politics','https://en.wikipedia.org/wiki/Sentience_Politics','2017-01-08',40,'Animal welfare/charity','Prose','Topic and work were done on own initiative; payment covered as it is part of coverage of animal welfare orgs');

# -- Michael Royzen list
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Michael Royzen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of speech and voice recognition', 'https://en.wikipedia.org/wiki/Timeline_of_speech_and_voice_recognition', '2016-06-21', 50, 'Artificial intelligence/Computer science', 'Timeline', NULL);

# -- Sean Yu list
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Sean Yu', 'Wikipedia', 'Wikipedia page creation', 'Form 1120', 'https://en.wikipedia.org/wiki/Form_1120', '2016-06-24', 35, 'United States taxation', 'Prose', NULL);

# -- Sergey Yegorov list
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Sergey Yegorov', 'Wikipedia', 'Wikipedia page creation', 'Academic Training', 'https://en.wikipedia.org/wiki/Academic_Training', '2016-09-20', 150, 'United States migration/academia', 'Prose', NULL),
  ('Sergey Yegorov', 'Wikipedia', 'Wikipedia page creation', 'Food frequency questionnaire', 'https://en.wikipedia.org/wiki/Food_frequency_questionnaire', '2016-10-23', 28, 'Nutrition', 'Prose', NULL),
  ('Sergey Yegorov', 'Wikipedia', 'Miscellaneous Wikipedia work', 'WHO-CHOICE', 'https://en.wikipedia.org/wiki/WHO-CHOICE', '2016-12-24', 20, 'Global health/priority-setting', 'Prose', 'Initia work that would lead to final published article by Vipul Naik on 2017-01-21');
  
# -- Thomas Foster list
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Thomas Foster', 'Wikipedia', 'Wikipedia page creation', 'Timeline of machine learning', 'https://en.wikipedia.org/wiki/Timeline_of_machine_learning', '2016-06-16', 80, 'Artificial intelligence/Machine learning', 'Timeline', NULL),
  ('Thomas Foster', 'Wikipedia', 'Wikipedia page creation', 'Timeline of sovereign states in Oceania', 'https://en.wikipedia.org/wiki/Timeline_of_sovereign_states_in_Oceania', '2016-06-23', 25, 'Geography/history', 'Timeline', 'Worker-initiated page creation');

# -- Joey Malandra list
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Joey Malandra', 'Wikipedia', 'Wikipedia page creation', 'American Time Use Survey', 'https://en.wikipedia.org/wiki/American_Time_Use_Survey','2016-12-14',34,'Survey research','Prose',NULL),
  ('Joey Malandra', 'Wikipedia', 'Wikipedia page creation', 'Marlowe–Crowne Social Desirability Scale', 'https://en.wikipedia.org/wiki/Marlowe%E2%80%93Crowne_Social_Desirability_Scale','2016-12-24',30,'Survey research','Prose',NULL),
  ('Joey Malandra', 'Wikipedia', 'Wikipedia page creation', '24-hour diet recall', 'https://en.wikipedia.org/wiki/24-hour_diet_recall','2017-01-10',30,'Nutrition','Prose',NULL),
  ('Joey Malandra', 'Wikipedia', 'Wikipedia page creation', 'MalariaWorld', 'https://en.wikipedia.org/wiki/MalariaWorld','2017-01-26',28,'Global health/malaria','Prose',NULL);

# -- Alex K. Chen list

insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  # -- 2015 pages
  ('Alex K. Chen','Wikipedia','Wikipedia page creation','Parker Conrad','https://en.wikipedia.org/wiki/Parker_Conrad','2015-05-13',25,'Technology/influential people','Prose','Accidental/retroactive bounty -- page was created to decent quality so bounty awarded'),
  ('Alex K. Chen','Wikipedia','Wikipedia page creation','Timeline of Reddit','https://en.wikipedia.org/wiki/Timeline_of_Reddit','2015-05-30',60,'Technology/company','Timeline','First timeline and first major bounty'),
  ('Alex K. Chen','Wikipedia','Wikipedia page creation','Timeline of Uber','https://en.wikipedia.org/wiki/Timeline_of_Uber','2015-06-30',35,'Technology/company','Timeline','Originally created on 2015-06-01, fully expanded by 2015-06-30'),
  ('Alex K. Chen','Wikipedia','Wikipedia page creation','Timeline of Quora','https://en.wikipedia.org/wiki/Timeline_of_Quora','2015-07-01',25,'Technology/company','Timeline',NULL),
  ('Alex K. Chen','Wikipedia','Wikipedia page creation','Proof School','https://en.wikipedia.org/wiki/Proof_School','2015-07-30',25,'Education/school','Prose',NULL),
  ('Alex K. Chen','Wikipedia','Wikipedia page creation','Public Welfare Foundation','https://en.wikipedia.org/wiki/Public_Welfare_Foundation','2015-08-16',25,'Philanthropy/foundation','Prose','Page suggested by Issa Rice'),
  ('Alex K. Chen','Wikipedia','Wikipedia page creation','Inside Philanthropy','https://en.wikipedia.org/wiki/Inside_Philanthropy','2015-08-30',25,'Philanthropy/nonprofit evaluation/online publication','Prose','Page suggested by Issa Rice'),
  ('Alex K. Chen','Wikipedia','Wikipedia page creation',
   "Eroom's law", # -- '
   'https://en.wikipedia.org/wiki/Eroom%27s_law','2015-10-16',25,'Technology/trend','Prose','Created with capital L law but page later moved on 2016-10-07'),
  ('Alex K. Chen','Wikipedia','Wikipedia page creation','Timeline of Tesla Motors','https://en.wikipedia.org/wiki/Timeline_of_Tesla_Motors','2015-11-29',75,'Technology/company','Timeline','Page moved to main on 2015-11-13, but fully done on 2015-11-29'),
  ('Alex K. Chen','Wikipedia','Wikipedia page creation','Timeline of Square','https://en.wikipedia.org/wiki/Timeline_of_Square','2015-11-29',200,'Technology/company','Timeline','Extra large bounty because of timelineness due to recent IPO'),
  ('Alex K. Chen','Wikipedia','Wikipedia page creation','Project Healthy Children','https://en.wikipedia.org/wiki/Project_Healthy_Children','2015-11-28',25,'Philanthropy/nonprofit evaluation','Prose',NULL),
  ('Alex K. Chen','Wikipedia','Wikipedia page creation','The Humane League','https://en.wikipedia.org/wiki/The_Humane_League','2015-11-30',20,'Animal welfare/organizations','Prose',NULL),
  # -- 2016 pages
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of online food delivery', 'https://en.wikipedia.org/wiki/Online_food_ordering#Timeline_of_online_food_delivery', '2016-01-10',55,'Technology/trends','Timeline','50 for initial page, 5 for adding stuff. Page was deleted and moved to the online food ordering page, with a redirect'),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of Amazon.com', 'https://en.wikipedia.org/wiki/Timeline_of_Amazon.com', '2016-01-17',250,'Technology/company','Timeline',NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of Microsoft', 'https://en.wikipedia.org/wiki/Timeline_of_Microsoft', '2016-01-25', 128, 'Technology/company', 'Timeline', '125 for original, 3 for adding acquisition of LinkedIn'),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of Intel', 'https://en.wikipedia.org/wiki/Timeline_of_Intel', '2016-02-02',150,'Technology/company','Timeline',NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'CrunchFund', 'https://en.wikipedia.org/wiki/CrunchFund', '2016-02-08', 50, 'Technology/investor', 'Prose', NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Garry Tan', 'https://en.wikipedia.org/wiki/Garry_Tan', '2016-02-14', 50, 'Technology/investor/influential people', 'Prose', NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'M. G. Siegler', 'https://en.wikipedia.org/wiki/M._G._Siegler', '2016-02-14', 50, 'Technology/investor/influential people', 'Prose', NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Paige Craig', 'https://en.wikipedia.org/wiki/Paige_Craig', '2016-02-27', 57, 'Technology/investor/influential people', 'Prose', '50 for initial work, 7 for updates'),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Scott Stanford (investor)', 'https://en.wikipedia.org/wiki/Scott_Stanford_(investor)', '2016-03-07', 50, 'Technology/investor/influential people', 'Prose', 'Page currently nominated for deletion'),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Initialized Capital', 'https://en.wikipedia.org/wiki/Initialized_Capital', '2016-03-14', 50, 'Technology/investor', 'Prose', NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Data Collective', 'https://en.wikipedia.org/wiki/Data_Collective', '2016-03-14', 50, 'Technology/investor', 'Prose', NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Matthew Emerton', 'https://en.wikipedia.org/wiki/Matthew_Emerton', '2016-03-14', 15, 'Mathematics/research/influential people', 'Prose', NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Uri Simonsohn', 'https://en.wikipedia.org/wiki/Uri_Simonsohn', '2016-04-02', 25, 'Statistics/research/influential people', 'Prose', NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Thomas C. Leonard', 'https://en.wikipedia.org/wiki/Thomas_C._Leonard', '2016-04-11', 25, 'Influential people', 'Prose', NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of Instagram', 'https://en.wikipedia.org/wiki/Timeline_of_Instagram', '2016-04-16',100,'Technology/company','Timeline',NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of LinkedIn', 'https://en.wikipedia.org/wiki/Timeline_of_LinkedIn', '2016-04-20',81,'Technology/company','Timeline','75 for initial work, 6 for updates'),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of Dropbox', 'https://en.wikipedia.org/wiki/Timeline_of_Dropbox', '2016-04-27',75,'Technology/company','Timeline',NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Coatue Management', 'https://en.wikipedia.org/wiki/Coatue_Management', '2016-05-07', 35, 'Technology/investor', 'Prose', NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Maverick Capital', 'https://en.wikipedia.org/wiki/Maverick_Capital', '2016-05-16', 35, 'Technology/investor', 'Prose', NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of Netflix', 'https://en.wikipedia.org/wiki/Timeline_of_Netflix', '2016-05-21', 135,'Technology/company','Timeline',NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of WhatsApp', 'https://en.wikipedia.org/wiki/Timeline_of_WhatsApp', '2016-05-31',120,'Technology/company','Timeline',NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of Xiaomi', 'https://en.wikipedia.org/wiki/Timeline_of_Xiaomi', '2016-06-12',75,'Technology/company','Timeline',NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of Amazon Web Services', 'https://en.wikipedia.org/wiki/Timeline_of_Amazon_Web_Services', '2016-06-15',95,'Technology/company','Timeline',NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of Twitch.tv', 'https://en.wikipedia.org/wiki/Timeline_of_Twitch.tv', '2016-06-20',40,'Technology/company','Timeline',NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of Lyft', 'https://en.wikipedia.org/wiki/Timeline_of_Lyft', '2016-06-29',40,'Technology/company','Timeline',NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of Nordstrom', 'https://en.wikipedia.org/wiki/Timeline_of_Nordstrom', '2016-07-01',75,'Retail/company','Timeline','50 for page, 25 for getting started on retail timeline'),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of online video', 'https://en.wikipedia.org/wiki/Timeline_of_online_video', '2016-07-27',175,'Technology/trends','Timeline',NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of Valve Corporation', 'https://en.wikipedia.org/wiki/User:Simfish/Timeline_of_Valve_Corporation', '2016-08-09',75,'Technology/company','Timeline',NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Timeline of Monsanto', 'https://en.wikipedia.org/wiki/Timeline_of_Monsanto', '2016-08-15',80,'Biotechnology/company','Timeline',NULL),
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page creation', 'Michael Seibel', 'https://en.wikipedia.org/wiki/Michael_Seibel', '2016-09-25',50,'Technology/investor/influential people','Prose',NULL); 

# -- Ethan Bashkansky's other work
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Ethan Bashkansky', 'Wikipedia', 'Miscellaneous Wikipedia work', 'N/A', 'N/A', '2016-09-07', 120, 'Miscellaneous', 'Prose','Ethan went on a page creation spree and sought rewards for creating broadly relevant pages'),
  ('Ethan Bashkansky', 'Wikipedia', 'Attempted Wikipedia work', 'De minimis fringe benefit', 'https://en.wikipedia.org/wiki/De_minimis_fringe_benefit','2016-04-26',5,'United States taxation','Prose','The page already existed'),
  ('Ethan Bashkansky', 'Wikipedia', 'Attempted Wikipedia work', 'Filing Information Returns Electronically', 'N/A','2016-04-26',5,'United States taxation','Prose','Decided against creating the page'),
  ('Ethan Bashkansky', 'None', 'Survey recruitment', 'Wikipedia use change over time', 'N/A', '2016-09-30',20.5, 'Wikipedia usage', 'Outreach', 'Got 41 responses from UW audience for 50 cents a response');

# -- Amy Zhang's other work
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Amy Zhang', 'Wikipedia', 'Wikipedia page update','Timeline of global health','https://en.wikipedia.org/wiki/Timeline_of_global_health','2016-06-26',80,'Global health', 'Timeline', 'Expanded existing events, added a few more, and revamped big picture');

# -- Alex K. Chen's other work

insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  # -- 2015 page updates
  ('Alex K. Chen','Wikipedia','Wikipedia page update','Timeline of Uber','https://en.wikipedia.org/wiki/Timeline_of_Uber','2015-07-17',3,'Technology/company','Timeline',NULL),
  ('Alex K. Chen','Wikipedia','Wikipedia page update','Timeline of Reddit','https://en.wikipedia.org/wiki/Timeline_of_Reddit','2015-07-04',3,'Technology/company','Timeline',NULL),
  # -- 2016 page updates
  ('Alex K. Chen', 'Wikipedia', 'Wikipedia page update', 'Many timeline pages', 'N/A', '2016-09-24',200,'Technology/company','Timeline','Work spread over a month, to avoid having other timelines meet the deletion fate of Timeline of Valve Corporation');

# -- Avi Glozman's other work
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Avi Glozman', 'Wikipedia', 'Wikipedia page update', 'Vote pairing in the United States presidential election, 2016','https://en.wikipedia.org/wiki/Vote_pairing_in_the_United_States_presidential_election,_2016','2016-11-03',27,'United States politics','Prose','Improved typology around vote pairing sites and added more references');

# -- Christopher Kunin's other work

insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Christopher Kunin','Wikipedia','Wikipedia page update','Privacy Impact Assessment','https://en.wikipedia.org/wiki/Privacy_Impact_Assessment','2016-07-29',45,'Government bureaucracy jargon','Prose','Originally intended to create the page, but somebody else made it, so added content into it');

# -- Jesse Clifton's other work

insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Jesse Clifton','Wikipedia','Wikipedia page update','Animal welfare in the United States','https://en.wikipedia.org/wiki/Animal_welfare_in_the_United_States','2016-05-08',60,'Animal welfare by country','Prose',NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page update','Animal welfare and rights in Israel','https://en.wikipedia.org/wiki/Animal_welfare_and_rights_in_Israel','2016-05-24',50,'Animal welfare by country','Prose',NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page update','The Humane League','https://en.wikipedia.org/wiki/The_Humane_League','2016-06-23',25,'Animal welfare/organizations','Prose',NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page update','Faunalytics','https://en.wikipedia.org/wiki/Faunalytics','2016-06-27',12,'Animal welfare/organizations','Prose',NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page update','The Good Food Institute','https://en.wikipedia.org/wiki/The_Good_Food_Institute','2016-11-24',10,'Animal welfare/organizations','Prose',NULL),
  ('Jesse Clifton','Effective Altruism Forum','Blog post or article','Scenarios for cellular agriculture','http://effective-altruism.com/ea/yu/scenarios_for_cellular_agriculture/','2016-06-20',200,'Animal welfare/Technology','Prose/Opinion',NULL),
  ('Jesse Clifton','Wikipedia','Wikipedia page update','The Humane League, Mercy for Animals,The Good Food Institute,...','N/A','2016-11-29',20,'Animal welfare/Animal Charity Evaluators/nonprofit evaluation','Prose','Updates to all ACE top charities and standouts with information on the latest ACE recommendation');

# -- Sean Yu's other work
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Sean Yu', 'Wikipedia', 'Wikipedia page update', 'Form 1040', 'https://en.wikipedia.org/wiki/Form_1040','2016-07-31',20,'United States taxation','Prose','Adding stuff on state taxes and controversies');

# -- Sebastian Sanchez's other work

insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Sebastian Sanchez','Wikipedia','Wikipedia page update','Cancer timelines','N/A','2016-08-28',5,'Global health/diseases','Timeline','Adding IARC to existing timelines'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page update','Timeline of malaria','https://en.wikipedia.org/wiki/Timeline_of_malaria','2016-12-06',185,'Global health/diseases','Timeline','Significant expansion of early history of malaria, also some recent events. And four graphs'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page update','Timeline of malaria','https://en.wikipedia.org/wiki/Timeline_of_malaria','2016-12-16',80,'Global health/diseases','Timeline','Cleanup, mainly focused on reference robustification'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page update','Timeline of cholera','https://en.wikipedia.org/wiki/Timeline_of_cholera','2016-12-19',160,'Global health/diseases','Timeline','Expansion, cleanup, and reference robustification'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page update','Timeline of malaria','https://en.wikipedia.org/wiki/Timeline_of_malaria','2016-12-22',10,'Global health/diseases','Timeline','Filling in missing geographic locations plus updating pictures data in Wikimedia Commons'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page update','Timeline of healthcare in China','https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_China','2016-12-23',55,'Country healthcare','Timeline','Reference robustification with focus on organizations'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page update','Timeline of healthcare in France','https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_France','2016-12-24',33,'Country healthcare','Timeline','Reference robustification with focus on organizations'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page update','Timeline of healthcare in Italy','https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Italy','2016-12-24',30,'Country healthcare','Timeline','Reference robustification with focus on organizations'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page update','Timeline of tuberculosis','https://en.wikipedia.org/wiki/Timeline_of_tuberculosis','2016-11-22',5,'Global health/diseases','Timeline','Graph added'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page update','Timeline of healthcare in India','https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_India','2016-12-31',27,'Country healthcare','Timeline','Reference robustification plus ten new hospitals added'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page update','Timeline of healthcare in Germany','https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Germany','2017-01-02',30,'Country healthcare','Timeline','Reference robustification'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page update','Timeline of healthcare in Japan','https://en.wikipedia.org/wiki/Timeline_of_healthcare_in_Japan','2017-01-02',35,'Country healthcare','Timeline','Reference robustification'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page update','Timeline of leukemia','https://en.wikipedia.org/wiki/Timeline_of_leukemia','2017-01-01',5,'Global health/diseases','Timeline','Graph added'),
  ('Sebastian Sanchez','Wikipedia','Wikipedia page update','Multiple timelines: healthcare in Japan, India, Germany, Ethiopia','N/A','2017-01-02',20,'Country healthcare','Timeline','Life expectancy graphs added');


# -- Issa Rice's Open Philanthropy Project periodic grant updates

insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Issa Rice','Wikipedia','Wikipedia page update','Open Philanthropy Project,Good Ventures','https://en.wikipedia.org/wiki/Open_Philanthropy_Project,https://en.wikipedia.org/wiki/Good_Ventures','2016-04-30',50,'Philanthropy/Grants','Table','April end grants update'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Open Philanthropy Project,Good Ventures','https://en.wikipedia.org/wiki/Open_Philanthropy_Project,https://en.wikipedia.org/wiki/Good_Ventures','2016-06-04',50,'Philanthropy/Grants','Table','May end grants update'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Open Philanthropy Project,Good Ventures','https://en.wikipedia.org/wiki/Open_Philanthropy_Project,https://en.wikipedia.org/wiki/Good_Ventures','2016-07-01',27,'Philanthropy/Grants','Table','June end grants update'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Open Philanthropy Project,Good Ventures','https://en.wikipedia.org/wiki/Open_Philanthropy_Project,https://en.wikipedia.org/wiki/Good_Ventures','2016-07-29',45,'Philanthropy/Grants','Table','July end grants update: 6 new grants + 2 delayed grants'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Open Philanthropy Project,Good Ventures','https://en.wikipedia.org/wiki/Open_Philanthropy_Project,https://en.wikipedia.org/wiki/Good_Ventures','2016-08-31',55,'Philanthropy/Grants','Table','August end grants update: 45 for 8 new grants and 10 for one-time extra work to deal with format changes'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Open Philanthropy Project,Good Ventures','https://en.wikipedia.org/wiki/Open_Philanthropy_Project,https://en.wikipedia.org/wiki/Good_Ventures','2016-09-29',50,'Philanthropy/Grants','Table','September end grants update: max 50; 8 grants to Open Phil, 12 grants to Good Ventures'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Open Philanthropy Project,Good Ventures','https://en.wikipedia.org/wiki/Open_Philanthropy_Project,https://en.wikipedia.org/wiki/Good_Ventures','2016-10-27',50,'Philanthropy/Grants','Table','October end grants update: max 50; 18 grants to Open Phil, 11 grants to Good Ventures'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Open Philanthropy Project,Good Ventures','https://en.wikipedia.org/wiki/Open_Philanthropy_Project,https://en.wikipedia.org/wiki/Good_Ventures','2016-11-30',50,'Philanthropy/Grants','Table','November end grants update: 4 grants to Open Phil (plus some manual work), 8 grants to Good Ventures, but 9 or more distinct grants, so pay >= 5 * 9 + 5, and also pay <= 50, so 50'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Open Philanthropy Project,Good Ventures','https://en.wikipedia.org/wiki/Open_Philanthropy_Project,https://en.wikipedia.org/wiki/Good_Ventures','2016-12-28',40,'Philanthropy/Grants','Table','December end grants update: 7 grants to Open Phil, 0 grants to Good Ventures, so pay = 5 * ( 1 + 7) = 40'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Open Philanthropy Project,Good Ventures','https://en.wikipedia.org/wiki/Open_Philanthropy_Project,https://en.wikipedia.org/wiki/Good_Ventures','2017-01-29',50,'Philanthropy/Grants','Table','January end grants update: 6 grants to Open Phil, 13 grants to Good Ventures, so pay = 50');

# -- Issa Rice's IATI grant updates

insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  ('Issa Rice','Wikipedia','Wikipedia page update','Bill & Melinda Gates Foundation','https://en.wikipedia.org/wiki/Bill_%26_Melinda_Gates_Foundation','2016-08-29',50,'Philanthropy/Grants/IATI','Table','IATI Gates Round 1'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Bill & Melinda Gates Foundation','https://en.wikipedia.org/wiki/Bill_%26_Melinda_Gates_Foundation','2016-09-01',40,'Philanthropy/Grants/IATI','Table','IATI Gates Round 2'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Bill & Melinda Gates Foundation','https://en.wikipedia.org/wiki/Bill_%26_Melinda_Gates_Foundation','2016-09-02',5,'Philanthropy/Grants/IATI','Table','IATI Gates Round 3: Clarifications'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Hewlett Foundation','https://en.wikipedia.org/wiki/Hewlett_Foundation','2016-09-02',40,'Philanthropy/Grants/IATI','Table',NULL),
  ('Issa Rice','Wikipedia','Wikipedia page update','Department for International Development','https://en.wikipedia.org/wiki/Department_for_International_Development','2016-09-03',30,'Philanthropy/Grants/IATI','Table',NULL),
  ('Issa Rice','Wikipedia','Wikipedia page update','World Bank','https://en.wikipedia.org/wiki/World_Bank','2016-09-04',30,'Philanthropy/Grants/IATI','Table',NULL),
  ('Issa Rice','Wikipedia','Wikipedia page update','United Nations Development Programme','https://en.wikipedia.org/wiki/United_Nations_Development_Programme','2016-09-04',30,'Philanthropy/Grants/IATI','Table',NULL),
  ('Issa Rice','Wikipedia','Attempted Wikipedia work','French Development Agency','https://en.wikipedia.org/wiki/French_Development_Agency','2016-09-05',10,'Philanthropy/Grants/IATI','Table','We decided not to publish as there was too little meaningful data'),
  ('Issa Rice','Wikipedia','Wikipedia page update','GAVI Alliance','https://en.wikipedia.org/wiki/GAVI_Alliance','2016-09-06',15,'Philanthropy/Grants/IATI','Table',NULL);
  
# -- Other payments to Issa Rice
insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values
  # -- Touch payments
  ('Issa Rice','None','Contacting people','N/A','N/A','2016-12-12',320,'Miscellaneous','Email','Total payment for reaching out to people with relevant questions, suggestions, and comments'),
  ('Issa Rice','None','Contacting people','N/A','N/A','2017-01-19',20,'Miscellaneous','Email','Total payment for reaching out to people with relevant questions, suggestions, and comments'),
  # -- 2015 payments
  ('Issa Rice','Wikipedia','Wikipedia page update','A Plus (aplus.com)','https://en.wikipedia.org/wiki/A_Plus_(aplus.com)','2015-04-05',20,'Media company','Prose','First Wikipedia article experience. Originally intended to create article, but it got created while this was in draft, so merged work in.'),
  ('Issa Rice','wikiHow','Wiki page creation','Archive Websites on Unix Like Systems','http://www.wikihow.com/Archive-Websites-on-Unix-Like-Systems','2015-09-22',300,'Digital preservation','Prose/How-to',NULL),
  ('Issa Rice','Effective Altruism Forum','Blog post or article',
   "An overview of Y Combinator's non-profit program", # -- '
   'http://effective-altruism.com/ea/pn/an_overview_of_y_combinators_nonprofit_program/','2015-11-07',250,'Philanthropy/nonprofit evaluation/effective altruism','Prose',NULL),
  ('Issa Rice','None','Preliminary research','N/A','N/A','2016-01-18',150,'United States taxation','Communication with Vipul','Investigated Form 1099 filing requirements. It later turned out that Form 1099 is not required since Vipul is not operating as an organization.'),
  ('Issa Rice','None','Consulting','N/A','N/A','2015-04-19',98,'No record','No record',NULL),
  ('Issa Rice','None','Consulting','N/A','N/A','2015-03-30',100,'Schooling/education','Communication with Vipul','Consulting on student notes websites'),
  ('Issa Rice','None','Consulting','N/A','N/A','2015-08-05',42,'No record','Communication with Vipul',NULL),
  ('Issa Rice','None','Consulting','N/A','N/A','2015-08-08',37,'No record','Communication with Vipul',NULL),
  ('Issa Rice','None','Consulting','N/A','N/A','2015-08-08',20,'Spam filtering','Communication with Vipul','Helped Vipul set up spam filters for Google Analytics accounts'),
  ('Issa Rice','None','Consulting','Quantcast data tabulation','N/A','2015-11-22',50,'Web analytics/Quantcast','Spreadsheet','Tabulated a bunch of data related to website Quantcast data. Some of this was later used in wikiHow articles by Vipul such as http://www.wikihow.com/Understand-Your-Website-Audience-Profile'),
  # -- 2016 payments
  ('Issa Rice','Wikipedia Views','Coding','pageviewQueries.inc','https://github.com/vipulnaik/wikipediaviews/blob/master/backend/pageviewQueries.inc','2016-01-31',80,'API integration','Code','Add ability to query Wikimedia API for pageviews'),
  ('Issa Rice','Wikipedia','Miscellaneous Wikipedia work','Animal Charity Evaluators','https://en.wikipedia.org/wiki/User:Riceissa/Animal_Charity_Evaluators','2016-03-18',20,'Animal welfare/nonprofit evaluation/Animal Charity Evaluators','Communication','Retrieved deleted page from admin and userfied it'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Disease Control Priorities Project','https://en.wikipedia.org/wiki/Disease_Control_Priorities_Project','2016-04-13',6,'Global health','Prose','Add years'),
  ('Issa Rice','None','Consulting','N/A','N/A','2016-04-16',25,'N/A','N/A',NULL),
  ('Issa Rice','Wikipedia','Attempted Wikipedia work','Timeline of mental health','https://en.wikipedia.org/wiki/Timeline_of_psychiatry','2016-04-26',10,'Global health/diseases/mental health','Timeline','Initial research into timeline of mental health; scrapped on seeing an existing timeline of psychiatry'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Disease Control Priorities Project','https://en.wikipedia.org/wiki/Disease_Control_Priorities_Project','2016-06-25',20,'Global health','Prose','Significant page restructuring, more info on specific reports'),
  ('Issa Rice','LessWrong','Survey creation','Wikipedia usage survey','http://lesswrong.com/lw/nru/wikipedia_usage_survey_results/','2016-05-31',70,'Wikipedia','Survey','Design of survey, buying responses, and preliminary analysis'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Against Malaria Foundation, GiveDirectly, and other GiveWell top charities','https://en.wikipedia.org/wiki/Against_Malaria_Foundation,https://en.wikipedia.org/wiki/GiveDirectly,others','2016-06-24',55,'Philanthropy/GiveWell/top charities','Prose','25 each for AMF and GiveDirectly, 5 for others'),
  ('Issa Rice','Personal website','Preliminary research','GiveWell finances and other stuff review','http://issarice.com/givewell-executive-compensation/,http://issarice.com/givewell-staff-growth/','2016-06-25',100,'Philanthropy/GiveWell/evaluation','Prose, tables, and charts',NULL),
  ('Issa Rice','Personal website','Blog post or article','Resolving issues with the IRS','http://issarice.com/resolving-issues-with-the-irs/','2016-07-01',100,'United States taxation/personal experience','Prose/Autobiography',NULL),
  ('Issa Rice','LessWrong','Blog post or article','Wikipedia usage survey results','http://lesswrong.com/lw/nru/wikipedia_usage_survey_results/','2016-07-14',110,'Wikipedia','Prose with tables','Finished writing up findings from survey conducted in late May'),
   ('Issa Rice','Wikipedia','Wikipedia page update','Privacy Impact Assessment','https://en.wikipedia.org/wiki/Privacy_Impact_Assessment','2016-08-07',5,'Government bureaucracy jargon','Prose',NULL),
  ('Issa Rice','Effective Altruism Forum','Blog post or article','June 2016 GiveWell board meeting','http://effective-altruism.com/ea/10l/june_2016_givewell_board_meeting/','2016-08-17',100,'Philanthropy/GiveWell/evaluation','Prose/transcript',NULL),
  ('Issa Rice','None','Coding','Model for estimating the value of a Wikipedia page','N/A','2016-08-29',40,'Wikipedia/Contract work','Code','Initial work piloted on a small subset of timelines, gives an estimate of the total money due based on attributes of the timeline'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Google Surveys','https://en.wikipedia.org/wiki/Google_Surveys','2016-09-30',32,'Survey tools','Prose with diagram','Expanded page, added references, explained and clarified model with diagram'),
  ('Issa Rice','Personal website','Blog post or article','GiveWell staff growth','http://issarice.com/givewell-staff-growth/','2016-10-01',10,'Philanthropy/GiveWell/evaluation','Prose with tables','Updated page to reflect separation of GiveWell and Open Phil staff listings'),
  ('Issa Rice','Wikipedia Views','Coding','graph.py','https://gist.github.com/riceissa/8726e6a90d4a7634f3dd79cc1fdb63d5,https://github.com/vipulnaik/wikipediaviews/blob/master/python/graph.py','2016-10-13',80,'Graphing','Code','Add graphing capabilities to Wikipedia Views'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Scientific Charity Movement','https://en.wikipedia.org/wiki/Scientific_Charity_Movement','2016-10-14',20,'Philanthropy/philosophy','Prose','Cleaned up and improved the page'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Hiroshi Nakajima','https://en.wikipedia.org/wiki/Hiroshi_Nakajima','2016-10-20',35,'Global health/influential people','Prose','The project was motivated by a Facebook post by Howie Lempel'),
  ('Issa Rice','Wikipedia Views','Coding','Wikipedia Clickstream','N/A','2016-11-04',130,'Wikipedia','Code','Processing of Wikipedia clickstream data set for use in Wikipedia Views. Successfully integrated in Wikipedia Views 2016-11-25'),
  ('Issa Rice','None','Preliminary research','N/A', 'N/A', '2016-11-15',80,'United States migration/Survey research','Code and structured data','Investigation into correlation between estimates of foreign-born and unauthorized population and state-level values of the population'),
  ('Issa Rice','Wikipedia Views','Coding','distrib.py','https://github.com/vipulnaik/wikipediaviews/blob/master/python/distrib.py','2016-11-19',40,'Wikipedia','Code','Code to show bar or line plot for distribution of Wikipedia pageviews'),
  ('Issa Rice','Wikipedia Views','Coding','Special pages','N/A','2016-11-20',40,'Wikipedia','Data dump','List of special pages in all language Wikipedias'),
  ('Issa Rice','Wikipedia Views','Coding','Help pages','N/A','2016-11-21',25,'Wikipedia','Data dump','List of help pages in all language Wikipedias'),
  ('Issa Rice','None','Coding','Backups','N/A','2016-11-28',100,'Wikipedia/Backup','Data dump','Setup for periodic backup of all important Wikipedia content for easy recoverability'),
  ('Issa Rice','Wikipedia','Wikipedia page update','GiveWell,GiveWell top charities (various pages)','https://en.wikipedia.org/wiki/GiveWell','2016-11-30',100,'Philanthropy/GiveWell/top charities','Prose with tables',NULL),
  ('Issa Rice','Wikimedia Meta','Wiki page update','Timeline of Wikimedia analytics','https://meta.wikimedia.org/wiki/Research:Timeline_of_Wikimedia_analytics','2016-11-30',10,'Wikipedia','Timeline','Timeline events on starting dates for availability of search metrics'),
  ('Issa Rice','wikiHow','Preliminary research','Optimize Your Amazon S3 Costs','http://www.wikihow.com/Optimize-Your-Amazon-S3-Costs','2016-12-03',170,'Amazon Web Services','Graphs and code','Investigated comparison of different cost plans by Amazon and when each one is optimal'),
  ('Issa Rice','LessWrong','Review','Wikipedia usage survey results', 'http://lesswrong.com/r/discussion/lw/odb/wikipedia_usage_survey_results/','2016-12-24',55,'Wikipedia','Prose with tables','Reviewed changes by Vipul, fixed a lot of rendering issues, and provided frank feedback on post'),
  ('Issa Rice','LessWrong','Preliminary research','Revisiting the great decline in Wikipedia pageviews','https://github.com/vipulnaik/working-drafts/blob/master/wikipediaviews/revisiting-the-great-decline-in-wikipedia-pageviews.md','2016-10-03',925,'Wikipedia','Prose with tables and charts and code','Started on it at ~$100/day pay, slowed down, then we realized a lot more toolkit improvements are needed before we can push out the post'),
  ('Issa Rice','Wikipedia Views','Coding','Tag entries in different languages','https://wikipediaviews.org','2016-10-04',150,'Wikipedia Views','Coding with data output','Wrote code to translate tags en masse to new languages. Code still exists, plan is now to incorporate into Wikipedia Views itself to avoid need to run separate code'),
  ('Issa Rice','None','Preliminary research','Researcher profiles','N/A as it was private work','2016-12-31',70,'Research strategy','Prose','Officially stopped project 2017-01-01 but part paid by Vipul was finished by 2016-12-31'),
  # -- 2017 payments
  ('Issa Rice','Donations list website','Data entry','Donations','https://donations.vipulnaik.com','2017-01-08',155,'Effective altruism/donation history','Structured data','Designed SQL tables and provided initial set of rows to insert'),
  ('Issa Rice','Effective Altruism Forum','Blog post or article','Essay contest: general considerations for evaluating small-scale giving opportunities ($300 for winning submission)','http://effective-altruism.com/ea/16e/essay_contest_general_considerations_for/','2017-01-19',50,'Effective altruism/contest/small-scale giving','Prose','Announced contest organized by Peter Hurford, Vipul Naik, and Issa Rice. Remaining $50 pay to be given after first serious submission'),
  ('Issa Rice','Wikipedia Views','Consulting','PHP/MySQL: Fixing utf8 text corrupted by implicit mysqli::set_charset(latin1) connection','https://stackoverflow.com/questions/39261867/php-mysql-fixing-utf8-text-corrupted-by-implicit-mysqliset-charsetlatin1','2017-01-25',20,'Character encoding issues','Private communication','Investigated character encoding issue, discovered relevant Stack Overflow question'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Timeline of global health','https://en.wikipedia.org/wiki/Timeline_of_global_health','2017-01-26',20,'Global health','Timeline','Fixed 11 dead links and added three new events (first two cholera pandemics, typhus epidemic)'),
  ('Issa Rice','Wikipedia','Wikipedia page update','Institute for Health Metrics and Evaluation','https://en.wikipedia.org/wiki/Institute_for_Health_Metrics_and_Evaluation','2017-01-28',14,'Global health','Prose','Added reception section and some minor reference fixes');
# -- insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptacle_url, completion_date, payment, topic, format, notes) values

