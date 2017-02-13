#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "list.h"

struct List *list_create(char *text) {
  struct List *list = malloc(sizeof(struct List));
  
  struct Node *node = malloc(sizeof(struct Node));
  strcpy(node->text, text);

  list->first = node;
  list->last = node;

  return list;
}

void list_add(struct List *list, char *text) {
  struct Node *node = malloc(sizeof(struct Node));
  strcpy(node->text, text);

  list->last->link = node;
  list->last = node;
}

void list_print(struct List *list) {
  nodes_print(list->first);
}

void nodes_print(struct Node *node) {
  printf("%s\n", node->text);
  if(node->link != NULL) {
    nodes_print(node->link);
  }
}

void list_destroy(struct List *list) {
  struct Node *node = list->first;
  if(node->link != NULL) {
    list->first = node->link;
    list_destroy(list);
  }
}
