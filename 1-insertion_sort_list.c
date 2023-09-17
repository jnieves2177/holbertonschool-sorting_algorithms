#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion
 * sort algorithm
 * @list: doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current, *insertion_point, *temp;

    current = (*list)->next;

    while (current)
    {
        insertion_point = current->prev;

        while (insertion_point && insertion_point->n > current->n)
        {
            temp = current->next;

            if (insertion_point->prev)
                insertion_point->prev->next = current;
            else
                *list = current;

            if (current->next)
                current->next->prev = insertion_point;

            current->prev = insertion_point->prev;
            insertion_point->prev = current;
            current->next = insertion_point;

            print_list(*list);

            current = temp;
        }

        current = current->next;
    }
}
