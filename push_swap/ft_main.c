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
	return (head);
}

void	sort_3(t_node *a)
{
	t_node	*mid;
	t_node	*last;

	mid = a->next->next;
	last = mid->next;
	// 정렬되어 있으면 리턴
	if (a->next->i < mid->i && mid->i < last->i)
		return ;
	// 첫번째가 최대일 때
	if (a->next->i > last->i && a->next->i > mid->i)
		rotate(a, a->next, "ra");
	// 첫번째가 최소거나 1, 0, 3 이 아닐 때
	else if (a->next->i < mid->i && a->next->i < last->i)
		r_rotate(a, a->next, "rra");
	else if (!(last->i > a->next->i && last->i > mid->i && a->next->i > mid->i))
		r_rotate(a, a->next, "rra");
	mid = a->next->next;
	last = mid->next;
	if (last->i > a->next->i && last->i > mid->i && a->next->i > mid->i)
		swap(a, a->next, "sa");
}

void	sort_4(t_node *a, t_node *b)
{
	if (a->pre->i == 0)
		r_rotate(a, a->next, "rra");
	while (a->next->i != 0)
		rotate(a, a->next, "ra");
	push(a, b, "pb");
	sort_3(a);
	push(b, a, "pa");
}

void	sort_5(t_node *a, t_node *b)
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

void	small_sort(t_node *a, t_node *b)
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

// 수정 필요..
void	a_to_b(t_node *a, t_node *b, int num, int k)
{
	int cnt = 0;
	while (a->size)
	{
		// print_lst(a);
		// print_lst(b);
		// ft_printf("\n");
		if (a->next->i <= num)
		{
			// ft_printf("top %d is less than num %d\n", a->next->i, num);
			push(a, b, "pb");
			num++;
		}
		else if (a->next->i > num && a->next->i <= num + k)
		{
			// ft_printf("top %d is between num %d and num+k %d\n", a->next->i, num, num + k);
			push(a, b, "pb");
			rotate(b, b->next, "rb");
			num++;
		}
		else if (a->next->i > num + k)
		{
			// ft_printf("top %d is more than num %d\n", a->next->i, num);
			rotate(a, a->next, "ra");
		}
		cnt++;
	}
	// ft_printf("A to B count: %d\n", cnt);
}

void	b_to_a(t_node *a, t_node *b, int k)
{
	int	chunk;
	// int cnt = 0;
	// 최댓값 찾아서 순서대로 푸쉬
	while (b->size)
	{
		chunk = k;

		if (b->pre->i == b->size - 1)
			r_rotate(b, b->next, "rrb");
		if (b->next->i == b->size - 1)
			push(b, a, "pa");
		else
		{
			rotate(b, b->next, "rb");
		}
	}
	// ft_printf("B to A count: %d\n", cnt);
}

// int	top_from_top(t_node *b, int max, int k)
// {
// 	int		cnt;
// 	t_node	*top;

// 	cnt = 0;
// 	top = b->next;
// 	while (k && top->next != b)
// 	{
// 		if (top->i == max)
// 		{
// 			cnt++;
// 			max--;
// 		}
// 		else
// 			top = top->next;
// 		k--;
// 	}
// 	return (cnt);
// }

// int	top_from_bottom(t_node *b, int max, int k)
// {
// 	int		cnt;
// 	t_node	*top;

// 	cnt = 0;
// 	top = b->pre;
// 	while (k && top->pre != b)
// 	{
// 		if (top->i == max)
// 		{
// 			cnt++;
// 			max--;
// 		}
// 		else
// 			top = top->pre;
// 		k--;
// 	}
// 	return (cnt);
// }

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

int	find_min(t_node *head, int min)
{
	int		cnt;
	t_node	*top;

	cnt = 0;
	top = head->next;
	while (top->i != min)
	{
		top = top->next;
		cnt++;
	}
	return cnt;
}

t_pivot	set_pivot(int size)
{
	t_pivot	pivot;

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
		// 큰 덩어리
		if (a->next->i > p.high)
		{
			if (a->pre->i <= p.high)
				r_rotate(a, a->next, "rra");
			else
				flag.high = 1;
		}
		// 작은 덩어리
		if (a->next->i <= p.low)
		{
			push(a, b, "pb");
			flag.low = 1;
		}
		if (flag.high && flag.low)
			rr(a, b);
		else if (flag.high)
			rotate(a, a->next, "ra");
		else if (flag.low)
			rotate(b, b->next, "rb");
		// 중간 덩어리
		if (a->next->i > p.low && a->next->i <= p.high)
			push(a, b, "pb");
	}
	while (a->size)
		push(a, b, "pb");
}

void	sorting(t_node *a, t_node *b)
{
	int	pos;
	int	min;

	min = 0;
	while (a->size > 3)
	{
		pos = find_min(a, min);
		if (pos > a->size / 2 + 0.5)
		{
			while (a->next->i != min)
				r_rotate(a, a->next, "rra");
		}
		else
		{
			while (a->next->i != min)
				rotate(a, a->next, "ra");
		}
		push(a, b, "pb");
		min++;
	}
	sort_3(a);
	while (b->size)
		push(b, a, "pa");
}

void	ft_sort(t_node *a, t_node *b)
{
	int	k;

	k = a->size / 2 + 1;
	if (a->size <= 5)
		small_sort(a, b);
	else
	{
		greedy_a_to_b(a, b);
		// sorting(a, b);
		// a -> b
		// a_to_b(a, b, 0, k);
		// print_stack(a, b);
		// b_to_a(a, b, k);
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
