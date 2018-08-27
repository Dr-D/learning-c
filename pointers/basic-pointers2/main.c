#include <stdio.h>
#include <stdlib.h>

#include "point.h"

int main(int argc, char *argv[]) {

  struct Point *ppoint = point_create(2, 3);

  point_print(ppoint);

  point_scale(ppoint, 10);

  point_print(ppoint);

  point_reflectx(ppoint, 10);

  point_print(ppoint);

  point_reflecty(ppoint, 15);

  point_print(ppoint);

  free(ppoint);

  exit(EXIT_SUCCESS);
}
