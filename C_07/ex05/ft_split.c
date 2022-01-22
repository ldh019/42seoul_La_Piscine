/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 16:15:32 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/20 17:51:01 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	isdeli(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	wc;

	wc = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (isdeli(str[i + 1], charset) == 1 && isdeli(str[i], charset) == 0)
			wc++;
		i++;
	}
	return (wc);
}

void	write_str(char *dest, char *from, char *charset)
{
	int	i;

	i = 0;
	while (isdeli(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

void	split_str(char **split, char *str, char *charset)
{
	int		i;
	int		j;
	int		wc;

	wc = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (isdeli(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (isdeli(str[i + j], charset) == 0)
				j++;
			split[wc] = (char *) malloc(sizeof(char) * (j + 1));
			write_str(split[wc], str + i, charset);
			i += j;
			wc++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		wc;

	wc = count_word(str, charset);
	res = (char **) malloc(sizeof(char *) * (wc + 1));
	res[wc] = 0;
	split_str(res, str, charset);
	return (res);
}
