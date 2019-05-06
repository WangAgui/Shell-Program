#include<stdio.h>
#include<stdlib.h>


void deal(char *cmdline);
int parseline(char *buf,char **argv);
int builtin_command(char **argv);
#define MAXLINE 256
int main()
{
        char cmdline[MAXLINE];

        while(1){
                printf("> ");
                fgets(cmdline,MAXLINE,stdin);


                if(feof(stdin))
                        exit(0);



                deal(cmdline);
                }


}
