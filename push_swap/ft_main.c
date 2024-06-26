/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:14:22 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/09 03:53:48 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	leak_check()
// {
// 	system("leaks push_swap");
// }

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	// atexit(leak_check);
	if (argc < 2)
		exit(EXIT_FAILURE);
	a = create_head();
	b = create_head();
	parse_args(argc, argv, a);
	if (check_lst(a, a->next))
		exit(EXIT_SUCCESS);
	ft_sort(a, b);
	free_lst(a, a->size);
	free_lst(b, b->size);
	return (0);
}
