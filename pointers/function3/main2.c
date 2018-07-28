//A version of main.c using array notation possibly easier to read

#include <stdio.h>
#include <stdlib.h>

int add_int(int, int);
int multiply_int(int, int);

void operator(int (*[])(int,int), int, int, int);

int main(int argc, char *argv[]) {

  int (*arr_pfunc[])(int, int) = {add_int, multiply_int, NULL};

  operator(arr_pfunc, 90, 10, 5);

  exit(EXIT_SUCCESS);
}

int add_int(int a, int b) {
  return a + b;
}

int multiply_int(int a, int b) {
  return a * b;
}


void operator(int (*arr_func[])(int,int), int x, int y, int z) {
  int res = arr_func[1](arr_func[0](x, y), z);
  printf("res: '%d'\n", res);

  //iterating over array 90 + 10 then 90 * 10
  for(int i = 0; arr_func[i] != NULL; i++) {
    int res2 = arr_func[i](x, y);
    printf("res2: '%d'\n", res2);
  }

  //last thing I was trying to do was a c style iteration
  //  for(; **arr_func != NULL; arr_func++) {}
  // as we have a pointer to an array of pointers
  // error: called object ‘arr_func’ is not a function or function pointer
  // one of the issues is that add_int, *add_int, **add_int, ***add_int are the same
}

