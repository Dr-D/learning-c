#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("Content-type: text/plain\n\n");
  //printf("<html><head></head><body>");

  printf("FORM Get<br><br>");
  char content_length = getenv("CONTENT_LENGTH");
  
  char * query_string = getenv("QUERY_STRING");
  printf("QUERY_STRING: '%s'<br>", (query_string == NULL)? "null" : query_string);
  
  //printf("</body></html>");
  return 0;
}
