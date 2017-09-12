#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct Person {
  int age;
  char name[20];
};

int main(int argc, char *argv[]) {

  key_t key = ftok("/tmp", 'R');
  int shmid = shmget(key, 1024, 0644 | IPC_CREAT);

  struct Person *data = shmat(shmid, (void *)0, 0);// returns a void pointer
  if (data == (struct Person *)(-1)) {
    perror("shared memory attach(shmat)");
  }

  printf("Enter age: ");
  scanf("%d", &data->age);

  printf("Enter name: ");
  scanf("%s", data->name);

  printf("Person: '%s', Age: '%d'\n", data->name, data->age);

  shmdt(data);//shared memory detach -1 on error/0 success

  shmctl(shmid, IPC_RMID, NULL);

  return 0;
}
