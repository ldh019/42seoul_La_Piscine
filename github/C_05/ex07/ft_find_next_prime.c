/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:50:34 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/13 16:56:38 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;
	int	j;
	int	ans;

	i = nb;
	if (nb == 3 || nb == 2)
		ans = nb;
	else if (nb < 2)
		ans = 2;
	else
		ans = 0;
	while (ans == 0)
	{
		j = 2;
		while (j <= i / 2)
		{
			if (i % j == 0)
				break ;
			j++;
		}
		if (j == i / 2 + 1)
			ans = i;
		i++;
	}
	return (ans);
}
