#include "libft/libft.h"

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
t_list  *one_arg(char *av)
{
    t_list *new_node;
    int i;
    i = ft_atoi(av);
    new_node = ft_lstnew(i);
   // printf("{%d}",ft_atoi(av));
    return (new_node);
}

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
            
            while(av[i][j])
            {   
                if(av[i][j] <= 32)
                    j++;
                if(!(av[i][j] >= '0' && av[i][j]  <= '9'))
                {
                    printf("ali");
                    return (0);
                }
                    
                j++;
            }
            i++;
        }
        i = 1;     
        stack(av, &head);
        itr = head;
        while (itr)
        {
            printf("%d->",itr->content);
            itr = itr->next;
        }
    }
}