import shared, connection

queries = [
    "select * from stipends where day(stipend_start_date) != 1 and not (payer = 'Future Fund Regranting Program' and stipend_start_date = '2022-12-17');",

    "select * from stipends where last_day(stipend_end_date) != stipend_end_date and not (payer = 'Future Fund Regranting Program' and stipend_end_date in ('2022-11-08','2024-04-22'));",

    "select * from stipends where last_day(stipend_start_date) != last_day(stipend_end_date) and not (payee = 'Alex K. Chen' or notes regexp 'managing AKC');",

    "select * from stipends where stipend_end_date != stipend_award_date and not (stipend_award_date in ('2016-12-28','2017-03-24'));",
]

_connection = connection.connect()

for query in queries:
    shared.executeQueryAndPrintIfNonEmptyResults(query, _connection)
