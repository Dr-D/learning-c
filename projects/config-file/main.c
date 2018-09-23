#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "trim.h"
#include "properties.h"

int main(int argc, char *argv[]) {

  struct Property *pprops = properties_get();
  struct Property *temp = pprops;
  printf("\n\nGot properties from config file.\n");

  int i = 0;
  while(pprops != NULL) {
    printf("Found property[%d]): '%s':'%s'\n", i, pprops->name, pprops->value);
    pprops = pprops->property;
    i++;
  }

  pprops = temp;

  struct Property prop_arr[i];
  for(int j = 0; j < i; j++) {
    properties_copy(pprops, &prop_arr[j]);
    printf("Copied  property[%d]): '%s':'%s'\n", j, prop_arr[j].name, prop_arr[j].value);
    pprops = pprops->property;
  }

  properties_free();

  exit(EXIT_SUCCESS);
}
