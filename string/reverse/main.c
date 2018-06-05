#include <stdio.h>
#include <stdlib.h>

void strreverse(char * dest, const char *src) {
	//Copy pointer so we know where the string starts
	const char *start = src;

	//Move pointer to end of source string i.e. character before terminator
	for( ; *(src + 1) != '\0'; src++);

	//Copy the characters moving forward in destination and backwards in source
	for( ; src >= start; *dest = *src, dest++, src-- );
	*(dest + 1) = '\0';//Add string terminator
}

int main(int argc, char *argv[]) {
	char * text = malloc(sizeof(char) * 100);
	strreverse(text, "Testing reverse");

	printf("text: '%s'\n", text);

	free(text);
}
