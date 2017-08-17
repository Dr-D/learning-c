#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "node.h"

int main(int argc, char *argv[]) {

  struct Node node1;
  strcpy(node1.text, "First");

  struct Node node2;
  strcpy(node2.text, "Second");

  node1.link = &node2;

  printf("Node1 text: '%s'\n", node1.text);
  printf("Node1 link text: '%s'\n", node1.link->text);
  
  exit(EXIT_SUCCESS);
}
