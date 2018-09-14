#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "trim.h"

void strtrim(char *src, char *dst) {
  while(isspace(*src)) {
    src++;
    printf("src: '%s'\n", src);
  }

  *dst = *src;
  char *tmp = dst;
  //move to end of string
  while(*src != '\0') {
    *dst = *src;//copy string
    dst++;
    src++;
  }

  if (*tmp == '\0') {
    return;
  }

  //move back to first non-space char. Possible issues if string is empty
  do {
    dst--;
  } while(isspace(*dst));

  //put the terminating char after the first non space char
  *(dst + 1) = '\0';//
}
