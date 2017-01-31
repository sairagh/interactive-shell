#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<setjmp.h>
#include"a.h"
void user_print(char home[])
{
	int i;
	char user[64]={0};
	int x=getlogin_r(user,sizeof(user)-1);
	//	char sys[50]={0};
	//	int y=gethostname(sys,sizeof(sys)-1);
	//	printf("%s",sys);
	char cwd[500]={0};
	if(getcwd(cwd,sizeof(cwd)-1)==NULL)
	{
		perror("error in retriving current directory");
	}
	//printf("home is %s",home);
	char *x11;
	char x1[100]="/home/";
	strcat(x1,user);
	x11=strstr(cwd,home);
	char sys[50]={0};
	int y=gethostname(sys,sizeof(sys)-1);
	//	printf("%s",sys);
	if(x11==NULL)
	{
		printf("<%s@%s:%s>",user,sys,cwd);
	}
	else{
	
		printf("<%s@%s:~",user,sys);
		//printf("%s",cwd);
		for(i=strlen(home);i<=strlen(cwd);i++)
		{
					printf("%c",cwd[i]);
		}
		printf(">");
	}
}

