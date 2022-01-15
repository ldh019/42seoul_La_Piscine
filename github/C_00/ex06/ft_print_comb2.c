/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:51:17 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/06 17:05:06 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_print_comb2(void)
{
	int		a;
	int		b;
	char	print[7];

	a = 0;
	print[2] = ' ';
	print[5] = ',';
	print[6] = ' ';
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			print[0] = a / 10 + 48;
			print[1] = a % 10 + 48;
			print[3] = b / 10 + 48;
			print[4] = b % 10 + 48;
			if (!(a == 98 && b == 99))
				write(1, print, 7);
			else
				write(1, print, 5);
			b++;
		}
		a++;
	}
}
