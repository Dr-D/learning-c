#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

  struct addrinfo hints, *res;
  memset(&hints, 0 , sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_DGRAM;

  getaddrinfo("0.0.0.0", "12345", &hints, &res);

  int sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  u_int yes=1;
  /*Allows socket to forcibly bind to a port already in use */
  setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
 
  bind(sd, res->ai_addr, res->ai_addrlen);
     
  /* join IPv4 multicast group */
  struct ip_mreq mreq;
  mreq.imr_multiaddr.s_addr=inet_addr("225.0.0.37");
  mreq.imr_interface.s_addr=htonl(INADDR_ANY);
  setsockopt(sd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));

  while (1) {
    char read_b[100];
    memset(&read_b, 0, 100);
    int n =  recvfrom(sd, read_b, 100, 0, res->ai_addr, &res->ai_addrlen);
    printf("%s\n", read_b);
  }
}
