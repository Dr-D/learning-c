#include <stdio.h>
#include <stdlib.h>

void* get_int(void *);
void* get_char(void *);

int main(int argc, char *argv[]) {
  int i = 97;
  int *pi = &i;

  int *int_result = get_int(pi);
  printf("int_result: '%d'\n", *int_result);

  char *char_result = get_char(pi);
  printf("char_result: '%c'\n", *char_result);
  
  exit(EXIT_SUCCESS);
}

void* get_int(void *param) {
  int *pnum = (int*)param;
  return pnum;
}

void* get_char(void *param) {
  char *pchar = param;
  return pchar;
}
