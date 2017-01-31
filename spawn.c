#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<setjmp.h>
#include"a.h"
extern  void insert_process(char name[],pid_t pid);
void spawn(char **args)
{
	pid_t pid;
	pid=fork();
	int status;
	//background process
	if(1)
	{
		//child process
		if(pid==0)
		{
			//independent process
			setpgid(0,0);
			int val=execvp(args[0],args);
			if(val==-1)
			{
				perror("error");
				exit(1);
			}
			// else
			// exit(0);
		}
		else if(pid<0)
		{
			perror("error");
			return;
		}
		else
		{
			printf("%d\n",pid);
			insert_process(args[0],pid);
			// wait(NULL);
		}

	}
}
