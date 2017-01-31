#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<setjmp.h>
#include <fcntl.h>
void built(int input1,int output1,int flag1,int flag2,int input,int output)
{
	if(flag2!=1&&input1!=0)
	{
		//printf("hellofg");
		dup2(input1,0);
		close(input1);
	}
	if(flag2==1)
	{
		dup2(input,0);
		close(input);
	}
	if(flag1!=1&&output1!=1)
	{
		//printf("hello1 fg");
		dup2(output1,1);
		close(output1);
	}
	if(flag1==1)
	{
		dup2(output,1);
		close(output);
	}
}

