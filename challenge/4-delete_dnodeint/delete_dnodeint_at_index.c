#include <string.h>
#include <stdlib.h>
#include "lists.h"

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
    dlistint_t *tmp;
    unsigned int i;

    /* If the list is empty, return -1 */
    if (*head == NULL)
    {
        return (-1);
    }

    tmp = *head;
    
    /* Traverse the list to the node to delete */
    for (i = 0; tmp != NULL && i < index; i++)
    {
        tmp = tmp->next;
    }

    /* If index is out of range, return -1 */
    if (tmp == NULL)
    {
        return (-1);
    }

    /* If deleting the first node */
    if (tmp == *head)
    {
        *head = tmp->next;
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
    }
    else
    {
        /* Re-link the previous node to the next node */
        if (tmp->next != NULL)
        {
            tmp->next->prev = tmp->prev;
        }
        tmp->prev->next = tmp->next;
    }

    /* Free the node */
    free(tmp);

    return (1);
}
