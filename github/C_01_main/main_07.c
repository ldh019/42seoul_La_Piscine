extern void ft_rev_int_tab(int *tab, int size);

#include <stdio.h>

int main(void)
{
	int arr[5] = {1,2,3,4,5};
	int size =5;

	ft_rev_int_tab(arr, size);

	for(int i=0;i<size;i++)
		printf("%d ",arr[i]);

	return 0;
}