/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:36 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/09 00:19:41 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// last가 first가 됨
int	r_rotate(t_node *head, t_node *first)
{
	t_node	*last;

	if (first == head || first->next == head)
		return (0);
	last = head->pre;
	head->next = last;
	head->pre = last->pre;
	last->pre->next = head;
	first->pre = last;
	last->pre = head;
	last->next = first;
	return (1);
}

void	rra(t_node *a)
{
	if (r_rotate(a, a->next))
		ft_printf("%s\n", "rra");
}

void	rrb(t_node *b)
{
	if (r_rotate(b, b->next))
		ft_printf("%s\n", "rrb");
}

void	rrr(t_node *a, t_node *b)
{
	r_rotate(b, b->next);
	r_rotate(a, a->next);
	ft_printf("%s\n", "rrr");
}
