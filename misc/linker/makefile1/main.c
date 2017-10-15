#include <stdio.h>
#include <stdlib.h>
#include "mymath.h"

int main(int argc, char *argv[]) {
  //delete this line and recompile
  int r = add(5, 10);

  printf("result: '%d'\n", r);
  
  exit(EXIT_SUCCESS);
}
