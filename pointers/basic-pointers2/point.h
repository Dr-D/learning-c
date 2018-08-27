#ifndef _point_h_

#define _point_h_

struct Point {
  int x;
  int y;
};

struct Point *point_create(int x, int y);

void point_scale(struct Point *ppoint, int scale);

void point_reflectx(struct Point *ppoint, int x);

void point_reflecty(struct Point *ppoint, int y);

void point_print(struct Point *ppoint);

#endif
