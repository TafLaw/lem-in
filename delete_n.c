#include "lem_in.h"

void    delete_n(t_lst **top)
{
    t_lst *temp;
    t_lst *next;

    temp = *top;
    while (temp)
    {
        next = temp->right;
        free(temp);
        temp = next;
    }
    *top = NULL;
}
