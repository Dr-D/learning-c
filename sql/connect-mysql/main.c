#include <stdio.h>
#include <stdlib.h>
#include <mysql/mysql.h>

int main(int argc, char *argv[]) {
  printf("MySQK client version: '%s'\n", mysql_get_client_info());
  
  exit(EXIT_SUCCESS);
}
