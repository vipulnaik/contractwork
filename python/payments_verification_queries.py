import shared, connection

queries = [
    "select * from payments where payment_method = 'Bitcoin' and payment != received_payment;",

    "select * from payments where payment_method = 'Bitcoin' and not ((sent_date = payment_notice_receipt_date) and (payment_notice_receipt_date = cashout_request_date) and (cashout_request_date = receipt_date));",

    "select * from payments where payee in ('Sebastian Sanchez','Gabriel Bobis') and sent_date >= '2020-06-02' and not (payment_method in ('Bitcoin','FTX','Bitcoin Cash'));",
]

_connection = connection.connect()

for query in queries:
    shared.executeQueryAndPrintIfNonEmptyResults(query, _connection)
