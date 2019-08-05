#include "header.h"

/**
 * _e - takes the string and args and check it through the env.
 * @s: string that is being passed
 * @args: args that are being passed.
 * @env: list that is reference with the outside env.
 **/

void _e(char *s, int args, list *env)
{

	if (args > 1)
	{
		write(STDERR_FILENO, "No such file or directory\n", 26);
		return;
	}


	print_list(env);
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
	long minnum = -2147483648;

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
				if (number + (*s - '0') > (maxnum / 10))
					return ((negcounter % 2 == 0) ? (maxnum) : (minnum));
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
		if (*s == '-' && *(s + 1) == '0')
		{
			s++;
			while (*s)
			{
				if (*s == '0')
					s++;
				else
					return (-1);
			}

			return (0);
		}

		if (*s >= '0' && *s <= '9')
			s++;
		else
			return (-1);
	}
	return (0);
}
