#include "header.h"

/**
 * print_list- prints all the elemtents of the list
 * @h: listint_t
 * Return: size_t
 */

int print_list(const list *h)
{

	int i;

	for (i = 0; h; i++)
	{
		write (STDOUT_FILENO, h->s, _strlen(h->s));

		_putchar('\n');
		h = h->next;
	}

return (i);
}
