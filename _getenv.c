#include <string.h>
#include "header.h"
/**
 * _getenv - compares the enviormental varable to the path.
 * @name: name of the pointer.
 * Return: return the null.
 *
or **/
char *_getenv(const char *name)
{

	int len = strlen(name);
	int counter = 0;
	char *path;

	while (*environ)
	{
		if (strncmp((*environ), name, len) == 0)
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
