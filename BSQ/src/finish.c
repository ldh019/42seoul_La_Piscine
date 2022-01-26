/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:29:03 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/26 13:27:59 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.h"
#include <unistd.h>

void	fill_map(int *ans, int **map)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ans[0])
	{
		j = -1;
		while (++j < ans[0])
		{
			map[ans[1] - i][ans[2] - j] = 2;
		}
	}
}

void	print(int **map, char *letter, t_pair a)
{
	int	i;
	int	j;

	i = -1;
	while (++i < a.y)
	{
		j = -1;
		while (++j < a.x)
		{
			write(1, &letter[map[i][j]], 1);
		}
		write(1, "\n", 1);
	}
}
