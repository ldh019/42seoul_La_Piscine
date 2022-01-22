extern void	ft_div_mod(int a, int b, int *div, int *mod);

#include <stdio.h>

int main()
{
	int d, m;

	ft_div_mod(5, 3, &d, &m);

	printf("%d %d", d, m);

	return 0;
}