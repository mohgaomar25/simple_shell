#include "main.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#define MAX_ARG_COUNT 64

extern char **environ;

/**
 * executeCommand - function that write a command
 * @command: character to write a command
 * Return: void
 */

void executeCommand(char *command) 
{
    char *args[MAX_ARG_COUNT];
    int arg_count = 0;
    char *token;
    char *dir;
    
    for (token = strtok(command, " "); token; token = strtok(NULL, " "))
    {
	    args[arg_count++] = token;
    }
    args[arg_count] = NULL;
    
    if (arg_count > 0)
    {
	    pid_t pid = fork();
	    
	    if (pid < 0)
	    {
		    perror("fork");
	    }
	    else if (pid == 0)
	    {
		    execve(args[0], args, environ);
		    
		    for (dir = getenv("PATH"); dir; dir = strtok(NULL, ":"))
		    {
			    char *full_path = malloc(strlen(dir) + strlen(args[0]) + 2);
			    sprintf(full_path, "%s/%s", dir, args[0]);
			    if (access(full_path, F_OK) == 0) execve(full_path, args, environ);
			    free(full_path);
		    }
		    fprintf(stderr, "%s: command not found\n", args[0]);
		    exit(EXIT_FAILURE);
	    }
	    else
	    {
		    int status;
		    wait(&status);
	    }
    }
}
