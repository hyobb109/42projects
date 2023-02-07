/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 20:39:42 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/07 20:43:54 by hyobicho         ###   ########.fr       */
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
			link_list(numset[j++], a, &curr);
	}
}

void	link_list(char *num, t_node *a, t_node **curr)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		exit(1);
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

// 중복, size, 인덱싱, 정렬여부 같이 체크
int	check_lst(t_node *head, t_node *lst)
{
	t_node	*tmp;
	int		sorted;

	sorted = 1;
	while (lst != head)
	{
		tmp = lst->next;
		while (tmp != head)
		{
			if (lst->n == tmp->n)
				ft_error();
			if (lst->n > tmp-> n)
				sorted = 0;
			tmp = tmp->next;
		}
		indexing(head, head->next, lst);
		lst = lst->next;
		(head->size)++;
	}
	return (sorted);
}

t_node	*create_head(void)
{
	t_node	*head;

	head = malloc(sizeof(t_node));
	if (head == NULL)
		exit(1);
	head->pre = head;
	head->next = head;
	head->size = 0;
	head->i = -1;
	return (head);
}