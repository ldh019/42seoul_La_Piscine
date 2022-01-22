/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:58:24 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/16 17:28:41 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_isspace(char c);
int		ft_isnum(char c);
void	execute(void);
void	input(char *arr);

int	main(int argc, char **argv)
{
	g_error = 0;
	if (argc != 2)
		g_error = 1;
	input(argv[1]);
	execute();
	return (0);
}

void	input(char *arr)
{
	int	i;
	int	cnt;
	int	chk;

	chk = 0;
	i = 0;
	cnt = 0;
	while (arr[i] != '\0')
	{
		if (ft_isnum(arr[i]) == 1 && chk <= 0)
		{
			chk = 1;
			if (cnt < 16)
				g_boxcount[cnt / 4][cnt % 4] = arr[i] - 48;
			cnt++;
		}
		else if (ft_isspace(arr[i]) == 0 && ft_isnum(arr[i]) == 0)
			g_error = 1;
		else if (ft_isspace(arr[i]) == 1)
			chk = -1;
		i++;
	}
	if (cnt != 16)
		g_error = 1;
}

void	execute(void)
{
	if (!g_error)
	{
		g_error = 1;
		recursive(0, 0);
	}
	if (g_error)
	{
		write(1, "Error\n", 6);
	}
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= '\n' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
