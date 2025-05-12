#include "lists.h"
#include <stdlib.h>

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp;
    dlistint_t *saved_head;
    unsigned int p;

    if (*head == NULL)
    {
        return (-1);  /* List is empty, can't delete */
    }

    saved_head = *head;
    p = 0;

    /* Traverse to the correct node at the given index */
    while (p < index && *head != NULL)
    {
        *head = (*head)->next;
        p++;
    }

    /* If index is out of bounds or node doesn't exist, return -1 */
    if (p != index || *head == NULL)
    {
        *head = saved_head;
        return (-1);
    }

    /* Handle deleting the first node (index == 0) */
    if (index == 0)
    {
        tmp = (*head)->next;  /* Save the next node */
        free(*head);  /* Free the first node */
        *head = tmp;  /* Move head to the next node */
        if (tmp != NULL)
        {
            tmp->prev = NULL;  /* Update the prev pointer of the new head */
        }
    }
    else
    {
        /* Update the previous node's next pointer */
        (*head)->prev->next = (*head)->next;

        /* If the node to delete is not the last node, update the next node's prev pointer */
        if ((*head)->next != NULL)
        {
            (*head)->next->prev = (*head)->prev;
        }

        tmp = *head;
        *head = (*head)->next;  /* Move head to the next node after deletion */
        free(tmp);  /* Free the deleted node */
    }

    return (1);
}
