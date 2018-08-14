#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#include "mserver.h"

int main(int argc, char *argv[]) {
  pthread_t server_thread;
  int res = pthread_create(&server_thread, NULL, mserver, "SERVER_THREAD");
  if (res) {
    fprintf(stderr, "Error - pthread_create(), response code: '%d'", res);
    exit(EXIT_FAILURE);
  }

  sprintf(mserver_get_message(), "Initial message\n");

  while(1) {
    time_t time_now;
    time(&time_now);

    printf("%s: %s\n", ctime(&time_now), mserver_get_message());
    sleep(1);
  }
}
