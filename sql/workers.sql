create table workers(
  worker_id int(11) not null auto_increment primary key,
  worker varchar(40) not null,
  country varchar(20) not null,
  wikipedia_username varchar(40),
  timelines_wiki_username varchar(40),
  facebook_username varchar(100),
  email_id varchar(40),
  website varchar(40),
  preferred_payment_method enum('Cash','Check','PayPal','Wire transfer','Western Union','Ethereum','Bitcoin') not null,
  recruiter enum('Vipul Naik','Issa Rice','Ethan Bashkansky','Linchuan Zhang','Alex K. Chen','Sebastian Sanchez') not null,
  contact_method enum('inbound email','inbound Facebook','outbound email','outbound Facebook','outbound in-person') not null,
  notes varchar(2000) default null,
  private boolean default false,
  twitter_username varchar(40),
  lesswrong_username varchar(40),
  eaf_username varchar(40),
  patreon_username varchar(40),
  predictionbook_username varchar(40),
  github_username varchar(40),
  linkedin_username varchar(40),
  worker_file varchar(100),
  worker_own_file varchar(100),
  unique key worker(`worker`)
) ENGINE=InnoDB AUTO_INCREMENT=15239276 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

insert into workers(worker, country, wikipedia_username, timelines_wiki_username, facebook_username, email_id, preferred_payment_method, recruiter, contact_method, notes, worker_file) values
  ('Amana Rice','United States',NULL,NULL,'omgitsmana',NULL,'PayPal','Issa Rice','outbound in-person','Amana Rice is the sister of Issa Rice, who recruited her based on that connection.','amana-list.mediawiki'),
  ('Mati Roy','Canada','Mati_Roy','Mati_Roy','mati.roy.09','contact@matiroy.com','PayPal','Issa Rice','inbound email','Mati started working on the timeline of cryonics after it was initially proposed to Orpheus Lummis, who has completed another timeline for Timelines Wiki','mati-roy-list.mediawiki'),
  ('Orpheus Lummis','Canada','Orpheus_Lummis','Orpheus_Lummis','orpheus.lummis','o@orpheuslummis.com','Ethereum','Issa Rice','inbound email','Started work on topics of interest to the worker','orpheus-lummis-list.mediawiki'),
  ('Milo King','United States','MiloJBKing',NULL,'milo.king','milo.j.king@gmail.com','PayPal','Vipul Naik','outbound Facebook','Did a bit of Wikipedia work in March and then a lot of work on the Market subwiki in the summer of 2016','milo-list.mediawiki'),
  ('Issa Rice','United States','Riceissa','Issa','riceissa','riceissa@gmail.com','PayPal','Vipul Naik','outbound Facebook','Been working sporadically since 2015; started working regularly since early 2016. Recruited other workers and also helps with managing workers and sprints.', 'issa-list.mediawiki'),
  ('Sebastian Sanchez','Argentina','Wikisanchez','Sebastian','seba.sanchez.3998','sebastian123sanchez@gmail.com','Bitcoin','Vipul Naik','inbound Facebook','Started work in April 2016. Took break in June 2016 for Japan visit. Worked on disease timelines, country healthcare timelines, and miscellaneous global health Wikipedia articles.','sebastian-sanchez-list.mediawiki'),
  ('Ethan Bashkansky','United States','Ethanbas','Ethanbas','ethan.bashkansky','ethanbas@gmail.com','PayPal','Issa Rice','outbound in-person','Did sporadic work in February, and has done sporadic work a few times since. Also recruits other workers and stays in touch.','ethan-list.mediawiki'),
  ('Adrian Ulloa','Peru','Physikite',NULL,'physikite','physikite@outlook.com','PayPal','Vipul Naik','inbound email','Did sporadic work in September of 2016.','adrian-list.mediawiki'),
  ('Avi Glozman','United States','Avigl',NULL,'avi.glozman','avi.glozman@gmail.com','PayPal','Ethan Bashkansky','outbound Facebook','Sporadic work since late May/early June 2016','avi-list.mediawiki'),
  ('Charlie Corner','United States','Churrupy',NULL,'charlie.corner.5','churrupy@gmail.com','PayPal','Linchuan Zhang','inbound Facebook','Sporadic work since late June/early July 2016','charlie-list.mediawiki'),
  ('Christopher Kunin','United States','ChristopherLKunin',NULL,'chris.kunin.5','Chris.kunin@me.com','PayPal','Ethan Bashkansky','outbound Facebook','Sporadic wok since June 2016','chris-list.mediawiki'),
  ('Devansh Dwivedy','United States','Dave8033',NULL,'devansh33','devarshi@yahoo.com','PayPal','Ethan Bashkansky','outbound Facebook','Sporadic work since June 2016. Note that PayPal belongs to his father','devansh-list.mediawiki'),
  ('Eddy Su','United States','Esu44224',NULL,'EddySu98008','esu44224@gmail.com','PayPal','Ethan Bashkansky','outbound Facebook','Made two Wikipedia articles in June 2016.','eddy-list.mediawiki'),
  ('Jesse Clifton','United States','JesseClifton',NULL,'jesse.clifton2','jclifton333@gmail.com','Check','Vipul Naik','inbound Facebook','Introduced by Jacy Reese; Jesse had done a project for Jacy at Animal Charity Evaluators and had a summer off','jesse-list.mediawiki'),
  ('Michael Royzen','United States','Rushingcreek',NULL,'michael.royzen','michael@mlabtechnologies.com','PayPal','Ethan Bashkansky','outbound Facebook','Wrote one article in June 2016 but could not work further as he wanted to spend more time on developing his app.','michael-list.mediawiki'),
  ('Sean Yu','United States','Majesticfish',NULL,'sean.yu.18','yusean1792@gmail.com','PayPal','Ethan Bashkansky','outbound Facebook','A little work on tax forms in July 2016.','sean-list.mediawiki'),
  ('Sergey Yegorov','Russia','Sergie_Marienhof',NULL,'avereflection','sashspecial@gmail.com','PayPal','Vipul Naik','inbound Facebook','Sporadic work since September 2016.','sergey-list.mediawiki'),
  ('Thomas Foster','Australia','Thomas_James_Foster',NULL,'thomasjamesfoster96','me@thomasfoster.co','PayPal','Alex K. Chen','outbound Facebook','Work in June 2016. Could not continue as school term started.','thomas-list.mediawiki'),
  ('Alex K. Chen','United States','Simfish','InquilineKea','simfish','simfish@gmail.com','PayPal','Vipul Naik','outbound email','Started working in April 2015 on a unique contract. Continued in 2016, slowed down in last quarter.','akc-list.mediawiki'),
  ('Amy Zhang','United States','Amy.zhang425',NULL,'amy.zhang.5855594','bluemoonamy@live.com','PayPal','Ethan Bashkansky','outbound Facebook','Did some work in June 2016 on timeline of global health. Discontinued work due to other obligations','amy-list.mediawiki'),
  ('Daniel Alejandro Maidana','Argentina','DanielMB',NULL,'danielalejandro.maidana.50','unknown','PayPal','Sebastian Sanchez','inbound Facebook','Started working in August but delays on both sides so first payment in December','daniel-list.mediawiki'),
  ('Linchuan Zhang','United States','N/A',NULL,'linchuan.zhang','unknown','PayPal','Vipul Naik','inbound Facebook','Not a worker, but helped recruit some workers','linchuan-list.mediawiki'),
  ('Joey Malandra','United States','Joeykai',NULL,'joey.malandra.73','joseph.malandra@gmail.com','PayPal','Ethan Bashkansky','outbound Facebook','Introduced to Ethan through a mutual friend Ethan met at the Envision Conference. Had 58K edits at the time.','joey-list.mediawiki');

