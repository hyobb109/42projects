/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:14:22 by hyobicho          #+#    #+#             */
/*   Updated: 2023/01/20 22:48:05 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_lst(t_node *lst) // delete
{
	t_node	*head;

	head = lst;
	lst = head->next;
	ft_printf("==========\n");
	// while (lst->next != head->next)
	// {
	// 	ft_printf("p: %p, n: %d\n", lst, lst->n);
	// 	lst = lst->next;
	// }
	for (int i = 0; i < 5; i++)
	{
		ft_printf("p: %p, n: %d\n", lst, lst->n);
		lst = lst->next;
	}
}

void	link_list(char *num, t_node *stack_a, t_node **curr)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		exit(1);
	new->n = ft_atoi(num);
	if (stack_a->next == stack_a)
	{
		stack_a->next = new;
		new->pre = stack_a;
	}
	else
	{
		new->pre = *curr;
		(*curr)->next = new;
	}
	new->next = stack_a;
	stack_a->pre = new;
	*curr = new;
}

int	parse_args(int argc, char **argv, t_node *stack_a, int size)
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
			link_list(numset[j++], stack_a, &curr);
		size += j;
	}
	return (size);
}

// 중복체크하고 exit
void	check_dup(t_node *head, t_node *stack)
{
	t_node	*tmp;

	while (stack->next != head->next)
	{
		tmp = stack->next;
		while (tmp->next != head->next)
		{
			if (stack->n == tmp->n)
				ft_error();
			tmp = tmp->next;
		}
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;

	if (argc < 2)
		exit(1);
	// stack_a 
	stack_a = malloc(sizeof(t_node));
	if (stack_a == NULL)
		exit(1);
	stack_a->pre = stack_a;
	stack_a->next = stack_a;
	// stack_b
	stack_b = malloc(sizeof(t_node));
	if (stack_b == NULL)
		exit(1);
	stack_b->pre = stack_b;
	stack_b->next = stack_b;
	size = parse_args(argc, argv, stack_a, 0);
	ft_printf("size: %d\n"); // delete
	check_dup(stack_a, stack_a->next);
	print_lst(stack_a); //delete
	ft_printf("push b\n");
	push(stack_b, stack_a);
	print_lst(stack_a); //delete
	print_lst(stack_b); //delete
	ft_printf("swap a\n");
	swap(stack_a, stack_a->next, stack_a->next->next);
	print_lst(stack_a); //delete
	exit(0);
}
