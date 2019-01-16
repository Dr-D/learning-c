#include <stdlib.h>

#include "mymath.h"
#include "myprint.h"
#include "myrand.h"

int main(int argc, char *argv[]) {
  int random = myrand_int(10);

  int add = mymath_add(random, 10);

  int mult = mymath_multiply(add, 10);

  myprint_int(mult);

  exit(EXIT_SUCCESS);
}
