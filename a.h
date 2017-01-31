void exit_child(void);
void cd(char **args, char home[]);
void user_print(char home[]);
void spawn(char **args);
void fg(char **args,int input1,int output1,int flag1,int flag2,int input,int output);
char **splitline(char *line);
void built(int input1,int output1,int flag1,int flag2,int input,int output);
char **splitio1(char *line);
char **splitio(char *line,char *a);



