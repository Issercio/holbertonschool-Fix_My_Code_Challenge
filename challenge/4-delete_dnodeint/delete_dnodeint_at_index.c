#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a given position.
 * @head: Pointer to the head of the list.
 * @index: The index of the node to be deleted.
 *
 * Return: 1 if it succeeded, -1 if it failed.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1); /* If the list is empty, return -1 */

	/* Deleting the head node */
	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL; /* Set the prev pointer of the new head to NULL */
		free(temp);
		return (1);
	}

	/* Traverse the list to find the node at the given index */
	while (temp != NULL && i < index)
	{
		temp = temp->next;
		i++;
	}

	/* If the index is out of range, return -1 */
	if (temp == NULL)
		return (-1);

	/* Deleting the node at the given index */
	if (temp->next != NULL)
		temp->next->prev = temp->prev; /* Connect the next node to the previous one */
	if (temp->prev != NULL)
		temp->prev->next = temp->next; /* Connect the previous node to the next one */

	free(temp);
	return (1);
}
