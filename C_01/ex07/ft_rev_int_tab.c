/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:04:20 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/10 12:29:13 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	s;
	int	p;
	int	tmp;

	s = size / 2;
	p = 0;
	while (p < s)
	{
		tmp = tab[p];
		tab[p] = tab[size - p - 1];
		tab[size - p - 1] = tmp;
		p++;
	}
}
