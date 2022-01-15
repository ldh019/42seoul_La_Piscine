extern int ft_strncmp(char *s1, char *s2, unsigned int n);

#include <stdio.h>

int main()
{
	char a[] = "hel";
	char b[] = "hello";

	printf("%d", ft_strncmp(a, b, 4));

	return 0;
}