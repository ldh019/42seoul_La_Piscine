/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 09:20:10 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/13 17:37:25 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_addr(unsigned long long addr, int d);
void	print_hexa_data(char *addr, unsigned int size);
void	print_real_data(char *addr, unsigned int size);
void	ft_putchar(char c);
char	hexa(int c);

void	*ft_print_memory(void *addr, unsigned int size)
{
	void	*ret;
	int		tmp_size;

	ret = addr;
	while (size > 0)
	{
		if (size > 16)
			tmp_size = 16;
		else
			tmp_size = size;
		print_addr((unsigned long long)addr, 0);
		write(1, ":", 1);
		write(1, " ", 1);
		print_hexa_data((char *)addr, tmp_size);
		print_real_data((char *)addr, tmp_size);
		write(1, "\n", 1);
		addr += 16;
		size -= tmp_size;
	}
	return (ret);
}

void	print_addr(unsigned long long addr, int d)
{
	int	tmp;

	if (d < 15)
	{
		print_addr(addr / 16, d + 1);
	}
	tmp = hexa(addr % 16);
	write(1, &tmp, 1);
}

void	print_hexa_data(char *addr, unsigned int size)
{
	unsigned int	i;
	int				tmp;

	i = 0;
	while (i < size)
	{
		tmp = hexa(addr[i] / 16);
		write(1, &tmp, 1);
		tmp = hexa(addr[i] % 16);
		write(1, &tmp, 1);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
}

void	print_real_data(char *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (i + size < 16)
			write(1, " ", 1);
		else if (addr[i] < 32 || addr[i] == 127)
			write(1, ".", 1);
		else
			write(1, &addr[i], 1);
		i++;
	}
}

char	hexa(int n)
{
	if (n >= 0 && n <= 9)
		return (n + 48);
	else
		return (n + 87);
}
