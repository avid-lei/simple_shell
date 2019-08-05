#include <string.h>
#include "header.h"
/**
 * _getenv - compares the enviormental varable to the path.
 * @name: name of the pointer.
 * Return: return the null.
 *
or **/
char *_getenv(char *name)
{

	int len = _strlen(name);
	int counter = 0;
	char *path;

	while (*environ)
	{
		if (_strncmp((*environ), name, len) == 0)
		{
			path = _strdup(*environ + (len + 1));
			environ = environ - counter;
			return (path);

		}

		environ++;
		counter++;
	}


	return (NULL);

}
