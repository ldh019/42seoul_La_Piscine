/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 13:29:03 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/25 21:43:56 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.h"
#include <unistd.h>
#include <stdlib.h>

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

char	**int_to_char(int **map, char *letter, t_pair a)
{
	char	**print_map;
	int		i;
	int		j;

	print_map = (char **) malloc(sizeof(char *) * a.y);
	
	i = -1;
	while (++i < a.y)
	{
		print_map[i] = (char *) malloc(a.x);
		j = -1;
		while (++j < a.x)
		{
			print_map[i][j] = letter[map[i][j]];
		}
	}
	return (print_map);
}

void	print(int **map, char *letter, t_pair a)
{
	char	**print_map;
	int		i;
	int		j;

	print_map = int_to_char(map, letter, a);
	i = -1;
	while (++i < a.y)
	{
		j = -1;
		while (++j < a.x)
		{
			write(1, &print_map[i][j], 1);
		}
		write(1, "\n", 1);
	}
}
