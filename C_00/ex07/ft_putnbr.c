/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 17:07:39 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/08 17:44:34 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_putnbr(int nb)
{
	char	a;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		ft_putnbr(nb);
	}
	else if (nb < 10)
	{
		a = nb + 48;
		write(1, &a, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		a = nb % 10 + 48;
		write(1, &a, 1);
	}
}
