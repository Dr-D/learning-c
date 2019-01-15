#ifndef _node_h_

#define _node_h_

struct Node {
  char text[20];
  struct Node *link;
};

void set_add(char *text);

void set_remove(char *text);

struct Node *set_get();

void set_print();

#endif
