#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main(int argc, char *argv[]) {
  key_t key;
  int shmid;
  char *data;
  key = ftok("/tmp", 'R');
  shmid = shmget(key, 1024, 0644 | IPC_CREAT);
  data = shmat(shmid, (void *)0, 0);

  if (data == (char *)(-1))
    perror("shmat");

  printf("Enter a string: ");
  gets(data);

  printf("shared contents: %s\n", data);

  shmdt(data);//-1 on error/0 success

  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}
