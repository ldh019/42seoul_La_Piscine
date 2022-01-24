/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:27:09 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/24 13:48:49 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "pair.h"

extern void	execute(int **map, t_pair a);
extern void	return_file_content(char *file_name, int ***map,
				char *letter, t_pair *size);
extern void	print(int **map, char *letter, t_pair a);

int	main(int argc, char **argv)
{
	int		file_index;
	int		**map;
	char	*letter;
	t_pair	size;

	file_index = 1;
	letter = 0;
	while (file_index <= argc)
	{
		size.x = 0;
		size.y = 0;
		return_file_content(argv[file_index], &map, letter, &size);
		if (size.y > 0 && size.x > 0)
		{
			execute(map, size);
			print(map, letter, size);
		}
		else
			write(1, "map error\n", 17);
	}
	return (0);
}
