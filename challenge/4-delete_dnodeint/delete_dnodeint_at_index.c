#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node to delete
 * Return: 1 if successful, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp = *head;
	unsigned int i = 0;

	/* If the list is empty, return -1 */
	if (*head == NULL)
		return (-1);

	/* If the node to be deleted is the head node */
	if (index == 0)
	{
		*head = temp->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(temp);
		return (1);
	}

	/* Traverse the list to find the node at index */
	while (temp != NULL && i < index)
	{
		temp = temp->next;
		i++;
	}

	/* If we reached the end of the list, the index is out of range */
	if (temp == NULL)
		return (-1);

	/* Update the next pointer of the previous node */
	if (temp->prev != NULL)
		temp->prev->next = temp->next;

	/* Update the prev pointer of the next node */
	if (temp->next != NULL)
		temp->next->prev = temp->prev;

	/* Free the memory of the node */
	free(temp);
	return (1);
}
