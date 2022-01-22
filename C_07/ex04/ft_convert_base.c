/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:27:39 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/20 16:14:33 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

extern long	ft_atoi(char *str, char *base);
extern int	base_check(char *base);
extern int	ft_minus(char *str, char *base);

void	str_len(int *len, char *base)
{
	*len = 0;
	while (base[*len] != 0)
		(*len)++;
}

int	get_len(long num, int n)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		len++;
		num /= n;
	}
	return (len);
}

char	*ft_itob(long save, char *base)
{
	int		n;
	int		size;
	char	*ret;
	int		chk;

	str_len(&n, base);
	chk = 0;
	size = 1;
	if (save < 0)
	{
		save *= -1;
		chk = 1;
	}
	size += get_len(save, n);
	ret = (char *) malloc(size + 2);
	ret[0] = '-';
	ret[size] = '\0';
	while (--size > 0)
	{
		ret[size] = base[save % n];
		save /= n;
	}
	if (chk != 1)
		ret++;
	return (ret);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	save;

	if (base_check(base_to) == 0 || base_check(base_from) == 0)
		return (0);
	save = ft_atoi(nbr, base_from);
	return (ft_itob(save, base_to));
}
