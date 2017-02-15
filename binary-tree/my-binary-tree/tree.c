#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "tree.h"

struct Tree *tree_create(int num) {
  struct Tree *tree = malloc(sizeof(struct Tree));
  
  struct Node *node = malloc(sizeof(struct Node));
  node->num = num;
  node->left = NULL;
  node->right = NULL;

  tree->node = node;
  return tree;
}

void tree_add(struct Tree *tree, int num) {
  struct Node *node_new = malloc(sizeof(struct Node));
  node_new->num = num;
  node_new->left = NULL;
  node_new->right = NULL;

  
}

void node_add(struct Node *node_current, int num) {
  struct Node *new_node;
  if(num < node_current->num) {
    new_node = node_current->left;
  }
  if(num > node_current->num) {
    new_node = node_current->right;
  }
  
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
