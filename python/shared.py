verbose = False

def printIfVerbose(str):
    if verbose:
        print(str)

def executeQueryAndPrintIfNonEmptyResults(query, connection):
    connection.begin()
    try:
        with connection.cursor() as cursor:
            printIfVerbose(f"Executing query: { query }")
            cursor.execute(query)
            printIfVerbose(f"Got rowcount { cursor.rowcount }")
            if cursor.rowcount > 0:
                print(f"!!! Query returned a nonempty count ({ cursor.rowcount }) of results: { query }")
                for row in cursor.fetchall():
                    printIfVerbose(f"Row in result: { row }")
    except Exception as e:
        print(f"!!! Error executing query: { query }")
        print(repr(e))
    connection.commit()
