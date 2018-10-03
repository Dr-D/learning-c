#ifndef _properties_h_

#define _properties_h_

struct Property {
  char name[254 + 1];
  char value[254 + 1];
  struct Property *property;
};

void properties_free();

void properties_copy(struct Property *src, struct Property *dest);

struct Property * properties_get();

#endif
