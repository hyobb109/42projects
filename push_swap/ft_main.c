/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:14:22 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/02 19:54:39 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// delete
void	print_stack(t_node *a, t_node *b)
{
	t_node	*a_head;
	t_node	*b_head;

	ft_printf("====A : %d====\n", a->size);
	a_head = a;
	a = a_head->next;
	while (a != a_head)
	{
		ft_printf("%d ", a->i);
		a = a->next;
	}
	ft_printf("\n====B : %d====\n", b->size);
	b_head = b;
	b = b_head->next;
	while (b != b_head)
	{
		ft_printf("%d ", b->i);
		b = b->next;
	}
	ft_printf("\n==========\n");
}

// delete
void	test_rules(t_node *a, t_node *b)
{
	push(b, a, "pb");
	print_stack(a, b);
	swap(a, a->next, "sa");
	print_stack(a, b);
	rotate(a, a->next, "ra");
	print_stack(a, b);
	r_rotate(a, a->next, "rra");
	print_stack(a, b);
}

void	link_list(char *num, t_node *a, t_node **curr)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		exit(1);
	new->n = ft_atoi(num);
	if (a->next == a)
	{
		a->next = new;
		new->pre = a;
	}
	else
	{
		new->pre = *curr;
		(*curr)->next = new;
	}
	new->next = a;
	a->pre = new;
	*curr = new;
}

void	parse_args(int argc, char **argv, t_node *a)
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
			link_list(numset[j++], a, &curr);
	}
}

void	indexing(t_node *head, t_node *lst, t_node *curr)
{
	curr->i = 0;
	while (lst != head)
	{
		if (curr->n > lst->n)
			(curr->i)++;
		lst = lst->next;
	}
}

// 중복, size, 인덱싱, 정렬여부 같이 체크
int	check_lst(t_node *head, t_node *lst)
{
	t_node	*tmp;
	int		sorted;

	sorted = 1;
	while (lst != head)
	{
		tmp = lst->next;
		while (tmp != head)
		{
			if (lst->n == tmp->n)
				ft_error();
			if (lst->n > tmp-> n)
				sorted = 0;
			tmp = tmp->next;
		}
		indexing(head, head->next, lst);
		lst = lst->next;
		(head->size)++;
	}
	return (sorted);
}

t_node	*create_head(void)
{
	t_node	*head;

	head = malloc(sizeof(t_node));
	if (head == NULL)
		exit(1);
	head->pre = head;
	head->next = head;
	head->size = 0;
	head->i = -1;
	// head->min = 2147483650;
	// head->max = -2147483650;
	return (head);
}

void	sort_3(t_node *a)
{
	t_node	*mid;

	mid = a->next->next;
	// 정렬되어 있으면 리턴
	if (a->next->i < mid->i && mid->i < a->pre->i)
		return ;
	// 첫번째가 최대일 때
	if (a->next->i > a->pre->i && a->next->i > mid->i)
		rotate(a, a->next, "ra");
	// 첫번째가 최소거나 1, 0, 3 이 아닐 때
	else if (a->next->i < mid->i && a->next->i < a->pre->i)
		r_rotate(a, a->next, "rra");
	else if (!(a->pre->i > a->next->i && a->pre->i > mid->i && a->next->i > mid->i))
		r_rotate(a, a->next, "rra");
	mid = a->next->next;
	if (a->pre->i > a->next->i && a->pre->i > mid->i && a->next->i > mid->i)
		swap(a, a->next, "sa");
}

void	sort_4(t_node *a, t_node *b)
{
	if (a->pre->i == 0)
		r_rotate(a, a->next, "rra");
	while (a->next->i != 0)
		rotate(a, a->next, "ra");
	push(b, a, "pb");
	sort_3(a);
	push(a, b, "pa");
}

void	small_sort(t_node *a, t_node *b)
{
	if (a->size == 2)
		rotate(a, a->next, "ra");
	if (a->size == 3)
		sort_3(a);
	if (a->size == 4)
		sort_4(a, b);
	// 5개 정렬
}

void	a_to_b(t_node *a, t_node *b)
{
	int	num;
	int	k;

	num = 0;
	k = a->size / 5;
	ft_printf("num: %d, k = %d\n", num, k);
	while (a->size)
	{
		// print_lst(a);
		// print_lst(b);
		if (a->next->i <= num++)
			push(a, b, "pb");
		if (a->next->i > num && a->next->i <= num + k)
		{
			push(a, b, "pb");
			rotate(b, b->next, "rb");
			num++;
		}
		if (a->next->i > num + k)
			rotate(a, a->next, "ra");
	}
}

void	b_to_a(t_node *a, t_node *b)
{
	// 최댓값 찾아서 순서대로 푸쉬
	while (b->size)
	{
		if (b->next->i == b->size - 1)
			push(b, a, "pa");
		else
			r_rotate(b, b->next, "rrb");
	}
}

void	ft_sort(t_node *a, t_node *b)
{
	if (a->size < 5)
		small_sort(a, b);
	// a -> b
	a_to_b(a, b);
	print_stack(a, b);
	b_to_a(a, b);
	print_stack(a, b);
}

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
