#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current, *temp;

    for (current = (*list)->next; current != NULL; current = current->next)
    {
        temp = current;

        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            temp->prev->next = temp->next;
            temp->next = temp->prev;
            temp->prev = temp->next->prev;
            temp->next->prev = temp;

            if (temp->prev == NULL)
                *list = temp;

            if (temp->next->next != NULL)
                temp->next->next->prev = temp->next;

            print_list(*list);
        }
    }
}
