#include "main.h"
#include <stdio.h>
#include <errno.h>

#define MAX_ARG_COUNT 64

/**
 * executeCommand - function that write a command
 * @command: character to write a command
 * Return: void
 */

void executeCommand(char *command)
{
	char *args[MAX_ARG_COUNT];
	int arg_count = 0;

	char *token = strtok(command, " ");

	while (token != NULL)
	{
		args[arg_count] = token;
		arg_count++;
		token = strtok(NULL, " ");
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

			if (access(args[0], X_OK) == 0)
			{
				char *env[] = {NULL};

				execve(args[0], args, env);
				perror("execve");
				exit(EXIT_FAILURE);
			}
			else
			{
				fprintf(stderr, "%s: command not found\n", args[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;

			wait(&status);
		}
	}

}
