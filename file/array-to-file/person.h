struct Person {
  int account_num;
  char first_name [20];
  char last_name [20];
};

struct Person *person_create(int acc_num, char *first, char *last);

void person_print(struct Person *pperson);
