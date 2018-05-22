/*************************************************************************
    > File Name: fork.c
    > Author: ma6174
    > Mail: ma6174@163.com 
    > Created Time: Thu 08 Mar 2018 04:11:36 AM PST
 ************************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	int ret = fork();
	if(ret < 0)
	{
		perror("fork");
		return 1;
	}
	else if(ret == 0){
		printf("I am child:%d ret:%d\n",getpid(),ret);
			}
	else
	{
		printf("I am father :%d  ret:%d\n",getpid(),ret);
	}
	return 0;
}
