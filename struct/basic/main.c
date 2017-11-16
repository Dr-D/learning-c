#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  int age;
  char name[20];
};

int main(int argc, char *argv[]) {
  struct Person person;
  person.age = 10;
  strcpy(person.name, "Mickey");
  
  printf("Name: '%s', Age: '%d'\n", person.name, person.age);

  exit(EXIT_SUCCESS);
}
