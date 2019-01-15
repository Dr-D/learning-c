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
char host_addr[15];

#define MESSAGE_SIZE 15

static char *format_ip(char *address);

void* mclient(void *ptr) {
  printf("Starting client address: '%s', port: '%s'\n", multicast_addr, multicast_port);

  struct addrinfo hints, *res;
  memset(&hints, 0 , sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_DGRAM;

  getaddrinfo(multicast_addr, multicast_port, &hints, &res);

  int sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

  while(1) {
    format_ip(host_addr);
    sendto(sd, host_addr, strlen(host_addr) + 1,0,  res->ai_addr, res->ai_addrlen);
    sleep(1);
  }

  close(sd);
}

static char *format_ip(char *address) {
  char byte1[4];
  char byte2[4];
  char byte3[4];
  char byte4[4];
  char *addr = malloc(sizeof(char) * strlen(address));
  strcpy(addr, address);

  char *b1 = strtok(addr, ".");
  strcpy(byte1, b1);

  char *b2 = strtok(NULL, ".");
  strcpy(byte2, b2);

  char *b3 = strtok(NULL, ".");
  strcpy(byte3, b3);

  char *b4 = strtok(NULL, ".");
  strcpy(byte4, b4);

}

static void *format_byte(char * byte) {
  const int size = 3;
  char arr[4];
  strcpy(arr, byte);
  printf("arr: '%s'\n", arr);

  int len = strlen(byte);
  int diff = size - len;

  memmove(arr + diff, arr, len);
  memset(arr, '0', diff);
  printf("arr: '%s'\n", arr);

}
