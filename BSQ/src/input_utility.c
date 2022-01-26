/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:10:46 by jiikang           #+#    #+#             */
/*   Updated: 2022/01/26 14:41:07 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pair.h"

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

int	check_letter_is_valid(char *letter)
{
	if (letter[0] == letter[1] || letter[0] == letter[2] || \
		letter[1] == letter[2])
		return (-1);
	else
		return (1);
}

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

void	make_pair(t_pair *size, int row, int column)
{
	size->x = row;
	size->y = column;
}

int	make_letter(char *letter, char *buff, int length)
{
	if (length < 4)
		return (-1);
	letter[2] = buff[length - 1];
	letter[1] = buff[length - 2];
	letter[0] = buff[length - 3];
	if (check_letter_is_valid(letter) == -1)
		return (-1);
	buff[length - 3] = '\0';
	return (1);
}
