#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>

struct msgbuf {
  long mtype;
  char name[20]; // this can be a struct so that anything can be sent
};

int main(int argc, char *argv[]) {
  //might be better to create a file here check it exists then do ftok
  key_t key = ftok("/bin", 'a');
  printf("key: '%d' ", key); 
  
  int qid = msgget(key, 0666 | IPC_CREAT);
  printf("queue id: '%d'\n", qid);
 
  struct msgbuf mbuf = { 2, "TESTING MESSAGE"};
  int size = sizeof mbuf.name;
  /* msgsnd(qid, &mbuf, size, 0); */

  struct msgbuf mbuf_rec;
  msgrcv(qid, &mbuf_rec, size, 2, 0);

  printf("Recieved msg: '%s'", mbuf_rec.name);
  return 0;

  //destroy the queue use ipcs to get list of the queues
  //ipcrm to remove 
}
