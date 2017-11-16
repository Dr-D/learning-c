#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
  char name[20];
  struct Person *link;
};

int main(int argc, char *argv[]) {
  struct Person mickey, minnie, donald;
  strcpy(mickey.name, "Mickey");
  strcpy(minnie.name, "Minnie");
  strcpy(donald.name, "Donald");  

  minnie.link = &donald;
  mickey.link = &minnie;
  
  printf("mickey Name: '%s'\n", mickey.name);
  printf("mickey link: '%p'\n", mickey.link);
  printf("mickey link->name: '%s'\n", mickey.link->name);
  printf("mickey link->link->name: '%s'\n", mickey.link->link->name);

  mickey.link = &mickey;
  
  printf("mickey Name: '%s'\n", mickey.name);
  printf("mickey link->name: '%s'\n", mickey.link->name);
  printf("mickey link->link->name: '%s'\n", mickey.link->link->name);

  exit(EXIT_SUCCESS);
}
