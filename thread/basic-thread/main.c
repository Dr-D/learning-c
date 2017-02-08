#include <stdio.h>
#include <stdlib.h>

void *start_routine(void*);


int main(int argc, char *argv[]) {
  printf("Start main.\n");

  
  printf("End main.\n");
  
  exit(EXIT_SUCCESS);
}

void *start_routine(void*) {
  printf("In thread");
}
