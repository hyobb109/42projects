/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 02:09:31 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/09 03:52:39 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_cmds2(char *cmd, t_node *a, t_node *b)
{
	if (ft_strncmp(cmd, "ra\n", 3) == 0)
		rotate(a, a->next);
	else if (ft_strncmp(cmd, "rb\n", 3) == 0)
		rotate(b, b->next);
	else if (ft_strncmp(cmd, "rr\n", 3) == 0)
	{
		rotate(b, b->next);
		rotate(a, a->next);
	}
	else if (ft_strncmp(cmd, "rra\n", 4) == 0)
		r_rotate(a, a->next);
	else if (ft_strncmp(cmd, "rrb\n", 4) == 0)
		r_rotate(b, b->next);
	else if (ft_strncmp(cmd, "rrr\n", 4) == 0)
	{
		r_rotate(b, b->next);
		r_rotate(a, a->next);
	}
	else
		ft_error();
}

static void	run_cmds1(char *cmd, t_node *a, t_node *b)
{
	if (ft_strncmp(cmd, "sa\n", 3) == 0)
		swap(a, a->next);
	else if (ft_strncmp(cmd, "sb\n", 3) == 0)
		swap(b, b->next);
	else if (ft_strncmp(cmd, "ss\n", 3) == 0)
	{
		swap(a, a->next);
		swap(b, b->next);
	}
	else if (ft_strncmp(cmd, "pa\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(cmd, "pb\n", 3) == 0)
		push(a, b);
	else
		run_cmds2(cmd, a, b);
}

static int	sorted_stack(t_node *last, t_node *top)
{
	while (top != last)
	{
		if (top->i > top->next->i)
			return (0);
		top = top->next;
	}
	return (1);
}

static void	check_result(t_node *a, t_node *b)
{
	if (b->size || !(sorted_stack(a->pre, a->next)))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

// void	leak_check()
// {
// 	system("leaks checker");
// }

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	*cmd;

	// atexit(leak_check);
	if (argc < 2)
		exit(EXIT_FAILURE);
	a = create_head();
	b = create_head();
	parse_args(argc, argv, a);
	check_lst(a, a->next);
	// print_stack(a, b);
	cmd = get_next_line(0);
	while (cmd)
	{
		run_cmds1(cmd, a, b);
		cmd = get_next_line(0);
	}
	check_result(a, b);
	free_lst(a, a->size);
	free_lst(b, b->size);
	return (0);
}
