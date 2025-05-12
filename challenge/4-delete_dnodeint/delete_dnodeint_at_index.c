#include "lists.h"  /* Add this to recognize dlistint_t */
#include <stdlib.h>  /* Add this to use free */

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *saved_head;
    dlistint_t *tmp;
    unsigned int p;

    if (*head == NULL)
    {
        return (-1);
    }

    saved_head = *head;
    p = 0;

    /* Traverse to the correct node at the given index */
    while (p < index && *head != NULL)
    {
        *head = (*head)->next;
        p++;
    }

    /* If index is out of bounds, return -1 */
    if (p != index || *head == NULL)
    {
        *head = saved_head;
        return (-1);
    }

    /* Handle deleting the first node */
    if (index == 0)
    {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
        if (tmp != NULL)
        {
            tmp->prev = NULL;
        }
    }
    else
    {
        /* Update the previous node's next pointer and the next node's prev pointer */
        (*head)->prev->next = (*head)->next;
        if ((*head)->next != NULL)
        {
            (*head)->next->prev = (*head)->prev;
        }
        
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }

    /* Restore the head pointer to the original node (if modified) */
    *head = saved_head;
    return (1);
}
