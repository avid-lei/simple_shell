#include "header.h"

/**
 * _strcmp - string compare function
 * @s1: string one
 * @s2: string two
 * Return: returns the comp count of the string.
 **/


int _strcmp(char *s1, char *s2)
{
	int comp;

	if (_strlen(s1) != _strlen(s2))
		return (-1);

	while (*s1 == *s2)
	{
		s1++;
		s2++;
		if (*s1 == '\0')
			return (0);
	}
	comp = *s1 - *s2;
	return (comp);

}
/**
 * _strncmp - string compare function
 * @s1: string one
 * @s2: string two
 * @n: length of the strings.
 * Return: returns the comp count of the string.
 **/

int _strncmp(char *s1, char *s2, size_t n)
{
	int comp;
	size_t x = 0;


	while (*s1 == *s2)
	{
		s1++;
		s2++;
		x++;
		if (*s1 == '\0' || x == n)
			return (0);
	}
	comp = *s1 - *s2;
	return (comp);

}
