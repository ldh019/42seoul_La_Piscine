#include <stdio.h>

extern void ft_ft(int *nbr);
int main(void)
{
	int nbr = 10;

	ft_ft(&nbr);

	printf("%d",nbr);

	return 0;
}
