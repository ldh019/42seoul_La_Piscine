extern char *ft_strcpy(char *dest, char *src);

#include <stdio.h>

int main()
{
	char str[10] = "hello";
	char pnt[10] = "idgaf";

	ft_strcpy(pnt, str);

	printf("%s", pnt);

	return 0;
}