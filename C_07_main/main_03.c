#include <stdio.h>

extern char *ft_strjoin(int size, char **strs, char *sep);

int main()
{
	char **str;
	char *sep = ";;";
	str[0] = "hello";
	str[1] = "stranger";
	str[2] = "idgaf";
	char *ans = ft_strjoin(3, str, sep);
	printf("%s", ans);

	return 0;
}