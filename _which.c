#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "header.h"
#include <string.h>
#include <signal.h>

/**
 * _which - Goes through the struct of path variables.
 * @s: char pointer
 * @p: list struct.
 * Return: Null if SUCCESS
 **/

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
