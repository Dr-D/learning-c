#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = open("test", O_WRONLY);
  write(fd, "TEST FIFO WRITE\n", 16);
  close(fd);
  
  return 0;
}
