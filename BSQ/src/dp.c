/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:40:24 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/24 12:32:24 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "pair.h"

extern void	fill_map(int *ans, int **map, t_pair a);

int	min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a);
	else if (b <= a && b <= c)
		return (b);
	return (c);
}

int	*dynamic(int **map, int **dp, t_pair a)
{
	int	*ans;
	int	i;
	int	j;

	ans = (int *) malloc(12);
	ans[0] = 0;
	i = -1;
	while (++i < a.y)
	{
		j = -1;
		while (++j < a.x)
		{
			if (map[i][j] == 1)
			{
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1],
						dp[i - 1][j - 1]) + 1;
				if (dp[i][j] > ans[0])
				{
					ans[0] = dp[i][j];
					ans[1] = i;
					ans[2] = j;
				}
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
	t_pair	fill;

	dp = (int **) malloc(sizeof(int *) * a.y);
	i = -1;
	while (++i < a.y)
		dp[i] = (int *) malloc(sizeof(int) * a.x);
	ans = dynamic(map, dp, a);
	fill.y = ans[1];
	fill.x = ans[2];
	fill_map(ans, map, fill);
}
