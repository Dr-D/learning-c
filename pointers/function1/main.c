#include <stdio.h>
#include <stdlib.h>

int add_int(int, int);

int main(int argc, char *argv[]) {
    
  int (*pfunc)(int, int) = add_int;

  int int_result = pfunc(88, 12);
    
  printf("int_result: '%d'\n", int_result);

  exit(EXIT_SUCCESS);
}

int add_int(int a, int b) {
  return a + b;
}
