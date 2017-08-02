#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

  int pfd[2];

  pipe(pfd);

  pid_t pid = fork();

  if(pid > 0) {
    printf("This is the parent process\n");
    char write_b[] = "Writing to pipe.";
    write(pfd[1], write_b, strlen(write_b));
  } else {
    if(pid == 0) {
      printf("This is the child.\n");
      char read_b[100];
      read(pfd[0], read_b, 100);
      printf("%s\n", read_b);      
    } else {
      printf("Error forking. pid was: '%d'\n", pid);
    }
  }

  
}
