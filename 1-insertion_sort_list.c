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

    listint_t *current = (*list)->next;

    while (current)
    {
        listint_t *insertion_point = current->prev;
        listint_t *temp = current->next;

        while (insertion_point && insertion_point->n > current->n)
        {
            insertion_point = insertion_point->prev;
        }

        if (insertion_point == NULL)
        {
            (*list)->prev = current;
            current->next = *list;
            current->prev = NULL;
            *list = current;
        }
        else
        {
            current->prev = insertion_point;
            current->next = insertion_point->next;

            if (insertion_point->next)
                insertion_point->next->prev = current;

            insertion_point->next = current;
        }

        if (temp)
            temp->prev = current;

        current = temp;

        print_list(*list);
    }
}
