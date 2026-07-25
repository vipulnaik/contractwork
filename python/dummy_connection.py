import pymysql
from pymysql.constants import CLIENT

def connect():
    return pymysql.connect(
        host = "localhost",
        user = (user),
        password = (password),
        database = (database),
        cursorclass = pymysql.cursors.DictCursor,
        client_flag = CLIENT.MULTI_STATEMENTS,
    )
