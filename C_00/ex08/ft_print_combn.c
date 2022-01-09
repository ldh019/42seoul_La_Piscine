/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:28:54 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/08 16:00:14 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	ft_print_combn(int n)
{
	int		p;
	char	num[10];

	p = 0;
	num[0] = 47;
	while (!(num[0] == 10 - n + 48 && num[n - 1] == 57))
	{
		if (num[p] == 57)
		{
			num[p--] = 48;
		}
		else if (p < n - 1)
		{
			num[p++]++;
			num[p] = num[p - 1];
		}
		else
		{
			num[p]++;
			write(1, num, n);
			if (!(num[0] == 10 - n + 48 && num[n - 1] == 57))
				write(1, ", ", 2);
		}
	}	
}
