#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "properties.h"
#include "readprops.h"

char multicast_addr[15];
char multicast_port[5];
char host_addr[15];

void read_properties() {

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
    if(strcmp("MULTICAST_ADDRESS", pprops->name) == 0) {
      if(strlen(pprops->value) > 15) {
        fprintf(stderr, "Invalid MULTICAST_ADDRESS: '%s'", pprops->value);
        exit(EXIT_FAILURE);
      }
      strcpy(multicast_addr, pprops->value);
        printf("Copied  property[%d]): '%s':'%s'\n", j, prop_arr[j].name, prop_arr[j].value);
    }
    if(strcmp("MULTICAST_PORT", pprops->name) == 0) {
      if(strlen(pprops->value) > 5) {
        fprintf(stderr, "Invalid MULTICAST_PORT: '%s'", pprops->value);
        exit(EXIT_FAILURE);
      }
      strcpy(multicast_port, pprops->value);
      printf("Copied  property[%d]): '%s':'%s'\n", j, prop_arr[j].name, prop_arr[j].value);
    }
    if(strcmp("HOST_ADDRESS", pprops->name) == 0) {
      if(strlen(pprops->value) > 15) {
        fprintf(stderr, "Invalid HOST_ADDRESS: '%s'", pprops->value);
        exit(EXIT_FAILURE);
      }
      strcpy(host_addr, pprops->value);
      printf("Copied  property[%d]): '%s':'%s'\n", j, prop_arr[j].name, prop_arr[j].value);
    }

    pprops = pprops->property;
  }

  properties_free();
}
