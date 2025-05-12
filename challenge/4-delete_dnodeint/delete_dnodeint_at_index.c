#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index from a doubly
 * linked list.
 *
 * @head: A pointer to the first element of the list.
 * @index: The index of the node to delete.
 *
 * Return: 1 on success, -1 on failure.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int i;

    /* Check if the list is empty or the head pointer is NULL */
    if (head == NULL || *head == NULL)
    {
        return (-1);
    }

    current = *head;
    i = 0;

    /* Traverse the list to find the node to delete */
    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    /* If the node at the given index doesn't exist */
    if (current == NULL)
    {
        return (-1);
    }

    /* If the node to delete is the head node */
    if (current->prev == NULL)
    {
        *head = current->next;
        if (*head)
        {
            (*head)->prev = NULL;  /* Set the previous pointer of the new head to NULL */
        }
    }
    else
    {
        current->prev->next = current->next;  /* Adjust the previous node's next pointer */
        if (current->next)
        {
            current->next->prev = current->prev;  /* Adjust the next node's prev pointer */
        }
    }

    free(current);  /* Free the memory of the deleted node */
    return (1);  /* Return success */
}
