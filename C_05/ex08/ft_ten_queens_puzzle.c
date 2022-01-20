/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:58:50 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/17 20:05:35 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_map[10];
int	g_cnt;

void	print(void)
{
	int	i;
	int	p;

	i = 0;
	while (i < 10)
	{
		p = g_map[i] + 48;
		write(1, &p, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	available(int idx, int n)
{
	int	i;

	i = 1;
	while (idx - i > -1)
	{
		if (g_map[idx - i] == n)
			break ;
		if (g_map[idx - i] == n - i)
			break ;
		if (g_map[idx - i] == n + i)
			break ;
		i++;
	}
	if (i <= idx)
		return (0);
	return (1);
}

void	recursive(int idx)
{
	int	i;

	if (idx == 10)
	{
		g_cnt++;
		print();
		return ;
	}
	i = 0;
	while (i < 10)
	{
		if (available(idx, i))
		{
			g_map[idx] = i;
			recursive(idx + 1);
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	g_cnt = 0;
	recursive(0);
	return (g_cnt);
}
