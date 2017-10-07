#include <stdio.h>
#include <stdlib.h>
#include "add.h"
#include "subtract.h"
#include "product.h"

int main(int argc, char *argv[]) {
  int a = 10;
  int b = 5;
  
  printf("a: '%d', b: '%d'\n", a, b);
  printf("add: '%d'\n", add(a, b));
  printf("subtract: '%d'\n", subtract(a, b));
  printf("product: '%d'\n", multiply(a, b));
  
  exit(EXIT_SUCCESS);
}
