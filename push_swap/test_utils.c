#include "push_swap.h"

void	print_stack(t_node *a, t_node *b)
{
	t_node	*a_head;
	t_node	*b_head;

	ft_printf("====A : %d====\n", a->size);
	a_head = a;
	a = a_head->next;
	while (a != a_head)
	{
		ft_printf("%d ", a->i);
		a = a->next;
	}
	ft_printf("\n====B : %d====\n", b->size);
	b_head = b;
	b = b_head->next;
	while (b != b_head)
	{
		ft_printf("%d ", b->i);
		b = b->next;
	}
	ft_printf("\n==========\n");
}

void	test_rules(t_node *a, t_node *b)
{
	push(b, a, "pb");
	print_stack(a, b);
	swap(a, a->next, "sa");
	print_stack(a, b);
	rotate(a, a->next, "ra");
	print_stack(a, b);
	r_rotate(a, a->next, "rra");
	print_stack(a, b);
}
