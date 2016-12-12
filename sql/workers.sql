create table workers(
  worker_id int(11) not null auto_increment primary key,
  worker varchar(40) not null,
  country varchar(20) not null,
  wikipedia_username varchar(40),
  facebook_username varchar(100),
  email_id varchar(40),
  website varchar(40),
  preferred_payment_method enum('Cash','Check','PayPal','Wire transfer','Western Union') not null,
  recruiter enum('Vipul Naik','Issa Rice','Ethan Bashkansky','Linchuan Zhang','Alex K. Chen','Sebastian Sanchez') not null,
  contact_method enum('inbound email','inbound Facebook','outbound email','outbound Facebook','outbound in-person') not null,
  notes varchar(2000) default null,
  private boolean default false,
  unique key worker(`worker`)
) ENGINE=InnoDB AUTO_INCREMENT=15239276 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

insert into workers(worker, country, wikipedia_username, facebook_username, email_id, preferred_payment_method, recruiter, contact_method, notes) values 
  ('Milo King','United States','MiloJBKing','milo.king','milo.j.king@gmail.com','PayPal','Vipul Naik','outbound Facebook','Did a bit of Wikipedia work in March and then a lot of work on the Market subwiki in the summer of 2016'),
  ('Issa Rice','United States','Riceissa','riceissa','riceissa@gmail.com','Check','Vipul Naik','outbound Facebook','Been working sporadically since 2015; started working regularly since early 2016. Recruited other workers and also helps with managing workers and sprints.'),
  ('Sebastian Sanchez','Argentina','Wikisanchez','seba.sanchez.3998','sebastian123sanchez@gmail.com','Western Union','Vipul Naik','inbound Facebook','Started work in April 2016. Took break in June 2016 for Japan visit. Worked on disease timelines, country healthcare timelines, and miscellaneous global health Wikipedia articles.'),
  ('Ethan Bashkansky','United States','Ethanbas','ethan.bashkansky','ethanbas@gmail.com','PayPal','Issa Rice','outbound in-person','Did sporadic work in February, and has done sporadic work a few times since. Also recruits other workers and stays in touch.'),
  ('Adrian Ulloa','Peru','Physikite','physikite','physikite@outlook.com','PayPal','Vipul Naik','inbound email','Did sporadic work in September of 2016.'),
  ('Avi Glozman','United States','Avigl','avi.glozman','avi.glozman@gmail.com','PayPal','Ethan Bashkansky','outbound Facebook','Sporadic work since late May/early June 2016'),
  ('Charlie Corner','United States','Churrupy','charlie.corner.5','churrupy@gmail.com','PayPal','Linchuan Zhang','inbound Facebook','Sporadic work since late June/early July 2016'),
  ('Christopher Kunin','United States','ChristopherLKunin','chris.kunin.5','Chris.kunin@me.com','PayPal','Ethan Bashkansky','outbound Facebook','Sporadic wok since June 2016'),
  ('Devansh Dwivedy','United States','Dave8033','devansh33','devarshi@yahoo.com','PayPal','Ethan Bashkansky','outbound Facebook','Sporadic work since June 2016. Note that PayPal belongs to his father'),
  ('Eddy Su','United States','Esu44224','EddySu98008','esu44224@gmail.com','PayPal','Ethan Bashkansky','outbound Facebook','Made two Wikipedia articles in June 2016.'),
  ('Jesse Clifton','United States','JesseClifton','jesse.clifton2','jclifton333@gmail.com','Check','Vipul Naik','inbound Facebook','Introduced by Jacy Reese; Jesse had done a project for Jacy at Animal Charity Evaluators and had a summer off'),
  ('Michael Royzen','United States','Rushingcreek','michael.royzen','michael@mlabtechnologies.com','PayPal','Ethan Bashkansky','outbound Facebook','Wrote one article in June 2016 but could not work further as he wanted to spend more time on developing his app.'),
  ('Sean Yu','United States','Majesticfish','sean.yu.18','yusean1792@gmail.com','PayPal','Ethan Bashkansky','outbound Facebook','A little work on tax forms in July 2016.'),
  ('Sergey Yegorov','Russia','Sergie_Marienhof','avereflection','sashspecial@gmail.com','PayPal','Vipul Naik','inbound Facebook','Sporadic work since September 2016.'),
  ('Thomas Foster','Australia','Thomas_James_Foster','thomasjamesfoster96','me@thomasfoster.co','PayPal','Alex K. Chen','outbound Facebook','Work in June 2016. Could not continue as school term started.'),
  ('Alex K. Chen','United States','Simfish','simfish','simfish@gmail.com','PayPal','Vipul Naik','outbound email','Started working in April 2015 on a unique contract. Continued in 2016, slowed down in last quarter.'),
  ('Amy Zhang','United States','Amy.zhang425','amy.zhang.5855594','bluemoonamy@live.com','PayPal','Ethan Bashkansky','outbound Facebook','Did some work in June 2016 on timeline of global health. Discontinued work due to other obligations'),
  ('Daniel Alejandro Maidana','Argentina','DanielMB','danielalejandro.maidana.50','unknown','PayPal','Sebastian Sanchez','inbound Facebook','Started working in August but delays on both sides so first payment in December'),
  ('Linchuan Zhang','United States','N/A','linchuan.zhang','unknown','PayPal','Vipul Naik','inbound Facebook','Not a worker, but helped recruit some workers');

# -- website lists
update workers set website='https://issarice.com' where worker = 'Issa Rice';
