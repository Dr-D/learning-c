#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "node.h"

static struct Node *set = NULL;

void set_add(char *text) {
  printf("Adding: '%s' to set.\n", text);
  if (set == NULL) {
    set = malloc(sizeof(struct Node));
    strcpy(set->text, text);
    return;
  }

  struct Node *tmp = set;
  struct Node *tmp_prev;
  int comp;
  do {
    if (tmp->link == NULL) {
      printf("tmp->text: '%s', tmp->link is NULL\n", tmp->text);
      tmp->link = malloc(sizeof(struct Node));
      strcpy(tmp->link->text, text);
      return;
    }

    tmp_prev = tmp;
    tmp = tmp->link;
    comp = strcmp(text, tmp->text);
    printf("text: '%s', tmp->text: '%s', comp: '%d'\n", text, tmp->text, comp);
  } while (comp > 0);

  //text is the same do not add to list
  if (comp == 0) {
    printf("tmp->text: '%s', text: '%s'\n", tmp->text, text);
    return;
  }

  printf("tmp_prev->text: '%s', tmp->text: '%s'\n", tmp_prev->text, tmp->text);

  //the new text is bigger than tmp_prev->text value
  struct Node *new = malloc(sizeof(struct Node));
  strcpy(new->text, text);

  struct Node *tmp_link = tmp_prev->link;
  tmp_prev->link = new;

  new->link = tmp_link;

  return;
}

void set_remove(char *text) {
  if (set == NULL) {
    printf("Cannot remove from empty set");
    return;
  }

  struct Node *tmp = set;
  struct Node *tmp_prev = NULL;
  do {
    if (strcmp(text, tmp->text) == 0) {
      if (tmp_prev == NULL) {
        //removing first
        set = set->link;
      } else {
        tmp_prev->link = tmp->link;
      }
      free(tmp);
      return;
    }
    tmp_prev = tmp;
    tmp = tmp->link;
  } while (tmp != NULL);
}

//returns a copy of the first node in the list
struct Node *set_get() {
  struct Node* tmp = malloc(sizeof(struct Node*));
  tmp = set;
  return tmp;
}

void set_print() {
  if (set == NULL) {
    printf("EMPTY\n");
  }

  struct Node *tmp = set;
  do {
    printf("%s\n", tmp->text);
    tmp = tmp->link;
  } while(tmp != NULL);
}
