#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trim.h"
#include "properties.h"

#define MAXLINE 256
#define MAX_LENGTH 254
#define COMMENT_CHAR '#'

static struct Property *property_list;

static void check_max_length(char [], int);
static int properties_create(char [], struct Property*);
static void str_replace(char *dest, const char *src, const char replace, const char with);
static void properties_add(struct Property *pproperty, struct Property **property_list_temp);

void properties_free() {
  while(property_list->property != NULL) {
    struct Property *temp = property_list->property;
    printf("Freeing property: '%s':'%s'\n", property_list->name, property_list->value);
    free(property_list);
    property_list = temp;
  }
  printf("Freeing last property: '%s':'%s'\n", property_list->name, property_list->value);
  free(property_list);
}

//creates a linked list of struct Property
struct Property *properties_get() {
  property_list = NULL;
  struct Property *property_list_temp = NULL;

  const char *filename = "config";
  FILE *fp = fopen(filename, "r");

  char buff[MAXLINE];
  if(fp == NULL) {
      fprintf(stderr, "Could not open configuration file: '%s'\n", filename);
    exit(EXIT_FAILURE);
  }

  while(! feof(fp)){
    fgets(buff, MAXLINE, fp);

    check_max_length(buff, MAX_LENGTH);

    char *trimmed = malloc(sizeof(char) * strlen(buff));
    strtrim(buff, trimmed);

    struct Property *pproperty =  malloc(sizeof(struct Property));
    if (properties_create(trimmed, pproperty)) {
      printf("Found valid property: '%s':'%s'\n", pproperty->name, pproperty->value);
      properties_add(pproperty, &property_list_temp);
      printf("property_list: '%s':'%s'\n", property_list->name, property_list->value);
      printf("property_list_temp: '%s':'%s'\n", property_list_temp->name, property_list_temp->value);
    };

    free(trimmed);
    strcpy(buff, "\0");
  }

  fclose(fp);

  property_list = property_list_temp;
  return property_list;
}

void properties_copy(struct Property *src, struct Property *dest) {
  strcpy(dest->name, src->name);
  strcpy(dest->value, src->value);
}

static void properties_add(struct Property *pproperty, struct Property **property_list_temp) {
  if (property_list == NULL) {
    property_list = pproperty;//static variable
    printf("Setting property_list_temp\n");
    *property_list_temp = pproperty;//non-static variable, need to pass pointer to pointer
  } else {
    property_list->property = pproperty;
    property_list = pproperty;
  }
}

static void check_max_length(char buff[], int max_length) {
  if(strlen(buff) > max_length) {
    fprintf(stderr, "Error configuration line too long: '%s'\n", buff);
    exit(EXIT_FAILURE);
  }
}

//Added some of the checks in here as already needed to check if strtok creates name & value
static int properties_create(char buff[], struct Property *pproperty) {
  //exclude if line starts with a # or empty
  if (*buff == '#' || strlen(buff) == 0) {
    printf("Bailing out early first char: '%c', strlen: '%ld'\n", *buff, strlen(buff));
    return 0;
  }

  //We have trimmed the string and made sure it is not a comment or an empty string.
  //Now we remove end of line comments - replace  # with '\0'.
  char *updated_buff = malloc(sizeof(char)  * strlen(buff));
  str_replace(updated_buff, buff, '#', '\0');
  //do we need to re-trim here - looks like strtok takes care of it

  char *tok_save;
  //This uses a space a delimiter i.e. tabs wont work
  char *name = strtok_r(updated_buff, " ", &tok_save);

  strcpy(pproperty->name, name);

  char * value = strtok_r(NULL, " ", &tok_save);
  if(value == NULL) {
    printf("Line only contains single string: '%s'\n", name);
    return 0;//You may want to exit here as a badly formatted file
  }

  strcpy(pproperty->value, value);

  return 1;
}

//replace a char in a string
static void str_replace(char *dest, const char *src, const char replace, const char with) {
  while(*src != '\0') {
    if (*src == replace) {
      *dest = with;
    } else {
      *dest = *src;
    }

    dest ++;
    src++;
  }
}
