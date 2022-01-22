/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:35:52 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/19 11:24:38 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*ret;

	ret = (int *) malloc(sizeof(int) * (max - min));
	if (min >= max)
		return (0);
	i = min - 1;
	while (++i < max)
		ret[i - min] = i;
	*range = ret;
	return (max - min);
}
