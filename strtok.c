#include "header.h"

char *_strtok(char *str, char *delim)
{

	static char *s;
	int len = _strlen(delim);
	int i = 0;

	if (str)
		s = str;

	else
	{
		str = s;
		s = str;
	}

	if (*s == '\0')
		return (NULL);

	while (*s != '\0')
	{
		if (_strncmp(str, delim, len) == 0)
		{
			str++;
		}
		else if (_strncmp(s, delim, len) == 0)
		{
			for (i = 0; i < len; i++, s++)
			{
				*s = '\0';
			}
				return (str);

		}

		s++;
	}

	return (str);

}

int _strn(char *str)
{
	int count = 0;

	if (!str)
		return (-1);

	while (*str)
	{
		if (*str != ' ' && *str != '\n' && (*(str + 1) == ' ' || *(str + 1) == '\0'))
		{
			count++;
		}
		str++;
	}

	return (count);

}





