#include "libft/libft.h"

t_list   *tow_arg(char *av)
{
    char **arg;
    int i;
    t_list *head = NULL;
    t_list *new_node;
    i = 0;

    arg = ft_split(av,' ');
    // printf("{%s}\n", arg[0]);
    while(arg[i])
    {
        new_node = ft_lstnew(ft_atoi(arg[i]));
        if(!head)
            head = new_node;
        else
            ft_lstadd_back(&head, new_node);
        i++;
    }
    //printf("%d->",head->content);
    return (head);
}
int main(int ac , char **av)
{
    int i;
    t_list *head = NULL;
    t_list *new;

    i = 1;

    if(ac > 1)
    {
        new = tow_arg(av[i]);
        head = new;
        while(head)
        {
            printf("%d->",head->content);
            head = head->next;
        }
    }
    return (0);
}







char *ptr = "Hello";