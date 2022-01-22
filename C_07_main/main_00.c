extern char *ft_strdup(char *src);

#include <stdio.h>

int main()
{
	char *tmp;
	tmp = ft_strdup("abcd");

	printf("%s", tmp);

	return 0;
}