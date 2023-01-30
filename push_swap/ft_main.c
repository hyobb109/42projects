/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:14:22 by hyobicho          #+#    #+#             */
/*   Updated: 2023/01/30 21:30:13 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// 중복, size 같이 체크
void	check_dup(t_stack *head, t_stack *stack)
{
	t_stack	*tmp;

	while (stack != head)
	{
		tmp = stack->next;
		while (tmp != head)
		{
			if (stack->n == tmp->n)
				ft_error();
			tmp = tmp->next;
		}
		stack = stack->next;
		(head->size)++;
	}
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
	return (head);
}

void	sort_3(t_stack *a, t_stack *first, t_stack *second, t_stack *third)
{
	// 이미 정렬된 경우
	if (first->n < second->n && second->n < third->n)
		return ;
	//  1 3 2 의 경우
	if (first->n < second->n && first->n < third->n)
	{
		swap(a, first, "sa");
		rotate(a, a->next, "ra");
	}
	// 역순인 경우
	else if (first->n > second->n && second->n > third->n)
	{
		rotate(a, first, "ra");
		swap(a, a->next, "sa");
	}
	//  3 1 2의 경우
	else if (first->n > third->n && third->n > second->n)
		rotate(a, first, "ra");
	// 2 1 3 의 경우
	else if (second->n < third->n)
		swap(a, first, "sa");
	// 2 3 1 의 경우
	else
		r_rotate(a, first, "rra");
	print_lst(a);
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
		sort_3(a, a->next, a->next->next, a->pre);
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

// arr 정렬 후 중간값 2개, 최댓값, 최솟값 찾기
t_pivot	init_pivot(int *arr)
{
	t_pivot	p;

	return (p);
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
	check_dup(a, a->next);
	ft_printf("A size = %d\n", a->size); //delete;
	if (a->size == 1 || (a->size == 2 && a->pre->n > a->next->n))
		exit(0);
	arr = copy_lst(a, -1);
	
	// 배열 출력
	// for (int i = 0; i < a->size; i++)
	// 	ft_printf("%d ", arr[i]);
	ft_sort(a, b);
	exit(0);
}
