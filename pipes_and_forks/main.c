#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>

int main(void)
{
    int pid;
    int x;

    x = 2;
    //define functionality inside parent
    if (fork() == 0)
        {
            printf("process 1, pid: %i, val: %i\n", pid, x++);
        }
    printf("process 2, pid: %i, val: %i\n", pid, x--);
    exit(0);
}
