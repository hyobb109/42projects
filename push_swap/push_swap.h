/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:15:21 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/09 03:30:51 by hyobicho         ###   ########.fr       */
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
}	t_node;

typedef struct s_flag
{
	int	ra;
	int	rb;
}	t_flag;

t_node	*create_head(void);
void	parse_args(int argc, char **argv, t_node *a);
int		check_lst(t_node *head, t_node *top);
void	free_lst(t_node *stack, int size);

int		swap(t_node *head, t_node *first);
void	sa(t_node *a);
void	sb(t_node *b);
void	ss(t_node *a, t_node *b);
int		push(t_node *from, t_node *to);
void	pa(t_node *a, t_node *b);
void	pb(t_node *a, t_node *b);
int		rotate(t_node *head, t_node *first);
void	ra(t_node *a);
void	rb(t_node *b);
void	rr(t_node *a, t_node *b);
int		r_rotate(t_node *head, t_node *first);
void	rra(t_node *a);
void	rrb(t_node *b);
void	rrr(t_node *a, t_node *b);

void	ft_sort(t_node *a, t_node *b);
void	small_sort(t_node *a, t_node *b);

void	print_stack(t_node *a, t_node *b); // 지우기
/* delete!!!
void test_rules(t_node *a, t_node *b);
t_pivot set_pivot(int size);
void	greedy_a_to_b(t_node *a, t_node *b);
void	sorting(t_node *a, t_node *b);
int find_min(t_node *head, int min);
*/

#endif