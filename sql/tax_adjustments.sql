create table tax_adjustments(
  adjustment_id int(11) not null auto_increment primary key, 
  worker varchar(40),
  completion_year varchar(4) not null,
  payment_finalization_year varchar(4) not null,
  adjustment float(7,2) not null
 ) ENGINE=InnoDB AUTO_INCREMENT=15239276 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

insert into tax_adjustments(worker, completion_year, payment_finalization_year, adjustment) values
  ('Issa Rice','2016','2017',480);

