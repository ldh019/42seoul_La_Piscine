/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 18:09:23 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/15 19:25:00 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	g_a[4][4];
extern int	g_boxcount[4][4];

int	finish_row_left(int y)
{
	int	p;
	int	cnt;
	int	i;

	p = 0;
	cnt = 0;
	i = -1;
	while (++i < 4)
	{
		if (p < g_a[y][i])
		{
			p = g_a[y][i];
			cnt++;
		}
	}
	if (cnt != g_boxcount[2][y])
		return (0);
	return (1);
}

int	finish_row_right(int y)
{
	int	p;
	int	cnt;
	int	i;

	p = 0;
	cnt = 0;
	i = 4;
	while (--i >= 0)
	{
		if (p < g_a[y][i])
		{
			p = g_a[y][i];
			cnt++;
		}
	}
	if (cnt != g_boxcount[3][y])
		return (0);
	return (1);
}

int	finish_col_up(void)
{
	int	p;
	int	cnt;
	int	x;
	int	i;

	x = -1;
	while (++x < 4)
	{
		p = 0;
		cnt = 0;
		i = -1;
		while (++i < 4)
		{
			if (p < g_a[i][x])
			{
				p = g_a[i][x];
				cnt++;
			}
		}
		if (cnt != g_boxcount[0][x])
			return (0);
	}
	return (1);
}

int	finish_col_down(void)
{
	int	x;
	int	p;
	int	cnt;
	int	i;

	x = -1;
	while (++x < 4)
	{
		p = 0;
		cnt = 0;
		i = 4;
		while (--i >= 0)
		{
			if (p < g_a[i][x])
			{
				p = g_a[i][x];
				cnt++;
			}
		}
		if (cnt != g_boxcount[1][x])
			return (0);
	}
	return (1);
}
