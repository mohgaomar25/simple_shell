#include "main.h"
#include <unistd.h>
#include <string.h>

/**
 * newPrintf - the new custom printf
 * @c: string to print
 */

void newPrintf(const char *c)
{
	write(STDOUT_FILENO, c, strlen(c));
}
