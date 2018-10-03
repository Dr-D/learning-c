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

#define MESSAGE_SIZE 10

char multicast_addr[15];
char multicast_port[5];

static void read_properties();

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

static void read_properties() {

  struct Property *pprops = properties_get();
  struct Property *temp = pprops;
  printf("\n\nGot properties from config file.\n");

  int i = 0;
  while(pprops != NULL) {
    printf("Found property[%d]): '%s':'%s'\n", i, pprops->name, pprops->value);
    pprops = pprops->property;
    i++;
  }

  pprops = temp;

  struct Property prop_arr[i];
  for(int j = 0; j < i; j++) {
    properties_copy(pprops, &prop_arr[j]);
    if(strcmp("MULTICAST_ADDRESS", pprops->name) == 0) {
      if(strlen(pprops->value) > 15) {
        fprintf(stderr, "Invalid MULTICAST_ADDRESS: '%s'", pprops->value);
        exit(EXIT_FAILURE);
      }
      strcpy(multicast_addr, pprops->value);
        printf("Copied  property[%d]): '%s':'%s'\n", j, prop_arr[j].name, prop_arr[j].value);
    }
    if(strcmp("MULTICAST_PORT", pprops->name) == 0) {
      if(strlen(pprops->value) > 5) {
        fprintf(stderr, "Invalid MULTICAST_PORT: '%s'", pprops->value);
        exit(EXIT_FAILURE);
      }
      strcpy(multicast_port, pprops->value);
      printf("Copied  property[%d]): '%s':'%s'\n", j, prop_arr[j].name, prop_arr[j].value);
    }

    pprops = pprops->property;
  }

  properties_free();
}
