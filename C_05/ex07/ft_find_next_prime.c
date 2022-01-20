/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:50:34 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/19 10:21:11 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i <= nb && i * i >= 0)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}

int	reset(int nb)
{
	if (nb == 3 || nb == 2)
		return (nb);
	else if (nb < 2)
		return (2);
	else
		return (0);
}

int	ft_find_next_prime(int nb)
{
	int	i;
	int	j;
	int	ans;
	int	tmp;

	i = nb;
	ans = reset(nb);
	while (ans == 0 && i > 0)
	{
		j = 2;
		tmp = ft_sqrt(i);
		while (j <= tmp)
		{
			if (i % j == 0)
				break ;
			j++;
		}
		if (j > tmp)
			ans = i;
		i++;
	}
	return (ans);
}
