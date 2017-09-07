#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  int suc = mkfifo("test", 0666);
  if(suc < 0) {
    fprintf(stderr, "Failed to make fifo.\n");
  }
  
  return 0;
}
