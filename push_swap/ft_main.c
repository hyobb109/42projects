/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:14:22 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/06 23:02:27 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (head);
}

void sort_3(t_node *a)
{
	int	mid;
	int	last;

	mid = a->next->next->i;
	last = a->next->next->next->i;
	// 정렬되어 있으면 리턴
	if (a->next->i < mid && mid < last)
		return;
	// 첫번째가 최대일 때
	if (a->next->i > last && a->next->i > mid)
		rotate(a, a->next, "ra");
	// 첫번째가 최소거나 1, 0, 3 이 아닐 때
	else if (a->next->i < mid && a->next->i < last)
		r_rotate(a, a->next, "rra");
	else if (!(last > a->next->i && last > mid && a->next->i > mid))
		r_rotate(a, a->next, "rra");
	mid = a->next->next->i;
	last = a->next->next->next->i;
	if (last > a->next->i && last > mid && a->next->i > mid)
		swap(a, a->next, "sa");
}

void sort_4(t_node *a, t_node *b)
{
	if (a->pre->i == 0)
		r_rotate(a, a->next, "rra");
	while (a->next->i != 0)
		rotate(a, a->next, "ra");
	push(a, b, "pb");
	sort_3(a);
	push(b, a, "pa");
}

void sort_5(t_node *a, t_node *b)
{
	while (a->size > 3)
	{
		if (a->pre->i == 1 || a->pre->i == 0)
			r_rotate(a, a->next, "rra");
		if (a->next->i == 1 || a->next->i == 0)
			push(a, b, "pb");
		rotate(a, a->next, "ra");
	}
	sort_3(a);
	if (b->next->i < b->pre->i)
		swap(b, b->next, "sb");
	push(b, a, "pa");
	push(b, a, "pa");
}

void small_sort(t_node *a, t_node *b)
{
	if (a->size == 2)
		rotate(a, a->next, "ra");
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
}

// rr 확인!
void	a_to_b(t_node *a, t_node *b, int num, int k)
{
	int cnt = 0;
	t_pivot	flag;

	while (a->size)
	{
		flag.low = 0;
		flag.high = 0;
		if (a->next->i <= num + k)
		{
			push(a, b, "pb");
			if (a->next->i > num++) // 중간 범위면 rb 플래그 남김
				flag.low = 1;
		}
		if (a->next->i > num + k)
		{
			// 마지막이 작거나 중간 범위이면 rra
			if (a->pre->i <= num + k)
				flag.high = 2;
			else
				flag.high = 1;
		}
		if (flag.low && flag.high == 1)
			rr(a, b);
		else if (flag.low)
			rotate(b, b->next, "rb");
		else if (flag.high == 1)
			rotate(a, a->next, "ra");
		if (flag.high == 2)
			r_rotate(a, a->next, "rra");
	}
}

int find_max(t_node *head, int max)
{
	t_node *top;
	int		cnt;

	cnt = 0;
	top = head->next;
	while (top->i != max)
	{
		top = top->next;
		cnt++;
	}
	return cnt;
}

void	b_to_a(t_node *a, t_node *b)
{
	int	pos;
	// 최댓값 찾아서 순서대로 푸쉬
	while (b->size)
	{
		// 최댓값 찾아서 첫번째에 올림, 뒤쪽에 있으면 rrb, 아니면 rb
		pos = find_max(b, b->size - 1);
		if (pos > b->size / 2 + 0.5)
		{
			while (b->next->i != b->size - 1)
				r_rotate(b, b->next, "rrb");
		}
		else
		{
			while (b->next->i != b->size - 1)
				rotate(b, b->next, "rb");
		}
		push(b, a, "pa");
	}
}

t_pivot set_pivot(int size)
{
	t_pivot pivot;

	pivot.low = size / 3;
	pivot.high = size - size / 3;
	return (pivot);
}

void	greedy_a_to_b(t_node *a, t_node *b)
{
	t_pivot	p;
	t_pivot flag;
	int		remainder;

	p = set_pivot(a->size);
	remainder = a->size - p.high;
	// a to b :  작은수 -> 중간 수 -> 큰 수 차례대로 pb
	while (a->size >= remainder)
	{
		flag.low = 0;
		flag.high = 0;
		// 중간, 작은 덩어리
		if (a->next->i <= p.high)
		{
			push(a, b, "pb");
			if (a->next->i <= p.low) // 작은덩어리는 rb 필요
				flag.low = 1;
		}
		// 큰 덩어리
		if (a->next->i > p.high)
		{
			// 마지막이 작거나 중간 범위이면 rra
			if (a->pre->i <= p.high)
				flag.high = 2;
			else
				flag.high = 1;
		}
		if (flag.low && flag.high == 1)
			rr(a, b);
		else if (flag.low)
			rotate(b, b->next, "rb");
		else if (flag.high == 1)
			rotate(a, a->next, "ra");
		if (flag.high == 2)
			r_rotate(a, a->next, "rra");
	}
	while (a->size)
		push(a, b, "pb");
}

// void	b_to_a(t_node *a, t_node *b, int k)
// {
// 	int	chunk;
// 	int	i;
// 	int	cnt;
// 	while (b->size)
// 	{
// 		chunk = k;
// 		cnt = top_from_top(b, b->size - 1, chunk);
// 		ft_printf("** cnt: %d, chunk: %d\n", cnt, chunk);
// 		i = 0;
// 		while (i < cnt && chunk)
// 		{
// 			if (b->next->i == b->size - 1)
// 			{
// 				push(b, a, "pa");
// 				i++;
// 			}
// 			else
// 				rotate(b, b->next, "rb");
// 			chunk--;
// 		}
// 		// 윗 부분에서 넘어간 값들 더해줌
// 		chunk = k + k - cnt;
// 		cnt = top_from_bottom(b, b->size - 1, chunk);
// 		ft_printf("** cnt: %d, chunk: %d\n", cnt, chunk);
// 		while (cnt && chunk)
// 		{
// 			r_rotate(b, b->next, "rb");
// 			if (b->next->i == b->size - 1)
// 			{
// 				push(b, a, "pa");
// 				cnt--;
// 			}
// 			chunk--;
// 		}
// 	}
// }

// int find_min(t_node *head, int min)
// {
// 	int cnt;
// 	t_node *top;

// 	cnt = 0;
// 	top = head->next;
// 	while (top->i != min)
// 	{
// 		top = top->next;
// 		cnt++;
// 	}
// 	return cnt;
// }

// void	sorting(t_node *a, t_node *b)
// {
// 	int	pos;
// 	int	min;

// 	min = 0;
// 	while (a->size > 3)
// 	{
// 		pos = find_min(a, min);
// 		if (pos > a->size / 2 + 0.5)
// 		{
// 			while (a->next->i != min)
// 				r_rotate(a, a->next, "rra");
// 		}
// 		else
// 		{
// 			while (a->next->i != min)
// 				rotate(a, a->next, "ra");
// 		}
// 		push(a, b, "pb");
// 		min++;
// 	}
// 	sort_3(a);
// 	while (b->size)
// 		push(b, a, "pa");
// }

void	ft_sort(t_node *a, t_node *b)
{
	int	k;

	// k의 값...??
	k = a->size / 150 + 1;
	if (a->size <= 5)
		small_sort(a, b);
	else
	{
		// greedy_a_to_b(a, b);
		// sorting(a, b);
		// a -> b
		a_to_b(a, b, 0, k);
		// print_stack(a, b);
		b_to_a(a, b);
		// print_stack(a, b);
	}
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
