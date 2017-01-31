#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<setjmp.h>
sigjmp_buf env;
#include"a.h"
extern void remove_process(pid_t pid);
void exit_child(void)
{
	pid_t child;
	int status;
	while ((child = waitpid(-1, &status, WNOHANG)) > 0)
	{
		remove_process(child);
		printf("\nChild %d terminated\n",child);
	}
	siglongjmp(env,1);
}
