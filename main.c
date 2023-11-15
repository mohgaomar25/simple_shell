#include "main.h"

int main(void)
{
	char comnd[170];

	while (true)
	{
		start_the_prompt();
		scan_command(comnd, sizeof(comnd));
		execute_command(comnd);
	}

	return (0);
}
