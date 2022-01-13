extern int ft_atoi_base(char *str, char *base);

#include <stdio.h>

int main()
{
	char str[] = "---+---12ABCD";
	char base[] = "0123456789";

	printf("%d", ft_atoi_base(str, base));

	return 0;
}