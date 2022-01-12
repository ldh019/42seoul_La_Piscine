/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:05:26 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/12 19:11:40 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hexa_nonprint(unsigned char a);
char	change_hexa(int a);

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*r;
	int				i;

	r = (unsigned char *)str;
	i = 0;
	while (r[i] != '\0')
	{
		if (r[i] < 32 || r[i] < 126)
			hexa_nonprint(r[i]);
		else
			write(1, &r[i], 1);
		i++;
	}
}

void	hexa_nonprint(unsigned char a)
{
	char	tmp;

	write(1, "\\", 1);
	tmp = change_hexa(a / 16);
	write(1, &tmp, 1);
	tmp = change_hexa(a % 16);
	write(1, &tmp, 1);
}

char	change_hexa(int a)
{
	char	arr[16];
	int		i;

	i = 0;
	while (i < 16)
	{
		if (i < 10)
			arr[i] = i + 48;
		else
			arr[i] = i + 87;
		i++;
	}
	return (arr[a]);
}
