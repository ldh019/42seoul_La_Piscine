extern unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

#include <stdio.h>

int main()
{
	char a[] = "hello";
	char b[] = "idg";

	printf("%d", ft_strlcpy(a, b, 3));
	printf("%s", a);
	return 0;
}
