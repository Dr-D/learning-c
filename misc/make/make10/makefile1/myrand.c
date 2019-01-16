#include <stdlib.h>
#include <time.h>

#include "myrand.h"

//Here we return a random integer between min and max
int myrand_int_range(int min, int max) {
  time_t t;
  srand((unsigned) time(&t));

  return (rand() % (max - min)) + min ;
}

int myrand_int(int max) {
  return myrand_int_range(0, max);
}


