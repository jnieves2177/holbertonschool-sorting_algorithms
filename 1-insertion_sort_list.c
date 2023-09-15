#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order using
 * the Insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *curr, *temp;

    for (curr = (*list)->next; curr != NULL; curr = curr->next)
    {
        temp = curr;
        while (temp->prev != NULL && temp->n < temp->prev->n)
        {
            temp->prev->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            temp->next = temp->prev;
            temp->prev = temp->next->prev;
            temp->next->prev = temp;
            if (temp->prev != NULL)
                temp->prev->next = temp;
            else
                *list = temp;
            print_list(*list); // Print the list after each swap
        }
    }
}
