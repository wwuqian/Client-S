/*************************************************************************
    > File Name: zombie.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Sun 11 Mar 2018 07:41:04 PM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	pid_t id = fork();
	if(id < 0){
		perror("fork");
		return 1;
	}
	else if(id > 0){
		printf("parent[%d] is sleep\n",getpid());
		sleep(20);
	}
	else{
		printf("child[%d] is begin zombie...\n",getpid());
		sleep(5);
		exit(EXIT_SUCCESS);
	}
	return 0;
}
	
