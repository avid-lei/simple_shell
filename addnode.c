#include "header.h"
#include <stdlib.h>
/**
 * add_nodeint_end - add node at the end
 * @head: listint_t **
 * @n: const int
 * Return: listint_t
 */

list *add_node(list **head, char *str)
{
	list *temp = *head;
	list *place = *head;
	list *new = malloc(sizeof(list));

	if (!new)
		return (NULL);

	new->s = _strdup(str);
	new->next = NULL;


	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;

	return (place);



}

list *add_node_end(list **head, char *str)
{
	list *temp = *head;
	list *place = *head;
	list *new = malloc(sizeof(list));

	if (!new)
		return (NULL);

	new->s = _strdup(str);

	if (!*head)
	{
		*head = new;
		return (new);
	}

	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->next = NULL;

	return (place);

}

void delete_node(list **head, unsigned int index)
{

	list *new = *head;
	list *temp;
	unsigned int counter = 0;


	if (index == 0)
	{
		*head = (*head)->next;
		free(new->s);
		free(new);
		return;
	}
	while (new)
	{
		if (index == counter + 1)
		{
			temp = new->next;
			new->next = new->next->next;
			free(temp);
			return;

		}

		counter++;
		new = new->next;

	}

	return;

}

