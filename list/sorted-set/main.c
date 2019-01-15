#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

int main(int argc, char *argv[]) {

  set_add("A");
  set_print();
  printf("1*******************\n");

  set_add("B");
  set_print();
  printf("2*******************\n");

  set_add("E");
  set_print();
  printf("3*******************\n");

  set_add("D");
  set_print();
  printf("4*******************\n");

  set_add("G");
  set_print();
  printf("3*******************\n");

  set_add("F");
  set_print();
  printf("4*******************\n");


  set_add("C");
  set_print();
  printf("5*******************\n");

  set_remove("C");
  set_print();
  printf("6*******************\n");

  set_remove("A");
  set_print();
  printf("7*******************\n");

  set_remove("G");
  set_print();
  printf("8*******************\n");

  set_add("D");
  set_print();
  printf("9*******************\n");

  exit(EXIT_SUCCESS);
}
