extern void ft_sort_int_tab(int *tab, int size);

#include <stdio.h>

int main(void)
{
	int arr[5] = {10, 30, 20, 50, 70};

	ft_sort_int_tab(arr, 5);

	for(int i=0;i<5;i++)
		printf(" %d", arr[i]);

	return 0;
}