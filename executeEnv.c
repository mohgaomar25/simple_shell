#include <stdio.h>
#include "main.h"


/**
 * executeEnv - the function for the excution
 * Return: Void
 */

void executeEnv(void)
{
	char **environ = NULL;
	char *env_var = *environ;

	while (env_var)
	{
		printf("%s\n", env_var);
		env_var = *(environ++);
	}
}
