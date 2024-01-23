#include "sort.h"

/**
 * print_list - a function that print list of integer
 * @list: list
 */

void print_list(const listint_t *list)
{
        int x;

        x = 0;
        while (list)
        {
                if (x > 0)
                        printf(", ");
                printf("%d", list->n);
                ++x;
                list = list->next;
        }
        printf("\n");
}
