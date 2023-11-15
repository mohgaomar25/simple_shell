#include "main.h"
#include <unistd.h>
#include <string.h>

void newPrintf(const char *c)
{
	write(STDOUT_FILENO, c, strlen(c));
}
