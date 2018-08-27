#include <stdlib.h>
#include <stdio.h>

#include "point.h"

struct Point *point_create(int x, int y) {
  struct Point *ppoint = malloc(sizeof(struct Point));
  ppoint->x = x;
  ppoint->y = y;

  return ppoint;
}

void point_scale(struct Point *ppoint, int scale) {
  ppoint->x = ppoint->x * scale;
  ppoint->y = ppoint->y * scale;
}

void point_reflectx(struct Point *ppoint, int x) {
  int distance = ppoint->x - x;
  ppoint->x = x - distance;
}

void point_reflecty(struct Point *ppoint, int y) {
  int distance = ppoint->y - y;
  ppoint->y = y - distance;
}

void point_print(struct Point *ppoint) {
  printf("(%d, %d)\n", ppoint->x, ppoint->y);
}
