#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Address {
  int number;
  char street[20];
  char town[20];
};

struct Person {
  int age;
  char name[20];
  struct Address address;
};

int main(int argc, char *argv[]) {
  struct Address address;
  address.number = 1;
  strcpy(address.street, "Kernighan Road");
  strcpy(address.town, "Ritchie city");

  struct Person person, person2;
  person.age = 10;
  strcpy(person.name, "Mickey");
  person.address = address;

  printf("Name: '%s', Age: '%d'\n", person.name, person.age);
  printf("Number: '%d', Street: '%s', Town: '%s'\n", (person.address).number, (person.address).street, (person.address).town);

  person2.age = 9;
  strcpy(person2.name, "Minnie");
  person2.address = address;

  printf("Name: '%s', Age: '%d'\n", person2.name, person2.age);
  printf("Number: '%d', Street: '%s', Town: '%s'\n", person2.address.number, person2.address.street, person2.address.town);

  exit(EXIT_SUCCESS);
}
