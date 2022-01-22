/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:29:39 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/22 16:13:23 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

void	write_str(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*ret;
	int					i;
	int					len;

	if (ac == 1)
		ret = 0;
	else
	{
		i = 1;
		ret = (struct s_stock_str *) malloc(sizeof(struct s_stock_str) * ac);
		ret[ac - 1].str = 0;
		while (i < ac)
		{
			len = 0;
			while (av[i][len] != 0)
				len++;
			ret[i - 1].size = len;
			ret[i - 1].str = av[i];
			ret[i - 1].copy = (char *) malloc(len);
			write_str(ret[i - 1].copy, av[i]);
			i++;
		}
	}
	return (ret);
}
