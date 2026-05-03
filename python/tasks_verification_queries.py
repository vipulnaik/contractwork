import shared, connection

queries = [
    "select * from tasks where worker = 'Sebastian Sanchez' and task_venue = 'Org Watch' and not (notes regexp concat('last commit of the month was on ',completion_date)) and not (notes regexp 'assisting Gabriel');",
]

_connection = connection.connect()

for query in queries:
    shared.executeQueryAndPrintIfNonEmptyResults(query, _connection)
