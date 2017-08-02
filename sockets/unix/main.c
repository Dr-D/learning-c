#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char* argv[]) {
  struct sockaddr_un addr;
  memset(&addr, 0, sizeof addr);
  addr.sun_family = AF_UNIX;
  strncpy(addr.sun_path, "socket", sizeof(addr.sun_path)-1);
  
  int sd = socket(addr.sun_family, SOCK_STREAM, 0);

  int b = bind(sd, (struct sockaddr*)&addr, sizeof(addr));
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
