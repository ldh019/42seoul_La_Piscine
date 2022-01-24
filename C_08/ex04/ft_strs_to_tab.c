/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 14:29:39 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/24 10:09:16 by donghunl         ###   ########.fr       */
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
	dst[i] = 0;
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*ret;
	int			i;
	int			len;

	i = 0;
	ret = (t_stock_str *) malloc(sizeof(t_stock_str) * (ac + 1));
	if (ret == 0)
		return (0);
	ret[ac].str = 0;
	while (i < ac)
	{
		len = 0;
		while (av[i][len] != 0)
			len++;
		ret[i].size = len;
		ret[i].str = av[i];
		ret[i].copy = (char *) malloc(len + 1);
		write_str(ret[i].copy, av[i]);
		i++;
	}
	return (ret);
}
