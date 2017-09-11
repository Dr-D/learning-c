#include <stdio.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>

#define MAX_SIZE 1000

struct msgbuf {
  long mtype;
  char text[MAX_SIZE];
};

int main(int argc, char *argv[]) {
  
  key_t key = ftok("/bin", 'a');
  printf("key: '%d' ", key); 
  
  int qid = msgget(key, 0666 | IPC_CREAT);
  printf("queue id: '%d'\n", qid);
 
  struct msgbuf mbuf;
  mbuf.mtype = 2;
  
  FILE *fp = fopen("test.pdf", "r");
  fread(mbuf.text, sizeof(char), MAX_SIZE, fp); 
  fclose(fp);

  printf("Sending message\n");
  msgsnd(qid, &mbuf, MAX_SIZE, 0);

  struct msgbuf mbuf_rec;
  msgrcv(qid, &mbuf_rec, MAX_SIZE, 2, 0);
  
  FILE *fp_rec = fopen("received.pdf", "w");  
  fwrite(mbuf_rec.text, sizeof(char), MAX_SIZE, fp_rec);
  fclose(fp_rec);

  return 0;
}
