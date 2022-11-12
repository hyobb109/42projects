#include <libft.h>

int ft_lstsize(t_list *lst)
{
    int size;

    if (lst == NULL)
        return (0);
    size = 1;
    while (lst->next)
    {
        size++;
        lst = lst->next;
    }
    return (size);
}
