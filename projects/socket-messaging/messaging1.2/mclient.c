#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

#include "mclient.h"

char multicast_addr[15];
char multicast_port[5];

#define MESSAGE_SIZE 10

void* mclient(void *ptr) {
  printf("Starting client address: '%s', port: '%s'\n", multicast_addr, multicast_port);

  struct addrinfo hints, *res;
  memset(&hints, 0 , sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_DGRAM;

  getaddrinfo(multicast_addr, multicast_port, &hints, &res);

  int sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  while(1) {
    printf("Enter message: ");
    char client_message[MESSAGE_SIZE];
    fgets(client_message, MESSAGE_SIZE, stdin);

    //swap new line for end of string char
    for(int i = 0; i < MESSAGE_SIZE; i++) {
      if(client_message[i] == '\n') {
        client_message[i] = '\0';
      }
    }

    client_message[MESSAGE_SIZE -1] = '\0';//ensure max size of string

    sendto(sd, client_message, strlen(client_message) + 1,0,  res->ai_addr, res->ai_addrlen);
    sleep(1);
  }

  close(sd);
}
