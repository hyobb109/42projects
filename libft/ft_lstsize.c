#include <libft.h>

int ft_lstsize(t_list *lst)
{
    int size;

    size = 1;
    while (lst->next)
    {
        size++;
        lst++;
    }
    return (size);
}
