#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>
#include<signal.h>
#include<setjmp.h>
#include <fcntl.h>
typedef struct bp
{       char pname[200];
	pid_t pid;
	struct bp *next;
}bp;
bp *background_process;
sigjmp_buf env;
char home[100];
void insert_process(char name[],pid_t pid)
{
	bp *new=(bp *)malloc(sizeof(bp));
	strcpy(new->pname,name);
	new->pid=pid;
	new->next=NULL;
	if(background_process==NULL)
		background_process=new;
	else
	{
		bp *temp=background_process;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=new;
	}
}
void remove_process(pid_t pid)
{
	if(background_process!=NULL)
	{
		bp *temp=background_process;
		if(background_process->pid==pid)
		{
			background_process=background_process->next;
			free(temp);
		}
		else
		{
			bp *r;
			while(temp!=NULL&&temp->pid!=pid)
			{
				r=temp;
				temp=temp->next;
			}
			if(temp!=NULL)
			{
				r->next=temp->next;
				free(temp);
			}
			else
				;
		}
	}
}
void printjobs()
{
	bp *temp;
	temp=background_process;
	int count=1;
	while(temp!=NULL)
	{
		printf("[%d]",count);
		count++;
		printf("%s",temp->pname);
		printf("[%d]\n",temp->pid);
		temp=temp->next;
	}
}
void killjobs()
{
	bp *temp;
	temp=background_process;
	int count=0;
	while(temp!=NULL)
	{
		//printf("[%d]",count);
		//count++;
		//printf("%s",temp->pname);
		//	remove_process(temp->pid);
		kill(temp->pid,9);
		//remove_process(temp->pid);
		//printf("[%d]\n",temp->pid);
		temp=temp->next;
	}



}
void kill1(int i,int j)
{
	bp *temp;
	temp=background_process;
	int count=1;
	while(temp!=NULL)
	{
		//	printf("[%d]",count);
		if(count==i)
		{
			kill(temp->pid,j);
		}
		count++;
		//printf("%s",temp->pname);
		//printf("[%d]\n",temp->pid);
		temp=temp->next;
	}
}
void fg1(int i)
{
	bp *temp;
	temp=background_process;
	int count=1;
	while(temp!=NULL)
	{
	//      printf("[%d]",count);
	if(count==i)
	{
		int status;
		remove_process(temp->pid);
		waitpid(temp->pid,&status,0);
	//	remove_process(temp->pid);

	}
	count++;
	//printf("%s",temp->pname);
	//printf("[%d]\n",temp->pid);
	temp=temp->next;
}
}
/*void func()
{
	printf("\n");
user_print(home);
fflush(stdout);
}*/

sigjmp_buf env;
#include"a.h"
void func()
{
	        printf("\n");
		user_print(home);
		fflush(stdout);
}

