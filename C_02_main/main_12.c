extern void* ft_print_memory(void *addr, unsigned int size);
#include <stdio.h>

int main()
{
	char arr[] = "Hello my computer";

	ft_print_memory(arr, 17);

	return 0;
}
