/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 04:55:17 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/09 04:58:09 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_range(t_node *head, int target)
{
	t_node	*top;
	int		cnt;

	cnt = 0;
	top = head->next;
	while (top->i > target)
	{
		top = top->next;
		cnt++;
	}
	return (cnt);
}

int	find_max(t_node *head, int target)
{
	t_node	*top;
	int		cnt;

	cnt = 0;
	top = head->next;
	while (top->i != target)
	{
		top = top->next;
		cnt++;
	}
	return (cnt);
}

void	cmd_loop(t_node *stack, int target, void (*cmd)(t_node *), int flag)
{
	if (flag)
	{
		while (stack->next->i > target)
			cmd(stack);
	}
	else
	{
		while (stack->next->i != target)
			cmd(stack);
	}
}

void	check_flag(t_node *a, t_node *b, t_flag f, int target)
{
	if (f.rb && f.ra == 1)
		rr(a, b);
	else if (f.rb)
		rb(b);
	else if (f.ra == 1)
		cmd_loop(a, target, ra, 1);
	else if (f.ra == -1)
		cmd_loop(a, target, rra, 1);
}
