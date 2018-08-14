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

int main(int argc, char *argv[]) {
  pthread_t server_thread;
  int pthread_res = pthread_create(&server_thread, NULL, mserver, "SERVER_THREAD");
  if (pthread_res) {
    fprintf(stderr, "Error - pthread_create(), response code: '%d'", pthread_res);
    exit(EXIT_FAILURE);
  }

  struct addrinfo hints, *res;
  memset(&hints, 0 , sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_DGRAM;

  getaddrinfo("225.0.0.37", "12345", &hints, &res);

  int sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  while(1) {
    printf("Enter message: ");
    char client_message[100];
    fgets(client_message, 100, stdin); 
    
    sendto(sd, client_message, strlen(client_message),0,  res->ai_addr, res->ai_addrlen);
  }

  close(sd);
}
