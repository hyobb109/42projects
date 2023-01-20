/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:36 by hyobicho          #+#    #+#             */
/*   Updated: 2023/01/20 22:48:04 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *head, t_node *first, t_node *second)
{
	t_node	*third;

	if (first->next == head)
		return ;
	third = second->next;
	head->next = second;
	second->pre = head;
	second->next = first;
	first->pre = second;
	first->next = third;
	third->pre = first;
}

// 고쳐야 함..
void	push(t_node *target, t_node *stack)
{
	t_node	*tar1;
	t_node	*s1;

	if (stack->next == stack)
		return ;
	s1 = stack->next;
	if (target->next == target)
	{
		target->pre = s1;
		target->next = s1;
		target->next->pre = target;
		target->next->next = target;
		stack->next = s1->next;
		s1->next->pre = stack;
	}
	else
	{
		tar1 = target->next;
		target->next = s1;
		stack->next = s1->next;
		s1->next->pre = stack;
		s1->pre = target;
		s1->next = tar1;
		tar1->pre = s1;
	}
}
