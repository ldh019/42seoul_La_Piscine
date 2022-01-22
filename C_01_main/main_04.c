extern void ft_ultimate_div_mod(int *a, int *b);
#include <stdio.h>

int main(void)
{
	int a, b;

	a = 5;
	b = 3;

	ft_ultimate_div_mod(&a, &b);

	printf("%d %d", a, b);

	return 0;
}