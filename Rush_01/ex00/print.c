/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:23:37 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/16 11:54:13 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	ft_itoa(int n)
{
	return (n + 48);
}

void	print(void)
{
	int		i;
	int		j;
	char	print;

	i = -1;
	j = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			print = ft_itoa(g_a[i][j]);
			write(1, &print, 1);
			if (j < 3)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
		}
	}
}
