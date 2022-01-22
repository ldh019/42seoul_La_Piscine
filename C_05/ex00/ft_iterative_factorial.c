/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghunl <donghunl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 14:36:42 by donghunl          #+#    #+#             */
/*   Updated: 2022/01/13 14:45:25 by donghunl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	ans;

	if (nb < 0)
		return (0);
	ans = 1;
	while (nb > 1)
	{
		ans *= nb;
		nb--;
	}
	return (ans);
}
