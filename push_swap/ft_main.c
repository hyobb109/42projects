/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:14:22 by hyobicho          #+#    #+#             */
/*   Updated: 2023/01/26 04:00:33 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// delete
void	print_lst(t_node *lst)
{
	t_node	*head;

	head = lst;
	lst = head->next;
	ft_printf("==========\n");
	while (lst->next != head->next)
	{
		ft_printf("%d ", lst->n);
		lst = lst->next;
	}
	ft_printf("\n==========\n");
}

// delete
void	test_rules(t_node *stack_a, t_node *stack_b)
{
	push(stack_b, stack_a, "pb");
	ft_printf("stcak A\n");
	print_lst(stack_a);
	ft_printf("stcak B\n");
	print_lst(stack_b);
	swap(stack_a, stack_a->next, stack_a->next->next, "sa");
	print_lst(stack_a);
	rotate(stack_a, stack_a->next, "ra");
	print_lst(stack_a);
	reverse_rotate(stack_a, stack_a->next, "rra");
	print_lst(stack_a);
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

void	parse_args(int argc, char **argv, t_node *stack_a)
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
	}
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

t_node	*create_head(void)
{
	t_node	*head;

	head = malloc(sizeof(t_node));
	if (head == NULL)
		exit(1);
	head->pre = head;
	head->next = head;
	return (head);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		exit(1);
	stack_a = create_head();
	stack_b = create_head();
	parse_args(argc, argv, stack_a);
	check_dup(stack_a, stack_a->next);
	print_lst(stack_a); //delete
	test_rules(stack_a, stack_b); // delete
	exit(0);
}
