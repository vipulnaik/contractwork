create table venues(
  venue_id int(11) not null auto_increment primary key,
  venue_name varchar(40) unique not null,
  homepage_urls varchar(200),
  updates_urls varchar(200),
  reach_urls varchar(200),
  reach_notes varchar(200),
  goals_notes varchar(2000) not null
)  ENGINE=InnoDB AUTO_INCREMENT=15239276 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
  
insert into venues (`venue_name`, homepage_url, updates_url, reach_url, reach_notes, goals_notes) values
  ('Wikipedia', 'https://www.wikipedia.org/|https://en.wikipedia.org/|https://es.wikipedia.org/'
