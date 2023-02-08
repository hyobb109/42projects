/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:20:49 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/09 00:19:29 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// first가 마지막 원소가 됨
int	rotate(t_node *head, t_node *first)
{
	t_node	*last;

	// 원소가 하나 이하면 그대로
	if (first == head || first->next == head)
		return (0);
	last = head->pre;
	head->next = first->next;
	first->next->pre = head;
	head->pre = first;
	last->next = first;
	first->pre = last;
	first->next = head;
	return (1);
}

void	rr(t_node *a, t_node *b)
{
	rotate(b, b->next);
	rotate(a, a->next);
	ft_printf("%s\n", "rr");
}

void	ra(t_node *a)
{
	if (rotate(a, a->next))
		ft_printf("%s\n", "ra");
}

void	rb(t_node *b)
{
	if (rotate(b, b->next))
		ft_printf("%s\n", "rb");
}
