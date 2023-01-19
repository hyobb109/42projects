/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:14:22 by hyobicho          #+#    #+#             */
/*   Updated: 2023/01/19 17:57:51 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	check_error(int argc, char **argv)
// {
// 	int tmp;

// 	// 인자가 아무것도 없다면

// 	// 정수가 아닌 인자
// 	if ()
// 	// 중복된 인자
	

// }

void	parse_args(int argc, char **argv)
{
	int		i;
	int		j;
	int		num;
	char	**numset;

	i = 0;
	while (++i < argc)
	{
		// 공백으로 스플릿하고 쪼개진 문자열 돌면서 확인!!
		numset = ft_split(argv[i], ' ');
		j = 0;
		while (numset[j])
		{
			num = ft_atoi(numset[j++]);
			if (num >= 2147483647 || num <= -2147483648)
			{
				ft_printf("Error\n");
				exit(1);
			}
			else
				ft_printf("%d\n", num);
		}
	}
}

int	main(int argc, char **argv)
{
	// 에러 처리
	// char *test[] = {"./sedgfsd", "4636", "123"};
	if (argc < 2)
		exit(1);
	parse_args(argc, argv);
	exit(0);
}