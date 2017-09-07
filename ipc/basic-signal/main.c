#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void myhandler() {
  fprintf(stderr, "Handled sig action\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {

  struct sigaction action;
  action.sa_handler = myhandler;

  if(sigaction(SIGINT, &action, NULL) < 0) {
    printf("sigaction: failed");
    exit(EXIT_FAILURE);
  }

  printf("Enter value:");
  
  char buff[20];
  scanf("%s", buff);
  printf("You entered: '%s'\n", buff);
  
  exit(EXIT_SUCCESS);
}
