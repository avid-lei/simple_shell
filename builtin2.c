#include "header.h"

void _e(char *s, int args, list *env)
{

	if (args > 1)
	{
		printf("env: %s: No such file or directory\n", s);
		return;
	}


	print_list(env);
}


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

