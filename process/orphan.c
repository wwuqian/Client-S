/*************************************************************************
    > File Name: orphan.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sun 11 Mar 2018 08:15:52 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
	pid_t id = fork();
	if(id < 0)
	{
		perror("fork");
		return 1;
	}
	else if(id == 0){
		printf("I am child: %d\n",getpid());
		sleep(20);
	}
	else{
		printf("I am parent: %d\n",getpid());
		sleep(5);
		exit(0);
	}
	return 0;
}
