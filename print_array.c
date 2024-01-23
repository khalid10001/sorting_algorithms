#include "sort.h"

/**
 * print_array - a function that print array of integer
 * @array: array
 * @size: number of elements
 */

void print_array(const int *array, size_t size)
{
        size_t x;

        x = 0;
        while (array && x < size)
        {
                if (x > 0)
                        printf(", ");
                printf("%d", array[x]);
                ++x;
        }
        printf("\n");
}
