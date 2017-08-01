#include <libxml/parser.h>

int main(int argc, char *argv[]) {
  
  xmlDocPtr doc = xmlNewDoc(BAD_CAST "1.0");
  xmlNodePtr n = xmlNewNode(NULL, BAD_CAST "parent");
  xmlNodeSetContent(n, BAD_CAST "parent-content");

  xmlNodePtr n2 = xmlNewNode(NULL, BAD_CAST "child");
  xmlNodeSetContent(n2, BAD_CAST "child-content");
  /*xmlAttrPtr newattr =*/ xmlNewProp (n2, (xmlChar *)"attr", (xmlChar *)"attr-value");
  
  xmlAddChild(n, n2);
  xmlDocSetRootElement(doc, n);

  xmlChar *xmlbuff;
  int buffersize;
  xmlDocDumpFormatMemory(doc, &xmlbuff, &buffersize, 1);
  printf("%s", (char *)xmlbuff);
 
  xmlFree(xmlbuff);
  xmlFreeDoc(doc);

  return (0);
}
