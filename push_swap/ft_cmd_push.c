/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:16:15 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/07 20:58:14 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_node *from, t_node *to)
{
	t_node	*x;
	t_node	*top;

	// 옮길 것이 없으면 아무것도 x
	if (from->next == from)
		return (0);
	// from 연결 
	(from->size)--;
	x = from->next;
	from->next = x->next;
	x->next->pre = from;
	// to 연결
	(to->size)++;
	top = to->next;
	to->next = x;
	x->pre = to;
	x->next = top;
	top->pre = x;
	return (1);
}

void	pa(t_node *a, t_node *b)
{
	push(b, a);
	ft_printf("%s\n", "pa");
}

void	pb(t_node *a, t_node *b)
{
	push(a, b);
	ft_printf("%s\n", "pb");
}
