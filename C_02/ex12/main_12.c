extern void* ft_print_memory(void *addr, unsigned int size);
#include <stdio.h>

int main()
{
	char arr[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n \0";

	ft_print_memory(arr, 95);

	return 0;
}
