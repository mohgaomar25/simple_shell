#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * readInput - function to read the user input
 * @input: the input that the user will inter
 * @inputSize: the memory space for the input
 * Return: void
 */

void readInput(char *input, int inputSize)
{
	printf("$ ");

	if (fgets(input, inputSize, stdin) == NULL)
	{
		perror("fgets");
		exit(1);
	}
}
