/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:13:19 by jiikang           #+#    #+#             */
/*   Updated: 2022/01/26 15:23:06 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.h"
#include "input.h"

int	check_map(int **map, t_pair size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size.y)
	{
		j = 0;
		while (j < size.x)
		{
			if (map[i][j] == -1 || map[i][j] == 2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	put_line(char *temp, int **map, char *letter, int num)
{
	int	i;

	i = 0;
	while (temp[i] != '\0')
	{
		map[num][i] = check_letter(temp[i], letter);
		i++;
	}
	map[num][i] = '\0';
}
