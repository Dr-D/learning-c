#include <stdio.h>
#include <stdlib.h>

void strcopy(char *dest, const char *src) {
  while(*src != '\0') {
    *dest = *src;
    dest ++;
    src++;
  }
}

void strcopy2(char *dest, const char *src) {
  for( ;*src != '\0'; *dest = *src, dest ++, src++);
}

int main(int argc, char *argv[]) {

  char *dest = malloc(sizeof(char) * 20);
  char *pd = dest;
  char *src = "Testing copy";
  char *ps = src;
  while(*ps != '\0') {
    *pd = *ps;
    pd++;
    ps++;
  }
  printf("dest: '%s'\n", dest);

  char *src2 = "Testing strcopy";
  strcopy(dest, src2);
  printf("dest2: '%s'\n", dest);

  char *src3 = "Testing strcopy2";
  strcopy2(dest, src3);
  printf("dest3: '%s'\n", dest);

  printf("src2: '%s'\n", src2);
  printf("src3: '%s'\n", src3);

  free(dest);

  exit(EXIT_SUCCESS);
}
