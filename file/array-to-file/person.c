#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "person.h"

struct Person *person_create(int acc_num, char *first, char *last) {
  struct Person *pperson = malloc(sizeof(struct Person));
  pperson->account_num = acc_num;
  strcpy(pperson->first_name, first);
  strcpy(pperson->last_name, last);

  return pperson;
}

void person_print(struct Person *pperson) {
  printf("Account Num: '%d', First Name: '%s', Last Name '%s'\n", pperson->account_num, pperson->first_name, pperson->last_name);
}
