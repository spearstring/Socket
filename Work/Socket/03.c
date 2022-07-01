#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int arc, char *argv[])
{
	int sock;
	int pid;
	sock = socket(AF_INET, SOCK_STREAM, 0);		// 소켓생성

	pid = fork();		// 프로세스 복사

	if(pid == 0)
	{
		printf("parent sock : %d\n", sock);
	}
	else
	{
		printf("child sock : %d\n", sock);
	}
	
	return 0;
}
