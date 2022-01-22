extern char *ft_strstr(char *str, char *to_find);

#include <stdio.h>

int main()
{
	char a[] = "hel";
	char b[] = "hhelloasdfh";

	printf("%s", ft_strstr(b, a));

	return 0;
}