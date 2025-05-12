#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;
	i = 0;

	/* Traverse to the node at the given index */
	while (current != NULL && i < index)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (-1);

	/* If the node to delete is the head */
	if (current->prev == NULL)
	{
		*head = current->next;
		if (*head)
			(*head)->prev = NULL;
	}
	else
	{
		current->prev->next = current->next;
		if (current->next)
			current->next->prev = current->prev;
	}

	free(current);
	return (1);
}
