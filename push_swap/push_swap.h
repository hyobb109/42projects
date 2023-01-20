/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:15:21 by hyobicho          #+#    #+#             */
/*   Updated: 2023/01/20 22:47:43 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
typedef struct s_node
{
	int				n;
	struct s_node	*pre;
	struct s_node	*next;
}	t_node;

void	swap(t_node *head, t_node *first, t_node *second);
void	push(t_node *target, t_node *stack);

#endif