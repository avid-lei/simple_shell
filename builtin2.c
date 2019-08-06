#include "header.h"

/**
 * _e - takes the string and args and check it through the env.
 * @s: string that is being passed
 * @args: args that are being passed.
 * @env: list that is reference with the outside env.
 * Return: 0
 **/

int _e(char *s __attribute__((unused)), int args, list *env)
{

	if (args > 1)
	{
		return (-1);
	}

	print_list(env);
	return (0);
}

/**
 * _atoi - takes the string turns it into an integer.
 * @s: string that is being passed
 * Return: turns the char into an integer.
 **/

int _atoi(char *s)
{
	long negcounter = 0;
	long number;
	long maxnum = 2147483647;

	while (*s)
	{
		if (*s == '-')
		{
			negcounter++;
			s++;
		}
		else if (*s >= '0' && *s <= '9')
		{
			number = *s - '0';
			s++;
			while (*s >= '0' && *s <= '9')
			{
				if (number >= (maxnum / 10) && *s >= '8')
					return (-1);
				number = (number * 10) + (*s - '0');
				s++;
			}
			if (negcounter % 2 == 1)
				return (number * (-1));
			else
				return (number);
		}
		else
			s++;
	}
	return (0);
}
/**
 * isnum - check isf the string ins a number.
 * @s: string that is being passed
 * Return: it returns 0 if success.
 **/
int isnum(char *s)
{

	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			s++;
		else
			return (-1);
	}
	return (0);
}

/**
 *_errors - print errors
 *@argv: char[]
 *@first: char
 *Return:void
 */

void _errors(char *argv[], char *first)
{
	write(STDERR_FILENO, argv[0], _strlen(argv[0]));
	write(STDERR_FILENO, ": ", 2);

	write(STDERR_FILENO, first, _strlen(first));
	write(STDERR_FILENO, " not found\n", 11);

}

