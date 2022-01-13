extern void ft_putnbr_base(int nbr, char *base);

#include <stdio.h>

int main()
{
	int a = 10923560;
	char *base = "01";
	ft_putnbr_base(a, base);
}