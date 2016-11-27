create database contractwork;

use contractwork;

create table tasks(
  task_id not null auto_increment,
  worker varchar(40),
  task_venue enum('Wikipedia','Wikipedia Views','Effective Altruism Forum','LessWrong','Personal website') default 'Wikipedia',
  task_type enum('Wikipedia page creation','Wikipedia page update','Wikipedia pge translation','attemped Wikipedia work','miscellaneous Wikipedia work'),
  task_receptacle varchar(100) NOT NULL,
  task_receptacle_url varchar(100) NOT NULL,
  completion_date date NOT NULL,
  payment float(7,2) NOT NULL
)
