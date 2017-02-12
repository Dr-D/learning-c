#include <string.h>
#include <stdlib.h>

#include "list.h"

struct List *list_create(char *text) {
  struct List *list = malloc(sizeof(struct List));
  
  struct Node *node = malloc(sizeof(struct Node));
  strcpy(node->text, text);

  list->first = node;
  list->last = node;

  return list;
}
