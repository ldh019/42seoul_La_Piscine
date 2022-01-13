/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:58:50 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/13 16:58:50 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void display(int map[10][10], int *cnt, int dep);

int	ft_ten_queens_puzzle(void)
{
	int map[10][10];
	int i;
	int j;
	int cnt;

	cnt = 0;
	i = 0;
	while(i < 10)
	{
		j = 0;
		while(j < 10)
			map[i][j] = 0;
	}
	display(map, &cnt, 0);
	return (cnt);
}

void display(int map[10][10], int *cnt, int dep)
{
	int i;

	i = 0;
	while (i < 10)
	{
		if (map[dep][i] == 0)
		{
			map[dep][i] == 1;
		} 
	}
}