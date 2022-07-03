create table payers(
  payer varchar(40) primary key not null,
  notes varchar(2000)
) ENGINE=InnoDB AUTO_INCREMENT=1 DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

insert into payers(payer, notes) values
  ('Vipul Naik','Vipul Naik originally started the contract work website; it''s designed primarily for contract work for Vipul Naik.'),
  ('Peter Hurford','Peter Hurford (also known as Peter Wildeford) funded contract work in 2017 and 2018; he used Vipul Naik''s contract work portal as the workers were already familiar with it and it simplified the management and tracking of payments.'),
  ('Berkeley Existential Risk Initiative','Berkeley Existential Risk Initiative (BERI) funded some contract work by Issa Rice for the Future of Humanity Institute in 2019. Vipul Naik was not involved, and only added the task here to make it easier for Issa Rice to track this along with the rest of his contract work.'),
  ('Alex Flint','Alex Flint funded a timeline by Issa Rice in 2018 through Vipul Naik.'),
  ('Centre for Effective Altruism','Centre for Effective Altruism paid a prize to Issa Rice in 2019. Vipul Naik was not involved, and only added the task here to make it easier for Issa Rice to track this along with the rest of his contract work.'),
  ('Andy Matuschak','Andy Matuschak paid Issa Rice for a contract work task in 2021. Vipul Naik was not involved, and only added the task here to make it easier for Issa Rice to track this along with the rest of his contract work.'),
  ('Future Fund Regranting Program','Around mid-June 2022, the Future Fund Regranting Program sponsored $8,000 in work by Sebastian Sanchez on timelines. The upfront payment was to be earned by Sebastian through work done in the future. The grant administrator is Pablo Stafforini, and Vipul Naik is working closely with Pablo and Sebastian on the project. See https://forum.effectivealtruism.org/posts/paMYXYFYbbjpdjgbt/future-fund-june-2022-update#Regranting_program_in_more_detail or more general background on the Future Fund Regranting Program (this particular grant is not listed there and, as of early July 2022, is not listed at https://ftxfuturefund.org/our-regrants/#grants either.');
