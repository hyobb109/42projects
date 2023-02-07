/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:14:22 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/07 20:43:53 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc < 2)
		exit(1);
	a = create_head();
	b = create_head();
	parse_args(argc, argv, a);
	if (check_lst(a, a->next))
		exit(0);
	ft_sort(a, b);
	exit(0);
}
