#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<setjmp.h>
#include"a.h"
void cd(char **args,char home[])
{
	char c1[]="-";
	if(args[1]==NULL)
	{
		char user[64]={0};
		int x=getlogin_r(user,sizeof(user)-1);
		char m[]="/home/";
		strcat(m,user);
		chdir(home);
	}
	else
	{
		char bn[1000];
		char *a1;
		char *a2;
		char bc[]="~";
		char user[64]={0};
		int x=getlogin_r(user,sizeof(user)-1);
		char m[]="/home/";
		strcat(m,user);
		a1=strtok(args[1],"~");
		if(a1!=NULL)
		{
			strcpy(bn,a1);
		}
		a2=strtok(args[1],"/");
		if(strcmp(a2,bc)==0)
		{
			//printf("hello");
			if(a1!=NULL)
			{
				strcat(home,bn);
			}
			if(chdir(home)==-1)
			{
				perror("Error");
			}

		}

		else if(strcmp(a2,bc)!=0)
		{


			char cwd[500]={0};
			char *a;
			const char a5[]="/";
			//a5[0]='/';
			a=getcwd(cwd,sizeof(cwd)-1);
			strcat(cwd,a5);
			strcat(cwd,bn);
			//	printf("%s",cwd);
			if(chdir(cwd)==-1)
			{
				perror("Error");
			}
		}

	}
}
