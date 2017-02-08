#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  const char *path = "test.bin";
  int i = 10;
  
  FILE *fp_write = fopen(path, "w");

  if(fp_write == NULL) {
    printf("Unable to open file for writing: '%s'\n", path);
    exit(EXIT_FAILURE);
  }

  fwrite(&i, sizeof(int), 1, fp_write);

  fclose(fp_write);

  printf("Finished writing to file: '%s'\n", path);
  
  FILE *fp_read = fopen(path, "r");
  
  if(fp_read == NULL) {
    printf("Unable to open file for reading: '%s'\n", path);
    exit(EXIT_FAILURE);
  }

  int num;
  fread(&num, sizeof(int), 1, fp_read);

  fclose(fp_read);

  printf("Number read from file: '%d'\n", num);
  
  exit(EXIT_SUCCESS);
}
