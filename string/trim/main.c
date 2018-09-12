#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void strtrim(char *, char *);

int main(int argc, char *argv[]) {

  char *src = " Testing Trim1   ";
  /*  char *src = "  \t\v   ";
  char *src = "1";
  char *src = " ";
  char *src = "                                                                                                                                               TESTING A LONG STRING WITH ALOT OF SPACES                                                                                                                    ";
  char *src = "                                                                                                                                               TESTING A LONG STRING WITH ALOT OF SPACES AND A SINGLE CHAR AT THE END                                                                                                                   1";
  char *src = "1                                                                                                                                               TESTING A LONG STRING WITH ALOT OF SPACES AND A SINGLE CHAR AT THE END AND BEGINING                                                                                                                  1";
  */

  char *dst = malloc(sizeof(char) * strlen(src));
  printf("pre trim: '%s'\n", src);

  strtrim(src, dst);
  printf("post trim src: '%s', dst: '%s'\n", src, dst);

  exit(EXIT_SUCCESS);
}

void strtrim(char *src, char *dst) {
  while(isspace(*src)) {
    src++;
    printf("src: '%s'\n", src);
  }

  printf("mid trim src: '%s', dst: '%s'\n", src, dst);

  *dst = *src;
  char *tmp = dst;
  //move to end of string
  while(*src != '\0') {
    *dst = *src;//copy string
    dst++;
    src++;
    printf("src: '%s'\n", src);
  }

  if (*tmp == '\0') {
    printf("Empty String returning\n");
    return;
  }

  //move back to first non-space char. Possible issues if string is empty
  do {
    dst--;
    printf("src: '%s'\n", dst);
  } while(isspace(*dst));

  //put the terminating char after the first non space char
  *(dst + 1) = '\0';//
  printf("final: '%s'\n", dst);
}
