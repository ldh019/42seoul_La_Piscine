extern void	ft_swap(int *a, int *b);

#include <stdio.h>

int main(void)
{
	int a = 1, b = 2;

	ft_swap(&a, &b);

	printf("%d %d", a, b);

	return 0;
}