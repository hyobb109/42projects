/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:14:22 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/01 22:24:06 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 배열 출력 -> 지우기
void	print_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
		ft_printf("%d ", arr[i]);
}

// delete
void	print_lst(t_stack *lst)
{
	t_stack	*head;

	head = lst;
	lst = head->next;
	ft_printf("==========\n");
	while (lst != head)
	{
		ft_printf("%d ", lst->n);
		lst = lst->next;
	}
	ft_printf("\n---idx---\n");
	lst = head->next;
	while (lst != head)
	{
		ft_printf("%d ", lst->i);
		lst = lst->next;
	}
	ft_printf("\n==========\n");
}

// delete
void	test_rules(t_stack *a, t_stack *b)
{
	push(b, a, "pb");
	ft_printf("stcak A\n");
	print_lst(a);
	ft_printf("stcak B\n");
	print_lst(b);
	swap(a, a->next, "sa");
	print_lst(a);
	rotate(a, a->next, "ra");
	print_lst(a);
	r_rotate(a, a->next, "rra");
	print_lst(a);
}

void	link_list(char *num, t_stack *a, t_stack **curr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
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

void	parse_args(int argc, char **argv, t_stack *a)
{
	int		i;
	int		j;
	t_stack	*curr;
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

void	indexing(t_stack *head, t_stack *stack, t_stack *curr)
{
	// if (curr->n < head->min);
	// 	head->min = curr->n;
	// if (curr->n > head->max)
	// 	head->max = curr->n;
	curr->i = 0;
	while (stack != head)
	{
		if (curr->n > stack->n)
			(curr->i)++;
		stack = stack->next;
	}
}

// 중복, size, 인덱싱, 정렬여부 같이 체크
int	check_lst(t_stack *head, t_stack *stack)
{
	t_stack	*tmp;
	int		sorted;

	sorted = 1;
	while (stack != head)
	{
		tmp = stack->next;
		while (tmp != head)
		{
			if (stack->n == tmp->n)
				ft_error();
			if (stack->n > tmp-> n)
				sorted = 0;
			tmp = tmp->next;
		}
		indexing(head, head->next, stack);
		stack = stack->next;
		(head->size)++;
	}
	return (sorted);
}

t_stack	*create_head(void)
{
	t_stack	*head;

	head = malloc(sizeof(t_stack));
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

// 대소관계 수정 필요!!!
void	sort_3(t_stack *a)
{
	t_stack	*mid;

	mid = a->next->next;
	if (a->next->i > a->pre->i && a->next->i > mid->i)
		rotate(a, a->next, "ra");
	else if (a->next->i == 0 || !(a->pre->i == 2 && mid->i == 0))
		r_rotate(a, a->next, "rra");
	mid = a->next->next;
	if (a->pre->i == 2 && a->next->next->i == 0)
		swap(a, a->next, "sa");
}

void	sort_4(t_stack *a, t_stack *b)
{
	t_stack *tmp;

	if (a->pre->i == 0)
		r_rotate(a, a->next, "rra");
	tmp = a->next;
	while (tmp->i != 0)
		rotate(a, a->next, "ra");
	push(b, a, "pb");
	sort_3(a);
	push(a, b, "pa");
}

void	small_sort(t_stack *a, t_stack *b)
{
	// // 2개 보내고 3 정렬 후 합침
	// if (a->size == 5)
	// {
		
	// }
	// // 최솟값을 b로 보내고 3개 정렬....
	// if (a->size == 4)
	// {
	// }
	if (a->size == 2)
		rotate(a, a->next, "ra");
	if (a->size == 3)
		sort_3(a);
	if (a->size == 4)
		sort_4(a, b);
	print_lst(a);
	b->n = 0;
}

void	ft_sort(t_stack *a, t_stack *b)
{
	if (a->size < 6)
		small_sort(a, b);
	b->n = 0;
}

int	*copy_lst(t_stack *a, int i)
{
	int		*arr;
	t_stack	*lst;

	arr = malloc(sizeof(int) * a->size);
	if (arr == NULL)
		exit(1);
	lst = a->next;
	while (++i < a->size)
	{
		arr[i] = lst->n;
		lst = lst->next;
	}
	return (arr);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*arr;

	if (argc < 2)
		exit(1);
	a = create_head();
	b = create_head();
	parse_args(argc, argv, a);
	if (check_lst(a, a->next))
		exit(0);
	ft_printf("A size = %d\n", a->size); //delete;
	arr = copy_lst(a, -1);
	ft_sort(a, b);
	exit(0);
}
