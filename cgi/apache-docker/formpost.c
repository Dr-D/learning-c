#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  printf("Content-type: text/html\n\n");
  printf("<html><head></head><body>");
  
  printf("<H1>Simple Form!</H1><br><br>");
  printf("<HR>");

  printf("<FORM ACTION=\"/cgi-bin/formget\" METHOD=\"POST\"> Command: <INPUT TYPE=\"text\" NAME=\"command\" SIZE=40> ");
  printf("<P>");
  printf("<INPUT TYPE=\"submit\" VALUE=\"Submit Form!\">");
  printf("<INPUT TYPE=\"reset\"  VALUE=\"Clear Form\">");
  printf("<P>");
  printf("</FORM>");
  printf("<HR>");
  
  printf("</body></html>");
  return 0;
}
