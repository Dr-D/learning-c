#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(int argc, char *argv[]) {

  struct List *list = list_create("First");

  list_add(list, "Second");
  list_add(list, "Third");
  list_add(list, "Fourth");

  list_print(list);

  list_destroy(list);
  exit(EXIT_SUCCESS);
}
