#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trim.h"

#define MAXLINE 256
#define MAX_LENGTH 254
#define MAX_PROPERTIES 10
#define COMMENT_CHAR '#'

struct Property {
  char name[254 + 1];
  char value[254 + 1];
};

struct Property properties[MAX_PROPERTIES];//dependent on how many are required

static void check_max_length(char [], int);
static int create_property(char [], struct Property*);

int main(int argc, char *argv[]) {

  const char *filename = "config";
  FILE *fp = fopen(filename, "r");

  char buff[MAXLINE];
  if(fp != NULL) {
    while(! feof(fp)){

      fgets(buff, MAXLINE, fp);

      check_max_length(buff, MAX_LENGTH);
      char *trimmed = malloc(sizeof(char) * strlen(buff));
      strtrim(buff, trimmed);

      struct Property property;
      if (create_property(trimmed, &property)) {

      };

      printf("property: '%s':'%s'\n", property.name, property.value);
      free(trimmed);
    }
  } else {
    fprintf(stderr, "Could no open configuration file: '%s'\n", filename);
    exit(EXIT_FAILURE);
  }
}

static void check_max_length(char buff[], int max_length) {
  if(strlen(buff) > max_length) {
    fprintf(stderr, "Error configuration line too long: '%s'\n", buff);
    exit(EXIT_FAILURE);
  }
}


static int create_property(char buff[], struct Property *pproperty) {
  //exclude if line starts with a # or empty
  if (*buff == '#' || strlen(buff) == 0) {
    return 0;//bail out early
  }

  //replace  # with '\0'
  while(){}

  char *tok_save;
  char *name = strtok_r(buff, " ", &tok_save);

  strcpy(pproperty->name, name);

  char * value = strtok_r(NULL, " ", &tok_save);
  strcpy(pproperty->value, value);
  if(name != NULL && value != NULL) {
    return 1;
  }

  return 0;
}
