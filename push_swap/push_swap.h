/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:15:21 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/02 19:40:30 by hyobicho         ###   ########.fr       */
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

void	swap(t_node *head, t_node *first, char *cmd);
void	push(t_node *to, t_node *from, char *cmd);
void	rotate(t_node *head, t_node *first, char *cmd);
void	r_rotate(t_node *head, t_node *first, char *cmd);

#endif