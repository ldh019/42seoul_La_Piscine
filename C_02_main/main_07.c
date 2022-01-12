extern char* ft_strupcase(char *str);

#include <stdio.h>

int main()
{
	char arr[15] = "ASFDaG";
	arr[6] = 1;
	ft_strupcase(arr);
	printf("%s", arr);

	return 0;
}
