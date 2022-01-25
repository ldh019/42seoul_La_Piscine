/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiikang <jiikang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:27:09 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/25 21:47:08 by jiikang          ###   ########.fr       */
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
extern void	make_map(char *filename, int **map, char *letter, t_pair *size);

char *file_make()
{
	char	buf;
	int		fd;
	char	*ret = "donghun.txt";

	fd = open(ret, O_RDWR | O_TRUNC | O_CREAT, 0644);
	while (read(0, &buf, 1))
		write(fd, &buf, 1);
	close(fd);
	return (ret);
}

void	ft_main(int argc, char **argv)
{
	int		file_index;
	int		**map;
	char	*letter;
	char	*tmp;
	int		i;

	t_pair	size;
	file_index = 1;
	letter = (char *) malloc(3);
	while (file_index < argc)
	{
		size.x = 0;
		size.y = 0;
		tmp = strdup(argv[file_index]);
		return_file_content(tmp, &map, letter, &size);
		map = (int **)malloc(sizeof(int *) * (size.y + 1));
		i = 0;
		while (i < size.y)
		{
			map[i++] = (int *)malloc(sizeof(int) * (size.x + 1));
		}
		make_map(argv[file_index], map, letter, &size);
		if (size.y > 0 && size.x > 0 && check_map(map, size)) 
		{
			execute(map, size);
			print(map, letter, size);
		}
		else
			write(2, "map error\n", 17);
		file_index++;
	}
}


int main(int argc, char **argv)
{
	char	**tmp_argv;

	if (argc == 1)
	{
		tmp_argv = (char **) malloc(sizeof(char *) * 2);
		*(tmp_argv + 1) = file_make();
		ft_main(2, tmp_argv);
		free(tmp_argv);
	}
	else
		ft_main(argc, argv);
	return (0);
}
