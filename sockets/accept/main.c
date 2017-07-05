#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char* argv[]) {
  struct addrinfo hints, *res;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  
  getaddrinfo(NULL, "6000", &hints, &res);
  
  int sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  int b = bind(sd, res->ai_addr, res->ai_addrlen);
  if(b == -1) {
    printf("Could not bind.");
    exit(EXIT_FAILURE);
  }

  int l = listen(sd, 10);

  while(1) {
    int acc = accept(sd, (struct sockaddr*)NULL, NULL);
    
    char read_b[2048];
    int r = read(acc, read_b, 2048);
    printf("%s\n", read_b);
    
    char write_b[] = "Testing Socket";
    write(acc, write_b, strlen(write_b));
    
    close(acc);
  }
}
