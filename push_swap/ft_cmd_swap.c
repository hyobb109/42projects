/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:13:46 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/09 03:14:36 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node *head, t_node *first)
{
	t_node	*second;
	t_node	*third;

	second = first->next;
	if (second == head)
		return (0);
	third = second->next;
	head->next = second;
	second->pre = head;
	second->next = first;
	first->pre = second;
	first->next = third;
	third->pre = first;
	return (1);
}

void	sa(t_node *a)
{
	swap(a, a->next);
	ft_printf("%s\n", "sa");
}

void	sb(t_node *b)
{
	swap(b, b->next);
	ft_printf("%s\n", "sb");
}

void	ss(t_node *a, t_node *b)
{
	swap(a, a->next);
	swap(b, b->next);
	ft_printf("%s\n", "ss");
}
