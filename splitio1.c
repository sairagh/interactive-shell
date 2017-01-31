#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<setjmp.h>
#include <fcntl.h>
char **splitio1(char *line)
{
	int bufsize = 500, position = 0;
	char * newline=(char*)malloc((1024)*sizeof(char));
	strcpy(newline,line);
	char **com = malloc(bufsize * sizeof(char*));
	char *a1;
	a1=strtok(newline,">>");
	while(a1!=NULL)
	{
		com[position]=a1;
		position++;
		a1 = strtok(NULL,">>");
	}
	com[position]=NULL;
	return com;
}

