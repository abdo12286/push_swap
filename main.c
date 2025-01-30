#include "libft/libft.h"

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
                    printf("q");
                     //return (0);
                }
                else
                    printf("f");
                j++;
            }
            i++;
        }
    }
}