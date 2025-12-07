create table workers(
  worker_id int(11) not null auto_increment primary key,
  worker varchar(40) not null,
  active boolean,
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
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

insert into workers(worker, active, country, wikipedia_username, timelines_wiki_username, facebook_username, email_id, preferred_payment_method, recruiter, contact_method, notes, worker_file) values
  ('Amana Rice',false,'United States',null,null,'omgitsmana','omgitsmana@gmail.com','PayPal','Issa Rice','outbound in-person','Amana Rice is the sister of Issa Rice, who recruited her based on that connection.','amana-list.mediawiki'),
  ('Mati Roy',false,'Canada','Mati_Roy','Mati_Roy','mati.roy.09','contact@matiroy.com','PayPal','Issa Rice','inbound email','Mati started working on the timeline of cryonics after it was initially proposed to Orpheus Lummis, who has completed another timeline for Timelines Wiki','mati-roy-list.mediawiki'),
  ('Orpheus Lummis',false,'Canada','Orpheus_Lummis','Orpheus_Lummis','orpheus.lummis','o@orpheuslummis.com','Ethereum','Issa Rice','inbound email','Started work on topics of interest to the worker','orpheus-lummis-list.mediawiki'),
  ('Milo King',false,'United States','MiloJBKing',null,'milo.king','milo.j.king@gmail.com','PayPal','Vipul Naik','outbound Facebook','Did a bit of Wikipedia work in March and then a lot of work on the Market subwiki in the summer of 2016','milo-list.mediawiki'),
  ('Issa Rice',true,'United States','Riceissa','Issa','riceissa','riceissa@gmail.com','PayPal','Vipul Naik','outbound Facebook','Been working sporadically since 2015; started working regularly since early 2016. Recruited other workers and also helps with managing workers and sprints.', 'issa-list.mediawiki'),
  ('Sebastian Sanchez',true,'Argentina','Wikisanchez','Sebastian','seba.sanchez.3998','sebastian123sanchez@gmail.com','Bitcoin','Vipul Naik','inbound Facebook','Started work in April 2016. Took break in June 2016 for Japan visit. Worked on disease timelines, country healthcare timelines, and miscellaneous global health Wikipedia articles.','sebastian-sanchez-list.mediawiki'),
  ('Ethan Bashkansky',false,'United States','Ethanbas','Ethanbas','ethan.bashkansky','ethanbas@gmail.com','PayPal','Issa Rice','outbound in-person','Did sporadic work in February, and has done sporadic work a few times since. Also recruits other workers and stays in touch.','ethan-list.mediawiki'),
  ('Adrian Ulloa',false,'Peru','Physikite',null,'physikite','physikite@outlook.com','PayPal','Vipul Naik','inbound email','Did sporadic work in September of 2016.','adrian-list.mediawiki'),
  ('Avi Glozman',false,'United States','Avigl',null,'avi.glozman','avi.glozman@gmail.com','PayPal','Ethan Bashkansky','outbound Facebook','Sporadic work since late May/early June 2016','avi-list.mediawiki'),
  ('Charlie Corner',false,'United States','Churrupy',null,'charlie.corner.5','churrupy@gmail.com','PayPal','Linchuan Zhang','inbound Facebook','Sporadic work since late June/early July 2016','charlie-list.mediawiki'),
  ('Christopher Kunin',false,'United States','ChristopherLKunin',null,'chris.kunin.5','Chris.kunin@me.com','PayPal','Ethan Bashkansky','outbound Facebook','Sporadic wok since June 2016','chris-list.mediawiki'),
  ('Devansh Dwivedy',false,'United States','Dave8033',null,'devansh33','devarshi@yahoo.com','PayPal','Ethan Bashkansky','outbound Facebook','Sporadic work since June 2016. Note that PayPal belongs to his father','devansh-list.mediawiki'),
  ('Eddy Su',false,'United States','Esu44224',null,'EddySu98008','esu44224@gmail.com','PayPal','Ethan Bashkansky','outbound Facebook','Made two Wikipedia articles in June 2016.','eddy-list.mediawiki'),
  ('Jesse Clifton',false,'United States','JesseClifton',null,'jesse.clifton2','jclifton333@gmail.com','Check','Vipul Naik','inbound Facebook','Introduced by Jacy Reese; Jesse had done a project for Jacy at Animal Charity Evaluators and had a summer off','jesse-list.mediawiki'),
  ('Michael Royzen',false,'United States','Rushingcreek',null,'michael.royzen','michael@mlabtechnologies.com','PayPal','Ethan Bashkansky','outbound Facebook','Wrote one article in June 2016 but could not work further as he wanted to spend more time on developing his app.','michael-list.mediawiki'),
  ('Sean Yu',false,'United States','Majesticfish',null,'sean.yu.18','yusean1792@gmail.com','PayPal','Ethan Bashkansky','outbound Facebook','A little work on tax forms in July 2016.','sean-list.mediawiki'),
  ('Sergey Yegorov',true,'Russia','Sergie_Marienhof',null,'avereflection','sashspecial@gmail.com','PayPal','Vipul Naik','inbound Facebook','Sporadic work since September 2016.','sergey-list.mediawiki'),
  ('Thomas Foster',false,'Australia','Thomas_James_Foster',null,'thomasjamesfoster96','me@thomasfoster.co','PayPal','Alex K. Chen','outbound Facebook','Work in June 2016. Could not continue as school term started.','thomas-list.mediawiki'),
  ('Alex K. Chen',false,'United States','Simfish','InquilineKea','simfish','simfish@gmail.com','PayPal','Vipul Naik','outbound email','Started working in April 2015 on a unique contract. Continued in 2016, slowed down in last quarter.','akc-list.mediawiki'),
  ('Amy Zhang',false,'United States','Amy.zhang425',null,'amy.zhang.5855594','bluemoonamy@live.com','PayPal','Ethan Bashkansky','outbound Facebook','Did some work in June 2016 on timeline of global health. Discontinued work due to other obligations','amy-list.mediawiki'),
  ('Daniel Alejandro Maidana',false,'Argentina','DanielMB',null,'danielalejandro.maidana.50','unknown','PayPal','Sebastian Sanchez','inbound Facebook','Started working in August but delays on both sides so first payment in December','daniel-list.mediawiki'),
  ('Linchuan Zhang',false,'United States','N/A',null,'linchuan.zhang','unknown','PayPal','Vipul Naik','inbound Facebook','Not a worker, but helped recruit some workers','linchuan-list.mediawiki'),
  ('Joey Malandra',false,'United States','Joeykai',null,'joey.malandra.73','joseph.malandra@gmail.com','PayPal','Ethan Bashkansky','outbound Facebook','Introduced to Ethan through a mutual friend Ethan met at the Envision Conference. Had 58K edits at the time.','joey-list.mediawiki'),
  ('Gabriel Bobis',true,'Argentina',null,null,'gabobis','gabrielbobis.arg@gmail.com','Bitcoin','Sebastian Sanchez','inbound Facebook','Sebastian brough this contract worker to Vipul''s attention. As of September 2024, communication is being handled through Sebsastian.','gabriel-list.mediawiki'),
  ('Olivia Mora',false,'United States',null,'Olivia',null,'oliviagmora1@gmail.com','PayPal','Issa Rice','inbound email','Olivia initially connected to Issa for AI Watch and Issa redirected Olivia to Vipul. After some discussion, Olivia and Vipul decided that timelines would be more suitable for Olivia to work on. Olivia agreed to work for Vipul on timelines for 150 hours spread over a period of a few months. The work was done August to December 2024 and all dues were settled in 2024.','olivia-list.mediawiki'),
  ('Reagan Sang',false,'Kenya',null,null,null,'reagankibetsang@gmail.com','PayPal','Issa Rice','inbound email','Reagan initially connected to Issa for AI Watch and Issa redirected Reagan to Vipul. Reagan finished contract work for Vipul in November 2024. All dues were settled on December 1.','reagan-list.mediawiki'),
  ('Hithheshwar',false,'United Kingdom',null,'Hith',null,'hithheshwar1@gmail.com','Wire transfer','Issa Rice','inbound email','Hithheshwar (Hith) initially connected with AI Watch and Issa redirected Hith to Vipul. After some discussion, Hith and Vipul deicded that timelines would be more suitable for Hith to work on. The work was done August to December 2024 and all dues were settled in January 2025.','hith-list.mediawiki'),
  ('Tajudeen Riliwan',true,'Nigeria',null,null,null,'dekunle4dreal1@gmail.com','Wire transfer','Issa Rice','inbound email','Riliwan initially connected to Issa for AI Watch and Issa redirected Riliwan to Vipul.','riliwan-list.mediawiki');

-- website lists
update workers set website='https://issarice.com' where worker = 'Issa Rice';
update workers set website='http://orpheuslummis.com/' where worker = 'Orpheus Lummis';

-- LessWrong and EAF username lists
update workers set lesswrong_username='riceissa' where worker = 'Issa Rice';
update workers set eaf_username='riceissa' where worker = 'Issa Rice';
update workers set eaf_username='JesseClifton' where worker = 'Jesse Clifton';
update workers set eaf_username='tjriliwan' where worker = 'Tajudeen Riliwan';

-- GitHub username lists
update workers set github_username='riceissa' where worker = 'Issa Rice';
update workers set github_username='aviglozman' where worker = 'Avi Glozman';
update workers set github_username='ethanbas' where worker = 'Ethan Bashkansky';
update workers set github_username='sebastiansanchez123' where worker = 'Sebastian Sanchez';
update workers set github_username='omgitsmana' where worker = 'Amana Rice';
update workers set github_username='ReaganKibet' where worker = 'Reagan Sang';
update workers set github_username='b3arded-t3ch' where worker = 'Tajudeen Riliwan';

-- LinkedIn usernames
update workers set linkedin_username='issarice' where worker='Issa Rice';
update workers set linkedin_username='ethan-bashkansky-56166766' where worker='Ethan Bashkansky';
update workers set linkedin_username='sebastián-sánchez-7b77968a' where worker='Sebastian Sanchez';
update workers set linkedin_username='jesse-clifton-45652758' where worker='Jesse Clifton';
update workers set linkedin_username='amanarice' where worker = 'Amana Rice';
update workers set linkedin_username='reagan-langat' where worker = 'Reagan Sang';
update workers set linkedin_username='hithheshwar-r-7abb1b216' where worker = 'Hithheshwar';
update workers set linkedin_username='riliwan-tajudeen-3a7867187' where worker = 'Tajudeen Riliwan';
