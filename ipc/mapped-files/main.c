#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = open("mapped", O_RDWR);
  printf("fd: '%d'\n", fd);
  
  int page_size = getpagesize();
  printf("PageSize: '%d'\n", page_size);

  posix_fallocate(fd, 0, page_size + 1);//the file needs to be big enough to hold page_size
  
  char *data =  mmap((caddr_t)0, page_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, page_size);
  printf("data: '%s'\n", data);

  char *pdata = data;//make copy of pointer that is pointing to start or mapped memory
  char arr[] = "Hello World!";
  char *cp;
  //copy chars into mapped memory
  for(cp = arr; *cp != '\0'; cp ++, data ++) {
    *data = *cp;
  }
  
  printf("data: '%s'\n", pdata);
  
  return 0;
}
