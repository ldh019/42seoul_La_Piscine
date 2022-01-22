/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 11:39:24 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/19 17:27:52 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_strlens(int size, char **strs, char *sep)
{
	int	len;
	int	sep_len;
	int	i;

	sep_len = 0;
	while (sep[sep_len] != '\0')
		sep_len++;
	len = (sep_len * (-1));
	while (size-- > 0)
	{
		i = 0;
		while (strs[size][i] != '\0')
			i++;
		len += i;
		len += sep_len;
	}
	return (len);
}

char	*ft_write(char *dst, char *src, int *p)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		dst[(*p)++] = src[i++];
	return (dst);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		i;
	int		len;
	int		p;

	if (size == 0)
	{
		ret = (char *) malloc(1);
		return (ret);
	}
	len = ft_strlens(size, strs, sep);
	if (len == 0)
		return (0);
	ret = (char *) malloc(len);
	i = -1;
	p = 0;
	while (++i < size)
	{
		if (i != 0)
			ft_write(ret, sep, &p);
		ft_write(ret, strs[i], &p);
	}
	ret[p] = '\0';
	return (ret);
}
