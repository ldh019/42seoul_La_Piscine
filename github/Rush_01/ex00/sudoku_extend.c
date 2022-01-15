/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_extend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:16:38 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/15 20:33:14 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
extern void	print(int arr[4][4]);
extern int	finish_row_left(int y);
extern int	finish_row_right(int y);
extern int	finish_col_up(void);
extern int	finish_col_down(void);
void		recursive(int y, int x);
int			available(int y, int x, int v);
void		execute(void);
void		fillmap(int y, int x);

int		**g_a;
int		g_c;
int		**g_boxcount;
int		g_size;

int	main(int argc, char **argv)
{
	int		i;
	int		cnt;

	g_c = 1;
	i = -1;
	cnt = 0;
	while (argv[1][++i] != 0)
		cnt++;
	if ((cnt + 1) / 2 % 4 != 0 || argc == 0)
		g_c = 0;
	g_size = (cnt + 1) / 2;
	g_a = (int**)malloc(sizeof(int*)*g_size);
	g_boxcount = (int**)malloc(sizeof(int*)*g_size);
	i = 0;
	while (i < 31)
	{
		if (i % 2 == 1 && argv[1][i] != ' ')
			g_c = 0;
		else if (i % 2 == 0 && (argv[1][i] < '1' || argv[1][i] > '0' + g_size))
			g_c = 0;
		else if(i % 2 == 0)
			g_boxcount[(i / 2) / g_size][(i / 2) % g_size] = argv[1][i] - 48;
		i++;
	}
	execute();
	return (0);
}

void	execute(void)
{
	if (g_c == 1)
	{
		g_c = 0;
		recursive(0, 0);
	}
	if (g_c == 0)
		write(1, "Error\n", 6);
}

void	recursive(int y, int x)
{
	if (g_c != 0)
		return ;
	if (y >= 4)
	{
		if (finish_col_up() && finish_col_down())
		{
			print(g_a);
			g_c = 1;
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
