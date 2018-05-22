/*************************************************************************
    > File Name: pipe1.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Fri 30 Mar 2018 02:08:44 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int fd[2];
	char buf[1024];
	int len;

	if(pipe(fd) == -1){
		perror("pipe");
		exit(1);
	}

	printf(">> ");
	//read from stdin
	while(fgets(buf,sizeof(buf),stdin)){
		len = strlen(buf);

		//write into pipe
		if(write(fd[1],buf,len) != len){
			perror("write to pipe");
			break;
		}
		memset(buf,0x00,sizeof(buf));

		//read from pipe
		if((len = read(fd[0],buf,sizeof(buf))) == -1){
			perror("read from pipe");
			break;
		}

		printf(">> ");
		//write to stdout
		if(write(1,buf,len) != len){
			perror("write to stdout");
			break;
		}
	}
	return 0;
}
