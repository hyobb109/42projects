/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:24:00 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/07 21:03:19 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_max(t_node *head, int max)
{
	t_node *top;
	int		cnt;

	cnt = 0;
	top = head->next;
	while (top->i != max)
	{
		top = top->next;
		cnt++;
	}
	return cnt;
}

void	a_to_b(t_node *a, t_node *b, int num, int k)
{
	t_flag	f;

	while (a->size)
	{
		f.ra = 0;
		f.rb = 0;
		if (a->next->i <= num + k)
		{
			pb(a, b);
			if (b->next->i > num++) // 중간 범위면 rb 플래그 남김
				f.rb = 1;
		}
		if (a->next->i > num + k)
		{
			// 마지막이 작거나 중간 범위이면 rra
			if (a->pre->i <= num + k)
				f.ra = -1;
			else
				f.ra = 1;
		}
		// ft_printf("f.rb = %d, f.ra =  %d\n", f.rb, f.ra);
		if (f.rb && f.ra == 1)
			rr(a, b);
		else {
			if (f.rb)
				rb(b);
			if (f.ra == 1)
				ra(a);
			else if (f.ra == -1)
				rra(a);
		}
		// if (a->size == 99) exit(1);
	}
}

void	b_to_a(t_node *a, t_node *b)
{
	int	pos;
	// 최댓값 찾아서 순서대로 푸쉬
	while (b->size)
	{
		// 최댓값 찾아서 첫번째에 올림, 뒤쪽에 있으면 rrb, 아니면 rb
		pos = find_max(b, b->size - 1);
		if (pos > b->size / 2 + 0.5)
		{
			while (b->next->i != b->size - 1)
				rrb(b);
		}
		else
		{
			while (b->next->i != b->size - 1)
				rb(b);
		}
		pa(a, b);
	}
}

void	ft_sort(t_node *a, t_node *b)
{
	int	k;

	// k의 값...??
	k = 1;
	// k = 0;
	if (a->size <= 5)
		small_sort(a, b);
	else
	{
		a_to_b(a, b, 0, k);
		print_stack(a, b);
		b_to_a(a, b);
		print_stack(a, b);
	}
}
