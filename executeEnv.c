#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <stdlib.h>


/**
 * executeEnv - the function for the excution
 * Return: Void
 */

void executeEnv(void)
{
	char **env_var = environ;

	while (*env_var != NULL)
	{
		printf("%s\n", *env_var);
		env_var++;
	}
}
