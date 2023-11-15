#include "main.h"

void execute_command(const char *comnd)
{
	pid_t childpid = fork();
	if (childpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (childpid == 0)
	{
		char *argv[64];
		int argc = 0;
		char *token = strtok((char *)command, " \n");
		
		while (token)
		{
			argv[argc++] = token;
			token = strtok(NULL, " \n");
		}
		argv[argc] = NULL;
		
		execvp(argv[0], argv);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

}
