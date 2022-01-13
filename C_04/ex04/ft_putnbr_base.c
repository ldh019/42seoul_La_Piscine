/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:02:46 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/13 19:21:12 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		base_check(char *base, int *len);
void	rev_print(int nbr, char *base, int len);

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	if (base_check(base, &len) == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	rev_print(nbr, base, len);
}

int	base_check(char *base, int *len)
{
	int		i;
	int		j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] < 32 || base[i] == 127)
			return (0);
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i == 0 || i == 1)
		return (0);
	*len = i;
	return (1);
}

void	rev_print(int nbr, char *base, int len)
{
	if (nbr >= len)
		rev_print(nbr / len, base, len);
	write(1, &base[nbr % len], 1);
}
