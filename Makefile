MYSQL_ARGS=
DATABASE=contractwork

.PHONY: init
init:
	mkdir -p access-portal/images
	mysql $(MYSQL_ARGS) -e "create database if not exists $(DATABASE);"

.PHONY: reset
reset:
	mysql $(MYSQL_ARGS) -e "use $(DATABASE); drop table if exists tasks;"
	mysql $(MYSQL_ARGS) -e "use $(DATABASE); drop table if exists payments;"
	mysql $(MYSQL_ARGS) -e "use $(DATABASE); drop table if exists commissions;"
	mysql $(MYSQL_ARGS) -e "use $(DATABASE); drop table if exists royalties;"
	mysql $(MYSQL_ARGS) -e "use $(DATABASE); drop table if exists stipends;"
	mysql $(MYSQL_ARGS) -e "use $(DATABASE); drop table if exists payer_payments;"
	mysql $(MYSQL_ARGS) -e "use $(DATABASE); drop table if exists tax_adjustments;"
	mysql $(MYSQL_ARGS) -e "use $(DATABASE); drop table if exists workers;"
	mysql $(MYSQL_ARGS) -e "use $(DATABASE); drop table if exists payers;"

.PHONY: read
read: read_public read_private

.PHONY: read_public
read_public:
	mysql $(MYSQL_ARGS) $(DATABASE) < sql/payers.sql
	mysql $(MYSQL_ARGS) $(DATABASE) < sql/workers.sql
	mysql $(MYSQL_ARGS) $(DATABASE) < sql/tasks.sql
	mysql $(MYSQL_ARGS) $(DATABASE) < sql/payments.sql
	mysql $(MYSQL_ARGS) $(DATABASE) < sql/commissions.sql
	mysql $(MYSQL_ARGS) $(DATABASE) < sql/royalties.sql
	mysql $(MYSQL_ARGS) $(DATABASE) < sql/stipends.sql
	mysql $(MYSQL_ARGS) $(DATABASE) < sql/payer_payments.sql
	mysql $(MYSQL_ARGS) $(DATABASE) < sql/tax_adjustments.sql

.PHONY: read_private
read_private:
	mysql $(MYSQL_ARGS) $(DATABASE) < sql/private/workers.sql
	mysql $(MYSQL_ARGS) $(DATABASE) < sql/private/tasks.sql
	mysql $(MYSQL_ARGS) $(DATABASE) < sql/private/payments.sql

.PHONY: fetch_table_sorting
fetch_table_sorting:
	curl -Lo access-portal/jquery-3.1.1.min.js \
		'https://code.jquery.com/jquery-3.1.1.min.js'
	curl -Lo access-portal/jquery.tablesorter.js \
		'https://github.com/christianbach/tablesorter/raw/master/jquery.tablesorter.js'
	curl -Lo access-portal/style.css \
		'https://raw.githubusercontent.com/christianbach/tablesorter/master/themes/blue/style.css'
	curl -Lo access-portal/bg.gif \
		'https://github.com/christianbach/tablesorter/raw/master/themes/blue/bg.gif'
	curl -Lo access-portal/asc.gif \
		'https://github.com/christianbach/tablesorter/raw/master/themes/blue/asc.gif'
	curl -Lo access-portal/desc.gif \
		'https://github.com/christianbach/tablesorter/raw/master/themes/blue/desc.gif'

.PHONY: clean_table_sorting
clean_table_sorting:
	rm -f access-portal/jquery-3.1.1.min.js
	rm -f access-portal/jquery.tablesorter.js
	rm -f access-portal/style.css
	rm -f access-portal/bg.gif
	rm -f access-portal/asc.gif
	rm -f access-portal/desc.gif

.PHONY: fetch_anchorjs
fetch_anchorjs:
	curl -Lo access-portal/anchor.min.js \
		'https://raw.githubusercontent.com/bryanbraun/anchorjs/master/anchor.min.js'

.PHONY: clean_anchorjs
clean_anchorjs:
	rm -f access-portal/anchor.min.js
