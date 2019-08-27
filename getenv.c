#include <stdio.h>
#include <string.h>
#include "header.h"
/*
 int main(void)
{
	char *token;
	char *p = _getenv("PATH");
	char *copy  = strdup(p);
	token = strtok(copy, ":");
	printf("%s\n", token);
	printf("%s\n", p);

return(0);
}
*/

char *_getenv(const char *name)
{

	extern char **environ;
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



int _getn(const char *name)
{

	int x = 0;
	extern char **environ;
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
