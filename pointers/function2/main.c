#include <stdio.h>
#include <stdlib.h>

int add_int(int, int);

void operator(int (*)(int,int), int, int);

int main(int argc, char *argv[]) {
    
  operator(add_int, 90, 10);
  
  exit(EXIT_SUCCESS);
}

int add_int(int a, int b) {
  return a + b;
}

void operator(int (*fparam)(int,int), int x, int y) {
  int res = fparam(x, y); 
  printf("res: '%d'\n", res);
}
