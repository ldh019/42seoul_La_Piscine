extern char* ft_strlowcase(char *str);

#include <stdio.h>

int main()
{
	char arr[15] = "ASFDaG";
	arr[6] = 1;
	ft_strlowcase(arr);
	printf("%s", arr);

	return 0;
}
