/*************************************************************************
    > File Name: server.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Tue 13 Mar 2018 07:36:49 PM PDTi
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>

int main(int argc,const char* argv[])
{
	if(argc != 3){
		return 1;
	}
	int sock = socket(AF_INET,SOCK_DGRAM,0);
	if(sock < 0){
		perror("socket");
		return 2;
	}
	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(atoi(argv[2]));
	local.sin_addr.s_addr = inet_addr(argv[1]);
	
	if (bind(sock,(struct sockaddr*)&local,sizeof(local)) < 0){
		perror("bind");
		return 3;
	}

	char buf[1024];
	struct sockaddr_in client;
	while(1){
		socklen_t len = sizeof(client);
		ssize_t s = recvfrom(sock,buf,sizeof(buf)-1,0, \
					(struct sockaddr*)&client,&len);
		if(s > 0){
			buf[s] = '\0';
			printf("[%s:%d]: %s\n",inet_ntoa(client.sin_addr), \
					ntohs(client.sin_port),buf);
			sendto(sock,buf,strlen(buf),0, \
					(struct sockaddr*)&client,sizeof(client));
		}
	}
	return 0;
}
