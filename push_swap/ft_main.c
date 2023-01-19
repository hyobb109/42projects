/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:14:22 by hyobicho          #+#    #+#             */
/*   Updated: 2023/01/19 22:42:35 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_lst(t_node *lst, int size) // delete
{
	for (int i = 0; i < size; i++)
	{
		ft_printf("%p\n", lst);
		ft_printf("n: %d\n", lst->n);
		lst = lst->next;
	}
}

void	parse_args(int argc, char **argv, t_node **head, int *size)
{
	int		i;
	int		j;
	t_node	*new;
	t_node	*curr;
	char	**numset;

	i = 0;
	while (++i < argc)
	{
		// 공백으로 스플릿하고 쪼개진 문자열 돌면서 확인!!
		numset = ft_split(argv[i], ' ');
		j = 0;
		while (numset[j])
		{
			// node 할당하고 연결하기....
			new = malloc(sizeof(t_node));
			if (new == NULL)
				exit(1);
			new->n = ft_atoi(numset[j++]);
			if ((*head)->next == *head)
			{
				ft_printf("*number: %d\n", new->n);
				(*head)->next = new;
				new->pre = *head;
			}
			else
				new->pre = curr;
			new->next = *head;
			(*head)->pre = new;
			curr = new;
			ft_printf("new->n: %d\n", new->n);
		}
		(*size) += j;
	}
}

int	main(int argc, char **argv)
{
	t_node	*head;
	int		size;
	// char *test[] = {"./sedgfsd", "4636", "123"};
	// 인자 없을 때
	if (argc < 2)
		exit(1);
	head = malloc(sizeof(t_node));
	if (head == NULL)
		exit(1);
	head->pre = head;
	head->next = head;
	size = 0;
	parse_args(argc, argv, &head, &size);
	ft_printf("size: %d\n", size);
	check_lst(head->next, size);
	exit(0);
}
