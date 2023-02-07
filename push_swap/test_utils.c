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

/*

typedef struct s_pivot
{
	int	low;
	int	high;
} t_pivot;

void	test_rules(t_node *a, t_node *b)
{
	pb(b);
	print_stack(a, b);
	sa(a);
	print_stack(a, b);
	ra(a);
	print_stack(a, b);
	rra(a);
	print_stack(a, b);
}

// 테스트 코드

t_pivot set_pivot(int size)
{
	t_pivot pivot;

	pivot.low = size / 3;
	pivot.high = size - size / 3;
	return (pivot);
}

void	greedy_a_to_b(t_node *a, t_node *b)
{
	t_pivot	p;
	t_pivot flag;
	int		remainder;

	p = set_pivot(a->size);
	remainder = a->size - p.high;
	// a to b :  작은수 -> 중간 수 -> 큰 수 차례대로 pb
	while (a->size >= remainder)
	{
		flag.low = 0;
		flag.high = 0;
		// 중간, 작은 덩어리
		if (a->next->i <= p.high)
		{
			pb(b);
			if (a->next->i <= p.low) // 작은덩어리는 rb 필요
				flag.low = 1;
		}
		// 큰 덩어리
		if (a->next->i > p.high)
		{
			// 마지막이 작거나 중간 범위이면 rra
			if (a->pre->i <= p.high)
				flag.high = 2;
			else
				flag.high = 1;
		}
		if (flag.low && flag.high == 1)
			rr(a, b);
		else if (flag.low)
			rb(b);
		else if (flag.high == 1)
			ra(a);
		if (flag.high == 2)
			rra(a);
	}
	while (a->size)
		pb(b);
}
*/