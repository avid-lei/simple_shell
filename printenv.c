#include "header.h"
void _printenv(void)
{
	int x;

	for (x = 0; environ[x]; x++)
	{
		write(STDOUT_FILENO, environ[x], _strlen(environ[x]));
		_putchar('\n');

	}


}
