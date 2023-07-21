create table tax_adjustments(
  adjustment_id int(11) not null auto_increment primary key, 
  worker varchar(40),
  completion_year varchar(4) not null,
  payment_finalization_year varchar(4) not null,
  adjustment decimal(7,2) not null,
  constraint adjustment_is_for_worker foreign key (worker) references workers (worker)
 ) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

insert into tax_adjustments(worker, completion_year, payment_finalization_year, adjustment) values
  ('Issa Rice','2016','2017',480);

