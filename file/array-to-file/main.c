#include <stdio.h>
#include <stdlib.h>

#include "person.h"

int main(int argc, char *argv[]) {
  const char *path = "test.bin";
  const int SIZE = 3;

  struct Person persons[SIZE];
  persons[0] = *person_create(1, "Mickey", "Mouse");
  persons[1] = *person_create(2, "Donald", "Duck");
  persons[2] = *person_create(3, "Minnie", "Mouse");

  FILE *fp_write = fopen(path, "w");

  if(fp_write == NULL) {
    printf("Unable to open file for writing: '%s'\n", path);
    exit(EXIT_FAILURE);
  }

  fwrite(persons, sizeof(struct Person), SIZE, fp_write);

  fclose(fp_write);

  printf("Finished writing to file: '%s'\n", path);
  
  FILE *fp_read = fopen(path, "r");
  
  if(fp_read == NULL) {
    printf("Unable to open file for reading: '%s'\n", path);
    exit(EXIT_FAILURE);
  }

  struct Person persons_read[SIZE];
  fread(persons_read, sizeof(struct Person), SIZE, fp_read);

  fclose(fp_read);
  
  int i;
  for(i = 0; i < SIZE; i++) {
    person_print(&persons_read[i]);
  }
  
  exit(EXIT_SUCCESS);
}
