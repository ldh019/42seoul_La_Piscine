extern char *ft_strcapitalize(char *str);

#include <stdio.h>

int main()
{
	char arr[200] = "salut??  comment tu vas ? 42mots quarante-deux; cinquante+et_un";

	ft_strcapitalize(arr);

	printf("%s", arr);

	return 0;
}
