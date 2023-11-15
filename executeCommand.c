#include "main.h"
#include <stdio.h>
#include <errno.h>
#include <unistd.h>


/**
 * executeCommand - function that write a command
 * @command: character to write a command
 * Return: void
 */

void executeCommand(char *command)
{
	char *args[64];
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
			execv("/bin/ls", args);
			perror("execv");
			exit(EXIT_FAILURE);
		}
		else
		{
			int status;

			wait(&status);
		}
	}
}
