extern char *ft_strncpy(char *dest, char *src, unsigned int n);

#include <stdio.h>

int main()
{
	char str[10] = "hello";
	char pnt[10] = "idgaf";

	ft_strncpy(pnt, str, 3);

	printf("%s", pnt);

	return 0;
}