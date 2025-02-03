#include "text/libft/libft.h"

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
t_list  *one_arg(char *av)
{
    t_list *new_node;
    int j;
    j = ft_atoi(av);
    if(j == 2147483648)
    {
        write(1,"Erruer",6);
        exit(1);
    }
    new_node = ft_lstnew(j);
   // printf("{%d}",ft_atoi(av));
    return (new_node);
}
void sa(t_list ** stack_a)
{
    t_list *tmp;
    t_list *head;

    head = *stack_a;
    tmp  = head->next;
    head->next = tmp->next;
    tmp->next = head;
    *stack_a = tmp;
}

void sb(t_list **stack_b)
{
    t_list *tmp;
    t_list *head;

    head = *stack_b;
    tmp  = head->next;
    head->next = tmp->next;
    tmp->next = head;
    *stack_b = tmp;
}
void ss(t_list **stack_a, t_list **stack_b)
{
    if(!stack_a)
        sb(stack_b);
    else if(!stack_b)
        sa(stack_a);
    else
       {
            sb(stack_b);
            sa(stack_a);
       } 
}
void pa(t_list **stack_a, t_list **stack_b)
{
    t_list *head_a;
    t_list *head_b;
    t_list *tmp_b;
    t_list *tmp_a;
    if(stack_b)
    {
        head_a = *stack_a;
        head_b = *stack_b;
        tmp_a = head_a->next;
        head_a->next = head_b;
        *stack_a = tmp_a;
        *stack_b = head_a;

    }
}
void    ra(t_list **stack_a)
{
    t_list *tmp;
    t_list *head;
    t_list *itr;

    head = *stack_a;
    itr = head;
    tmp = head->next;
    head->next=NULL;
    *stack_a = tmp;
    while(tmp->next)
        tmp= tmp->next;
    tmp->next = itr;
}
void    rra(t_list **stack_a)
{
    t_list *tmp;
    t_list *head;
    t_list *lst;
    head = *stack_a;
    tmp = head;
    lst = head;
    while(tmp->next)
        tmp = tmp->next;
    while(lst->next->next)
        lst = lst->next;
    lst->next = NULL;
    tmp->next = head;
    *stack_a = tmp;
}
int main(int ac , char **av)
{
    int i;
    int j = 1;
    t_list *head = NULL;
    t_list *tmp = NULL;
    t_list *satck_a;
    t_list *satck_b;

    i = 0;

    if(av[j][i])
        satck_a = tow_arg(av[j]);
    j++;
    if(av[j][i])
        satck_b = tow_arg(av[j]);
    //ss(&satck_a,&satck_b);
    rra(&satck_a);
    head = satck_a;
    tmp = satck_b;
    
    while (head)
    {
        printf("%d->",head->content);
        head = head->next;
    }
    printf("\n");
    while (tmp)
    {
        printf("%d->",tmp->content);
        tmp = tmp->next;
    }
    
    return (0);
}
