#include "header.h"
#include <stdio.h>

/**
 * print_listint- prints all the elemtents of the list
 * @h: listint_t
 * Return: size_t
 */

int print_list(const list *h)
{

	int i;

	for (i = 0; h; i++)
	{
		printf("%s\n", h->s);
		h = h->next;
	}

return (i);
}
