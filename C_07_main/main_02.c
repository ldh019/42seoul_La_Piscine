extern int ft_ultimate_range(int **range, int min, int max);

#include <stdio.h>

int main()
{
	int *arr = NULL;

	printf("%d\n",ft_ultimate_range(&arr, 2, 5));
	for(int i =0;i<3;i++)
		printf("%d", arr[i]);
	return 0;
}