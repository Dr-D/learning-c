#include <stdio.h>
#include <stdlib.h>

struct TestSize {
  char ch[1];
  int i;
};

struct TestSize2 {
  int i;
  char ch[1];
};


struct TestSize3 {
  short sh;
  char ch[1];
  int i;
};


int main(int argc, char *argv[]) {

  printf("TestSize: '%ld'\n", sizeof(struct TestSize));

  printf("TestSize2: '%ld'\n", sizeof(struct TestSize2));

  printf("TestSize3: '%ld'\n", sizeof(struct TestSize3));

  exit(EXIT_SUCCESS);
}
