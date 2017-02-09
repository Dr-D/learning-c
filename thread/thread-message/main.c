#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "Thread_Message.h"

void *run(void*);

int main(int argc, char *argv[]) {
  printf("Start main.\n");

  pthread_t thread;
  struct Thread_Message *message = thread_message_create("Test Message", 99);
  
  int created = pthread_create(&thread, NULL, run, message);

  //on success pthread_create returns 0.
  if(created != 0) {
    printf("Failed to create thread.\n");
    exit(EXIT_FAILURE);
  }
  
  pthread_join(thread, NULL);
  
  printf("End main.\n");
  
  exit(EXIT_SUCCESS);
}

void *run(void* param) {
  printf("In thread\n");

  struct Thread_Message *message = param;
  printf("Text: '%s', num: '%d'\n", message->text, message->num);
  
  return NULL;
}
