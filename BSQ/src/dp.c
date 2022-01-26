/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:40:24 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/26 17:33:33 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "pair.h"
#include "execute.h"

int	min(int **dp, int y, int x)
{
	if (y == 0 || x == 0)
		return (0);
	else
	{
		if (dp[y - 1][x] <= dp[y - 1][x - 1] && dp[y - 1][x] <= dp[y][x - 1])
			return (dp[y - 1][x]);
		else if (dp[y - 1][x - 1] <= dp[y - 1][x]
			&& dp[y - 1][x - 1] <= dp[y][x - 1])
			return (dp[y - 1][x - 1]);
		else if (dp[y][x - 1] <= dp[y - 1][x]
			&& dp[y][x - 1] <= dp[y - 1][x - 1])
			return (dp[y][x - 1]);
	}
	return (0);
}

void	ans_set(int *ans, int v, int y, int x)
{
	ans[0] = v;
	ans[1] = y;
	ans[2] = x;
}

int	*dynamic(int **map, int ***dp, int *ans, t_pair a)
{
	int	i;
	int	j;

	ans[0] = 0;
	i = -1;
	while (++i < a.y)
	{
		j = -1;
		while (++j < a.x)
		{
			if (map[i][j] == 0)
			{
				(*dp)[i][j] = min(*dp, i, j) + 1;
				if ((*dp)[i][j] > ans[0])
					ans_set(ans, (*dp)[i][j], i, j);
			}
		}
	}
	return (ans);
}

void	execute(int **map, t_pair a)
{
	int		**dp;
	int		*ans;
	int		i;

	ans = (int *) malloc(12);
	dp = (int **) malloc(sizeof(int *) * a.y);
	i = -1;
	while (++i < a.y)
		dp[i] = (int *) malloc(sizeof(int) * a.x);
	ans = dynamic(map, &dp, ans, a);
	fill_map(ans, map);
	free(ans);
	i = 0;
	while (i < a.y)
		free(dp[i++]);
	free(dp);
}
