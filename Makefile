

start:
        gcc -o shell shell.c deal.c parseline.c builtin_command.c


clean:
        rm -rf *.o 
