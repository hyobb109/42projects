/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:55:19 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/09 03:53:45 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_head(void)
{
	t_node	*head;

	head = malloc(sizeof(t_node));
	if (head == NULL)
		exit(EXIT_FAILURE);
	head->pre = head;
	head->next = head;
	head->size = 0;
	head->i = -1;
	return (head);
}

void	free_lst(t_node *stack, int size)
{
	t_node	*tmp;
	int		i;

	i = 0;
	while (i <= size)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
		i++;
	}
}
