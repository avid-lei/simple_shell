#include <string.h>
#include "header.h"
/**
* _getn - compares the string to environmental token returns the location.
* @name: string name passing through
* Return: return the location number.
**/

int _getn(const char *name)
{

	int x = 0;
	int len = strlen(name);

	for (x = 0; environ[x] != '\0'; x++)
	{

		if (strncmp(environ[x], name, len) == 0)
		{

			return (x);
		}


	}


	return (-1);

}
