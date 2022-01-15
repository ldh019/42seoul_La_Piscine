extern int ft_strlcat(char *dest, char *src, unsigned int size);

#include <stdio.h>

int main()
{
	char a[] = "hel";
	char b[] = "hello";

	printf("%d", ft_strlcat(a, b, 10));

	return 0;
}