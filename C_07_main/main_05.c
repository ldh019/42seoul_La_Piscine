#include <stdio.h>
extern char	**ft_split(char *str, char *charset);
int main()
{
	int i;
	char **ans;
	char *src = "abc;abcd,efs;;;adff,osoidgh;";
	char *deli = ";,";

	ans = ft_split(src, deli);

	for(i = 0 ;i<5;i++)
		printf("%s\n", ans[i]);

	return 0;
}