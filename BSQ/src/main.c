/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:27:09 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/24 20:38:46 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "pair.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern void	execute(int **map, t_pair a);
extern void	return_file_content(char *file_name, int ***map,
				char *letter, t_pair *size);
extern void	print(int **map, char *letter, t_pair a);
extern int	check_map(int **map, t_pair size);

int	main(int argc, char **argv)
{
	int		file_index;
	int		**map;
	char	*letter;
	char	*tmp;

	t_pair	size;
	file_index = 1;
	letter = (char *) malloc(3);
	while (file_index < argc)
	{
		size.x = 0;
		size.y = 0;
		tmp = strdup(argv[file_index]);
		return_file_content(tmp, &map, letter, &size);
		if (size.y > 0 && size.x > 0 && check_map(map, size)) 
		{
			execute(map, size);
			print(map, letter, size);
		}
		else
			write(2, "map error\n", 17);
		file_index++;
	}
	return (0);
}
