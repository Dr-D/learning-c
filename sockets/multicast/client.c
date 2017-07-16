#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  
  struct addrinfo hints, *res;
  memset(&hints, 0 , sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_DGRAM;

  getaddrinfo("225.0.0.37", "12345", &hints, &res);

  int sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  for(int i = 0; i < 10; i++) {
    char message[100] = "Hello Multicast";
    if(argc > 1) {
      sprintf(message, "argv: '%s', count: '%d'", argv[1], i);
    }

    sendto(sd, message, strlen(message),0,  res->ai_addr, res->ai_addrlen);
  }
  
  close(sd);
}

