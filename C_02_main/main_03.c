extern int ft_str_is_numeric(char *str);

#include <stdio.h>

int main()
{
	char arr[15] = "123532a357";

	printf("%d", ft_str_is_numeric(arr));

	return 0;
}
