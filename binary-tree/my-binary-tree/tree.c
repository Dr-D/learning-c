#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

struct Tree *tree_create(int num) {
  struct Tree *tree = malloc(sizeof(struct Tree));
  
  struct Node *node = malloc(sizeof(struct Node));
  node->num = num;

  tree->left = node;
  tree->right = node;

  return tree;
}

void tree_add(struct Tree *tree, int num) {
  /*struct Node *node = malloc(sizeof(struct Node));
  node->num = num;

  tree->last->link = node;
  tree->last = node;*/
}

void tree_print(struct Tree *tree) {
  //nodes_print(tree->first);
}

void nodes_print(struct Node *node) {
  /*printf("%s\n", node->num);
  if(node->link != NULL) {
    nodes_print(node->link);
    }*/
}

void tree_destroy(struct Tree *tree) {
  /*  struct Node *node = tree->first;
  if(node->link != NULL) {
    tree->first = node->link;
    tree_destroy(tree);
    }*/
}
