extern char *ft_strncat(char *s1, char *s2, unsigned int nb);

#include <stdio.h>

int main()
{
	char a[] = "hel";
	char b[] = "hello";

	printf("%s", ft_strncat(a, b, 3));

	return 0;
}