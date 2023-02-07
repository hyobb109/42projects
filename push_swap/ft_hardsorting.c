/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hardsorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:29:59 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/07 20:58:41 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_3(t_node *a)
{
	int	mid;
	int	last;

	mid = a->next->next->i;
	last = a->next->next->next->i;
	// 정렬되어 있으면 리턴
	if (a->next->i < mid && mid < last)
		return;
	// 첫번째가 최대일 때
	if (a->next->i > last && a->next->i > mid)
		ra(a);
	// 첫번째가 최소거나 1, 0, 3 이 아닐 때
	else if (a->next->i < mid && a->next->i < last)
		rra(a);
	else if (!(last > a->next->i && last > mid && a->next->i > mid))
		rra(a);
	mid = a->next->next->i;
	last = a->next->next->next->i;
	if (last > a->next->i && last > mid && a->next->i > mid)
		sa(a);
}

static void sort_4(t_node *a, t_node *b)
{
	if (a->pre->i == 0)
		rra(a);
	while (a->next->i != 0)
		ra(a);
	pb(a, b);
	sort_3(a);
	pa(a, b);
}

static void sort_5(t_node *a, t_node *b)
{
	while (a->size > 3)
	{
		if (a->pre->i == 1 || a->pre->i == 0)
			rra(a);
		if (a->next->i == 1 || a->next->i == 0)
			pb(a, b);
		ra(a);
	}
	sort_3(a);
	if (b->next->i < b->pre->i)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void small_sort(t_node *a, t_node *b)
{
	if (a->size == 2)
		ra(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
}
