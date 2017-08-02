#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

  pid_t pid = fork();

  if(pid > 0) {
    printf("This is the parent process\n");

  } else {
    if(pid == 0) {
      printf("This is the child process, pid: '%d'\n", getpid());

      char *args[] = {"/bin/sh", "-c", "echo test", NULL};
      execve("/bin/sh", args, NULL);
      printf("This should not show if execve is successful.\n");
    } else {
      printf("Error forking. pid was: '%d'\n", pid);
    }
  }
}
