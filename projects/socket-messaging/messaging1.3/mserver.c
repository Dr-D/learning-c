#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <pthread.h>

#include "mserver.h"

char multicast_addr[15];
char multicast_port[5];
char host_addr[15];

static char shared_message[15];

struct ListAddress {
  char address[15];
  struct ListAddress *next;
};

static struct ListAddress *addresses;

char *mserver_get_message() {
  return shared_message;
}

static void add_address();

void *mserver(void *ptr) {
  addresses = NULL;
  printf("Starting server address: '%s', port: '%s'\n", multicast_addr, multicast_port);

  struct addrinfo hints, *res;
  memset(&hints, 0 , sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_protocol = 0;

  getaddrinfo("0.0.0.0", multicast_port, &hints, &res);

  int sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  u_int yes = 1;
  setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));

  bind(sd, res->ai_addr, res->ai_addrlen);

  struct ip_mreq mreq;
  mreq.imr_multiaddr.s_addr = inet_addr(multicast_addr);
  mreq.imr_interface.s_addr = htonl(INADDR_ANY);
  setsockopt(sd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));

  sprintf(shared_message, "Init message\n");

  while (1) {
    recvfrom(sd, shared_message, 100, 0, res->ai_addr, &res->ai_addrlen);
    time_t time_now;
    time(&time_now);
    add_address(shared_message);

    //ctime returns string that has new line on the end
    printf("%s Received host address: %s\n", ctime(&time_now), host_addr);
  }
}

//Add the address if not already present, ordered by ip address
static void add_address(char address[]) {
  if (addresses == NULL) {
    addresses = malloc(sizeof(struct ListAddress));
    strcpy(addresses->address, address);
    addresses->next = NULL;
  }

  //smallest should be first
  if(strcmp() == -1) {
    tmp = addresses;
    addresses = malloc(sizeof(struct ListAddress));
    strcpy(addresses->address, address);
    addresses->next = tmp;
  }

  

}
