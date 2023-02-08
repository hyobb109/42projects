/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:39:42 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/09 03:53:36 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	indexing(t_node *head, t_node *lst, t_node *curr)
{
	curr->i = 0;
	while (lst != head)
	{
		if (curr->n > lst->n)
			(curr->i)++;
		lst = lst->next;
	}
}

static void	link_list(char *num, t_node *a, t_node **curr)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		exit(EXIT_FAILURE);
	new->n = ft_atoi(num);
	if (a->next == a)
	{
		a->next = new;
		new->pre = a;
	}
	else
	{
		new->pre = *curr;
		(*curr)->next = new;
	}
	new->next = a;
	a->pre = new;
	*curr = new;
}

void	parse_args(int argc, char **argv, t_node *a)
{
	int		i;
	int		j;
	t_node	*curr;
	char	**numset;

	i = 0;
	while (++i < argc)
	{
		numset = ft_split(argv[i], ' ');
		j = 0;
		while (numset[j])
		{
			link_list(numset[j], a, &curr);
			free(numset[j++]);
		}
		free(numset);
	}
}

// 중복, size, 인덱싱, 정렬여부 같이 체크
int	check_lst(t_node *head, t_node *top)
{
	t_node	*tmp;
	int		sorted;

	sorted = 1;
	while (top != head)
	{
		tmp = top->next;
		while (tmp != head)
		{
			if (top->n == tmp->n)
				ft_error();
			if (top->n > tmp-> n)
				sorted = 0;
			tmp = tmp->next;
		}
		indexing(head, head->next, top);
		top = top->next;
		(head->size)++;
	}
	return (sorted);
}
