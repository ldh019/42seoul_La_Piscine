extern int ft_atoi(char *str);

#include <stdio.h>

int main(int argc, char **argv)
{
	argc = 1;
	printf("%d", ft_atoi(argv[0]));

	return 0;
}