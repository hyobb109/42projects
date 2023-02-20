/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:24:00 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/20 21:56:56 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pivot set_pivot(int size)
{
	t_pivot pivot;

	pivot.low = size / 3;
	pivot.high = size - size / 3;
	return (pivot);
}

// greedy
void	a_to_b(t_node *a, t_node *b)
{
	t_pivot	p;
	t_flag flag;
	int		remainder;

	p = set_pivot(a->size);
	remainder = a->size - p.high;
	// a to b :  작은수 -> 중간 수 -> 큰 수 차례대로 pb
	while (a->size >= remainder)
	{
		flag.rb = 0;
		flag.ra = 0;
		// 중간, 작은 덩어리
		if (a->next->i <= p.high)
		{
			pb(a, b);
			if (a->next->i <= p.low) // 작은덩어리는 rb 필요
				flag.rb = 1;
		}
		// 큰 덩어리
		if (a->next->i > p.high)
		{
			// 마지막이 작거나 중간 범위이면 rra
			if (a->pre->i <= p.high)
				flag.ra = -1;
			else
				flag.ra = 1;
		}
		if (flag.rb && flag.ra == 1)
			rr(a, b);
		else if (flag.rb)
			rb(b);
		else if (flag.ra == 1)
			ra(a);
		if (flag.ra == -1)
			rra(a);
	}
	while (a->size)
		pb(a, b);
}

// 모래시계
// static void	a_to_b(t_node *a, t_node *b, int num, int k)
// {
// 	t_flag	f;
// 	int		pos;
// 	int cnt = 0;
// 	while (a->size)
// 	{
// 		f.ra = 0;
// 		f.rb = 0;
// 		ft_printf("x: %d range : %d ~ %d\n", a->next->i, num, num + k);
// 		if (a->next->i <= num + k)
// 		{
// 			pb(a, b);
// 			if (b->next->i > num++) // 중간 범위면 rb 플래그 남김
// 				f.rb = 1;
// 		}
// 		if (a->next->i > num + k)
// 		{
// 			// pos 는 다음에 푸쉬할 것의 위치 => pos가 위쪽이면 ra, 아래쪽이면 rra
// 			pos = find_range(a, num + k);
// 			if (pos > a->size / 2 + 0.5)
// 				f.ra = -1;
// 			else
// 				f.ra = 1;
// 		}
// 		if (f.rb)
// 			cnt++;
// 		//ft_printf("f.rb = %d, f.ra =  %d\n", f.rb, f.ra);
// 		check_flag(a, b, f, num + k);
// 	}
// 	ft_printf("k: %d, cnt: %d\n", k, cnt);
// 	exit(1);
// }

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
		k = 0.045 * a->size + 7.5; // (100, 12), (500, 30) 으로 임의로 계산함
	if (a->size <= 5)
		small_sort(a, b);
	else
	{
		a_to_b(a, b);
		// print_stack(a, b);
		b_to_a(a, b);
		// print_stack(a, b);
	}
}
