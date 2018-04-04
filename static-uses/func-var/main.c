#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testStatic();
void testStatic2(char [], char **);

int main(int argc, char *argv[]) {

  int i;
  for(i = 0; i < 10; i++) {
    testStatic();
  }

  char *str = malloc(sizeof(char) * 10);
  
  testStatic2("first", &str);
  printf("str: '%s'\n", str);

  testStatic2("second", &str);
  strcpy(str, "BAD-CODE");

  testStatic2("third", &str);

  //  free(str);
  exit(EXIT_SUCCESS);
}

void testStatic() {
  static int st_int = 0;
  printf("st_int: '%d'\n", st_int);
  st_int++;
}

void testStatic2(char message[], char **strp) {
  static char text[10] = "Initial";
  printf("text: '%s'\n", text);
  strcpy(text, message);
  *strp = text;
}
