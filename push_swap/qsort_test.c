#include <stdio.h>
#include <stdlib.h>

int n;

typedef struct s_idx
{
	int left;
	int right;
} t_idx;

void print(int *arr)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap1(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int pivot_start(int *arr, int start, int end)
{
	int p = arr[start];
	int swap_idx = start;
	for (int i = start + 1; i <= end; i++)
	{
		if (p > arr[i])
		{
			swap1(&arr[++swap_idx], &arr[i]);
		}
	}
	swap1(&arr[swap_idx], &arr[start]);
	return swap_idx;
}

int pivot_end(int *arr, int start, int end)
{
	int p = arr[end];
	int swap_idx = start;
	for (int i = start; i < end; i++)
	{
		if (p > arr[i])
		{
			swap1(&arr[swap_idx++], &arr[i]);
		}
	}
	swap1(&arr[swap_idx], &arr[end]);
	return swap_idx;
}

t_idx pivot_dual(int *arr, int start, int end)
{
	t_idx i;

	if (arr[start] > arr[end])
		swap1(&arr[start], &arr[end]);
	int p1 = arr[start];
	int p2 = arr[end];
	int idx = start;
	i.left = start + 1;
	i.right = end - 1;
	// 3분할
	while (++idx <= i.right)
	{
		// 3번 구역으로 가야할 것들
		if (arr[idx] > p2)
		{
			// p2보다 작은 원소 오른쪽 끝에서부터 찾음
			while (arr[i.right] > p2 && idx < i.right)
				i.right--;
			swap1(&arr[idx], &arr[i.right--]);
		}
		// 1번 구역으로 갈 것들
		if (arr[idx] < p1) 
			swap1(&arr[i.left++], &arr[idx]);
	}
	swap1(&arr[start], &arr[--i.left]);
	swap1(&arr[end], &arr[++i.right]);
	return i;
}

int	(*pivot[2])(int *, int, int) = {pivot_start, pivot_end};

int *q_sort1(int *arr, int left, int right)
{
	if (left < right)
	{
		int pivot_idx = pivot[1](arr, left, right);
		// left
		q_sort1(arr, left, pivot_idx - 1);
		// right
		q_sort1(arr, pivot_idx + 1, right);
	}
	return (arr);
}

int *q_sort2(int *arr, int left, int right)
{
	if (left < right)
	{
		t_idx p = pivot_dual(arr, left, right);
		printf("====p1: %d p2: %d====\n", p.left, p.right);
		print(arr);
		// left
		q_sort2(arr, left, p.left - 1);
		// mid
		q_sort2(arr, p.left + 1, p.right - 1);
		// right
		q_sort2(arr, p.right + 1, right);
	}
	return (arr);
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		n = argc - 1;
		int *arr = malloc(sizeof(int) * n);
		for (int i = 0; i < n; i++)
		{
			arr[i] = atoi(argv[i + 1]);
		}
		arr = q_sort2(arr, 0, n-1);
		print(arr);
		free(arr);
	}
	return (0);
}