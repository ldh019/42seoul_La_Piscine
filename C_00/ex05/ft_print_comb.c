/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:56:53 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/08 12:02:18 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_print_comb(void)
{
	int		a;
	char	print[2];
	char	b;

	a = 12;
	print[0] = ',';
	print[1] = ' ';
	while (a <= 789)
	{
		if (a / 100 < (a % 100) / 10 && (a % 100) / 10 < a % 10)
		{
			b = (a / 100) + 48;
			write(1, &b, 1);
			b = ((a % 100) / 10) + 48;
			write(1, &b, 1);
			b = a % 10 + 48;
			write(1, &b, 1);
			if (a != 789)
				write(1, print, 2);
		}
		a++;
	}
}