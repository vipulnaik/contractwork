create table commissions(
  commission_id int(11) not null auto_increment primary key,
  earner varchar(40) not null,
  commission_receiver varchar(40) not null,
  commission float(0,2) not null,
  commission_reason enum('Recruiter','Guide') not null,
  notes varchar(2000)
) ENGINE=InnoDB AUTO_INCREMENT=15239276 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

insert into commissions(earner,commission_receiver,commission,commission_reason) values 
  ('Adrian Ulloa','Issa Rice',0.10,'Guide'),
  ('Amy Zhang','Issa Rice',0.15,'Guide'),
  ('Avi Glozman','Issa Rice',0.10,'Guide'),
  ('Charlie Corner','Issa Rice',0.15,'Guide'),
  ('Christopher Kunin','Issa Rice',0.10,'Guide'),
  ('Devansh Dwivedy','Issa Rice',0.10,'Guide'),
  ('Eddy Su','Issa Rice',0.10,'Guide'),
  ('Michael Royzen','Issa Rice',0.10,'Guide'),
  ('Sean Yu','Issa Rice',0.10,'Guide'),
  ('Sergey Yegorov','Issa Rice',0.10,'Guide'),
  ('Thomas Foster','Issa Rice',0.10,'Guide'),
  ('Alex K. Chen','Issa Rice',0.03,'Guide'),
 
  ('Amy Zhang','Ethan Bashkansky',0.15,'Recruiter'),
  ('Avi Glozman','Ethan Bashkansky',0.10,'Guide'),
  ('Christopher Kunin','Ethan Bashkansky',0.10,'Guide'),
  ('Devansh Dwivedy','Ethan Bashkansky',0.10,'Guide'),
  ('Eddy Su','Ethan Bashkansky',0.10,'Guide'),
  ('Michael Royzen','Ethan Bashkansky',0.10,'Guide'),
  ('Sean Yu','Ethan Bashkansky',0.10,'Guide'),
  ('Thomas Foster','Ethan Bashkansky',0.10,'Guide');

