#include <string.h>
#include <stdlib.h>

#include "Thread_Return.h"

struct Thread_Return *thread_return_create(char *text, int num) {
  struct Thread_Return *t_return = malloc(sizeof(struct Thread_Return));
  strcpy(t_return->text, text);
  t_return->num = num;
  return t_return;
}
