#include "main.h"

void scan_command(char *comnd, size_t size)
{
	if (fgets(comnd, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			new_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			new_printf("Error reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	comnd[strcspn(comnd, "\n")] = '\0';
}
