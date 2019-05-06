#include<stdlib.h>
#include<string.h>

int builtin_command(char **argv)
{
        if(!strcmp(argv[0],"quit"))
                exit(0);
        if(!strcmp(argv[0],"&"))
                return 1;

        return 0;
}
