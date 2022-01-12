extern int ft_str_is_printable(char *str);

#include <stdio.h>

int main()
{
	char arr[15] = "ASFDaG";
	arr[6] = 1;

	printf("%d", ft_str_is_printable(arr));

	return 0;
}
