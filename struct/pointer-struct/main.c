#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  int age;
  char name[20];
};

int main(int argc, char *argv[]) {
  struct Person person;
  printf("sizeof person.age: '%lu'\n", sizeof(person.age));
  printf("sizeof person.name: '%lu'\n", sizeof(person.name));
  printf("sizeof person: '%lu'\n", sizeof(person));

  person.age = 10;
  strcpy(person.name, "Mickey");  

  struct Person *p_person = &person;
  printf("Name: '%s', Age: '%d'\n", (*p_person).name, p_person->age);

  exit(EXIT_SUCCESS);
}
