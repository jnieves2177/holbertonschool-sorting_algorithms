#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using the insertion sort algorithm.
 * @list: Pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current, *prev, *temp;

    current = (*list)->next;

    while (current)
    {
        prev = current->prev;
        temp = current;

        while (prev != NULL && temp->n < prev->n)
        {
            if (temp->next != NULL)
                temp->next->prev = prev;

            prev->next = temp->next;
            temp->prev = prev->prev;
            temp->next = prev;

            if (prev->prev != NULL)
                prev->prev->next = temp;
            else
                *list = temp;

            prev->prev = temp;
            prev = temp->prev;
            print_list(*list);
        }

        current = current->next;
    }
}
