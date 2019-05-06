#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
extern char **environ;
int parseline(char *command,char **argv);
int builtin_command(char **argv);
void deal(char *cmdline)
{
        char command[256];
        char *argv[256];
        int bg;
        pid_t pid;

        strcpy(command,cmdline);

        bg = parseline(command,argv);

        if(argv[0] == NULL)
                return; // ignore the empty lines


        if(!builtin_command(argv)){
                if((pid =fork) == 0){
                        if(execve(argv[0],argv,environ)<0){
                                printf("%s: Command not found.\n",argv[0]);
                                exit(0);
                        }
                }

                if(!bg){
                        int status;
                        if(waitpid(pid,&status,0)<0)
                                perror("waitpid error");
                }
                else
                        printf("%d %s",pid,cmdline);
        }
        return ;
}
                    