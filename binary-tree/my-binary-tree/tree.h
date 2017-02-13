#include "node.h"

struct List {
  struct Node *first;
  struct Node *last;
};

struct List *list_create(char *);

void list_add(struct List *, char *);

void list_print(struct List *list);

void nodes_print(struct Node *node);

void list_destroy(struct List *list);
