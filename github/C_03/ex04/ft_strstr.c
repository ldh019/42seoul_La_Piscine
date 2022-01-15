/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:22:25 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/12 19:13:32 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_while(char *str, char *to_find);

char	*ft_strstr(char *str, char *to_find)
{
	char	*ret;
	char	*save;

	save = to_find;
	while (*str != '\0')
	{
		if (*str == *to_find)
		{
			ret = str;
			if (ft_while(str, to_find) == 1)
				return (ret);
			else
				to_find = save;
		}
		str++;
	}
	return ("\0");
}

int	ft_while(char *str, char *to_find)
{
	while (*str != '\0' && *to_find != '\0')
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	if (*str == '\0' && *to_find != '\0')
		return (0);
	return (1);
}
