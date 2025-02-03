#include "text/libft/libft.h"
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
void pb(t_list **stack_a, t_list **stack_b)
{
    t_list *head_a;
    t_list *head_b;
    t_list *tmp_b;
    if(stack_b)
    {
        head_a = *stack_a;
        head_b = *stack_b;
        tmp_b = head_b->next;
        head_b->next = head_a;
        *stack_b = tmp_b;
        *stack_a = head_b;

    }
}

void    ra(t_list **stack_a)
{
    t_list *tmp;
    t_list *head;
    t_list *itr;

    head = *stack_a;
   // itr = head;
    tmp = head->next;
    head->next=NULL;
    *stack_a = tmp;
    while(tmp->next)
        tmp= tmp->next;
    tmp->next = head;
}

void    rb(t_list **stack_b)
{
    t_list *tmp;
    t_list *head;
    t_list *itr;

    head = *stack_b;
    // itr = head;
    tmp = head->next;
    head->next=NULL;
    *stack_b = tmp;
    while(tmp->next)
        tmp= tmp->next;
    tmp->next = head;
}
void rr(t_list **stack_a, t_list **stack_b)
{
     if(!stack_a)
        rb(stack_b);
    else if(!stack_b)
        ra(stack_a);
    else
       {
            rb(stack_b);
            ra(stack_a);
       }
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
void    rrb(t_list **stack_b)
{
    t_list *tmp;
    t_list *head;
    t_list *lst;
    head = *stack_b;
    tmp = head;
    lst = head;
    while(tmp->next)
        tmp = tmp->next;
    while(lst->next->next)
        lst = lst->next;
    lst->next = NULL;
    tmp->next = head;
    *stack_b = tmp;
}

void rrr(t_list **stack_a, t_list **stack_b)
{
     if(!stack_a)
        rrb(stack_b);
    else if(!stack_b)
        rra(stack_a);
    else
       {
            rrb(stack_b);
            rra(stack_a);
       }
}

int chick(char *av)
{
    int     i;

    i = 0;
    while(av[i])
    {
        if(i == ' ')
        {
            i = 1;
            return (i);
        }
            
        i++;
    }
    return (0);
}
void free_stack(t_list **stack)
{
    t_list *lst;
    t_list *s;

    lst = *stack;
    while(lst)
    {
       s = lst->next;
       free(lst);
       lst = s;
    }
}

void xi_haja(t_list **stack)
{
    t_list *tmp;
    t_list *node;
    t_list *next;

   tmp = *stack;
    while(tmp)
    {
        if(tmp->content == 2147483648 || tmp->content == -2147483648)
        {
            printf("{out:x}");
            free_stack(stack);
            write(1,"Error\n",6);
            exit(0);
        }
        tmp = tmp->next;
    }
    tmp = *stack ;
    node = tmp ;
    while (tmp)
    { 
        next = tmp->next;
        while (next)
        {
            // printf("%d",node->content);
            // printf("(%d)",next->content);
            if(node->content == next->content)
            {
                //printf("333");
                write(1,"Error\n",6);
                free_stack(stack);
                exit(0);
            }
            next = next->next;
        }
        node = tmp->next;
        tmp = tmp->next;
    }
}

t_list  *one_arg(char *av)
{
    t_list *new_node;
    int j;
 
    j = ft_atoi(av);
    new_node = ft_lstnew(j);
   // printf("{%d}",ft_atoi(av));

    return (new_node);
}

t_list   *tow_arg(char *av)
{
    char **arg;
    int i;
    int j;
    t_list *head = NULL;
    t_list *new_node;
    i = 0;
    while(av[i])
    {
        if(!(av[i] <= 32))
        {
            i=0;
            break;
        }   
        i++;
    }
    if(!av[i])
    {
        write(1,"Error\n",6);
        exit(1);
    }
    arg = ft_split(av,' ');
    while(arg[i])
    {
        j = ft_atoi(arg[i]);
        new_node = ft_lstnew(j);
        if(!head)
            head = new_node;
        else
        {
            ft_lstadd_back(&head, new_node);    
        }       
        i++;
    }
    // printf("%d->",head->next);
    return (head);
}
void stack (char **av, t_list **head)
{
  
    t_list *new_node;
    int i;

    i = 1;
    while(av[i])
    {
       // printf("%d",chick(av[i]));
        if(chick(av[i]) == 0)
        {
            new_node = tow_arg(av[i]);
            //printf("1");
        }
        else
            new_node = one_arg(av[i]);
        //printf("%d",new_node->content);
        if(!head){
            
            *head = new_node;
        }
        else
            ft_lstadd_back(head,new_node);
        i++;
    }
}

int main(int ac , char **av)
{
    int i;
    int j;
    t_list *head = NULL;
    t_list *itr;

    i = 1;
  
    if(ac  > 1)
    {
        while (ac > i)
        {
            j = 0;
            if(!av[i][j])
            {
                write(1,"Error\n",6);
                exit(1);
            }
            while(av[i][j])
            {   
                if(av[i][j] == '-' || av[i][j] == '+')
                {
                    if(av[i][j] == '-' && !(av[i][j] >= '0' && av[i][j]  <= '9') )
                    {
                        write(1,"Error\n",6);
                        exit(1);
                    }
                    j++;
                }
                    
                if(!(av[i][j] >= '0' && av[i][j]  <= '9'))
                {
                    if(av[i][j] <= 32)
                        break;
                    //printf("%d",j);
                    write(1,"Error\n",6);
                    return (0);
                }
                
                j++;
                
            }
           
            i++;
        }
        i = 1;     
        stack(av, &head);
        xi_haja(&head);
        //sa(&head);
        itr = head;
        while (itr)
        {
            printf("%d->",itr->content);
            itr = itr->next;
        }
    }
}