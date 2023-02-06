/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:15:21 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/06 23:00:49 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
typedef struct s_node
{
	int				n;
	int				i;
	int				size;
	struct s_node	*pre;
	struct s_node	*next;
} t_node;

typedef struct s_pivot
{
	int	low;
	int	high;
} t_pivot;

void	swap(t_node *head, t_node *first, char *cmd);
void	push(t_node *from, t_node *to, char *cmd);
void	rotate(t_node *head, t_node *first, char *cmd);
void	r_rotate(t_node *head, t_node *first, char *cmd);
void	rr(t_node *a, t_node *b);

// delete!!!
void print_stack(t_node *a, t_node *b);
void test_rules(t_node *a, t_node *b);
//

#endif