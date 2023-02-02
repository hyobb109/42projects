/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:36 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/02 19:41:33 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *head, t_node *first, char *cmd)
{
	t_node	*second;
	t_node	*third;

	ft_printf("%s\n", cmd);
	second = first->next;
	if (second == head)
		return ;
	third = second->next;
	head->next = second;
	second->pre = head;
	second->next = first;
	first->pre = second;
	first->next = third;
	third->pre = first;
}

void	push(t_node *from, t_node *to, char *cmd)
{
	t_node	*x;
	t_node	*tmp;

	// 옮길 것이 없으면 아무것도 x
	if (from->next == from)
		return ;
	ft_printf("%s\n", cmd);
	// from 연결 
	(from->size)--;
	x = from->next;
	from->next = x->next;
	x->next->pre = from;
	// to 연결
	(to->size)++;
	tmp = to->next;
	to->next = x;
	x->pre = to;
	x->next = tmp;
	tmp->pre = x;
}

// first가 마지막 원소가 됨
void	rotate(t_node *head, t_node *first, char *cmd)
{
	t_node	*last;

	// 원소가 하나 이하면 그대로
	if (first == head || first->next == head)
		return ;
	ft_printf("%s\n", cmd);
	last = head->pre;
	head->next = first->next;
	first->next->pre = head;
	head->pre = first;
	last->next = first;
	first->pre = last;
	first->next = head;
}

// last가 first가 됨
void	r_rotate(t_node *head, t_node *first, char *cmd)
{
	t_node	*last;

	if (first == head || first->next == head)
		return ;
	ft_printf("%s\n", cmd);
	last = head->pre;
	head->next = last;
	head->pre = last->pre;
	last->pre->next = head;
	first->pre = last;
	last->pre = head;
	last->next = first;
}
