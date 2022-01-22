#include <stdio.h>

extern void ft_ultimate_ft(int *********nbr);

int main(void) {
	int tmp1 = 10;
	int *tmp2 = &tmp1;
	int **tmp3 = &tmp2;
	int ***tmp4 = &tmp3;
	int ****tmp5 = &tmp4;
	int *****tmp6 = &tmp5;
	int ******tmp7 = &tmp6;
	int *******tmp8 = &tmp7;
	int ********tmp9 = &tmp8;
	int *********nbr = &tmp9;

	ft_ultimate_ft(nbr);

	printf("%d", tmp1);
}