#include "header.h"

/**
 * print_list- prints all the elemtents of the list
 * @h: listint_t
 * Return: size_t
 */

int print_list(const list *h)
{

	int i, x;

	for (i = 0; h; i++)
	{
		for (x = 0; h->s[x] != '\0'; x++)
		{
			_putchar(h->s[x]);
		}
		_putchar('\n');
		h = h->next;
	}

return (i);
}
