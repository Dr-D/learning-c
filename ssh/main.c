/*
 ============================================================================
 Name        : App.c
 Author      : drd
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <openssl/bio.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

void InitializeSSL()
{
    SSL_load_error_strings();
    SSL_library_init();
    OpenSSL_add_all_algorithms();
}

void DestroySSL()
{
    ERR_free_strings();
    EVP_cleanup();
}

void ShutdownSSL(SSL *cSSL) {
    SSL_shutdown(cSSL);
    SSL_free(cSSL);
}

int main(void) {

	InitializeSSL();
	struct addrinfo hints, *res;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;

	getaddrinfo("0.0.0.0", "55555", &hints, &res);

	int sd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);

	int b = bind(sd, res->ai_addr, res->ai_addrlen);
	if (b != 0) {
		fprintf(stderr, "Could not bind");
		exit(EXIT_FAILURE);
	}

	listen(sd, 10);

	while(1) {
		int acc = accept(sd, (struct sockaddr*)NULL, NULL);

		SSL_CTX *sslctx = SSL_CTX_new( SSLv23_server_method());
		SSL_CTX_set_options(sslctx, SSL_OP_SINGLE_DH_USE);
		int use_cert = SSL_CTX_use_certificate_file(sslctx, "cert.pem" , SSL_FILETYPE_PEM);
		if (use_cert != 1) {
			fprintf(stderr, "Error using cert file\n");
			exit(EXIT_FAILURE);
		}

		int use_prv = SSL_CTX_use_PrivateKey_file(sslctx, "key.pem", SSL_FILETYPE_PEM);
		if (use_prv != 1) {
			perror("Error with key file");
			fprintf(stderr, "Error using key file\n");
			exit(EXIT_FAILURE);
		}


		SSL *cSSL = SSL_new(sslctx);
		SSL_set_fd(cSSL, acc);

		//Here is the SSL Accept portion.  Now all reads and writes must use SSL
		int ssl_err = SSL_accept(cSSL);
		if(ssl_err <= 0) {
			fprintf(stderr, "SSL_accept Error shutting down SSL\n");
			ShutdownSSL(cSSL);
		    DestroySSL();
		}

		char read_b[2048];
		fprintf(stderr, "Doing SSL_READ\n");
		SSL_read(cSSL, read_b, 2048);
		printf("%s\n", read_b);

		char write_b[] = "HTTP/1.1 200 OK\nServer: myServer\nContent-Type: text/html\n\n<html>\n<body>\n<h1>Hello, World!</h1>\n</body>\n</html>\n\n";
		fprintf(stderr, "Doing SSL_WRITE\n");
		SSL_write(cSSL, write_b, strlen(write_b));

		close(acc);
	}
}
