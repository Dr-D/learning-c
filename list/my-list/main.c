#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(int argc, char *argv[]) {


  struct List *list = list_create("First");
  printf("Hello World!\n");
  
  exit(EXIT_SUCCESS);
}
