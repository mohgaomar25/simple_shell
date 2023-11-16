#include <string.h>
#include "main.h"
#include <stdio.h>

#define MAX_INPUT_SIZE 1024

/**
 * runShell - function to run our own shell
 */

void runShell(void)
{
	char input[MAX_INPUT_SIZE];

	while (1)
	{
		readInput(input, sizeof(input));
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "env") == 0)
		{
			executeEnv();
		}
		else if (strcmp(input, "exit") == 0)
		{
			printf("Exiting shell\n");
			_exit(0);
		}
		else
			executeCommand(input);
	}
}
