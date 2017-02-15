#include "node.h"

struct Tree {
  struct Node *node;
};

struct Tree *tree_create(int);

void tree_add(struct Tree *, int);

void tree_print(struct Tree *);

void nodes_print(struct Node *);

void tree_destroy(struct Tree *);
