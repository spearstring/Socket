#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
#define IMG_SIZE 7000000

void error_handling(char* message);

char webpage[] = "HTTP/1.1 200 OK\r\n"
		"Server:Linux Web Server\r\n"
		"Content-Type: text/html; charset=UTF-8\r\n\r\n"
		"<!DOCTYPE html>\r\n"
		"<html><head><title> My Web Page </title>\r\n"
		"<style>body {background-color: #FFFF00 }</style></head>\r\n"
		"<body><center><h1>Hello world!!</h1><br>\r\n"
		 "<img src=\"img.png\"></center></body></html>\r\n";

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	int clnt_adr_sz;
	int fd;
	char buf[BUF_SIZE];
	char img[IMG_SIZE];

	if(argc!=2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	serv_sock=socket(PF_INET, SOCK_STREAM, 0);

	if(serv_sock == -1)
	{
		error_handling("socket() error");
	}
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
	{
		error_handling("bind() error");
	}
	
	if(listen(serv_sock, 5)==-1)
	{
		error_handling("listen() error");
	}
	
	while(1)
	{
		clnt_adr_sz = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
		
		if(clnt_sock == -1)
		{
			error_handling("accept() error");
		}
		read(clnt_sock, buf, sizeof(buf));
		printf("%s\n", buf);

		if(!strncmp(buf, "GET /img.png", 12))
		{
			fd = open("img.png", O_RDONLY);

			if(fd == -1)
			{
				error_handling("open() error");
			}
			read(fd, img, sizeof(img));
			write(clnt_sock, img, sizeof(img));

			close(fd);
		}
		else
		{
			write(clnt_sock, webpage, sizeof(webpage) -1);
			printf("closeing.......");
		}
	}
	close(serv_sock);
	return 0;
}

void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
