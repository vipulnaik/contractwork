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
)

# -- Ethan Bashkansky's Wikipedia work

insert into tasks(worker, task_venue, task_type, task_receptacle, task_receptable_url, completion_date, payment, topic, format, notes) values
  ('Ethan Bashkansky', 'Wikipedia', 'Wikipedia page creation','Form W-4','https://en.wikipedia.org/wiki/Form_W-4','2016-02-12',30,'United States taxation','Prose'),
  
