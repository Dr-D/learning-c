#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

#include "mserver.h"
#include "mclient.h"
#include "properties.h"
#include "readprops.h"

#define MESSAGE_SIZE 10

char multicast_addr[15];
char multicast_port[5];
char host_addr[15];

int main(int argc, char *argv[]) {

  read_properties();

  pthread_t server_thread;
  int serv_res = pthread_create(&server_thread, NULL, mserver, "SERVER_THREAD");
  if (serv_res) {
    fprintf(stderr, "Error - pthread_create(server), response code: '%d'", serv_res);
    exit(EXIT_FAILURE);
  }

  int client_res = pthread_create(&server_thread, NULL, mclient, "CLIENT_THREAD");
  if (client_res) {
    fprintf(stderr, "Error - pthread_create(client), response code: '%d'", client_res);
    exit(EXIT_FAILURE);
  }

  while(1){}
}
