#include<string.h>
#include<stdlib.h>

// Parse the command line and buid the argv array!
int parseline(char *command,char **argv)
{
        char *delim;

        int argc; // number of args
        int bg;   // background job?


        command[strlen(command)-1] = ' ';// replace /n with space
        while(*command&&(*command == ' '))
                command++;

        /* build the argv list */

        argc = 0;
        while((delim = strchr(command,' '))){
                argv[argc++] = command;
                *delim = '\0';
                command = delim+1;
                while(*command&&(*command == ' '))
                        command++;
        }

        argv[argc] = NULL;

        if(argc == 0)
                return 1;

        if((bg = (*argv[argc-1] == '&')!=0))
                argv[--argc] = NULL;

        return bg;

}
