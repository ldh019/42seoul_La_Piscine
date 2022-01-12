extern char *ft_strcat(char *s1, char *s2);

#include <stdio.h>

int main()
{
	char a[] = "hel";
	char b[] = "hello";

	printf("%s", ft_strcat(a, b));

	return 0;
}