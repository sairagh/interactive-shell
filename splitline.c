#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<setjmp.h>
#include"a.h"
char **splitline(char *line)
{
	int bufsize = 500, position = 0;
	char **com = malloc(bufsize * sizeof(char*));
	char *a1;
	a1=strtok(line," \t\r\n\a");
	while(a1!=NULL)
	{
		com[position]=a1;
		position++;
		a1 = strtok(NULL," \t\n");
	}
	com[position]=NULL;
	return com;
}
