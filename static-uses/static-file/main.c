#include <stdio.h>
#include <stdlib.h>
#include "main.h"

static char text[100];

int main(int argc, char *argv[]) {
  printf("Enter text:");
  scanf("%s", text);

  sayHello();
  exit(EXIT_SUCCESS);
}

static void sayHello() {
  printf("Hello %s\n", text);
}
