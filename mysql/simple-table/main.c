#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

void executeQuery(MYSQL *, char[]);
void getResult(MYSQL *, char[]);

int main(int argc, char *argv[]) {
  MYSQL *conn = mysql_init(NULL);

  if (conn == NULL) {
    printf("Failed to initilise connection: '%s'\n", mysql_error(conn));
    exit(EXIT_FAILURE);
  }

  if (mysql_real_connect(conn, "localhost", "root", "password", NULL, 0, NULL, 0) == NULL) {
    printf("Failed to create connection: '%s'\n", mysql_error(conn));
    mysql_close(conn);
    exit(EXIT_FAILURE);
  }

  executeQuery(conn, "CREATE DATABASE drd;");
  executeQuery(conn, "USE drd;");
  executeQuery(conn, "CREATE TABLE PERSON (ID BIGINT NOT NULL, NAME VARCHAR(20) NOT NULL);");
  executeQuery(conn, "INSERT INTO PERSON (ID, NAME) VALUES (1, 'Mickey');");
  executeQuery(conn, "SELECT ID, NAME FROM  PERSON;");
  //  executeQuery(conn, "DROP DATABASE drd;");
  
  mysql_close(conn);
  exit(EXIT_SUCCESS);
}

void executeQuery(MYSQL *conn, char query[]) {
  if (mysql_query(conn, query)) {
    printf("Failed to execute query: '%s', '%s'\n", query, mysql_error(conn));
    mysql_close(conn);
    exit(EXIT_FAILURE);
  }
}

void getResult(MYSQL *conn, char select[]) {
  executeQuery(conn, select);

  MYSQL_RES *res = mysql_store_result(conn);
  if(res == NULL) {
    printf("Failed to get result: '%s", mysql_error(conn));
    exit(EXIT_FAILURE);
  }

  int num_fields = mysql_num_fields(res);

  MYSQL_ROW row;

  while((row = mysql_fetch_row(res))) {
    for(int i = 0; i < num_fields; i++) {
      char *aValue = row[i] ? row[i] : NULL;
      printf("%s ", aValue);
    }
    printf("\n");
  }
  mysql_free_result(res);
  mysql_close(conn);
}
