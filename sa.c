#include "text/libft/libft.h"

void sa(t_list ** stack_a)
{
    t_list *tmp;
    t_list *head;

    head = *stack_a;
    tmp  = head->next;
    head->next = tmp->next;
    tmp->next =  head->content;
}