int main(int argc,char **argv)
{
	//char home[100];
	char *a234;
	a234=getcwd(home,sizeof(home)-1);
	int flag=1,tq;
	while(flag)
	{
		//char home[100];
		//char *a234;
		//a234=getcwd(home,sizeof(home)-1);
		int saved_stdout = dup(1);
		int saved_stdin = dup(0);
		int i;
		int oldfd;
		user_print(home);
		char *line = NULL;
		ssize_t bufsize = 0; // have getline allocate a buffer for us
		signal(SIGINT,func);
		int x6=getline(&line, &bufsize, stdin);
		if(x6==-1)
		{
			printf("\n");
		exit(1);
		}
		//printf("%s",line);
		//int x=strlen(line);
		char a[]="exit";
		char b[]="cd";
		char c[]="pwd";
		char d[]="echo";
		//	if(x6==-1)
		//	{
		//	perror("No input is entered");
		//	continue;
		//	}
		int count1=0,mk,flag4;
		char **argsc;
		argsc=splitio(line,";");
		for(mk=0;argsc[mk]!=NULL;mk++)
		{
			char **args1;
			args1=splitio(argsc[mk],"|");
			int count=0,flag1=0,flag2=0,input,output,input1=0;
			for(i=0;args1[i]!=NULL;i++)
			{
				count++;
			}
			int fd[2];
			for(i=0;i<count;i++)
			{
				flag1=0;
				flag2=0;
				flag4=0;
				pipe(fd);
				char *temp=(char*)malloc((1024)*sizeof(char));;
				strcpy(temp,args1[i]);
				char **temp1;
				temp1=splitline(temp);
				for(tq=0;temp1[tq]!=NULL;tq++)
				{
					//printf("%s\n",temp1[tq]);
					if(strcmp(temp1[tq],">>")==0)
					{
						//printf("hai");
						flag4=1;
						break;
					}
				}
				char **less;
				less=splitio(args1[i],"<");
				if(strcmp(less[0],args1[i])==0)
				{
					char **great1;
					if(flag4==1)
					{
						great1=splitio(args1[i],">>");	
						//printf("gr%s",great1[0]);	

						if(strcmp(great1[0],args1[i])!=0)
						{
							//printf("%s",great1[0]);
							char **args31;
							args31=splitline(great1[1]);
							//printf("%s",args31[0]);
							output=open(args31[0],O_APPEND| O_CREAT|O_WRONLY,S_IRWXG|S_IRWXU);
							flag1=1;
							strcpy(args1[i],great1[0]);
						}
					}
					else{
						char **great;
						great=splitio(args1[i],">");
						if(strcmp(great[0],args1[i])!=0)
						{
							//printf("hello");

							char **args21;
							args21=splitline(great[1]);
							//	printf("out%s\n",args21[0]);
							output=open(args21[0], O_CREAT | O_WRONLY | O_TRUNC,S_IRWXG|S_IRWXU);
							//dup2(output,STDOUT_FILENO);
							flag1=1;
							//close(output);
							strcpy(args1[i],great[0]);
						}
					}}
				else
				{
					char **great;
					great=splitio(args1[i],">");
					if(strcmp(great[0],args1[i])==0)
					{
						char **args22;
						args22=splitline(less[1]);
						input=open(args22[0],O_RDONLY);
						if(input<0)
						{
							perror("Error opening");
							break;
						}
						else
						{
							//dup2(input,0);
							flag2=1;
							//close(input);
							strcpy(args1[i],less[0]);
						}
					}
					else
					{
						char **args54;
						if(flag4==1)
						{
							args54=splitio(less[1],">>");
							if(strcmp(less[0],args54[0])!=0&&flag4==1)
							{
								char **args55;
								args55=splitline(args54[0]);
								input=open(args55[0],O_RDONLY);
								if(input<0)
								{
									perror("Error opening");
									break;
								}
								else
								{
									flag2=1;
									//dup2(input,0);
									//close(input);
								}
								char **args335;
								args335=splitio(args54[1],"<");
								char **args3416;
								args3416=splitline(args335[0]);
								output=open(args3416[0],O_APPEND| O_CREAT|O_WRONLY,S_IRWXG|S_IRWXU);
								if(output<0)
								{
									perror("Error opening");
									break;
								}
								else
								{
									flag1=1;
									//dup2(output,STDOUT_FILENO);
									//close(output);
								}
								char **args3323;
								args3323=splitio(less[0],">>");
								strcpy(args1[i],args3323[0]);

							}
						}
						else{
							char **args33;
							args33=splitio(less[1],">");
							char **args34;
							args34=splitline(args33[0]);
							input=open(args34[0],O_RDONLY);
							if(input<0)
							{
								perror("Error opening");
								break;
							}
							else
							{
								flag2=1;
								//dup2(input,0);
								//close(input);
							}
							char **args331;
							args331=splitio(great[1],"<");
							char **args341;
							args341=splitline(args331[0]);
							output=open(args341[0], O_CREAT | O_WRONLY | O_TRUNC,S_IRWXG|S_IRWXU);
							if(output<0)
							{
								perror("Error opening");
								break;
							}
							else
							{
								flag1=1;
								//dup2(output,STDOUT_FILENO);
								//close(output);
							}
							char **args332;
							args332=splitio(less[0],">");
							strcpy(args1[i],args332[0]);
						}

					}
				}
				char **args;
				args=splitline(args1[i]);
				//	output1=fd[1];
				//rintf("%s",args[0]);
				if(args[0]==NULL)
				{
					fprintf(stderr,"No command was entered\n");
					continue;
				}
				else if(strcmp(args[0],"quit")==0)
				{
					exit(0);
				}
				else if(strcmp(b,args[0])==0)
				{
					cd(args,home);
				}		
				else if(strcmp(c,args[0])==0)
				{
					char cwd[100]={0};
					char *p;
					p=getcwd(cwd,sizeof(cwd)-1);
					if(i==count-1){
						built(input1,1,flag1,flag2,input,output);
					}
					else
					{
						built(input1,fd[1],flag1,flag2,input,output);

					}
					printf("%s\n",cwd);
					close(fd[1]);
					input1=fd[0];
					dup2(saved_stdout,1);
					dup2(saved_stdin,0);

				}
				else if(strcmp(d,args[0])==0)
				{
					int llk=1;
					if(i==count-1){
						char s1[200];
						built(input1,1,flag1,flag2,input,output);
						/*while(args[llk]!=NULL)
						  {
						  printf("%s",args[llk]);
						  llk=llk+1;
						  }
						  printf("\n");*/

					}
					if(i!=count-1)
					{
						char s[200];
						built(input1,fd[1],flag1,flag2,input,output);
					}
					while(args[llk]!=NULL)
					{
						printf("%s",args[llk]);
						llk=llk+1;
					}
					printf("\n");

					close(fd[1]);
					input1=fd[0];
					dup2(saved_stdout,1);
					dup2(saved_stdin,0);

				}
				else if(strcmp(args[0],"jobs")==0)
				{
					printjobs();
				}
				else if(strcmp(args[0],"killallbg")==0)
				{
					killjobs();
				}
				else if(strcmp(args[0],"kjob")==0)
				{
					int lmao=(int)(args[1][0]-'0');
					int ilo=(int)(args[2][0]-'0');
					//printf("%d %d\n",lmao,ilo);
					kill1(lmao,ilo);

				}
				else if(strcmp(args[0],"fg")==0)
				{
					int ler=(int)(args[1][0]-'0');
					fg1(ler);
				}
				else
				{
					int ik;
					for(ik=0;args[ik]!=NULL;ik++);
					int len=ik;
					if(strcmp(args[len-1],"&")==0)//background process
					{   
						args[len-1]=NULL;

						spawn(args);
						struct sigaction sa; 
						sigfillset(&sa.sa_mask); 
						sa.sa_handler=(void *)exit_child; 
						sa.sa_flags=0; 
						sigaction(SIGCHLD,&sa,NULL); 
						sigsetjmp(env,1);
					}
					else{	
						//printf("i%d c%d",i,count);
						if(i==count-1)
						{
							fg(args,input1,1,flag1,flag2,input,output);
						}
						if(i!=count-1)
						{
							//printf("hello1");
							fg(args,input1,fd[1],flag1,flag2,input,output);
						}
						/*if(flag1==1)
						  {
						  printf("hello2");
						  close(output);
						  }
						  if(flag2==1)
						  {
						  printf("hello3");
						  close(input);
						  }*/
						//input1=fd[0];
						close(fd[1]);
						input1=fd[0];
						dup2(saved_stdout,1);
						dup2(saved_stdin,0);
					}
				}
			}
		}}
	return 0;
}

