#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "header.h"
#include <string.h>
#include <signal.h>

int is_a(char *s)
{
	while (*s)
	{
		if (*s == '/')
			return (-1);
		s++;
	}

	return(1);
}



char *_which(char *s, list *p)
{

	char *path;
	int len = 0;
	struct stat st;


		while (p)
		{

			len = _strlen(p->s) + _strlen(s) + 2;

			path = malloc(len * sizeof(char));

			path = _strcpy(path, p->s);

			path = _strcat(path, "/");

			path = _strcat(path, s);

			if (stat(path, &st) == 0)
			{
				return (path);
			}
			p = p->next;
			free(path);
		}

	return (NULL);
}


void sigHandler(int sig_num __attribute__((unused)))
{
	        signal(SIGINT, sigHandler);
		        fflush(stdout);
}
