#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("Content-type: text/html\n\n");
  printf("<html><head></head><body>");
  printf("Hello CGI<br><br>");
  printf("argc: '%d'<br>", argc);

  int i;
  for(i = 0; i < argc; i++) {
    printf("%s<br>", argv[i]);
  }

  char * query_string = getenv("QUERY_STRING");
  printf("QUERY_STRING: '%s'<br>", (query_string == NULL)? "null" : query_string);
  
  printf("</body></html>");
  return 0;
}