# -- website lists
update workers set website='https://issarice.com' where worker = 'Issa Rice';
update workers set website='http://orpheuslummis.com/' where worker = 'Orpheus Lummis';

#-- LessWrong and EAF username lists
update workers set lesswrong_username='riceissa' where worker = 'Issa Rice';
update workers set eaf_username='riceissa' where worker = 'Issa Rice';
update workers set eaf_username='JesseClifton' where worker = 'Jesse Clifton';

# -- GitHub username lists
update workers set github_username='riceissa' where worker = 'Issa Rice';
update workers set github_username='aviglozman' where worker = 'Avi Glozman';
update workers set github_username='ethanbas' where worker = 'Ethan Bashkansky';
update workers set github_username='sebastiansanchez123' where worker = 'Sebastian Sanchez';
update workers set github_username='omgitsmana' where worker = 'Amana Rice';

# -- LinkedIn usernames
update workers set linkedin_username='issarice' where worker='Issa Rice';
update workers set linkedin_username='ethan-bashkansky-56166766' where worker='Ethan Bashkansky';
update workers set linkedin_username='sebastián-sánchez-7b77968a' where worker='Sebastian Sanchez';
update workers set linkedin_username='jesse-clifton-45652758' where worker='Jesse Clifton';
update workers set linkedin_username='amanarice' where worker = 'Amana Rice';

# -- Worker file insertions
update workers set worker_file = 'milo-list.mediawiki' where worker = 'Milo King';
update workers set worker_file = 'issa-list.mediawiki' where worker = 'Issa Rice';
update workers set worker_file = 'sebastian-sanchez-list.mediawiki' where worker = 'Sebastian Sanchez';
update workers set worker_file = 'ethan-list.mediawiki' where worker = 'Ethan Bashkansky';
update workers set worker_file = 'adrian-list.mediawiki' where worker = 'Adrian Ulloa';
update workers set worker_file = 'avi-list.mediawiki' where worker = 'Avi Glozman';
update workers set worker_file = 'charlie-list.mediawiki' where worker = 'Charlie Corner';
update workers set worker_file = 'chris-list.mediawiki' where worker = 'Christopher Kunin';
update workers set worker_file = 'devansh-list.mediawiki' where worker = 'Devansh Dwivedy';
update workers set worker_file = 'eddy-list.mediawiki' where worker = 'Eddy Su';
update workers set worker_file = 'jesse-list.mediawiki' where worker = 'Jesse Clifton';
update workers set worker_file = 'michael-list.mediawiki' where worker = 'Michael Royzen';
update workers set worker_file = 'sean-list.mediawiki' where worker = 'Sean Yu';
update workers set worker_file = 'sergey-list.mediawiki' where worker = 'Sergey Yegorov';
update workers set worker_file = 'thomas-list.mediawiki' where worker = 'Thomas Foster';
update workers set worker_file = 'akc-list.mediawiki' where worker = 'Alex K. Chen';
update workers set worker_file = 'amy-list.mediawiki' where worker = 'Amy Zhang';
update workers set worker_file = 'daniel-list.mediawiki' where worker = 'Daniel Alejandro Maidana';
update workers set worker_file = 'linchuan-list.mediawiki' where worker = 'Linchuan Zhang';

