extern int *ft_range(int min, int max);

#include <stdio.h>

int main()
{
	int *arr;
	arr = ft_range(2, 5);

	for(int i = 0; i<3; i++)
		printf("%d",arr[i]);
	return 0;
}