#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>
#include "./libft/libft.h"
#include <errno.h>

void    free_args(int argc, char **args)
{
    int i;

    i = 0;
    while (i < argc - 2)
    {
        free(args[i]);
        i++;
    }
    free(args);
}

int main(int argc, char *argv[], char *envp[])
{
    char    **arguments;
    int     error_number;
    int     pid;

    if (argc >= 2)
    {
        arguments = ft_split(argv[1], ' ');
        pid = fork();
        if (pid == 0)
        {
            execve(arguments[0], arguments, envp);
            exit(0);
        }
        error_number = errno;
        free_args(argc, arguments);
        exit(0);
    }
    return (0);
}