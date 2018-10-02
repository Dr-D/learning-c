#include <stdio.h>
#include <stdlib.h>

void str_replace(char *dest, const char *src, const char replace, const char with) {
  while(*src != '\0') {
    if (*src == replace) {
      *dest = with;
    } else {
      *dest = *src;
    }

    dest ++;
    src++;
  }
}

int main(int argc, char *argv[]) {
  char *dest = malloc(sizeof(char) * 20);
  char *src = "Testing replace";

  str_replace(dest, src, 'e', 'u');

  printf("dest: '%s'\n", dest);

  char *src2 = "Testing #replace2";
  str_replace(dest, src2, '#', '\0');

  printf("dest2: '%s'\n", dest);

  free(dest);

  exit(EXIT_SUCCESS);
}
