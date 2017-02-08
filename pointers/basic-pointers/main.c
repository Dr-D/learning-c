#include <stdio.h>
#include <stdlib.h>

void try_swap_chars(char , char);

void swap_chars(char *, char *);

int main(int argc, char *argv[]) {

  char char1 = 'a';
  char char2 = 'b';

  printf("Before try_swap char1: '%c', char2: '%c'\n", char1, char2);

  try_swap_chars(char1, char2);

  printf("After try_swap char1: '%c', char2: '%c'\n", char1, char2);

  char *pchar1 = &char1;
  char *pchar2 = &char2;
  swap_chars(pchar1, pchar2);
  
  printf("After swap char1: '%c', char2: '%c'\n", char1, char2);
  
  
  exit(EXIT_SUCCESS);
}

void try_swap_chars(char c1, char c2) {
  char temp = c1;
  c1 = c2;
  c2 = temp;

  printf("In try_swap c1: '%c', c2: '%c'\n", c1, c2);
};

void swap_chars(char *c1, char *c2) {
  char temp = *c1;
  *c1 = *c2;
  *c2 = temp;
}
