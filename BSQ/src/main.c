/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:27:09 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/26 17:30:42 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "pair.h"
#include "execute.h"

void	ft_free(int **map, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		free(map[i++]);
	}
	free(map);
}

char	*file_make(void)
{
	char	buf;
	int		fd;
	char	*ret;

	ret = "donghun.txt";
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
	char	letter[3];
	int		i;
	t_pair	size;

	file_index = 0;
	while (++file_index < argc)
	{
		size.x = 0;
		size.y = 0;
		return_file_content(argv[file_index], letter, &size);
		map = (int **)malloc(sizeof(int *) * (size.y + 1));
		i = -1;
		while (++i < size.y)
			map[i] = (int *)malloc(sizeof(int) * (size.x + 1));
		make_map(argv[file_index], map, letter, &size);
		if (size.y > 0 && size.x > 0 && check_map(map, size))
		{
			execute(map, size);
			print(map, letter, size);
		}
		else
			write(2, "map error\n", 17);
	}
	ft_free(map, size.y);
}

int	main(int argc, char **argv)
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
	system("leaks bsq");
	return (0);
}
