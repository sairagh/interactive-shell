#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<setjmp.h>
#include"a.h"
void fg(char **args,int input1,int output1,int flag1,int flag2,int input,int output)
{
	pid_t pid,wpid;
	int status;
	pid=fork();
	if(pid==0)
	{
		/*	setpgid(0,0);
			signal (SIGINT, SIG_DFL);
			signal (SIGQUIT, SIG_DFL);
			signal (SIGTSTP, SIG_DFL);
			signal (SIGTTIN, SIG_DFL);
			signal (SIGTTOU, SIG_DFL);
			signal (SIGCHLD, SIG_DFL);*/

		//	printf("%d %d",input1,output1);
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


		int x=execvp(args[0],args);
		/*if(input1!=0)
		  {
		  printf("hellofg");
		  dup2(input1,0);
		  close(input1);
		  }
		  if(output1!=1)
		  {
		  printf("hello1 fg");
		  dup2(output1,1);
		  close(output1);
		  }*/

		if(x==-1)
		{
			fprintf(stderr,"Unable to execute the command\n");
		//	perror("error");
		}
		exit(EXIT_FAILURE);
	}
	//      printf("%lld",pid);
	else if(pid<0)
	{
		perror("Error forking");
	}
	else {
		// Parent process
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}



}
