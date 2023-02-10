/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:24:00 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/10 12:43:32 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	a_to_b(t_node *a, t_node *b, int num, int k)
{
	t_flag	f;
	int		pos;
	// int cnt = 0;
	while (a->size)
	{
		f.ra = 0;
		f.rb = 0;
		// ft_printf("x: %d range : %d ~ %d\n", a->next->i, num, num + k);
		if (a->next->i <= num + k)
		{
			pb(a, b);
			if (b->next->i > num++) // 중간 범위면 rb 플래그 남김
				f.rb = 1;
		}
		if (a->next->i > num + k)
		{
			// pos 는 다음에 푸쉬할 것의 위치 => pos가 위쪽이면 ra, 아래쪽이면 rra
			pos = find_range(a, num + k);
			if (pos > a->size / 2 + 0.5)
				f.ra = -1;
			else
				f.ra = 1;
		}
		// if (f.rb)
		// 	cnt++;
		// ft_printf("f.rb = %d, f.ra =  %d\n", f.rb, f.ra);
		check_flag(a, b, f, num + k);
	}
	// ft_printf("k: %d, cnt: %d\n", k, cnt);
}

static void	b_to_a(t_node *a, t_node *b)
{
	int	max;
	// 최댓값 찾아서 순서대로 푸쉬
	while (b->size)
	{
		// 최댓값 찾아서 첫번째에 올림, 뒤쪽에 있으면 rrb, 아니면 rb
		max = find_max(b, b->size - 1);
		if (max > b->size / 2 + 0.5)
			cmd_loop(b, b->size - 1, rrb, 0);
		else
			cmd_loop(b, b->size - 1, rb, 0);
		pa(a, b);
	}
}

void	ft_sort(t_node *a, t_node *b)
{
	int	k;

	if (a->size < 35)
		k = 5;
	else
		k = 0.045 * a->size + 7.5;
	if (a->size <= 5)
		small_sort(a, b);
	else
	{
		a_to_b(a, b, 0, k);
		// print_stack(a, b);
		b_to_a(a, b);
		// print_stack(a, b);
	}
}
