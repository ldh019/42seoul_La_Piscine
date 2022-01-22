extern int ft_strcmp(char *s1, char *s2);

#include <stdio.h>

int main()
{
	char a[] = "hell";
	char b[] = "hello";

	printf("%d", ft_strcmp(a, b));

	return 0;
}