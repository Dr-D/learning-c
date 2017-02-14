#include <stdio.h>
#include <stdlib.h>

int add_int(int, int);
int multiply_int(int, int);

void operator(int (**)(int,int), int, int, int);

int main(int argc, char *argv[]) {

  int (*arr_pfunc[2])(int, int);
  arr_pfunc[0] = add_int;
  arr_pfunc[1] = multiply_int;
  
  operator(arr_pfunc, 90, 10, 5);
  
  exit(EXIT_SUCCESS);
}

int add_int(int a, int b) {
  return a + b;
}

int multiply_int(int a, int b) {
  return a * b;
}


void operator(int (**arr_func)(int,int), int x, int y, int z) {
  int res = arr_func[1](arr_func[0](x, y), z); 
  printf("res: '%d'\n", res);
}
