/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:15:39 by jiikang           #+#    #+#             */
/*   Updated: 2022/01/26 15:45:33 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "pair.h"
#include "input.h"

int	read_row_line(char *filename)
{
	int		ret;
	int		fd;
	char	buff[1];

	ret = 0;
	fd = open(filename, O_RDONLY);
	if (0 < fd)
	{
		while (0 < read(fd, buff, 1))
			if (buff[0] == '\n')
				break ;
		while (0 < read(fd, buff, 1))
		{
			if (buff[0] == '\n')
				break ;
			ret++;
		}
		close(fd);
	}
	return (ret);
}

int	read_one_line(int fd, char *return_line, int line_length, int flag)
{
	int		ret;
	char	buff[1];
	int		i;

	ret = 0;
	i = 0;
	if (0 < fd)
	{
		while (0 < read(fd, buff, 1))
		{
			if (buff[0] == '\n')
				break ;
			return_line[i] = buff[0];
			i++;
			ret++;
		}
	}
	else
		return (0);
	if ((buff[0] != '\n' || i != line_length - 1) && flag)
		return (0);
	return_line[i] = '\0';
	return (ret);
}

void	return_file_content(char *filename, char *letter, t_pair *size)
{
	char	buff[BUFF_SIZE];
	int		fd;
	int		length;
	int		row;

	fd = open(filename, O_RDONLY);
	if (0 >= fd)
		return ;
	length = read_one_line(fd, buff, BUFF_SIZE, 0);
	if (make_letter(letter, buff, length) == -1)
		return ;
	length = char_to_int(buff);
	if (length == -1)
		return ;
	row = read_row_line(filename);
	if (row == 0)
		return ;
	make_pair(size, row, char_to_int(buff));
	close(fd);
}

void	check_finish_file(int fd, char *buff, int **map)
{
	if (read(fd, buff, 1) > 0)
	{
		map[0][0] = -1;
		return ;
	}
}

void	make_map(char *filename, int **map, char *letter, t_pair *size)
{
	char	buff[15];
	char	*temp;
	int		fd;
	int		j;

	fd = open(filename, O_RDONLY);
	if (0 >= fd)
		return ;
	temp = (char *)malloc(sizeof(char) * (size->x + 1));
	temp[size->x] = '\0';
	read_one_line(fd, buff, 15, 0);
	j = 0;
	while (j < size->y)
	{
		if (read_one_line(fd, temp, size->x + 1, 1) == 0)
		{
			map[0][0] = -1;
			free (temp);
			return ;
		}
		put_line(temp, map, letter, j++);
	}
	check_finish_file(fd, buff, map);
	free(temp);
	close(fd);
}
