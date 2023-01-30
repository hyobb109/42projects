/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:15:21 by hyobicho          #+#    #+#             */
/*   Updated: 2023/01/30 21:15:24 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
typedef struct s_stack
{
	int				n;
	int				size;
	struct s_stack	*pre;
	struct s_stack	*next;
} t_stack;

typedef struct s_pivot
{
	int	small;
	int	big;
} t_pivot;

void	swap(t_stack *head, t_stack *first, char *cmd);
void	push(t_stack *to, t_stack *from, char *cmd);
void	rotate(t_stack *head, t_stack *first, char *cmd);
void	r_rotate(t_stack *head, t_stack *first, char *cmd);

#endif