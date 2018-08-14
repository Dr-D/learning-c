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
#include <time.h>

static char shared_message[100];

void *server(void *ptr);

int main(int argc, char *argv[]) {
  pthread_t server_thread;
  int res = pthread_create(&server_thread, NULL, server, "SERVER_THREAD");
  if (res) {
    fprintf(stderr, "Error - pthread_create(), response code: '%d'", res);
    exit(EXIT_FAILURE);
  }

  sprintf(shared_message, "Initial message\n");

  while(1) {
    time_t time_now;
    time(&time_now);

    printf("%s: %s\n", ctime(&time_now), shared_message);
    sleep(1);
  }
}

void *server(void *ptr) {
  struct addrinfo hints, *res;
  memset(&hints, 0 , sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_protocol = 0;

  getaddrinfo("0.0.0.0", "12345", &hints, &res);

  int sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  u_int yes = 1;
  setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));

  bind(sd, res->ai_addr, res->ai_addrlen);

  struct ip_mreq mreq;
  mreq.imr_multiaddr.s_addr = inet_addr("225.0.0.37");
  mreq.imr_interface.s_addr = htonl(INADDR_ANY);
  setsockopt(sd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));

  while (1) {
    recvfrom(sd, shared_message, 100, 0, res->ai_addr, &res->ai_addrlen);
  }
}
