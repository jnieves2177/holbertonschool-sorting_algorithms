#include "sort.h"
#include <stdbool.h> // Include for bool data type

/**
 * bubble_sort - sorts bubbly
 * @array: array to sort
 * @size: size
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, newsize = size;
    int tmp;
    bool swap; // Change int to bool for better readability

    if (array == NULL || size < 2)
        return;

    while (newsize)
    {
        swap = false; // Initialize swap as false
        for (i = 0; i < newsize - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                tmp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = tmp;
                print_array(array, size);
                swap = true; // Set swap to true if a swap occurs
            }
        }
        newsize--;
        if (!swap)
            break;
    }
}

