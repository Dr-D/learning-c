#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  const char *path = "test.txt";

  FILE *fp_write = fopen(path, "w"); 

  if(fp_write == NULL) {
    printf("Could not open file for write: '%s'\n", path);
    exit(EXIT_FAILURE);
  }

  fprintf(fp_write, "Hello World!\n");

  fclose(fp_write);
  printf("Finished writing to file: '%s'\n", path);

  FILE *fp_read = fopen(path, "r"); 

  if(fp_read == NULL) {
    printf("Could not open file for reading: '%s'\n", path);
    exit(EXIT_FAILURE);
  }

  char c;
  while((c = getc(fp_read)) != EOF) {
    putchar(c);
  }

  fclose(fp_read);
  
  exit(EXIT_SUCCESS);
}
