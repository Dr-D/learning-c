#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main(int argc, char *argv[]) {

  struct Tree *tree = tree_create(1);

  tree_add(tree, 2);
  tree_add(tree, 3);
  tree_add(tree, 4);

  tree_print(tree);

  tree_destroy(tree);
  exit(EXIT_SUCCESS);
}
