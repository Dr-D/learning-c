struct Thread_Return {
  char text[20];
  int num;
};

struct Thread_Return *thread_return_create(char *text, int num);
