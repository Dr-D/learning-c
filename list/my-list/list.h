#include "node.h"

struct List {
  struct Node *first;
  struct Node *last;
};

struct List *list_create(char *text);
