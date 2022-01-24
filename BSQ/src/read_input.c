/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 11:13:19 by jiikang           #+#    #+#             */
/*   Updated: 2022/01/24 13:59:20 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> //malloc, free, exit
#include <unistd.h> //close, read, write
#include <fcntl.h> //open
#define BUFF_SIZE 3000
#include "pair.h"
#include <stdio.h>

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

int	read_one_line(int fd, char *return_line, int line_length)
{
	int		ret;
	char	buff[1];
	int		i;

	ret = 0;
	i = 0;
	if (0 < fd)
	{
		while (0 < read(fd, buff, 1) && i < line_length)
		{
			if (buff[0] == '\n')
				break ;
			return_line[i] = buff[0];
			i++;
			ret++;
		}
	}
	return_line[i] = '\0';
	return (ret);
}
//fd이용해서 한줄이 끝나거나 return_line의 길이가 끝날때 까지 return_line에 값을 집어넣어줌 & 끝에 \0
//return은 array길이

int	check_letter_is_valid(char *letter)
{
	if (letter[0] == letter[1] || letter[0] == letter[2] || \
		letter[1] == letter[2])
		return (-1);
	else
		return (1);
}
//첫번째 줄로 들어오는 letter가 겹치지 않는가? 안겹치면 1 겹치면 -1

int	char_to_int(char *num)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (num[i] != '\0')
	{
		if (num[i] < '0' || num[i] > '9')
			return (-1);
		ret = ret * 10;
		ret += num[i] - '0';
		i++;
	}
	return (ret);
}
//입력받은 char *를 integer로 변환함. 오류면 -1, 아니라면 변환한 숫자를 return

int	check_letter(char a, char *letter)
{
	int	i;

	i = 0;
	while (letter[i] != '\0')
	{
		if (letter[i] == a)
			return (i);
		i++;
	}
	return (-1);
}
//0: 빈공간 1: 장애물 2:박스 (그럴 일 없음) -1:오류

//row : 가로줄 길이
int	*make_map(char *filename, int fd, int row, char *letter)
{
	char	*temp;
	int		*ret;
	int		i;

	temp = (char *)malloc(sizeof(char) * (row + 1));
	ret = (int *)malloc(sizeof(int) * (row + 1));
	read_one_line(fd, temp, row + 1);
	temp[row] = 0;
	i = 0;
	while (i < row)
	{
		ret[i] = check_letter(temp[i], letter);
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int	make_letter(char *letter, char *buff, int length)
{
	if (length < 4) //인자갯수 적은거
		return (-1);
	letter[2] = buff[length - 1];
	letter[1] = buff[length - 2];
	letter[0] = buff[length - 3];
	if (check_letter_is_valid(letter) == -1)
		return (-1);
	buff[length - 3] = '\0'; // 숫자만 남기기
	return (1);
}
//정상적으로 letter만들면 1,아니면 -1 리턴

void make_pair(t_pair *size, int row, int column)
{
	size->x = row;
	size->y = column;
}
//void return_file_content(char *filename, int **map, char *letter, t_pair *size) (pair : int y, int x)
void	return_file_content(char *filename, int ***map, char *letter, t_pair *size) //letter가 이제 그거..그. 9.01이거.. size로 세로 가로 길이 줘야댐 에러면 0,0
{
	char	buff[BUFF_SIZE];
	int		fd;
	int		length;
	int		row;
	int		i;

	fd = open(filename, O_RDONLY);
	if (0 >= fd)
		return ;
	length = read_one_line(filename, fd, buff, BUFF_SIZE);
	if (make_letter(letter, buff, length) == -1)
		return ;
	length = char_to_int(buff);
	if (length == -1)
		return ;
	*map = (int **)malloc(sizeof(int *) * (length + 1));
	map[length] = 0;
	row = read_row_line(filename);
	if (row == 0)
		return ;
	make_pair(size, row, char_to_int(buff));
	i = 0;
	while (i < length)
		(*map)[i++] = make_map(filename, fd, row, letter);
	close(fd);
}
// 	read first line
// 	and if that is invalid, error -> 중복되거나, 4개보다 적거나 많다 (처음 \n 만날때 까지) 맨 앞에 숫자인지 

// int main(int ac, char **av)
// {
// 	int	fd;
// 	char letter[3];
// 	int **map;

// 	if (ac < 2)
// 		return (0);
// 	if (0 < (fd = open("test.txt",O_RDONLY)))
// 	{
// 		return_file_content("test.txt", &map, letter);

// 	}
// 	printf("letter: %c, %c, %c\n",letter[0],letter[1],letter[2]);
// 		for (int k = 0 ;k < 9; k++)
// 		{
// 			for (int j = 0;j < 27; j++)
// 			{
// 				printf("%d", map[k][j]);
// 			}
// 			printf("\n");
// 		}
// 	return (0);
// }