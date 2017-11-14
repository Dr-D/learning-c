#include <stdio.h>
#include <stdarg.h>

long fact_vars(int num, ...);

int main(int argc, char *argv[]) {
  long res =  fact_vars(5, 1, 2, 3, 4, 5);
  printf("fact: '%ld'\n", res);

  return 0;
}

long fact_vars(int num, ...) {
  va_list list;
  va_start(list, num);

  long fact = 1;
  for(int i = 0; i < num; i++) {
    fact *= va_arg(list, int);
  }

  va_end(list);

  return fact;
}
