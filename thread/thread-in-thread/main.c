#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *run(void *ptr);

int main(int argc, char *argv[]) {
  printf("Started main()\n");
  pthread_t thread1;
  int res = pthread_create(&thread1, NULL, run, "thread1");
  if(res) {
    fprintf(stderr, "Error pthread_create(thread1) response code: '%d'", res);
    exit(EXIT_FAILURE);
  }

  sleep(1);
  pthread_join(thread1, NULL);

  printf("Exiting main()\n");

  exit(EXIT_SUCCESS);
}

void *run2(void *ptr);

void *run(void *ptr) {
  char *threadName = ptr;
  printf("Started thread: '%s'\n", threadName);

  pthread_t thread1_1;
  int res = pthread_create(&thread1_1, NULL, run2, "thread1_1");
  if(res) {
    fprintf(stderr, "Error pthread_create() response code: '%d'", res);
    exit(EXIT_FAILURE);
  }

  pthread_t thread1_2;
  res = pthread_create(&thread1_2, NULL, run2, "thread1_2");
  if(res) {
    fprintf(stderr, "Error pthread_create() response code: '%d'", res);
    exit(EXIT_FAILURE);
  }

  sleep(1);
  pthread_join(thread1_1, NULL);
  pthread_join(thread1_2, NULL);

  printf("Exiting thread: '%s'\n", threadName);

  return NULL;
}

void *run2(void *ptr) {
  char *threadName = ptr;
  printf("Started thread: '%s'\n", threadName);
  sleep(1);
  printf("Exiting thread: '%s'\n", threadName);

  return NULL;
}
