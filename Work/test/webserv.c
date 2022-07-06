#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUF_SIZE 1024 
#define SMALL_buf 100

void *request_handler(void *arg);
void send_data(FILE* fp, char* ct, char* file_name);
char *content_type(char *file);
void send_error(FILE* fp)
void error_handling(char *message);

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock;
	struct sockaddr_in srv_adr, clnt_adt;
	int clnt_adr_size;
	char buf[BUF_SIZE];
	pthread_t t_id;

	if(argc != 2)
	{
		printf("Usage : %s <port> \n:, argv[0]);
		exit(1)
	}

	

	return 0;
}
