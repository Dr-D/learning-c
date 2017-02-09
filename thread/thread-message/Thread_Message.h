struct Thread_Message {
  char text[20];
  int num;
};

struct Thread_Message *thread_message_create(char *text, int num);
