/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:06:44 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/10 17:23:45 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	isUp(char a);
int	isLow(char a);
int	isNum(char a);

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (isUp(str[i]) == 1)
		{
			str[i] += 32;
		}
		if (isLow(str[i]) == 1)
		{
			if (i == 0)
				str[i] -= 32;
			else if (isLow(str[i - 1]) == 0 && isUp(str[i - 1]) == 0)
				if (isNum(str[i - 1]) == 0)
					str[i] -= 32;
		}
		i++;
	}
	return (str);
}

int	isLow(char a)
{
	if (a >= 'a' && a <= 'z')
		return (1);
	else
		return (0);
}

int	isUp(char a)
{
	if (a >= 'A' && a <= 'Z')
		return (1);
	else
		return (0);
}

int	isNum(char a)
{
	if (a >= '0' && a <= '9')
		return (1);
	else
		return (0);
}
