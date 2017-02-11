#include <string.h>
#include <stdlib.h>

#include "Thread_Message.h"

struct Thread_Message *thread_message_create(char *text, int num) {
  struct Thread_Message *message = malloc(sizeof(struct Thread_Message));
  strcpy(message->text, text);
  message->num = num;
  return message;
}
