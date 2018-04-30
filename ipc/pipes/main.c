/*
 * App.c
 *
 *  Created on: 26 Apr 2018
 *      Author: darren
 */
#include <unistd.h>
#include <stdio.h>
#include <string.h>

typedef char bool;

int main(int argc, char *argv[]) {

	int fdp[2];//File descriptor for parent process writes
	pipe(fdp);

	int fdc[2];//File descriptor for child process writes
	pipe(fdc);

	__pid_t pid = fork();
	if (pid < 0) {
		fprintf(stderr, "fork() failed ");
	}
	if (pid > 0) {
		printf("Parent process");
		printf("P writing to pipe\n");

		char * write_b = "Parent message1\n";
		write(fdp[1], write_b, strlen(write_b));

		char read_b[100];
		read(fdc[0], read_b, 100);
		printf("P Reading from pipe: ");
		printf("%s\n", read_b);
	}
	if (pid == 0) {
		printf("Child process\n");
		printf("C Reading from pipe: ");
		char read_b[100];
		read(fdp[0], read_b, 100);
		printf("%s\n", read_b);

		printf("C writing to pipe\n");
		char * write_b = "Child message1\n";
		write(fdc[1], write_b, strlen(write_b));
	}
}
