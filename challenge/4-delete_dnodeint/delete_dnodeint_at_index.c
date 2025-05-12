#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list.
 *
 * @head: A pointer to the first element of a list.
 * @index: The index of the node to delete.
 *
 * Return: 1 on success, -1 on failure.
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp = *head;
    unsigned int i = 0;

    /* If the list is empty, return -1 */
    if (*head == NULL)
        return (-1);

    /* Traverse the list to find the node at the given index */
    while (tmp != NULL && i < index)
    {
        tmp = tmp->next;
        i++;
    }

    /* If we didn't find the node, return -1 */
    if (tmp == NULL)
        return (-1);

    /* If the node to be deleted is the first node */
    if (tmp == *head)
    {
        *head = tmp->next;  /* Update head to next node */
        if (*head)  /* If the new head exists, set its prev pointer to NULL */
            (*head)->prev = NULL;
    }
    else
    {
        /* Set the previous node's next pointer to the current node's next */
        if (tmp->prev)
            tmp->prev->next = tmp->next;

        /* Set the next node's prev pointer to the current node's prev */
        if (tmp->next)
            tmp->next->prev = tmp->prev;
    }

    /* Free the current node */
    free(tmp);
    return (1);
}
