/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:47:44 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/15 11:47:44 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	fillmap(int y, int x);

void	recursive(int y, int x)
{
	if (!g_error)
		return ;
	if (y >= 4)
	{
		if (finish_col_up() && finish_col_down())
		{
			print();
			g_error = 0;
		}
	}
	else if (x >= 4)
	{
		if (finish_row_left(y) && finish_row_right(y))
			recursive(y + 1, 0);
	}
	else
	{
		fillmap(y, x);
	}
	return ;
}

int	available(int y, int x, int v)
{
	int	i;

	i = -1;
	while (++i < x)
		if (g_a[y][i] == v)
			return (0);
	i = -1;
	while (++i < y)
		if (g_a[i][x] == v)
			return (0);
	return (1);
}

void	fillmap(int y, int x)
{
	int	v;

	v = 0;
	while (v++ < 4)
	{
		if (available(y, x, v) == 1)
		{
			g_a[y][x] = v;
			recursive(y, x + 1);
		}
	}
}
